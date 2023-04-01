@interface NSObject (Undocumented)
@end

@class CTXPCServiceSubscriptionContext;
@class CTPhoneNumberInfo;
@class CTPhoneBookEntry;
// @class id;

@interface IDSPhoneNumberValidationMechanism
    + (id)SMSMechanismWithContext:(_Nullable id)arg1;
    - (id)description;
    - (id)initWithType:(long long)arg1 context:(id)arg2;
@end

// @interface IDSPhoneNumberValidationStateMachine
//
//     - (void)_sendSMSVerificationWithMechanism:(id)arg1;
//     - (void)_issueAsyncCoreTelephonyPhoneNumberValidationRequestWithPushToken:(id)arg1 mechanism:(id)arg2;
//     - (_Bool)_isPhoneNumberIdentificationSupported;
//     - (void)pnrResponseReceived:(id)arg1 pnrRspData:(id)arg2;
//     - (void)pnrRequestSent:(id)arg1 pnrReqData:(id)arg2;
//     - (id)identifyPhoneNumberForRequestor:(id)arg1 queue:(id)arg2;
//     - (id)_telephonyRequestForPushToken:(id)arg1 phoneNumberValidationMechanism:(id)arg2;
//
//
//
//
// @end


@interface IDSPreflightMessage

    // - (void).cxx_destruct;
    - (void)handleResponseDictionary:(id)arg1;
    - (id)bagKey;
    - (id)requiredKeys;
    - (id)messageBody;
    - (id)additionalMessageHeaders;
    - (id)copyWithZone:(struct _NSZone *)arg1;

@end

@interface CTXPCServicePhonebookInterface
    - (void)getPhoneNumberWithCompletion:(CTXPCServiceSubscriptionContext *)arg1 completion:(void (^)(CTPhoneNumberInfo *, NSError *))arg2;
    - (void)getPhonebookEntryCountWithCompletion:(CTXPCServiceSubscriptionContext *)arg1 completion:(void (^)(int, NSError *))arg2;
    - (void)getPhonebookEntryWithCompletion:(CTXPCServiceSubscriptionContext *)arg1 atIndex:(int)arg2 completion:(void (^)(CTPhoneBookEntry *, NSError *))arg3;
    - (void)fetchPhonebook:(CTXPCServiceSubscriptionContext *)arg1 completion:(void (^)(NSError *))arg2;
    - (void)savePhonebookEntry:(CTXPCServiceSubscriptionContext *)arg1 atIndex:(int)arg2 withContactName:(NSString *)arg3 contactNumber:(NSString *)arg4 completion:(void (^)(NSError *))arg5;
    - (void)selectPhonebook:(CTXPCServiceSubscriptionContext *)arg1 forPhonebookName:(int)arg2 withPassword:(NSString *)arg3 completion:(void (^)(NSError *))arg4;
@end

@interface CTPhoneNumberInfo

    +(BOOL)supportsSecureCoding;
    -(NSString *)number;
    -(BOOL)isEditable;
    -(void)setIsEditable:(BOOL)arg1;
    -(void)setIsRead:(BOOL)arg1;
    -(void)setNumber:(NSString *)arg1;
    -(BOOL)isRead;
    -(id)initWithCoder:(id)arg1;
    -(void)encodeWithCoder:(id)arg1;
    -(NSString *)label;
    -(void)setDisplayPhoneNumber:(NSString *)arg1;
    -(void)setLabel:(NSString *)arg1;
    -(BOOL)isPresent;
    -(id)description;
    -(void)setIsPresent:(BOOL)arg1;
    -(NSString *)displayPhoneNumber;
    -(id)copyWithZone:(NSZone*)arg1;

@end

@interface CTXPCClientHandler

    - (void)getSimLessContexts:(id)arg1;

    - (void)getActiveContexts:(id)arg1;

    // - (id)initWithRegistry:(const shared_ptr_0fd4464b *)arg1 queue:(struct queue)arg2 connection:(id)arg3 {
    //     %log;
    //     return %orig;
    // }

    - (void)getSmscAddress:(id)arg1 completion:(id)arg2;

    - (void)isPhoneNumberCredentialValid:(id)arg1 completion:(id)arg2;

    - (void)getPNRContext:(id)arg1 completion:(id)arg2;

    - (void)issuePNRRequest:(id)arg1 pnrReqType:(id)arg2 completion:(id)arg3;

    - (void)isPNRSupported:(id)arg1 completion:(id)arg2;

    - (void)getPhoneNumberWithCompletion:(id)arg1 completion:(id)arg2;

    - (void)getPhonebookEntryWithCompletion:(id)arg1 atIndex:(int)arg2 completion:(id)arg3;

    - (void)context:(id)arg1 isProtectedIdentitySupported:(id)arg2 completion:(id)arg3;

    - (void)copyRegistrationDisplayStatus:(id)arg1 completion:(id)arg2;

    - (void)copyRegistrationStatus:(id)arg1 completion:(id)arg2;


@end


// #import <CoreTelephony/CoreTelephony-Structs.h>
// #import <libobjc.A.dylib/NSCopying.h>
// #import <libobjc.A.dylib/NSSecureCoding.h>

@class NSUUID, NSString, NSNumber;

@interface CTXPCServiceSubscriptionContext : NSObject <NSCopying, NSSecureCoding> {

	BOOL _isSimPresent;
	long long _slotID;
	NSUUID* _uuid;
	NSString* _labelID;
	NSString* _label;
	NSString* _phoneNumber;
	NSNumber* _userDataPreferred;
	NSNumber* _userDefaultVoice;

}

@property (nonatomic,retain) NSString * labelID;                        //@synthesize labelID=_labelID - In the implementation block
@property (nonatomic,retain) NSString * label;                          //@synthesize label=_label - In the implementation block
@property (nonatomic,retain) NSString * phoneNumber;                    //@synthesize phoneNumber=_phoneNumber - In the implementation block
@property (nonatomic,retain) NSNumber * userDataPreferred;              //@synthesize userDataPreferred=_userDataPreferred - In the implementation block
@property (nonatomic,retain) NSNumber * userDefaultVoice;               //@synthesize userDefaultVoice=_userDefaultVoice - In the implementation block
@property (assign,nonatomic) BOOL isSimPresent;                         //@synthesize isSimPresent=_isSimPresent - In the implementation block
@property (nonatomic,readonly) long long slotID;                        //@synthesize slotID=_slotID - In the implementation block
@property (nonatomic,readonly) NSUUID * uuid;                           //@synthesize uuid=_uuid - In the implementation block
+(id)contextWithSlot:(long long)arg1 ;
+(id)contextWithUUID:(id)arg1 ;
+(BOOL)supportsSecureCoding;
-(id)initWithUUID:(id)arg1 andSlot:(long long)arg2 ;
-(BOOL)isSimPresent;
-(void)setUserDataPreferred:(NSNumber *)arg1 ;
-(void)setUserDefaultVoice:(NSNumber *)arg1 ;
-(void)setIsSimPresent:(BOOL)arg1 ;
-(void)setPhoneNumber:(NSString *)arg1 ;
-(void)setLabelID:(NSString *)arg1 ;
-(id)initWithSlot:(long long)arg1 ;
-(NSString *)labelID;
-(NSNumber *)userDataPreferred;
-(NSNumber *)userDefaultVoice;
-(BOOL)isEqual:(id)arg1 ;
-(void)encodeWithCoder:(id)arg1 ;
-(id)initWithCoder:(id)arg1 ;
-(id)description;
-(NSUUID *)uuid;
-(id)copyWithZone:(NSZone*)arg1 ;
-(id)context;
-(NSString *)label;
-(long long)slotID;
-(void)setLabel:(NSString *)arg1 ;
-(id)initWithUUID:(id)arg1 ;
-(NSString *)phoneNumber;
@end



@interface NSConcreteNotification : NSNotification {

	NSString* name;
	id object;
	NSDictionary* userInfo;
	BOOL dyingObject;
}
+(id)newTempNotificationWithName:(id)arg1 object:(id)arg2 userInfo:(id)arg3 ;
-(id)initWithName:(id)arg1 object:(id)arg2 userInfo:(id)arg3 ;
-(void)recycle;
-(void)dealloc;
-(id)userInfo;
-(id)name;
-(id)object;
@end





