#import <Foundation/NSObject.h>
#import <objc/runtime.h>
#import <MRYIPCCenter.h>

@class NSObject;
@class NSConcreteNotification;
@class IMMessage;

#import <SpringBoard/SpringBoard.h>

@class CTXPCServiceSubscriptionContext;
@class CTPhoneBookEntry;
@class PSEditableTableCell;

@class IDSRegistration;
@class IDSDService;
@class KeychainSyncCountryInfo;
#import "Tweak.h"


NSString * const ANDROID_PHONE_NUMBER = @"+11234567890"; //Change this to your Android phone's number



%hook IDSPhoneNumberValidationMechanism

    + (id)SMSMechanismWithContext:(id)gatewayAddress {
        %log;
        //When the SMSMechanismWithContext constructor is called, it's passed the gateway phone number (i.e. +447786205094 in most cases)
        //The gateway phone number is the phone number the iPhone sends the REG-REQ SMS to (when registering for iMessage normally).
        //This code overwrites the gateway number to the Android phone's number such that the Android phone gets the
        //  REG-REQ SMS instead.

        //Note: This appeared to work when overriding with @"28818773", but I'm fairly sure it's supposed to be the Android phone number
        // NSString *pnrGatewayNumber = @"28818773";
        // return %orig(pnrGatewayNumber);
        NSLog(@"SMSMechanismWithContext called, overriding gatewayAddress with %@", ANDROID_PHONE_NUMBER);
        return %orig(ANDROID_PHONE_NUMBER);
    }

    + (id)SMSLessMechanism {
        //Some carriers support a registration method called "SMSLess", which doesn't send SMSes at all, and instead registers
        //  directly with the carrier's VoLTE servers via HTTP.
        //This code makes sure that if the system asks for an SMSLessMechanism object, it's replaced with an SMSMechanismWithContext
        //  object, forcing the iPhone to register via SMS.

        NSLog(@"PNRGateway: Got SMSLess mechanism, overriding with SMS mechanism");
        %log;
        // NSString *pnrGateNum = @"+11234567890";

        return [%c(IDSPhoneNumberValidationMechanism) SMSMechanismWithContext:ANDROID_PHONE_NUMBER];

    }

    - (id)initWithType:(long long)type context:(id)gatewayAddress {
        //This appears to be some other constructor involved in creating the IDSPhoneNumberValidationMechanism object.
        //This code is just here to make sure it creates an SMS registration object (type = 1) with the Android phone
        //  number for the gatewayAddress.

        NSLog(@"Got initWithType call, overriding with type 1 and gatewayAddress %@", ANDROID_PHONE_NUMBER);

        %log; // -[<IDSPhoneNumberValidationMechanism: 0x1017cc160> initWithType:1 context:+447537410287]
        // return %orig(1, @"+11234567890"); //Type 1 = SMS-based
        return %orig(1,ANDROID_PHONE_NUMBER);
    }

%end



//Shamelessly stolen from StackOverflow. https://stackoverflow.com/questions/2501033/nsstring-hex-to-bytes
//This converts a string with hex data (such as @"37C3F2AE") into a real NSData* object (i.e. <37c3 f2ae>)
//Used for converting the signature string in the REG-RESP SMS into an NSData* object
@interface NSString (NSStringHexToBytes)
-(NSData*) hexToBytes ;
@end

@implementation NSString (NSStringHexToBytes)
-(NSData*) hexToBytes {
  NSMutableData* data = [NSMutableData data];
  int idx;
  for (idx = 0; idx+2 <= self.length; idx+=2) {
    NSRange range = NSMakeRange(idx, 2);
    NSString* hexStr = [self substringWithRange:range];
    NSScanner* scanner = [NSScanner scannerWithString:hexStr];
    unsigned int intValue;
    [scanner scanHexInt:&intValue];
    [data appendBytes:&intValue length:1];
  }
  return data;
}
@end


%hook SMSApplication

