# PNRGatewayTweak
 The component of PNRGateway that runs on the iPhone as a Cydia tweak

### Note: I've put together a new version of PNRGateway that doesn't require a SIM card! Check it out at [SIMLessPNRGateway](https://github.com/AwesomeIndustry/SIMLessPNRGateway)



This is the side of PNRGateway that runs on the iPhone and modifies the REG-REQ SMS such that it gets sent to an Android device. The Android device should be running the [PNRGatewayClient application](https://github.com/AwesomeIndustry/PNRGatewayClient) in order to receive the SMS from the Android phone and forward it to Apple, as well as to send the response back to the iPhone.

**Note: If you're compiling this yourself, make sure to fill in your Android phone's number (in international format) in the constant `ANDROID_PHONE_NUMBER` at the top**

Here's a brief overview as to how the iPhone proves to Apple that it owns its phone number (without this tweak installed or any weird hacks). (PNR stands for Phone Number Registration, and most methods that have to do with iMessage registration have "PNR" in the signature somewhere) This tweak was designed on an iPhone 5S (GSM) with Checkra1n and iOS 12.5.6.

## Build instructions

The instructions for building PNRGatewayTweak are the same as SIMLessPNRGateway, so follow the [build instructions](https://github.com/AwesomeIndustry/SIMLessPNRGateway/blob/main/README.md) from over there.

## The vanilla registration process

1. The iPhone sends an HTTP request to identity.ess.apple.com, which is called the preflight request. I don't know very much about it, but the request contains the phone's IMSI and PLMN, which Apple uses to return the list of validation *mechanisms*

    1. Each PNR mechanism is a different method the iPhone can use to register the phone number with Apple. There are two types of mechanisms: SMS and SMSLess.

    2. When the iPhone is registering using the SMS mechanism, it sends an SMS to a *registration gateway address* to prove its identity to Apple. The gateway address is just a phone number connected to an Apple server somewhere. The most common gateway address is the UK number `+447786205094`, but there are many variations and some carriers have special ones (i.e. AT&T sends the SMS to `28818773`). If you'd like to find out what your carrier's gateway address is, you should be able to emulate the preflight HTTP request (in theory) and get the gateway address, but the easier method is to look in the carrier.plist for whichever carrier you have--the gateway address (or sometimes multiple) will be listed under the `PhoneNumberRegistrationGatewayAddress`. (For some reason the iPhone doesn't appear to usually use this value when it's registering--the phone number only comes from the preflight request.)

    3. However, there's another type of mechanism... *SMSLess*. When the iPhone is using the SMSLess mechanism to register, it doesn't send an SMS at all. Instead, it talks to the *carrier* via the same server that provisions other carrier features like VoLTE or WiFi calling (on AT&T it talks to `https://sentitlement2.mobile.att.net`). Note that **because SMSLess talks directly to the mobile carrier, Apple needs to have an agreement with them in order for SMSLess to work properly**. Most carriers don't have that kind of agreement with Apple, so SMSLess is pretty rare (though AT&T does appear to have it). Anecdotally, SMSLess appears to deregister much faster than SMS registration, which is likely because the carrier has greater visibility into which device actually has the SIM card in it.

4. After that, the iPhone begins the critical part of registration: the actual verification message. Here's how it works *(Note: The bulk of my research was on SMS registration, so that's the only registration method I'm going to cover here. SMSLess registration behaves entirely differently, and I haven't dug into how that works at all)*. I found [this page on the iPhone wiki](https://www.theiphonewiki.com/wiki/FaceTime#FaceTime_Activation_.2F_Registration) on the registration process to be super helpful (even though it's a little out of date).
5. The iPhone begins by sending the registration SMS to the gateway address it found earlier, which includes the *push token* and *request number*. I'm not terribly sure on the specifics of the push token, but for the purposes of this it's some sort of identifier Apple uses to tie the phone number to the iMessage account. The request number is used to link the registration SMS with the response SMS (both will have the same request number)
    6. A sample registration SMS looks like this: It's sent to the phone number (gateway address) `+447786205094` with the contents `REG-REQ?v=3;t=D57A21E052C085182732B6C466AD845DE249C547B07B5D64AEFDE2423E30EDDB;r=1604858336`. The `t=` part is the push token and the `r=` part is the request number.
7. Once Apple's gateway receives the `REG-REQ` SMS message, it can see the phone number the SMS was sent from, which is how it verifies that the iPhone owns the phone number it claims to have! It then formulates a *signature* of this phone number and sends it back in another SMS. As before, the signature can just be treated as a magic number the iPhone needs to finish its registration--I'm not quite sure how the details work. *Note that this SMS will usually arrive as a data SMS, so it usually won't be appear in the Messages app! Thankfully, Android still lets you listen for data SMSes so it's fairly straightforward to work around.*
    8. The response SMS looks something like `REG-RESP?v=3;r=1604858336;n=+11234567890;s=CA21C50C645469B25F4B65C38A7DCEC56592E038F39489F35C7CD6972D`, and is sent from the gateway address back to the iPhone.
    9. Note that this has the same request number `r=604858336` as before, to match it with the `REG-REQ` SMS. Interestingly, the response SMS actually tells the iPhone what phone number Apple thinks the phone has: In this case, the `n=+11234567890` tells the iPhone its phone number is `+1 (123) 456-7890`. **As it turns out, once the iPhone receives the `REG-RESP` SMS, it sets its own phone number to the one listed in the `REG-RESP` SMS. It doesn't matter what the phone number of the actual SIM card is--once the iPhone gets the iMessage response SMS, it will ignore everything else and reset its phone number to the one it's given here.**
10. That's about it! The iPhone does some more negotiations with iCloud to set up the iMessage data connection, but the actual phone number verification exchange is done!

Now that you know how the whole SMS registration process works, here's how PNRGateway messes with it to allow the iPhone to register to a *different* phone number than the one it's using.

## What PNRGateway does

PNRGateway exploits the fact that the iPhone doesn't _really_ know what phone number it has. The phone numbers labeled on SIM cards can be wrong or even missing, and on some carriers the iPhone even gives you a text box in Settings for you to tell it what your phone number is! The only way Apple knows the real phone number of the iPhone is by looking at the sender of the `REG-REQ` SMS. Thus, if we can send this `REG-REQ` SMS from, say, an Android phone, we can trick Apple into thinking the iPhone owns the phone number associated with the Android phone! Here's how it works:

1. The iPhone runs its preflight request as normal, except for the very end, when the Apple HTTP server returns the list of phone number registration mechanisms.
    1. This is where we pull our first bait-and-switch! Recall that the preflight mechanism has two attributes: the type (SMS or SMSLess) and the gateway address (the phone number the registration SMS is sent to). PNRGateway does two things with each mechanism:
    2. PNRGateway overrides any SMSLess mechanisms with SMS mechanisms, to make sure the iPhone does *not* go directly to the carrier to register. We want an SMS we can send from a different phone!
    3. PNRGateway also changes the gateway address from the real Apple number to the Android phone's number.
4. The iPhone continues through the registration process as normal, and it sends the `REG-REQ` SMS to what it *thinks* is the real gateway address. However, since we've just changed it, it gets sent to our Android phone instead! However, our Android phone still needs to send it onward to the real gateway address, which is where the PNRGatewayClient app comes in.
5. On the Android phone, there's a separate app (PNRGatewayClient) running, which receives the `REG-REQ` message from the iPhone and forwards it to the real gateway address.
6. Apple receives the `REG-REQ` SMS from the Android phone, and generates a `REG-RESP` SMS with the signature for the Android phone's number. It sends this back to the Android phone as a data SMS. (If you're testing this, look at the contents of the `REG-RESP` message received by the Android phone--you should see that the `n=` part shows your Android phone's number!)
7. The PNRGatewayClient app receives this `REG-RESP` data SMS and sends it as a regular SMS back to the iPhone.
8. PNRGatewayClient on the iPhone receives the `REG-RESP` SMS and calls the `handleIncomingSMSForPhoneNumber` method inside `IDSPhoneNumberValidationStateMachine`, passing in the phone number and signatures from the `REG-RESP` SMS. This simulates the iPhone actually getting the `REG-RESP` SMS response directly from Apple, and sets in motion the rest of the registration process.
9. Once that happens, the iPhone should think it has the phone number of the Android phone, as well as a valid signature to go with it, and registers iMessage to the Android phone's number!