@interface IMHandle : NSObject <NSSecureCoding> {

	// IMAccount* _account;
	NSString* _id;
	NSString* _uncanonicalID;
	NSString* _countryCode;
	NSDictionary* _otherServiceIDs;
	NSDate* _idleSince;
	NSDate* _feedUpdatedDate;
	NSDictionary* _extraProps;
	NSDictionary* _certs;
	NSSet* _groups;
	NSString* _cnFirstName;
	NSString* _cnLastName;
	NSString* _cnFullName;
	NSString* _cnNickname;
	NSString* _displayID;
	NSString* _firstName;
	NSString* _lastName;
	NSString* _fullName;
	NSString* _nickname;
	NSArray* _emails;
	NSString* _normalizedFormOfID;
	NSString* _IDWithoutResource;
	NSString* _IDWithTrimmedServer;
	NSString* _uniqueName;
	NSData* _pictureData;
	NSString* _statusMsg;
	NSString* _processedStatusMsg;
	NSAttributedString* _richStatusMsg;
	NSDate* _whenWentOffline;
	NSDate* _whenStatusChanged;
	NSString* _prevStatusMsg;
	NSMutableArray* _notificationNameQueue;
	NSMutableArray* _notificationQueue;
	// CFPhoneNumberRef _phoneNumberRef;
	NSString* _formattedNumber;
	unsigned long long _status;
	unsigned long long _prevStatus;
	unsigned long long _capabilities;
	unsigned _authRequestStatus;
	unsigned long long _resourceIndex;
	long long _IDStatus;
	BOOL _blockNotifications;
	BOOL _hasTemporaryWatch;
	BOOL _isMobile;
	BOOL _isBot;
	BOOL _isAnonymous;
	BOOL _beingTornDown;
	BOOL _hasCheckedPhoneNumber;
	long long _priority;
	int _addressBookIdentifier;
	int _notificationQueueCount;
	NSNumber* _isBusiness;
	NSNumber* _isMako;
	NSNumber* _isApple;
	BOOL _hasSuggestedName;
	BOOL _hasCheckedForSuggestions;
	NSString* _personCentricID;
	NSString* _guid;
	// MKMapItem* _mapItem;
	NSData* _mapItemImageData;
	NSData* _mapItemBannerImageData;
	// CNContact* _cnContact;
	NSString* _suggestedName;
	NSString* _cachedDisplayNameWithAbbreviation;
	NSString* _cachedName;
}
// @property (nonatomic,retain) CNContact * cnContact;                                         //@synthesize cnContact=_cnContact - In the implementation block
@property (nonatomic,retain) NSDictionary * otherServiceIDs;                                //@synthesize otherServiceIDs=_otherServiceIDs - In the implementation block
@property (assign,nonatomic) long long priority;                                            //@synthesize priority=_priority - In the implementation block
@property (assign,nonatomic) long long IDStatus;                                            //@synthesize IDStatus=_IDStatus - In the implementation block
// @property (nonatomic,retain) MKMapItem * mapItem;                                           //@synthesize mapItem=_mapItem - In the implementation block
@property (nonatomic,retain) NSData * mapItemImageData;                                     //@synthesize mapItemImageData=_mapItemImageData - In the implementation block
@property (nonatomic,retain) NSData * mapItemBannerImageData;                               //@synthesize mapItemBannerImageData=_mapItemBannerImageData - In the implementation block
@property (nonatomic,copy) NSString * suggestedName;                                        //@synthesize suggestedName=_suggestedName - In the implementation block
@property (assign,nonatomic) BOOL hasCheckedForSuggestions;                                 //@synthesize hasCheckedForSuggestions=_hasCheckedForSuggestions - In the implementation block
@property (assign,nonatomic) BOOL hasSuggestedName;                                         //@synthesize hasSuggestedName=_hasSuggestedName - In the implementation block
@property (nonatomic,readonly) BOOL hasLocation;
@property (nonatomic,retain,readonly) NSString * _displayNameWithAbbreviation;
@property (nonatomic,retain) NSString * cachedDisplayNameWithAbbreviation;                  //@synthesize cachedDisplayNameWithAbbreviation=_cachedDisplayNameWithAbbreviation - In the implementation block
@property (nonatomic,retain) NSString * cachedName;                                         //@synthesize cachedName=_cachedName - In the implementation block
@property (nonatomic,retain,readonly) NSString * ID;                                        //@synthesize id=_id - In the implementation block
@property (nonatomic,retain,readonly) NSString * originalID;                                //@synthesize uncanonicalID=_uncanonicalID - In the implementation block
@property (nonatomic,retain,readonly) NSString * countryCode;
@property (nonatomic,retain) NSString * personCentricID;                                    //@synthesize personCentricID=_personCentricID - In the implementation block
@property (nonatomic,retain,readonly) NSString * displayID;
@property (nonatomic,retain,readonly) NSString * normalizedID;
@property (nonatomic,readonly) BOOL hasName;
@property (nonatomic,retain,readonly) NSString * name;
@property (nonatomic,retain,readonly) NSString * fullName;
@property (nonatomic,retain,readonly) NSString * uniqueName;                                //@synthesize uniqueName=_uniqueName - In the implementation block
@property (nonatomic,retain,readonly) NSString * nameAndID;
@property (nonatomic,retain,readonly) NSString * nameAndEmail;
@property (nonatomic,retain,readonly) NSString * firstName;
@property (nonatomic,retain,readonly) NSString * lastName;
@property (nonatomic,retain,readonly) NSString * nickname;
@property (nonatomic,retain,readonly) NSString * phoneticFirstName;
@property (nonatomic,retain,readonly) NSString * phoneticLastName;
@property (nonatomic,retain,readonly) NSString * phoneticFullName;
// @property (nonatomic,retain,readonly) IMAccount * account;                                  //@synthesize account=_account - In the implementation block
// @property (nonatomic,retain,readonly) IMServiceImpl * service;
@property (nonatomic,readonly) unsigned long long status;
@property (nonatomic,retain,readonly) NSString * statusMessage;
@property (nonatomic,retain,readonly) NSString * nameOfStatus;
@property (nonatomic,retain,readonly) NSAttributedString * richStatusMessage;               //@synthesize richStatusMsg=_richStatusMsg - In the implementation block
@property (nonatomic,retain,readonly) NSString * offlineString;
@property (nonatomic,readonly) unsigned long long previousStatus;                           //@synthesize prevStatus=_prevStatus - In the implementation block
@property (nonatomic,retain,readonly) NSString * previousStatusMessage;                     //@synthesize prevStatusMsg=_prevStatusMsg - In the implementation block
@property (nonatomic,readonly) double timeSinceWentOffline;
@property (nonatomic,readonly) double timeSinceStatusChanged;
@property (nonatomic,readonly) unsigned authRequestStatus;                                  //@synthesize authRequestStatus=_authRequestStatus - In the implementation block
@property (nonatomic,readonly) double idleTime;
@property (nonatomic,retain,readonly) NSString * idleString;
@property (nonatomic,retain,readonly) NSDate * feedUpdatedDate;                             //@synthesize feedUpdatedDate=_feedUpdatedDate - In the implementation block
@property (nonatomic,readonly) BOOL canBeAdded;
@property (nonatomic,readonly) BOOL canBeDeleted;
@property (nonatomic,readonly) unsigned long long capabilities;
@property (nonatomic,readonly) BOOL isBot;                                                  //@synthesize isBot=_isBot - In the implementation block
@property (nonatomic,readonly) BOOL isBuddy;
@property (nonatomic,readonly) BOOL isLoginIMHandle;
@property (nonatomic,readonly) BOOL isVisiblyBlocked;
@property (assign,setter=setBlocked:,nonatomic) BOOL isBlocked;
@property (nonatomic,readonly) BOOL isAnonymous;
@property (nonatomic,readonly) BOOL isSystemUser;
@property (nonatomic,readonly) BOOL isMobile;                                               //@synthesize isMobile=_isMobile - In the implementation block
@property (nonatomic,readonly) BOOL isLoginIMHandleForAnyAccount;
@property (nonatomic,retain,readonly) NSString * mobileDeviceName;
@property (nonatomic,readonly) BOOL watchingIMHandle;
@property (nonatomic,retain,readonly) NSData * pictureData;                                 //@synthesize pictureData=_pictureData - In the implementation block
@property (nonatomic,retain,readonly) NSDictionary * extraProperties;                       //@synthesize extraProps=_extraProps - In the implementation block
@property (nonatomic,retain,readonly) NSString * email;
@property (nonatomic,retain,readonly) NSArray * emails;
@property (nonatomic,retain,readonly) NSArray * groupsArray;
@property (nonatomic,retain,readonly) NSSet * groups;
@property (nonatomic,readonly) BOOL hasOtherSiblings;
@property (nonatomic,retain,readonly) NSSet * siblings;
@property (nonatomic,retain,readonly) NSArray * siblingsArray;
@property (nonatomic,retain,readonly) NSArray * accountSiblingsArray;
@property (nonatomic,retain,readonly) NSArray * existingAccountSiblingsArray;
@property (nonatomic,readonly) id bestSibling;
@property (nonatomic,retain,readonly) id bestAccountSibling;
@property (nonatomic,readonly) BOOL isConferenceAvailable;
@property (nonatomic,readonly) BOOL hasConferencing;
@property (nonatomic,readonly) BOOL hasVideo;
@property (nonatomic,readonly) BOOL hasMultiwayVideo;
@property (nonatomic,readonly) BOOL hasAudio;
@property (nonatomic,readonly) BOOL hasMultiwayAudio;
@property (nonatomic,retain,readonly) NSString * resource;
@property (nonatomic,retain,readonly) NSString * IDWithoutResource;
@property (nonatomic,retain,readonly) NSString * server;
@property (nonatomic,retain,readonly) NSString * accountTypeName;
@property (nonatomic,retain,readonly) NSString * guid;                                      //@synthesize guid=_guid - In the implementation block
+(void)setNotificationsEnabled:(BOOL)arg1 ;
+(BOOL)supportsSecureCoding;
+(id)imageManager;
+(id)handlesForCNContact:(id)arg1 ;
+(BOOL)notificationsEnabled;
+(id)filterIMHandlesForBestAccountSiblings:(id)arg1 ;
+(void)_loadStatusNames;
+(id)cnPhoneticKeys;
+(id)bestIMHandleInArray:(id)arg1 ;
+(id)nameOfStatus:(unsigned long long)arg1 ;
+(id)filterIMHandlesForAccountSiblings:(id)arg1 onAccount:(id)arg2 ;
+(void)bestHandlesForCNContacts:(id)arg1 useExtendedAsyncLookup:(BOOL)arg2 completion:(/*^block*/id)arg3 ;
+(void)handlesForCNContacts:(id)arg1 useBestHandle:(BOOL)arg2 useExtendedAsyncLookup:(BOOL)arg3 completion:(/*^block*/id)arg4 ;
+(void)validHandlesForCNContacts:(id)arg1 useExtendedAsyncLookup:(BOOL)arg2 completion:(/*^block*/id)arg3 ;
+(void)bestHandlesForCNContacts:(id)arg1 completion:(/*^block*/id)arg2 ;
+(void)validHandlesForCNContacts:(id)arg1 completion:(/*^block*/id)arg2 ;
-(NSString *)phoneticLastName;
// -(IMAccount *)account;
-(unsigned long long)capabilities;
-(void)setCapabilities:(unsigned long long)arg1 ;
-(void)setEmail:(NSString *)arg1 ;
-(id)init;
-(NSString *)resource;
-(BOOL)hasName;
-(void)setAnonymous:(BOOL)arg1 ;
-(unsigned long long)hash;
-(id)_contactID;
-(NSString *)nickname;
-(BOOL)isAnonymous;
-(BOOL)isApple;
-(NSString *)ID;
-(void)setPriority:(long long)arg1 ;
-(NSString *)uniqueName;
-(BOOL)isBusiness;
-(NSString *)countryCode;
-(id)displayNameForChat:(id)arg1 ;
-(id)cnContactWithKeys:(id)arg1 ;
-(long long)compareIDs:(id)arg1 ;
-(BOOL)isBot;
-(NSString *)displayID;
-(NSString *)guid;
-(NSString *)phoneticFirstName;
-(NSSet *)groups;
-(NSString *)_displayNameWithAbbreviation;
-(id)fmfSiblingHandles;
-(NSString *)nameAndID;
-(id)initWithCoder:(id)arg1 ;
-(BOOL)isMako;
-(BOOL)isBlocked;
-(NSString *)server;
-(NSString *)statusMessage;
-(NSString *)personCentricID;
-(id)fmfHandle;
-(NSString *)name;
-(BOOL)hasVideo;
-(void)scheduleSuggestedNameFetchIfNecessary;
-(void)encodeWithCoder:(id)arg1 ;
-(NSString *)suggestedName;
-(void)setBlocked:(BOOL)arg1 ;
-(NSString *)fullName;
-(BOOL)isContact;
-(void)_sendRemoteLogDumpRequest:(id)arg1 ;
-(NSString *)originalID;
// -(IMServiceImpl *)service;
-(long long)compareAccountNames:(id)arg1 ;
-(void)setPersonCentricID:(NSString *)arg1 ;
-(double)idleTime;
-(NSSet *)siblings;
-(unsigned long long)status;
-(BOOL)isBuddy;
-(NSArray *)emails;
-(NSString *)firstName;
-(void)setSuggestedName:(NSString *)arg1 ;
-(BOOL)_allowedByScreenTime;
-(NSString *)email;
-(NSString *)lastName;
-(void)setEmails:(NSArray *)arg1 ;
// -(void)setCnContact:(CNContact *)arg1 ;
// -(MKMapItem *)mapItem;
-(BOOL)matchesIMHandle:(id)arg1 ;
-(id)description;
-(BOOL)hasSuggestedName;
-(id)imHandleForOtherAccount:(id)arg1 ;
-(NSData *)mapItemImageData;
-(BOOL)isLoginIMHandle;
-(BOOL)hasAudio;
-(BOOL)hasCapability:(unsigned long long)arg1 ;
-(NSString *)phoneticFullName;
-(void)_postNotification:(id)arg1 ;
-(long long)priority;
-(void)propertiesChanged:(id)arg1 ;
-(long long)compareStatus:(id)arg1 ;
-(void)dealloc;
-(BOOL)hasServer;
-(void)setFirstName:(id)arg1 lastName:(id)arg2 ;
-(BOOL)isMobile;
-(long long)IDStatus;
-(NSData *)pictureData;
-(BOOL)_setCapabilities:(unsigned long long)arg1 ;
-(id)initWithAccount:(id)arg1 ID:(id)arg2 alreadyCanonical:(BOOL)arg3 ;
-(void)_registerForNotifications;
-(void)setImageData:(id)arg1 ;
-(NSDictionary *)extraProperties;
// -(CNContact *)cnContact;
-(void)postNotificationName:(id)arg1 ;
// -(void)setMapItem:(MKMapItem *)arg1 ;
-(BOOL)hasLocation;
-(NSString *)normalizedID;
-(void)_postNotificationName:(id)arg1 userInfo:(id)arg2 ;
-(NSData *)mapItemBannerImageData;
// -(CFPhoneNumberRef)phoneNumberRef;
-(id)copyWithZone:(NSZone*)arg1 ;
-(id)bestAccountSibling;
-(id)publicAPIPropertiesDictionary;
-(id)immediateNameWithNeedsSuggestedNameFetch:(BOOL*)arg1 useSuggestedName:(BOOL)arg2 ;
-(unsigned)authRequestStatus;
-(void)setCustomPictureData:(id)arg1 key:(id)arg2 ;
-(void)beginNotificationQueue;
-(void)releaseNotificationQueue;
-(void)_stopRetainingAccount:(id)arg1 ;
-(void)_updateOriginalID:(id)arg1 ;
-(void)_setOriginalID:(id)arg1 ;
-(BOOL)watchingIMHandle;
-(void)setHasTemporaryWatch:(BOOL)arg1 ;
-(BOOL)resetCNContact;
-(void)updateCNContact:(id)arg1 ;
-(void)statusChanged:(unsigned long long)arg1 message:(id)arg2 ;
-(void)statusChanged:(unsigned long long)arg1 ;
-(BOOL)_isChatSiblingOf:(id)arg1 ;
-(void)_fetchBusinessInfo;
-(void)_setOriginalID:(id)arg1 updateSiblings:(BOOL)arg2 ;
-(void)_setCountryCode:(id)arg1 updateSiblings:(BOOL)arg2 ;
-(id)existingChatSiblingsArray;
-(NSArray *)groupsArray;
-(id)bestIMHandleForService:(id)arg1 ;
-(BOOL)shouldQueueNotifications;
-(BOOL)areCNContactPropertiesRecent;
-(void)resetCNContactProperties;
-(void)_clearCNContactProperties;
-(BOOL)hasCheckedForSuggestions;
-(void)setHasCheckedForSuggestions:(BOOL)arg1 ;
-(void)setHasSuggestedName:(BOOL)arg1 ;
-(id)_displayNameWithContact:(id)arg1 ;
-(BOOL)_hasServiceNameProperties;
-(id)_IDWithTrimmedServer;
-(id)_displayNameWithNicknameIfAvailable;
-(id)_formattedPhoneNumber;
-(BOOL)_hasABName;
-(void)_setBaseFirstName:(id)arg1 lastName:(id)arg2 fullName:(id)arg3 ;
-(void)setFirstName:(id)arg1 lastName:(id)arg2 fullName:(id)arg3 andUpdateABPerson:(BOOL)arg4 ;
-(void)setEmail:(id)arg1 andUpdateABPerson:(BOOL)arg2 ;
-(id)_fallbackCNContactWithAllKeys;
-(void)setCachedDisplayNameWithAbbreviation:(NSString *)arg1 ;
-(void)setCachedName:(NSString *)arg1 ;
-(void)sendNotificationABPersonChanged;
-(BOOL)hasResource;
-(NSString *)IDWithoutResource;
-(NSArray *)accountSiblingsArray;
// -(void)_createPhoneNumberRefIfNeeded;
-(BOOL)isBetterThanIMHandle:(id)arg1 nonPhoneNumbersPreferred:(BOOL)arg2 ;
-(double)timeSinceWentOffline;
-(id)bestIMHandleForAccount:(id)arg1 onService:(id)arg2 inGroup:(id)arg3 otherThan:(id)arg4 ;
-(NSArray *)existingAccountSiblingsArray;
-(BOOL)isBetterThanIMHandle:(id)arg1 ;
-(void)_setExtraProperties:(id)arg1 ;
-(BOOL)_isMyIDInList:(id)arg1 ;
-(id)imHandleWithoutResource;
-(void)setStatus:(unsigned long long)arg1 message:(id)arg2 richMessage:(id)arg3 ;
-(void)_updateStatusBasedOnAuthRequestStatus;
-(double)timeSinceStatusChanged;
-(void)_filterStatusMessage;
-(void)_clearStatusMessageURLCache;
-(id)_nameForComparisonPreferFirst:(BOOL)arg1 ;
-(id)chatSiblingsArray;
-(id)_chatSiblingsArray;
-(void)customPictureDataChanged:(id)arg1 key:(id)arg2 ;
-(void)_mapItemFetchedWithMapItems:(id)arg1 error:(id)arg2 ;
-(void)_fetchMapItemImageDataForMapItem:(id)arg1 ;
-(void)_fetchMapItemBannerImageDataForMapItem:(id)arg1 ;
-(void)_postOnScreenChangedNotificationForProperty:(id)arg1 ;
-(void)_mapItemImageDataFetchedWithResultData:(id)arg1 error:(id)arg2 ;
-(void)setMapItemImageData:(NSData *)arg1 ;
-(void)_mapItemBannerImageDataFetchedWithResultData:(id)arg1 error:(id)arg2 ;
-(void)setMapItemBannerImageData:(NSData *)arg1 ;
-(id)initWithAccount:(id)arg1 ID:(id)arg2 ;
-(id)_handleInfo;
-(void)_setOriginalID:(id)arg1 countryCode:(id)arg2 updateSiblings:(BOOL)arg3 ;
-(BOOL)canBeDeleted;
-(void)setUniqueName:(NSString *)arg1 ;
-(NSString *)nameAndEmail;
-(void)resetUniqueName;
-(void)setLocalNickname:(id)arg1 ;
-(BOOL)canBeAdded;
-(BOOL)isSystemUser;
-(void)setIsMobile:(BOOL)arg1 ;
-(void)setIsBot:(BOOL)arg1 ;
-(NSString *)mobileDeviceName;
-(BOOL)isLoginIMHandleForAnyAccount;
-(void)requestValueOfProperty:(id)arg1 ;
-(void)setValue:(id)arg1 ofExtraProperty:(id)arg2 ;
-(id)bestIMHandleForAccount:(id)arg1 ;
-(id)bestSibling;
-(BOOL)isVisiblyBlocked;
-(unsigned)sortOrderInGroup:(id)arg1 ;
-(NSString *)accountTypeName;
-(id)existingIMHandleWithoutResource;
-(id)dependentIMHandles;
-(void)setAuthRequestStatus:(unsigned)arg1 ;
-(void)setPersonStatus:(unsigned long long)arg1 ;
-(void)statusMessageChanged:(id)arg1 ;
-(NSString *)nameOfStatus;
-(void)_setIDStatus:(long long)arg1 ;
-(void)setIdleSince:(id)arg1 ;
-(void)setFeedUpdatedDate:(NSDate *)arg1 ;
-(NSString *)offlineString;
-(NSString *)idleString;
-(long long)compareFirstNames:(id)arg1 ;
-(long long)compareLastNames:(id)arg1 ;
-(long long)compareNormalizedIDs:(id)arg1 ;
-(BOOL)hasOtherSiblings;
-(NSArray *)siblingsArray;
-(BOOL)isAccountSiblingOf:(id)arg1 ;
-(BOOL)isSiblingOf:(id)arg1 ;
-(id)_chatSiblings;
-(id)_bestChatSibling;
-(BOOL)hasConferencing;
-(BOOL)isConferenceAvailable;
-(BOOL)hasMultiwayVideo;
-(BOOL)hasMultiwayAudio;
-(void)_sendAutomationData:(id)arg1 properties:(id)arg2 ;
-(void)_sendCommand:(id)arg1 properties:(id)arg2 ;
-(void)_imPersonPictureChanged:(id)arg1 ;
-(id)customPictureData;
-(void)setCustomPictureData:(id)arg1 ;
-(unsigned long long)previousStatus;
-(NSString *)previousStatusMessage;
-(NSAttributedString *)richStatusMessage;
-(NSDate *)feedUpdatedDate;
-(NSDictionary *)otherServiceIDs;
-(void)setOtherServiceIDs:(NSDictionary *)arg1 ;
-(void)setIDStatus:(long long)arg1 ;
-(NSString *)cachedDisplayNameWithAbbreviation;
-(NSString *)cachedName;
-(void)_sendRemoteLogDumpRequest;
@end