- (void)_messageReceived:(id)arg1 {
    //Listens for received messages from the Messages app. This is to receive the REG-RESP SMS the Android phone
    //  sends back to the iPhone. This doesn't actually have to be an SMS--you could send the REG-RESP message via
    //  HTTP or something and have it get received somewhere else--as long as you extract the phone number,
    //  extract the signature as an NSData* object, and call emulateReceivedResponsePNR in the IDSPhoneNumberValidationStateMachine,
    //  the phone number registration should still work.
    //
    //*****
    // NOTE: I couldn't get SMSes to get received by the tweak easily using the notification center or talking to IDSDaemon,
    //       so you'll need to make sure the Messages app is running (and possibly focused) to get this to work.
    //*****

    NSLog(@"Got _messageReceived call from SMSApplication!");

    %log;

	%orig;


    //Sets up and extracts the message text
	IMChat* chat = (IMChat *)[(NSConcreteNotification *)arg1 object];
	NSString* identifier = [chat chatIdentifier];
    NSLog(@"Got chat identifier %@", identifier);

    IMMessage *msg = [ [(NSConcreteNotification *)arg1 userInfo] objectForKey:@"__kIMChatValueKey" ];
    NSString* guid = [msg guid];

    NSLog(@"Message GUID: %@", guid);

    NSAttributedString *text = [msg text];
    NSLog(@"Message text: %@", text);

    //TODO: Check if the message is coming from the Android phone number (for security)

    NSAttributedString* msgTextAttributed = [msg text];
    NSString* msgText = msgTextAttributed.string;
    // Message text is REG-RESP?v=3;r=72325403;n=+11234567890;s=CA21C50C645469B25F4B65C38A7DCEC56592E038F39489F35C7CD6972D

    NSLog(@"msgText is %@", msgText);
    NSLog(@"This is the new regex match method!");

    //Uses a regular expression to extract the relevant fields from the received SMS: the phone number (starting with n=)
    //  and the signature (starting with s=)
    NSRegularExpression *regRespRegex = [NSRegularExpression regularExpressionWithPattern:@"REG-RESP\\?v=\\d;r=\\d+;n=([\\+\\d]+);s=([0-9A-F]+)" options:0 error:nil];
    NSTextCheckingResult *result = [regRespRegex firstMatchInString:msgText options:0 range:NSMakeRange(0, [msgText length])];


    if (result) {
        NSLog(@"Regex match: %@", result);
    } else {
        NSLog(@"No match found");
        return;
    }

    if (result.numberOfRanges < 2) {
        NSLog(@"Not enough matches found!");
        return;
    }

    //Extracts the phone number from the regex
    NSRange phoneNumberRange = [result rangeAtIndex:1];
    NSString *phoneNumberMatch = [msgText substringWithRange:phoneNumberRange];
    NSLog(@"Phone number: %@", phoneNumberMatch);

    //Extracts the signature from the regex
    NSRange signatureRange = [result rangeAtIndex:2];
    NSString *signatureMatch = [msgText substringWithRange:signatureRange];
    NSLog(@"Signature: %@", signatureMatch);

    //Converts the signature to NSData* using the hexToBytes method defined above.
    NSData* byteSignature = [signatureMatch hexToBytes];

    NSLog(@"Converted signature to bytes: %@", byteSignature);



    //Sets up the MRYIPC client so this method (running inside SMSApplication) can call the emulateReceivedResponsePNR
    //  method located in the IDSPhoneNumberValidationStateMachine
    NSLog(@"Setting up MRYIPC client");
    MRYIPCCenter* center = [MRYIPCCenter centerNamed:@"dev.altavision.PNRGatewayStateMachine"];
    NSLog(@"Got reference to dev.altavision.PNRGatewayStateMachine: %@", center);

    //Calls the emulateReceivedResponsePNR method inside the state machine
    NSLog(@"Calling external method handleIncomingSMSForPhoneNumber...");
    [center callExternalMethod:@selector(emulateReceivedResponsePNR:) withArguments:@[phoneNumberMatch, byteSignature]];
    NSLog(@"Called external method handleIncomingSMSForPhoneNumber");

}

%end

%hook IDSPhoneNumberValidationStateMachine

    %new

    - (void)emulateReceivedResponsePNR:(NSArray *) responseData {

        //Just a wrapper for handleIncomingSMSForPhoneNumber just because MRYIPC can't handle more than 1 argument
        //This method is called from the _messageReceived method above

        //responseData should be an NSArray with two elements:
        //  1. An NSString with the phone number in international format (i.e. +18882278255)
        //  2. An NSData with the signature data (i.e. <0123 45ab c23d ...>)

        NSLog(@"Got emulateReceivedResponsePNR call! %@", responseData);

        if (responseData.count != 2) {
            NSLog(@"Response data has wrong length! %@", responseData);
            return;
        }

        //Calls the real handleIncomingSMSForPhoneNumber method in IDSPhoneNumberValidationStateMachine, which will
        //  give the phone number and signature back to the state machine, which will complete phone number registration
        //  for the Android phone number!
        NSLog(@"Calling handleIncomingSMSForPhoneNumber");
        [self handleIncomingSMSForPhoneNumber:responseData[0] signature:responseData[1]];
        NSLog(@"Finished calling handleIncomingSMSForPhoneNumber");
    }

    - (void)pnrRequestSent:(id)arg1 pnrReqData:(id)arg2 {
        //This just sets up the MRYIPC server for the state machine whenever the PNR request is sent,
        //  to make sure it's ready by the time the SMS is received.
        %log;

        //TODO: Extract the r=67321832 value and create a new MRYIPCCenter for each request?


        //Sets up the MRYIPC server
        NSLog(@"Setting up the MRYIPCCenter");
        MRYIPCCenter* center = [MRYIPCCenter centerNamed:@"dev.altavision.PNRGatewayStateMachine"];
        NSLog(@"MRYIPCCenter is %@", center);

        //Adds the method to the MRYIPC server
        [center addTarget:self action:@selector(emulateReceivedResponsePNR:)];
        NSLog(@"Added emulateReceivedResponsePNR selector as an action for target self");

        return %orig;
    }

    - (void)handleIncomingSMSForPhoneNumber:(id)arg1 signature:(id)arg2 {
        //This is the method that will get the IDSPhoneNumberValidationStateMachine to finish registration after
        //  the SMS is received from the Android phone. The hooked code doesn't do anything of substance, just a
        //  little logging to make sure it's being called. The state machine handles the rest of the registration
        //  from here.

        %log;
        NSLog(@"Finishing phone number registration!");
        NSObject *a1 = arg1; //"+11234567890", __NSCFString__
        NSObject *a2 = arg2; //<ca21c50c 645469b2 5f4b65c3 8a7dcec5 6592e038 f39489f3 5c7cd697 2d>, _NSInlineData

        NSLog(@"arg1: %@", arg1);
        NSLog(@"Type of arg1: %@", NSStringFromClass(a1.class));

        NSLog(@"arg2: %@", arg2);
        NSLog(@"Type of arg2: %@", NSStringFromClass(a2.class));

        %orig;
    }


%end


// %hook IMDaemonController
//
// - (unsigned)_capabilities {
//     %log;
//     NSLog(@"IMDaemonController _capabilities called!");
//
//     // int origReturnValue = %orig;
//     // NSLog(@"IMDaemonController _capabilities return value: %d", origReturnValue);
//     // return origReturnValue;
//
//     //Return value is 17159
//
// 	// return 2162567; //This might be messing it up? Maybe we need a different number
//     return 17159;
// }
//
// %end