@interface IMMessage : NSObject <NSCopying> {

	IMHandle* _sender;
	IMHandle* _subject;
	NSAttributedString* _text;
	NSString* _plainBody;
	NSDate* _time;
	NSDate* _timeDelivered;
	NSDate* _timeRead;
	NSDate* _timePlayed;
	NSString* _guid;
	NSAttributedString* _messageSubject;
	NSArray* _fileTransferGUIDs;
	NSError* _error;
	NSString* _balloonBundleID;
	NSData* _payloadData;
	NSString* _expressiveSendStyleID;
	NSDate* _timeExpressiveSendPlayed;
	unsigned long long _flags;
	BOOL _isInvitationMessage;
	long long _messageID;
	NSDictionary* _bizIntent;
	NSString* _locale;
	BOOL _isAddressedToMe;
	BOOL _hasMention;
	BOOL _isSOS;
	// NSString* _associatedMessageGUID;
	long long _associatedMessageType;
	NSDictionary* _messageSummaryInfo;
	NSString* _threadIdentifier;
	IMMessage* _threadOriginator;
	NSDictionary* _replyCountsByPart;
	NSString* _associatedBalloonBundleID;
	NSString* _sourceApplicationID;
	NSData* _customTypingIndicatorIcon;
	NSString* _notificationIDSTokenURI;
	unsigned long long _sortID;
	NSRange _associatedMessageRange;
}
// @property (nonatomic,readonly) BOOL isRichLinkMessage;
// // @property (nonatomic,copy,readonly) NSString * associatedMessageGUID;
// @property (nonatomic,readonly) BOOL isAssociatedMessage;
// // @property (nonatomic,readonly) long long associatedMessageType;
// // @property (nonatomic,copy,readonly) NSDictionary * messageSummaryInfo;
// // @property (setter=_updateSender:,nonatomic,retain) IMHandle * sender;                                     //@synthesize sender=_sender - In the implementation block
// // @property (setter=_updateError:,nonatomic,retain) NSError * error;                                        //@synthesize error=_error - In the implementation block
// @property (assign,setter=_updateFlags:,nonatomic) unsigned long long flags;                               //@synthesize flags=_flags - In the implementation block
// @property (setter=_updateTime:,nonatomic,retain) NSDate * time;                                           //@synthesize time=_time - In the implementation block
// @property (setter=_updateTimeRead:,nonatomic,retain) NSDate * timeRead;                                   //@synthesize timeRead=_timeRead - In the implementation block
// @property (setter=_updateTimeDelivered:,nonatomic,retain) NSDate * timeDelivered;                         //@synthesize timeDelivered=_timeDelivered - In the implementation block
// @property (setter=_updateTimePlayed:,nonatomic,retain) NSDate * timePlayed;                               //@synthesize timePlayed=_timePlayed - In the implementation block
// @property (assign,setter=_updateMessageID:,nonatomic) long long messageID;                                //@synthesize messageID=_messageID - In the implementation block
// @property (setter=_updateGUID:,nonatomic,retain) NSString * guid;                                         //@synthesize guid=_guid - In the implementation block
// // @property (setter=_associatedMessageGUID:,nonatomic,copy) NSString * associatedMessageGUID;               //@synthesize associatedMessageGUID=_associatedMessageGUID - In the implementation block
// // @property (assign,setter=_associatedMessageType:,nonatomic) long long associatedMessageType;              //@synthesize associatedMessageType=_associatedMessageType - In the implementation block
// @property (assign,setter=_associatedMessageRange:,nonatomic) NSRange associatedMessageRange;              //@synthesize associatedMessageRange=_associatedMessageRange - In the implementation block
// // @property (setter=_messageSummaryInfo:,nonatomic,copy) NSDictionary * messageSummaryInfo;                 //@synthesize messageSummaryInfo=_messageSummaryInfo - In the implementation block
// @property (setter=_updateBizIntent:,nonatomic,retain) NSDictionary * bizIntent;                           //@synthesize bizIntent=_bizIntent - In the implementation block
// @property (setter=_updateLocale:,nonatomic,retain) NSString * locale;                                     //@synthesize locale=_locale - In the implementation block
// @property (setter=_updateText:,nonatomic,retain) NSAttributedString * text;                               //@synthesize text=_text - In the implementation block
// @property (assign,nonatomic) BOOL isInvitationMessage;                                                    //@synthesize isInvitationMessage=_isInvitationMessage - In the implementation block
// // @property (nonatomic,readonly) IMMessageItem * _imMessageItem;
// @property (setter=_updateFileTransferGUIDs:,nonatomic,copy) NSArray * fileTransferGUIDs;                  //@synthesize fileTransferGUIDs=_fileTransferGUIDs - In the implementation block
// @property (assign,nonatomic) unsigned long long sortID;                                                   //@synthesize sortID=_sortID - In the implementation block
// @property (nonatomic,readonly) IMHandle * subject;                                                        //@synthesize subject=_subject - In the implementation block
// @property (nonatomic,readonly) NSAttributedString * messageSubject;                                       //@synthesize messageSubject=_messageSubject - In the implementation block
// @property (nonatomic,readonly) NSString * plainBody;
// @property (nonatomic,readonly) NSString * senderName;
// @property (nonatomic,readonly) NSString * summaryString;
// @property (nonatomic,retain) NSString * balloonBundleID;                                                  //@synthesize balloonBundleID=_balloonBundleID - In the implementation block
// @property (nonatomic,retain) NSData * payloadData;                                                        //@synthesize payloadData=_payloadData - In the implementation block
// @property (nonatomic,retain) NSString * associatedBalloonBundleID;                                        //@synthesize associatedBalloonBundleID=_associatedBalloonBundleID - In the implementation block
// @property (nonatomic,retain) NSString * sourceApplicationID;                                              //@synthesize sourceApplicationID=_sourceApplicationID - In the implementation block
// @property (nonatomic,retain) NSString * expressiveSendStyleID;                                            //@synthesize expressiveSendStyleID=_expressiveSendStyleID - In the implementation block
// @property (nonatomic,retain) NSDate * timeExpressiveSendPlayed;                                           //@synthesize timeExpressiveSendPlayed=_timeExpressiveSendPlayed - In the implementation block
// @property (nonatomic,readonly) BOOL hasInlineAttachments;
// @property (nonatomic,readonly) NSArray * inlineAttachmentAttributesArray;
// @property (nonatomic,readonly) BOOL isSent;
// @property (nonatomic,readonly) BOOL isFinished;
// @property (nonatomic,readonly) BOOL isTypingMessage;
// @property (nonatomic,readonly) BOOL isLocatingMessage;
// @property (nonatomic,readonly) BOOL isEmote;
// @property (nonatomic,readonly) BOOL isFromMe;
// @property (nonatomic,readonly) BOOL isEmpty;
// @property (nonatomic,readonly) BOOL isDelayed;
// @property (nonatomic,readonly) BOOL isAutoReply;
// @property (nonatomic,readonly) BOOL isDelivered;
// @property (nonatomic,readonly) BOOL isRead;
// @property (nonatomic,readonly) BOOL isAudioMessage;
// @property (nonatomic,readonly) BOOL isPlayed;
// @property (nonatomic,readonly) BOOL isAddressedToMe;                                                      //@synthesize isAddressedToMe=_isAddressedToMe - In the implementation block
// @property (nonatomic,readonly) BOOL isAlert;
// @property (nonatomic,readonly) BOOL isSystemMessage;
// @property (nonatomic,readonly) BOOL hasDataDetectorResults;
// @property (assign,nonatomic) BOOL hasMention;                                                             //@synthesize hasMention=_hasMention - In the implementation block
// @property (nonatomic,readonly) BOOL wasDowngraded;
// @property (nonatomic,readonly) BOOL wasDataDetected;
// @property (nonatomic,retain) NSData * customTypingIndicatorIcon;                                          //@synthesize customTypingIndicatorIcon=_customTypingIndicatorIcon - In the implementation block
// @property (nonatomic,retain) NSString * notificationIDSTokenURI;                                          //@synthesize notificationIDSTokenURI=_notificationIDSTokenURI - In the implementation block
// @property (assign,nonatomic) BOOL isSOS;                                                                  //@synthesize isSOS=_isSOS - In the implementation block
// @property (nonatomic,copy) NSString * threadIdentifier;                                                   //@synthesize threadIdentifier=_threadIdentifier - In the implementation block
// @property (nonatomic,retain) IMMessage * threadOriginator;                                                //@synthesize threadOriginator=_threadOriginator - In the implementation block
// @property (nonatomic,retain) NSDictionary * replyCountsByPart;                                            //@synthesize replyCountsByPart=_replyCountsByPart - In the implementation block
+(id)breadcrumbMessageWithText:(id)arg1 associatedMessageGUID:(id)arg2 balloonBundleID:(id)arg3 fileTransferGUIDs:(id)arg4 payloadData:(id)arg5 threadIdentifier:(id)arg6 ;
+(Class)richLinksDataSourceClass;
+(id)instantMessageWithAssociatedMessageContent:(id)arg1 flags:(unsigned long long)arg2 associatedMessageGUID:(id)arg3 associatedMessageType:(long long)arg4 associatedMessageRange:(NSRange)arg5 messageSummaryInfo:(id)arg6 threadIdentifier:(id)arg7 ;
+(id)determineRichLinksInMessage:(id)arg1 additionalSupportedSchemes:(id)arg2 ;
+(id)locatingMessageWithGuid:(id)arg1 error:(id)arg2 ;
+(id)messageWithLocation:(id)arg1 flags:(unsigned long long)arg2 error:(id)arg3 guid:(id)arg4 ;
+(id)defaultInvitationMessageFromSender:(id)arg1 flags:(unsigned long long)arg2 ;
+(id)messageFromIMMessageItem:(id)arg1 sender:(id)arg2 subject:(id)arg3 ;
+(id)instantMessageWithText:(id)arg1 messageSubject:(id)arg2 flags:(unsigned long long)arg3 threadIdentifier:(id)arg4 ;
+(id)instantMessageWithText:(id)arg1 messageSubject:(id)arg2 flags:(unsigned long long)arg3 expressiveSendStyleID:(id)arg4 threadIdentifier:(id)arg5 ;
+(id)messageFromIMMessageItemDictionary:(id)arg1 body:(id)arg2 sender:(id)arg3 subject:(id)arg4 ;
+(BOOL)hasKnownSchemesForRichLinkURL:(id)arg1 additionalSupportedSchemes:(id)arg2 ;
+(BOOL)supportedRichLinkURL:(id)arg1 additionalSupportedSchemes:(id)arg2 ;
+(id)determineRichLinksInMessage:(id)arg1 ;
+(id)instantMessageWithText:(id)arg1 flags:(unsigned long long)arg2 threadIdentifier:(id)arg3 ;
+(id)instantMessageWithText:(id)arg1 messageSubject:(id)arg2 flags:(unsigned long long)arg3 expressiveSendStyleID:(id)arg4 ;
+(id)instantMessageWithText:(id)arg1 messageSubject:(id)arg2 fileTransferGUIDs:(id)arg3 flags:(unsigned long long)arg4 threadIdentifier:(id)arg5 ;
+(id)instantMessageWithText:(id)arg1 messageSubject:(id)arg2 fileTransferGUIDs:(id)arg3 flags:(unsigned long long)arg4 balloonBundleID:(id)arg5 payloadData:(id)arg6 expressiveSendStyleID:(id)arg7 ;
+(id)fromMeIMHandle:(id)arg1 withText:(id)arg2 fileTransferGUIDs:(id)arg3 flags:(unsigned long long)arg4 ;
+(BOOL)hasKnownSchemesForRichLinkURL:(id)arg1 ;
+(id)_vCardDataWithCLLocation:(id)arg1 ;
+(id)editedMessageWithOriginalMessage:(id)arg1 originalPrefixedGUID:(id)arg2 newBody:(id)arg3 ;
-(BOOL)__ck_isAcknowledgmentMessage;
-(id)__ck_mediaObjects;
-(BOOL)__ck_isEqualToMessageUsingGUID:(id)arg1 ;
-(id)__ck_attachmentPreviewTextForAttachmentAtIndex:(long long)arg1 ;
-(id)__ck_undowngradedMessage;
-(id)__ck_service;
-(BOOL)__ck_isSMS;
-(id)__ck_previewTextWithChat:(id)arg1 ignorePluginContent:(BOOL)arg2 ;
-(id)__ck_previewTextWithChat:(id)arg1 ;
-(BOOL)__ck_isiMessage;
-(id)__ck_downgradedMessage;
-(BOOL)isFinished;
-(id)initWithSender:(id)arg1 time:(id)arg2 text:(id)arg3 messageSubject:(id)arg4 fileTransferGUIDs:(id)arg5 flags:(unsigned long long)arg6 error:(id)arg7 guid:(id)arg8 subject:(id)arg9 associatedMessageGUID:(id)arg10 associatedMessageType:(long long)arg11 associatedMessageRange:(NSRange)arg12 messageSummaryInfo:(id)arg13 threadIdentifier:(id)arg14 ;
-(BOOL)hasMention;
-(NSDate *)time;
-(unsigned long long)sortID;
-(id)initWithSender:(id)arg1 time:(id)arg2 text:(id)arg3 messageSubject:(id)arg4 fileTransferGUIDs:(id)arg5 flags:(unsigned long long)arg6 error:(id)arg7 guid:(id)arg8 subject:(id)arg9 balloonBundleID:(id)arg10 payloadData:(id)arg11 expressiveSendStyleID:(id)arg12 threadIdentifier:(id)arg13 ;
-(NSString *)expressiveSendStyleID;
-(void)setThreadIdentifier:(NSString *)arg1 ;
-(NSDictionary *)bizIntent;
-(BOOL)isSOS;
-(void)setBalloonBundleID:(NSString *)arg1 ;
-(long long)associatedMessageType;
-(NSString *)guid;
-(BOOL)isRead;
-(BOOL)hasDataDetectorResults;
-(BOOL)wasDowngraded;
-(id)_copyWithFlags:(unsigned long long)arg1 ;
-(void)setIsSOS:(BOOL)arg1 ;
-(id)messagesBySeparatingRichLinks;
-(void)_updateSender:(id)arg1 ;
-(void)setPayloadData:(NSData *)arg1 ;
-(NSDictionary *)messageSummaryInfo;
-(BOOL)isPlayed;
-(BOOL)isDelivered;
-(IMHandle *)sender;
-(void)setAssociatedBalloonBundleID:(NSString *)arg1 ;
// -(IMBalloonPluginDataSource *)richLinkDataSource;
-(NSError *)error;
-(NSArray *)fileTransferGUIDs;
-(NSAttributedString *)messageSubject;
-(BOOL)isEmote;
-(NSString *)threadIdentifier;
-(NSRange)associatedMessageRange;
-(NSString *)plainBody;
-(NSString *)locale;
-(BOOL)isAlert;
-(BOOL)isTypingMessage;
-(void)setSortID:(unsigned long long)arg1 ;
-(void)setExpressiveSendStyleID:(NSString *)arg1 ;
-(BOOL)isDelayed;
-(NSDate *)timeRead;
-(NSDate *)timePlayed;
-(BOOL)isAudioMessage;
-(BOOL)isFromMe;
-(NSDate *)timeDelivered;
-(BOOL)isEqual:(id)arg1 ;
-(long long)messageID;
-(IMHandle *)subject;
-(BOOL)isLocatingMessage;
-(NSDate *)timeExpressiveSendPlayed;
-(BOOL)isEmpty;
-(NSString *)associatedBalloonBundleID;
-(id)description;
-(long long)compare:(id)arg1 comparisonType:(long long)arg2 ;
-(void)setThreadOriginator:(IMMessage *)arg1 ;
-(IMMessage *)threadOriginator;
-(NSString *)associatedMessageGUID;
// -(IMMessageItem *)_imMessageItem;
-(NSString *)summaryString;
-(long long)compare:(id)arg1 ;
-(BOOL)isRichLinkMessage;
-(NSAttributedString *)text;
-(NSData *)payloadData;
-(BOOL)isReply;
-(id)initWithSender:(id)arg1 time:(id)arg2 text:(id)arg3 fileTransferGUIDs:(id)arg4 flags:(unsigned long long)arg5 error:(id)arg6 guid:(id)arg7 subject:(id)arg8 threadIdentifier:(id)arg9 ;
-(NSString *)balloonBundleID;
-(unsigned long long)flags;
-(BOOL)isSent;
-(void)setTimeExpressiveSendPlayed:(NSDate *)arg1 ;
-(NSString *)notificationIDSTokenURI;
-(void)setNotificationIDSTokenURI:(NSString *)arg1 ;
-(NSDictionary *)replyCountsByPart;
-(void)setReplyCountsByPart:(NSDictionary *)arg1 ;
-(void)_updateFlags:(unsigned long long)arg1 ;
-(BOOL)wasDataDetected;
-(id)copyWithZone:(NSZone*)arg1 ;
-(NSString *)senderName;
-(id)descriptionForPurpose:(long long)arg1 inChat:(id)arg2 ;
-(id)descriptionForPurpose:(long long)arg1 ;
-(id)descriptionForPurpose:(long long)arg1 inChat:(id)arg2 senderDisplayName:(id)arg3 ;
-(id)initWithSender:(id)arg1 time:(id)arg2 text:(id)arg3 messageSubject:(id)arg4 fileTransferGUIDs:(id)arg5 flags:(unsigned long long)arg6 error:(id)arg7 guid:(id)arg8 subject:(id)arg9 threadIdentifier:(id)arg10 ;
-(NSString *)sourceApplicationID;
-(void)setSourceApplicationID:(NSString *)arg1 ;
-(BOOL)isSystemMessage;
-(void)_updateBizIntent:(id)arg1 ;
-(void)_updateLocale:(id)arg1 ;
-(void)_updateGUID:(id)arg1 ;
-(void)_updateFileTransferGUIDs:(id)arg1 ;
-(void)setCustomTypingIndicatorIcon:(NSData *)arg1 ;
-(id)_initWithSender:(id)arg1 time:(id)arg2 timeRead:(id)arg3 timeDelivered:(id)arg4 timePlayed:(id)arg5 plainText:(id)arg6 text:(id)arg7 messageSubject:(id)arg8 fileTransferGUIDs:(id)arg9 flags:(unsigned long long)arg10 error:(id)arg11 guid:(id)arg12 messageID:(long long)arg13 subject:(id)arg14 balloonBundleID:(id)arg15 payloadData:(id)arg16 expressiveSendStyleID:(id)arg17 timeExpressiveSendPlayed:(id)arg18 associatedMessageGUID:(id)arg19 associatedMessageType:(long long)arg20 associatedMessageRange:(NSRange)arg21 messageSummaryInfo:(id)arg22 threadIdentifier:(id)arg23 ;
-(void)_updateTime:(id)arg1 ;
-(void)_updateTimeRead:(id)arg1 ;
-(void)_updateTimeDelivered:(id)arg1 ;
-(void)_updateTimePlayed:(id)arg1 ;
-(void)_updateMessageID:(long long)arg1 ;
-(void)_associatedMessageGUID:(id)arg1 ;
-(void)_associatedMessageType:(long long)arg1 ;
-(void)_associatedMessageRange:(NSRange)arg1 ;
-(void)_messageSummaryInfo:(id)arg1 ;
-(BOOL)hasInlineAttachments;
-(BOOL)isInvitationMessage;
-(BOOL)isAddressedToMe;
-(id)initWithSender:(id)arg1 time:(id)arg2 text:(id)arg3 messageSubject:(id)arg4 fileTransferGUIDs:(id)arg5 flags:(unsigned long long)arg6 error:(id)arg7 guid:(id)arg8 subject:(id)arg9 ;
-(id)initWithSender:(id)arg1 time:(id)arg2 text:(id)arg3 fileTransferGUIDs:(id)arg4 flags:(unsigned long long)arg5 error:(id)arg6 guid:(id)arg7 subject:(id)arg8 ;
-(id)initWithSender:(id)arg1 time:(id)arg2 text:(id)arg3 messageSubject:(id)arg4 fileTransferGUIDs:(id)arg5 flags:(unsigned long long)arg6 error:(id)arg7 guid:(id)arg8 subject:(id)arg9 balloonBundleID:(id)arg10 payloadData:(id)arg11 expressiveSendStyleID:(id)arg12 ;
-(id)initWithSender:(id)arg1 time:(id)arg2 text:(id)arg3 messageSubject:(id)arg4 fileTransferGUIDs:(id)arg5 flags:(unsigned long long)arg6 error:(id)arg7 guid:(id)arg8 subject:(id)arg9 associatedMessageGUID:(id)arg10 associatedMessageType:(long long)arg11 associatedMessageRange:(NSRange)arg12 messageSummaryInfo:(id)arg13 ;
-(id)initWithSender:(id)arg1 fileTransfer:(id)arg2 ;
-(NSArray *)inlineAttachmentAttributesArray;
-(BOOL)isAutoReply;
-(void)_ovverrideGUIDForTest:(id)arg1 ;
-(void)_updateText:(id)arg1 ;
-(void)_updateError:(id)arg1 ;
-(void)setIsInvitationMessage:(BOOL)arg1 ;
-(void)setHasMention:(BOOL)arg1 ;
-(NSData *)customTypingIndicatorIcon;
-(BOOL)isAssociatedMessage;
-(id)initWithSender:(id)arg1 time:(id)arg2 text:(id)arg3 messageSubject:(id)arg4 fileTransferGUIDs:(id)arg5 flags:(unsigned long long)arg6 error:(id)arg7 guid:(id)arg8 subject:(id)arg9 associatedMessageGUID:(id)arg10 associatedMessageType:(long long)arg11 associatedMessageRange:(NSRange)arg12 associatedMessageInfo:(id)arg13 ;
@end

//Peacock

typedef NS_ENUM(UInt8, IMChatStyle) {
    IMChatStyleInstantMessage = '-',
    IMChatStyleGroup          = '+'
};

@class IMItem;


@protocol IMDaemonListenerProtocol
- (void) account:(NSString *)accountUniqueID chat:(NSString *)chatIdentifier style:(IMChatStyle)chatStyle chatProperties:(NSDictionary *)properties groupID:(NSString *)groupID chatPersonCentricID:(NSString *) personCentricID messageReceived:(IMItem *)msg;
- (void) account:(NSString *)accountUniqueID chat:(NSString *)chatIdentifier style:(IMChatStyle)chatStyle chatProperties:(NSDictionary *)properties groupID:(NSString *)groupID chatPersonCentricID:(NSString *) personCentricID messagesReceived:(NSArray<IMItem *> *)messages messagesComingFromStorage:(BOOL)fromStorage;
- (void) account:(NSString *)accountUniqueID chat:(NSString *)chatIdentifier style:(IMChatStyle)chatStyle chatProperties:(NSDictionary *)properties groupID:(NSString *)groupID chatPersonCentricID:(NSString *) personCentricID messagesReceived:(NSArray<IMItem *> *)messages;
@end

@interface IMDaemonListener
- (void)addHandler:(id)handler;
@end

@class IMDaemonController;

@interface IMDaemonController
- (Class) class;

- (IMDaemonController *)sharedController;
- (IMDaemonController *)sharedInstance;
- (IMDaemonListener *)listener;
- (BOOL)connectToDaemonWithLaunch:(BOOL)arg1 capabilities:(unsigned int)arg2 blockUntilConnected:(BOOL)arg3;
- (BOOL)addListenerID:(NSString *)arg1 capabilities:(unsigned int)arg2;
@end




@class IMSystemMonitorListener;

@interface IDSPhoneNumberValidationStateMachine : NSObject <IMDaemonListenerProtocol>

- (Class) class;

// @property(readonly, nonatomic) long long status; // @synthesize status=_status;
// @property(copy, nonatomic) IDSPreflightStack *currentPreflightStack; // @synthesize currentPreflightStack=_currentPreflightStack;
// // @property(copy, nonatomic) CDUnknownBlockType inFlightSMSTimeoutBlock; // @synthesize inFlightSMSTimeoutBlock=_inFlightSMSTimeoutBlock;
// // @property(copy, nonatomic) CDUnknownBlockType inFlightHeartbeatBlock; // @synthesize inFlightHeartbeatBlock=_inFlightHeartbeatBlock;
// @property(retain, nonatomic) IDSSystemAccountAdapter *systemAccountAdapter; // @synthesize systemAccountAdapter=_systemAccountAdapter;
// @property(retain, nonatomic) id <IDSPhoneNumberValidationStateMachineDeviceSupport> deviceSupport; // @synthesize deviceSupport=_deviceSupport;
// @property(retain, nonatomic) IDSPhoneNumberValidationModeArbiter *arbiter; // @synthesize arbiter=_arbiter;
// @property(retain, nonatomic) id <IDSPhoneNumberValidationStateMachineLockdownManager> lockdownManager; // @synthesize lockdownManager=_lockdownManager;
// @property(retain, nonatomic) id <IDSPhoneNumberValidationStateMachineMessageDelivery> httpMessageDelivery; // @synthesize httpMessageDelivery=_httpMessageDelivery;
// - (void).cxx_destruct;	// IMP=0x00000001002109d4
- (void)persistNumberOfPreflightAttempts:(unsigned int)arg1;	// IMP=0x00000001002108a4
- (unsigned int)loadNumberOfPreflightAttempts;	// IMP=0x0000000100210880
- (void)persistNumberOfSuccessfulValidationSends:(unsigned int)arg1;	// IMP=0x0000000100210868
- (unsigned int)loadNumberOfSuccessfulValidationSends;	// IMP=0x0000000100210844
- (void)_resetCarrierShortcodeSupportedCachedValue;	// IMP=0x0000000100210758
- (void)operatorBundleChange:(id)arg1;	// IMP=0x0000000100210660
- (void)carrierBundleChange:(id)arg1;	// IMP=0x0000000100210568
- (void)pnrResponseReceived:(id)arg1 pnrRspData:(id)arg2;	// IMP=0x0000000100210154
- (void)pnrRequestSent:(id)arg1 pnrReqData:(id)arg2;	// IMP=0x000000010020fdf8
- (void)heartbeat;	// IMP=0x000000010020f828
- (void)removePhoneNumberValidationRequestor:(id)arg1;	// IMP=0x000000010020f664
- (id)identifyPhoneNumberForRequestor:(id)arg1 queue:(id)arg2;	// IMP=0x000000010020f584
- (void)addPhoneNumberValidationRequestor:(id)arg1;	// IMP=0x000000010020f42c
- (void)removeListener:(id)arg1;	// IMP=0x000000010020f414
- (void)addListener:(id)arg1;	// IMP=0x000000010020f378
- (void)timedOutWaitingForSMS;	// IMP=0x000000010020f194
- (void)resetSMSCounter;	// IMP=0x000000010020efe8
- (void)handleIncomingSMSForPhoneNumber:(id)arg1 signature:(id)arg2;	// IMP=0x000000010020e640
- (void)handleRegistrationSMSSuccessfullyDeliveredWithTelephonyTimeout:(id)arg1;	// IMP=0x000000010020e174
- (void)handleRegistrationSMSDeliveryFailedWithShouldBypassRetry:(_Bool)arg1;	// IMP=0x000000010020db10
- (void)handleRegistrationSMSDeliveryFailed;	// IMP=0x000000010020db00
- (void)_checkRegistrationStatus;	// IMP=0x000000010020ce78
// - (void)_requestUserConsentForPhoneNumberValidationWithCompletion:(CDUnknownBlockType)arg1;	// IMP=0x000000010020cd40
- (void)_tryToSendSMSIdentification;	// IMP=0x000000010020bfa8


- (void)_sendPreflightVerificationWithIMSI:(id)arg1 PLMN:(id)arg2;	// IMP=0x000000010020b604

//^^^^^^^^^ OVERRIDE THIS MAYBE!! Maybe override it with the Android phone's IMSI



- (void)_performHighestPriorityPreflightVerification;	// IMP=0x000000010020b550


- (void)_popHighestPriorityPreflightVerification;	// IMP=0x000000010020b494
- (void)_sendPreflightVerificationIfNeeded;	// IMP=0x000000010020b214
- (void)_sendSMSVerificationWithMechanism:(id)arg1;	// IMP=0x000000010020af00
- (void)_issueAsyncCoreTelephonyPhoneNumberValidationRequestWithPushToken:(id)arg1 mechanism:(id)arg2;	// IMP=0x000000010020a634
- (id)_telephonyRequestForPushToken:(id)arg1 phoneNumberValidationMechanism:(id)arg2;	// IMP=0x000000010020a324 //MAYBE CHANGE THIS???
- (void)_setSMSDeliveryTimeout:(double)arg1;	// IMP=0x000000010020a138
- (_Bool)_canDeliverSMSNow;	// IMP=0x000000010020a120
- (void)_smsDeliveryClear;	// IMP=0x0000000100209f58
- (void)_clearSMSDeliveryTimeout;	// IMP=0x0000000100209f1c
- (void)_keychainMigrationComplete:(id)arg1;	// IMP=0x0000000100209e38
- (void)systemRestoreStateDidChange;	// IMP=0x0000000100209d54
- (void)systemDidStopBackup;	// IMP=0x0000000100209c70
- (void)systemDidFinishMigration;	// IMP=0x0000000100209ae8
- (void)_deviceIDChangedNotification:(id)arg1;	// IMP=0x00000001002099b8
- (void)_registrationStateChangedNotification:(id)arg1;	// IMP=0x0000000100209770
- (void)_registerForLockdownNotifications;	// IMP=0x0000000100209650
- (void)_lockdownStateChanged:(id)arg1;	// IMP=0x00000001002094fc
- (_Bool)_deviceCanRegisterPresently;	// IMP=0x000000010020932c
- (long long)_errorCodeForRegistrationError:(long long)arg1;	// IMP=0x00000001002092bc
- (void)_failPromisesWithError:(long long)arg1;	// IMP=0x0000000100209124
- (void)_fulfillPromisesWithPhoneNumber:(id)arg1 token:(id)arg2;	// IMP=0x0000000100208f7c
- (void)_notifySuccess:(id)arg1 token:(id)arg2;	// IMP=0x00000001002089c0
- (void)_notifyFailureWithError:(long long)arg1;	// IMP=0x0000000100208598
- (void)_notifyNeedsNewIdentification;	// IMP=0x00000001002083c0
- (void)_SIMSetupDidComplete;	// IMP=0x00000001002083ac
- (_Bool)_isUserSubscriptionSelectionStillPending;	// IMP=0x0000000100208138
- (_Bool)_isAwaitingUserSelectionDuringSetup;	// IMP=0x0000000100207f68
- (_Bool)_userHasDisabledSMSRegistration;	// IMP=0x0000000100207d6c
- (long long)_registrationControlStatus;	// IMP=0x0000000100207d10
- (_Bool)carrierSupportsShortCode;	// IMP=0x0000000100207b58
- (void)_registerForDeviceCenterNotifications;	// IMP=0x0000000100207a94
- (void)dealloc;	// IMP=0x000000010020794c
- (id)init;	// IMP=0x0000000100207810
- (id)initWithHTTPDelivery:(id)arg1 lockdownManager:(id)arg2 arbiter:(id)arg3 deviceSupport:(id)arg4 systemAccountAdapter:(id)arg5;	// IMP=0x0000000100207090
- (void)_cancelScheduledSMSTimeout;	// IMP=0x0000000100207004
- (void)_scheduleSMSTimeout:(double)arg1;	// IMP=0x0000000100206f24
- (void)_cancelScheduledHeartbeat;	// IMP=0x0000000100206e98
- (void)_scheduleHeartbeat:(double)arg1;	// IMP=0x0000000100206ce4
@property(readonly, copy) NSString *debugDescription;
- (_Bool)_isPhoneNumberIdentificationSupported;	// IMP=0x0000000100206b08

// Remaining properties
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end



@interface IMMessageItem

@end


extern IDSPhoneNumberValidationStateMachine * _Nullable pnrStateMachine;



@interface IMChat
    -(NSString *)chatIdentifier;
    -(NSAttributedString *)text;
    -(NSString *)guid;


@end



/* How to Hook with Logos
Hooks are written with syntax similar to that of an Objective-C @implementation.
You don't need to #include <substrate.h>, it will be done automatically, as will
the generation of a class list and an automatic constructor.

%hook ClassName

// Hooking a class method
+ (id)sharedInstance {
	return %orig;
}

// Hooking an instance method with an argument.
- (void)messageName:(int)argument {
	%log; // Write a message about this call, including its class, name and arguments, to the system log.

	%orig; // Call through to the original function with its original arguments.
	%orig(nil); // Call through to the original function with a custom argument.

	// If you use %orig(), you MUST supply all arguments (except for self and _cmd, the automatically generated ones.)
}

// Hooking an instance method with no arguments.
- (id)noArguments {
	%log;
	id awesome = %orig;
	[awesome doSomethingElse];

	return awesome;
}

// Always make sure you clean up after yourself; Not doing so could have grave consequences!
%end
*/
