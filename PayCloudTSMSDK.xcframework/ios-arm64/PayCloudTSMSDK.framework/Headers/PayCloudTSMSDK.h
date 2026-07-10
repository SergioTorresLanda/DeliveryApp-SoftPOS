#import <Foundation/NSArray.h>
#import <Foundation/NSDictionary.h>
#import <Foundation/NSError.h>
#import <Foundation/NSObject.h>
#import <Foundation/NSSet.h>
#import <Foundation/NSString.h>
#import <Foundation/NSValue.h>

@class PCTSMSDKAddCardRequest, PCTSMSDKAddCardRequestCompanion, PCTSMSDKAddCardResponse, PCTSMSDKAddCardResponseCompanion, PCTSMSDKApduCommand, PCTSMSDKApduCommandCompanion, PCTSMSDKBillingAddress, PCTSMSDKBillingAddressCompanion, PCTSMSDKConfirmProvisioningRequest, PCTSMSDKConfirmProvisioningRequestCompanion, PCTSMSDKConfirmProvisioningResponse, PCTSMSDKConfirmProvisioningResponseCompanion, PCTSMSDKCredentialInfo, PCTSMSDKCredentialStatus, PCTSMSDKDeviceRegistrationRequest, PCTSMSDKDeviceRegistrationRequestCompanion, PCTSMSDKIdvMethodInfo, PCTSMSDKIdvMethodInfoCompanion, PCTSMSDKInitiateIdvRequest, PCTSMSDKInitiateIdvRequestCompanion, PCTSMSDKInitiateIdvResponse, PCTSMSDKInitiateIdvResponseCompanion, PCTSMSDKKotlinArray<T>, PCTSMSDKKotlinByteArray, PCTSMSDKKotlinByteIterator, PCTSMSDKKotlinEnum<E>, PCTSMSDKKotlinEnumCompanion, PCTSMSDKKotlinException, PCTSMSDKKotlinIllegalStateException, PCTSMSDKKotlinNothing, PCTSMSDKKotlinRuntimeException, PCTSMSDKKotlinThrowable, PCTSMSDKKotlinx_serialization_coreSerialKind, PCTSMSDKKotlinx_serialization_coreSerializersModule, PCTSMSDKNetworkConfig, PCTSMSDKPersonalizationData, PCTSMSDKPersonalizationDataCompanion, PCTSMSDKResendOtpRequest, PCTSMSDKResendOtpRequestCompanion, PCTSMSDKResendOtpResponse, PCTSMSDKResendOtpResponseCompanion, PCTSMSDKSecureChannel, PCTSMSDKSecureElementInfo, PCTSMSDKSecureElementInfoCompanion, PCTSMSDKSecureSession, PCTSMSDKTokenInfo, PCTSMSDKTokenInfoCompanion, PCTSMSDKTokenLifecycleRequest, PCTSMSDKTokenLifecycleRequestCompanion, PCTSMSDKTokenLifecycleResponse, PCTSMSDKTokenLifecycleResponseCompanion, PCTSMSDKVerifyIdvRequest, PCTSMSDKVerifyIdvRequestCompanion, PCTSMSDKVerifyIdvResponse, PCTSMSDKVerifyIdvResponseCompanion;

@protocol PCTSMSDKAuthTokenProvider, PCTSMSDKKotlinAnnotation, PCTSMSDKKotlinComparable, PCTSMSDKKotlinIterator, PCTSMSDKKotlinKAnnotatedElement, PCTSMSDKKotlinKClass, PCTSMSDKKotlinKClassifier, PCTSMSDKKotlinKDeclarationContainer, PCTSMSDKKotlinx_coroutines_coreFlow, PCTSMSDKKotlinx_coroutines_coreFlowCollector, PCTSMSDKKotlinx_serialization_coreCompositeDecoder, PCTSMSDKKotlinx_serialization_coreCompositeEncoder, PCTSMSDKKotlinx_serialization_coreDecoder, PCTSMSDKKotlinx_serialization_coreDeserializationStrategy, PCTSMSDKKotlinx_serialization_coreEncoder, PCTSMSDKKotlinx_serialization_coreKSerializer, PCTSMSDKKotlinx_serialization_coreSerialDescriptor, PCTSMSDKKotlinx_serialization_coreSerializationStrategy, PCTSMSDKKotlinx_serialization_coreSerializersModuleCollector, PCTSMSDKNetworkClient;

NS_ASSUME_NONNULL_BEGIN
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunknown-warning-option"
#pragma clang diagnostic ignored "-Wincompatible-property-type"
#pragma clang diagnostic ignored "-Wnullability"

#pragma push_macro("_Nullable_result")
#if !__has_feature(nullability_nullable_result)
#undef _Nullable_result
#define _Nullable_result _Nullable
#endif

__attribute__((swift_name("KotlinBase")))
@interface PCTSMSDKBase : NSObject
- (instancetype)init __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
+ (void)initialize __attribute__((objc_requires_super));
@end

@interface PCTSMSDKBase (PCTSMSDKBaseCopying) <NSCopying>
@end

__attribute__((swift_name("KotlinMutableSet")))
@interface PCTSMSDKMutableSet<ObjectType> : NSMutableSet<ObjectType>
@end

__attribute__((swift_name("KotlinMutableDictionary")))
@interface PCTSMSDKMutableDictionary<KeyType, ObjectType> : NSMutableDictionary<KeyType, ObjectType>
@end

@interface NSError (NSErrorPCTSMSDKKotlinException)
@property (readonly) id _Nullable kotlinException;
@end

__attribute__((swift_name("KotlinNumber")))
@interface PCTSMSDKNumber : NSNumber
- (instancetype)initWithChar:(char)value __attribute__((unavailable));
- (instancetype)initWithUnsignedChar:(unsigned char)value __attribute__((unavailable));
- (instancetype)initWithShort:(short)value __attribute__((unavailable));
- (instancetype)initWithUnsignedShort:(unsigned short)value __attribute__((unavailable));
- (instancetype)initWithInt:(int)value __attribute__((unavailable));
- (instancetype)initWithUnsignedInt:(unsigned int)value __attribute__((unavailable));
- (instancetype)initWithLong:(long)value __attribute__((unavailable));
- (instancetype)initWithUnsignedLong:(unsigned long)value __attribute__((unavailable));
- (instancetype)initWithLongLong:(long long)value __attribute__((unavailable));
- (instancetype)initWithUnsignedLongLong:(unsigned long long)value __attribute__((unavailable));
- (instancetype)initWithFloat:(float)value __attribute__((unavailable));
- (instancetype)initWithDouble:(double)value __attribute__((unavailable));
- (instancetype)initWithBool:(BOOL)value __attribute__((unavailable));
- (instancetype)initWithInteger:(NSInteger)value __attribute__((unavailable));
- (instancetype)initWithUnsignedInteger:(NSUInteger)value __attribute__((unavailable));
+ (instancetype)numberWithChar:(char)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedChar:(unsigned char)value __attribute__((unavailable));
+ (instancetype)numberWithShort:(short)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedShort:(unsigned short)value __attribute__((unavailable));
+ (instancetype)numberWithInt:(int)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedInt:(unsigned int)value __attribute__((unavailable));
+ (instancetype)numberWithLong:(long)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedLong:(unsigned long)value __attribute__((unavailable));
+ (instancetype)numberWithLongLong:(long long)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedLongLong:(unsigned long long)value __attribute__((unavailable));
+ (instancetype)numberWithFloat:(float)value __attribute__((unavailable));
+ (instancetype)numberWithDouble:(double)value __attribute__((unavailable));
+ (instancetype)numberWithBool:(BOOL)value __attribute__((unavailable));
+ (instancetype)numberWithInteger:(NSInteger)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedInteger:(NSUInteger)value __attribute__((unavailable));
@end

__attribute__((swift_name("KotlinByte")))
@interface PCTSMSDKByte : PCTSMSDKNumber
- (instancetype)initWithChar:(char)value;
+ (instancetype)numberWithChar:(char)value;
@end

__attribute__((swift_name("KotlinUByte")))
@interface PCTSMSDKUByte : PCTSMSDKNumber
- (instancetype)initWithUnsignedChar:(unsigned char)value;
+ (instancetype)numberWithUnsignedChar:(unsigned char)value;
@end

__attribute__((swift_name("KotlinShort")))
@interface PCTSMSDKShort : PCTSMSDKNumber
- (instancetype)initWithShort:(short)value;
+ (instancetype)numberWithShort:(short)value;
@end

__attribute__((swift_name("KotlinUShort")))
@interface PCTSMSDKUShort : PCTSMSDKNumber
- (instancetype)initWithUnsignedShort:(unsigned short)value;
+ (instancetype)numberWithUnsignedShort:(unsigned short)value;
@end

__attribute__((swift_name("KotlinInt")))
@interface PCTSMSDKInt : PCTSMSDKNumber
- (instancetype)initWithInt:(int)value;
+ (instancetype)numberWithInt:(int)value;
@end

__attribute__((swift_name("KotlinUInt")))
@interface PCTSMSDKUInt : PCTSMSDKNumber
- (instancetype)initWithUnsignedInt:(unsigned int)value;
+ (instancetype)numberWithUnsignedInt:(unsigned int)value;
@end

__attribute__((swift_name("KotlinLong")))
@interface PCTSMSDKLong : PCTSMSDKNumber
- (instancetype)initWithLongLong:(long long)value;
+ (instancetype)numberWithLongLong:(long long)value;
@end

__attribute__((swift_name("KotlinULong")))
@interface PCTSMSDKULong : PCTSMSDKNumber
- (instancetype)initWithUnsignedLongLong:(unsigned long long)value;
+ (instancetype)numberWithUnsignedLongLong:(unsigned long long)value;
@end

__attribute__((swift_name("KotlinFloat")))
@interface PCTSMSDKFloat : PCTSMSDKNumber
- (instancetype)initWithFloat:(float)value;
+ (instancetype)numberWithFloat:(float)value;
@end

__attribute__((swift_name("KotlinDouble")))
@interface PCTSMSDKDouble : PCTSMSDKNumber
- (instancetype)initWithDouble:(double)value;
+ (instancetype)numberWithDouble:(double)value;
@end

__attribute__((swift_name("KotlinBoolean")))
@interface PCTSMSDKBoolean : PCTSMSDKNumber
- (instancetype)initWithBool:(BOOL)value;
+ (instancetype)numberWithBool:(BOOL)value;
@end

__attribute__((swift_name("AuthTokenProvider")))
@protocol PCTSMSDKAuthTokenProvider
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getValidTokenWithCompletionHandler:(void (^)(NSString * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getValidToken(completionHandler:)")));
@end

__attribute__((swift_name("NetworkClient")))
@protocol PCTSMSDKNetworkClient
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)addCardRequest:(PCTSMSDKAddCardRequest *)request completionHandler:(void (^)(PCTSMSDKAddCardResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("addCard(request:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)confirmProvisioningTokenId:(NSString *)tokenId request:(PCTSMSDKConfirmProvisioningRequest *)request completionHandler:(void (^)(PCTSMSDKConfirmProvisioningResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("confirmProvisioning(tokenId:request:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)deleteTokenTokenId:(NSString *)tokenId request:(PCTSMSDKTokenLifecycleRequest *)request completionHandler:(void (^)(PCTSMSDKTokenLifecycleResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("deleteToken(tokenId:request:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)initiateIdvRequest:(PCTSMSDKInitiateIdvRequest *)request completionHandler:(void (^)(PCTSMSDKInitiateIdvResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("initiateIdv(request:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)registerDeviceRequest:(PCTSMSDKDeviceRegistrationRequest *)request completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("registerDevice(request:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)resendOtpRequest:(PCTSMSDKResendOtpRequest *)request completionHandler:(void (^)(PCTSMSDKResendOtpResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("resendOtp(request:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)resumeTokenTokenId:(NSString *)tokenId request:(PCTSMSDKTokenLifecycleRequest *)request completionHandler:(void (^)(PCTSMSDKTokenLifecycleResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("resumeToken(tokenId:request:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)suspendTokenTokenId:(NSString *)tokenId request:(PCTSMSDKTokenLifecycleRequest *)request completionHandler:(void (^)(PCTSMSDKTokenLifecycleResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("suspendToken(tokenId:request:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)verifyIdvRequest:(PCTSMSDKVerifyIdvRequest *)request completionHandler:(void (^)(PCTSMSDKVerifyIdvResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("verifyIdv(request:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("IOSNetworkClient")))
@interface PCTSMSDKIOSNetworkClient : PCTSMSDKBase <PCTSMSDKNetworkClient>
- (instancetype)initWithConfig:(PCTSMSDKNetworkConfig *)config authTokenProvider:(id<PCTSMSDKAuthTokenProvider>)authTokenProvider __attribute__((swift_name("init(config:authTokenProvider:)"))) __attribute__((objc_designated_initializer));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)addCardRequest:(PCTSMSDKAddCardRequest *)request completionHandler:(void (^)(PCTSMSDKAddCardResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("addCard(request:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)confirmProvisioningTokenId:(NSString *)tokenId request:(PCTSMSDKConfirmProvisioningRequest *)request completionHandler:(void (^)(PCTSMSDKConfirmProvisioningResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("confirmProvisioning(tokenId:request:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)deleteTokenTokenId:(NSString *)tokenId request:(PCTSMSDKTokenLifecycleRequest *)request completionHandler:(void (^)(PCTSMSDKTokenLifecycleResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("deleteToken(tokenId:request:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)initiateIdvRequest:(PCTSMSDKInitiateIdvRequest *)request completionHandler:(void (^)(PCTSMSDKInitiateIdvResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("initiateIdv(request:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)registerDeviceRequest:(PCTSMSDKDeviceRegistrationRequest *)request completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("registerDevice(request:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)resendOtpRequest:(PCTSMSDKResendOtpRequest *)request completionHandler:(void (^)(PCTSMSDKResendOtpResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("resendOtp(request:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)resumeTokenTokenId:(NSString *)tokenId request:(PCTSMSDKTokenLifecycleRequest *)request completionHandler:(void (^)(PCTSMSDKTokenLifecycleResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("resumeToken(tokenId:request:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)suspendTokenTokenId:(NSString *)tokenId request:(PCTSMSDKTokenLifecycleRequest *)request completionHandler:(void (^)(PCTSMSDKTokenLifecycleResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("suspendToken(tokenId:request:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)verifyIdvRequest:(PCTSMSDKVerifyIdvRequest *)request completionHandler:(void (^)(PCTSMSDKVerifyIdvResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("verifyIdv(request:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KtorNetworkClient")))
@interface PCTSMSDKKtorNetworkClient : PCTSMSDKBase <PCTSMSDKNetworkClient>

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)addCardRequest:(PCTSMSDKAddCardRequest *)request completionHandler:(void (^)(PCTSMSDKAddCardResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("addCard(request:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)confirmProvisioningTokenId:(NSString *)tokenId request:(PCTSMSDKConfirmProvisioningRequest *)request completionHandler:(void (^)(PCTSMSDKConfirmProvisioningResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("confirmProvisioning(tokenId:request:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)deleteTokenTokenId:(NSString *)tokenId request:(PCTSMSDKTokenLifecycleRequest *)request completionHandler:(void (^)(PCTSMSDKTokenLifecycleResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("deleteToken(tokenId:request:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)initiateIdvRequest:(PCTSMSDKInitiateIdvRequest *)request completionHandler:(void (^)(PCTSMSDKInitiateIdvResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("initiateIdv(request:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)registerDeviceRequest:(PCTSMSDKDeviceRegistrationRequest *)request completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("registerDevice(request:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)resendOtpRequest:(PCTSMSDKResendOtpRequest *)request completionHandler:(void (^)(PCTSMSDKResendOtpResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("resendOtp(request:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)resumeTokenTokenId:(NSString *)tokenId request:(PCTSMSDKTokenLifecycleRequest *)request completionHandler:(void (^)(PCTSMSDKTokenLifecycleResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("resumeToken(tokenId:request:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)suspendTokenTokenId:(NSString *)tokenId request:(PCTSMSDKTokenLifecycleRequest *)request completionHandler:(void (^)(PCTSMSDKTokenLifecycleResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("suspendToken(tokenId:request:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)verifyIdvRequest:(PCTSMSDKVerifyIdvRequest *)request completionHandler:(void (^)(PCTSMSDKVerifyIdvResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("verifyIdv(request:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("NetworkConfig")))
@interface PCTSMSDKNetworkConfig : PCTSMSDKBase
- (instancetype)initWithBaseUrl:(NSString *)baseUrl timeoutMillis:(int64_t)timeoutMillis __attribute__((swift_name("init(baseUrl:timeoutMillis:)"))) __attribute__((objc_designated_initializer));
- (PCTSMSDKNetworkConfig *)doCopyBaseUrl:(NSString *)baseUrl timeoutMillis:(int64_t)timeoutMillis __attribute__((swift_name("doCopy(baseUrl:timeoutMillis:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *baseUrl __attribute__((swift_name("baseUrl")));
@property (readonly) int64_t timeoutMillis __attribute__((swift_name("timeoutMillis")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SecureEnclave")))
@interface PCTSMSDKSecureEnclave : PCTSMSDKBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)attestKeyKeyId:(NSString *)keyId challenge:(PCTSMSDKKotlinByteArray *)challenge completionHandler:(void (^)(PCTSMSDKKotlinByteArray * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("attestKey(keyId:challenge:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)generateAttestationKeyWithCompletionHandler:(void (^)(NSString * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("generateAttestationKey(completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TSMClient")))
@interface PCTSMSDKTSMClient : PCTSMSDKBase
- (instancetype)initWithBaseUrl:(NSString *)baseUrl partnerId:(NSString *)partnerId appletPackageId:(NSString *)appletPackageId secureChannel:(PCTSMSDKSecureChannel *)secureChannel networkClient:(id<PCTSMSDKNetworkClient>)networkClient __attribute__((swift_name("init(baseUrl:partnerId:appletPackageId:secureChannel:networkClient:)"))) __attribute__((objc_designated_initializer));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)addCardEncryptedCardData:(NSString *)encryptedCardData cardholderName:(NSString *)cardholderName billingAddress:(PCTSMSDKBillingAddress *)billingAddress pan:(NSString * _Nullable)pan expiryMonth:(NSString * _Nullable)expiryMonth expiryYear:(NSString * _Nullable)expiryYear cvv:(NSString * _Nullable)cvv deviceId:(NSString * _Nullable)deviceId walletId:(NSString * _Nullable)walletId pushToken:(NSString * _Nullable)pushToken completionHandler:(void (^)(PCTSMSDKAddCardResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("addCard(encryptedCardData:cardholderName:billingAddress:pan:expiryMonth:expiryYear:cvv:deviceId:walletId:pushToken:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)confirmProvisioningTokenId:(NSString *)tokenId success:(BOOL)success errorMessage:(NSString * _Nullable)errorMessage completionHandler:(void (^)(PCTSMSDKConfirmProvisioningResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("confirmProvisioning(tokenId:success:errorMessage:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)deleteCardCardId:(NSString *)cardId reason:(NSString *)reason reasonCode:(NSString *)reasonCode completionHandler:(void (^)(PCTSMSDKTokenLifecycleResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("deleteCard(cardId:reason:reasonCode:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)registerDeviceDeviceType:(NSString *)deviceType deviceName:(NSString *)deviceName os:(NSString *)os osVersion:(NSString *)osVersion secureElementInfo:(PCTSMSDKSecureElementInfo *)secureElementInfo completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("registerDevice(deviceType:deviceName:os:osVersion:secureElementInfo:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)resumeCardCardId:(NSString *)cardId reason:(NSString *)reason reasonCode:(NSString *)reasonCode completionHandler:(void (^)(PCTSMSDKTokenLifecycleResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("resumeCard(cardId:reason:reasonCode:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)suspendCardCardId:(NSString *)cardId reason:(NSString *)reason reasonCode:(NSString *)reasonCode completionHandler:(void (^)(PCTSMSDKTokenLifecycleResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("suspendCard(cardId:reason:reasonCode:completionHandler:)")));
@property (readonly) id<PCTSMSDKKotlinx_coroutines_coreFlow> currentCredentials __attribute__((swift_name("currentCredentials")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AddCardRequest")))
@interface PCTSMSDKAddCardRequest : PCTSMSDKBase
- (instancetype)initWithEncryptedCardData:(NSString *)encryptedCardData pan:(NSString * _Nullable)pan expiryMonth:(NSString * _Nullable)expiryMonth expiryYear:(NSString * _Nullable)expiryYear cvv:(NSString * _Nullable)cvv deviceId:(NSString * _Nullable)deviceId walletId:(NSString * _Nullable)walletId cardholderName:(NSString *)cardholderName billingAddress:(PCTSMSDKBillingAddress *)billingAddress pushToken:(NSString * _Nullable)pushToken __attribute__((swift_name("init(encryptedCardData:pan:expiryMonth:expiryYear:cvv:deviceId:walletId:cardholderName:billingAddress:pushToken:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) PCTSMSDKAddCardRequestCompanion *companion __attribute__((swift_name("companion")));
- (PCTSMSDKAddCardRequest *)doCopyEncryptedCardData:(NSString *)encryptedCardData pan:(NSString * _Nullable)pan expiryMonth:(NSString * _Nullable)expiryMonth expiryYear:(NSString * _Nullable)expiryYear cvv:(NSString * _Nullable)cvv deviceId:(NSString * _Nullable)deviceId walletId:(NSString * _Nullable)walletId cardholderName:(NSString *)cardholderName billingAddress:(PCTSMSDKBillingAddress *)billingAddress pushToken:(NSString * _Nullable)pushToken __attribute__((swift_name("doCopy(encryptedCardData:pan:expiryMonth:expiryYear:cvv:deviceId:walletId:cardholderName:billingAddress:pushToken:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) PCTSMSDKBillingAddress *billingAddress __attribute__((swift_name("billingAddress")));
@property (readonly) NSString *cardholderName __attribute__((swift_name("cardholderName")));
@property (readonly) NSString * _Nullable cvv __attribute__((swift_name("cvv")));
@property (readonly) NSString * _Nullable deviceId __attribute__((swift_name("deviceId")));
@property (readonly) NSString *encryptedCardData __attribute__((swift_name("encryptedCardData")));
@property (readonly) NSString * _Nullable expiryMonth __attribute__((swift_name("expiryMonth")));
@property (readonly) NSString * _Nullable expiryYear __attribute__((swift_name("expiryYear")));
@property (readonly) NSString * _Nullable pan __attribute__((swift_name("pan")));
@property (readonly) NSString * _Nullable pushToken __attribute__((swift_name("pushToken")));
@property (readonly) NSString * _Nullable walletId __attribute__((swift_name("walletId")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AddCardRequest.Companion")))
@interface PCTSMSDKAddCardRequestCompanion : PCTSMSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) PCTSMSDKAddCardRequestCompanion *shared __attribute__((swift_name("shared")));
- (id<PCTSMSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AddCardResponse")))
@interface PCTSMSDKAddCardResponse : PCTSMSDKBase
- (instancetype)initWithCardId:(NSString *)cardId last4:(NSString *)last4 cardNetwork:(NSString *)cardNetwork status:(NSString *)status tokenReferenceId:(NSString * _Nullable)tokenReferenceId tokenPan:(NSString * _Nullable)tokenPan aidList:(NSArray<NSString *> * _Nullable)aidList tokens:(NSArray<PCTSMSDKTokenInfo *> *)tokens __attribute__((swift_name("init(cardId:last4:cardNetwork:status:tokenReferenceId:tokenPan:aidList:tokens:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) PCTSMSDKAddCardResponseCompanion *companion __attribute__((swift_name("companion")));
- (PCTSMSDKAddCardResponse *)doCopyCardId:(NSString *)cardId last4:(NSString *)last4 cardNetwork:(NSString *)cardNetwork status:(NSString *)status tokenReferenceId:(NSString * _Nullable)tokenReferenceId tokenPan:(NSString * _Nullable)tokenPan aidList:(NSArray<NSString *> * _Nullable)aidList tokens:(NSArray<PCTSMSDKTokenInfo *> *)tokens __attribute__((swift_name("doCopy(cardId:last4:cardNetwork:status:tokenReferenceId:tokenPan:aidList:tokens:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSArray<NSString *> * _Nullable aidList __attribute__((swift_name("aidList")));
@property (readonly) NSString *cardId __attribute__((swift_name("cardId")));
@property (readonly) NSString *cardNetwork __attribute__((swift_name("cardNetwork")));
@property (readonly) NSString *last4 __attribute__((swift_name("last4")));
@property (readonly) NSString *status __attribute__((swift_name("status")));
@property (readonly) NSString * _Nullable tokenPan __attribute__((swift_name("tokenPan")));
@property (readonly) NSString * _Nullable tokenReferenceId __attribute__((swift_name("tokenReferenceId")));
@property (readonly) NSArray<PCTSMSDKTokenInfo *> *tokens __attribute__((swift_name("tokens")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AddCardResponse.Companion")))
@interface PCTSMSDKAddCardResponseCompanion : PCTSMSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) PCTSMSDKAddCardResponseCompanion *shared __attribute__((swift_name("shared")));
- (id<PCTSMSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ApduCommand")))
@interface PCTSMSDKApduCommand : PCTSMSDKBase
- (instancetype)initWithApduId:(NSString *)apduId apdu:(NSString *)apdu __attribute__((swift_name("init(apduId:apdu:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) PCTSMSDKApduCommandCompanion *companion __attribute__((swift_name("companion")));
- (PCTSMSDKApduCommand *)doCopyApduId:(NSString *)apduId apdu:(NSString *)apdu __attribute__((swift_name("doCopy(apduId:apdu:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *apdu __attribute__((swift_name("apdu")));
@property (readonly) NSString *apduId __attribute__((swift_name("apduId")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ApduCommand.Companion")))
@interface PCTSMSDKApduCommandCompanion : PCTSMSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) PCTSMSDKApduCommandCompanion *shared __attribute__((swift_name("shared")));
- (id<PCTSMSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BillingAddress")))
@interface PCTSMSDKBillingAddress : PCTSMSDKBase
- (instancetype)initWithLine1:(NSString *)line1 city:(NSString *)city state:(NSString *)state postalCode:(NSString *)postalCode country:(NSString *)country __attribute__((swift_name("init(line1:city:state:postalCode:country:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) PCTSMSDKBillingAddressCompanion *companion __attribute__((swift_name("companion")));
- (PCTSMSDKBillingAddress *)doCopyLine1:(NSString *)line1 city:(NSString *)city state:(NSString *)state postalCode:(NSString *)postalCode country:(NSString *)country __attribute__((swift_name("doCopy(line1:city:state:postalCode:country:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *city __attribute__((swift_name("city")));
@property (readonly) NSString *country __attribute__((swift_name("country")));
@property (readonly) NSString *line1 __attribute__((swift_name("line1")));
@property (readonly) NSString *postalCode __attribute__((swift_name("postalCode")));
@property (readonly) NSString *state __attribute__((swift_name("state")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BillingAddress.Companion")))
@interface PCTSMSDKBillingAddressCompanion : PCTSMSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) PCTSMSDKBillingAddressCompanion *shared __attribute__((swift_name("shared")));
- (id<PCTSMSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ConfirmProvisioningRequest")))
@interface PCTSMSDKConfirmProvisioningRequest : PCTSMSDKBase
- (instancetype)initWithProvisioningStatus:(NSString *)provisioningStatus __attribute__((swift_name("init(provisioningStatus:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) PCTSMSDKConfirmProvisioningRequestCompanion *companion __attribute__((swift_name("companion")));
- (PCTSMSDKConfirmProvisioningRequest *)doCopyProvisioningStatus:(NSString *)provisioningStatus __attribute__((swift_name("doCopy(provisioningStatus:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *provisioningStatus __attribute__((swift_name("provisioningStatus")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ConfirmProvisioningRequest.Companion")))
@interface PCTSMSDKConfirmProvisioningRequestCompanion : PCTSMSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) PCTSMSDKConfirmProvisioningRequestCompanion *shared __attribute__((swift_name("shared")));
- (id<PCTSMSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ConfirmProvisioningResponse")))
@interface PCTSMSDKConfirmProvisioningResponse : PCTSMSDKBase
- (instancetype)initWithTokenId:(NSString *)tokenId status:(NSString *)status errorMessage:(NSString * _Nullable)errorMessage __attribute__((swift_name("init(tokenId:status:errorMessage:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) PCTSMSDKConfirmProvisioningResponseCompanion *companion __attribute__((swift_name("companion")));
- (PCTSMSDKConfirmProvisioningResponse *)doCopyTokenId:(NSString *)tokenId status:(NSString *)status errorMessage:(NSString * _Nullable)errorMessage __attribute__((swift_name("doCopy(tokenId:status:errorMessage:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString * _Nullable errorMessage __attribute__((swift_name("errorMessage")));
@property (readonly) NSString *status __attribute__((swift_name("status")));
@property (readonly) NSString *tokenId __attribute__((swift_name("tokenId")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ConfirmProvisioningResponse.Companion")))
@interface PCTSMSDKConfirmProvisioningResponseCompanion : PCTSMSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) PCTSMSDKConfirmProvisioningResponseCompanion *shared __attribute__((swift_name("shared")));
- (id<PCTSMSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CredentialInfo")))
@interface PCTSMSDKCredentialInfo : PCTSMSDKBase
- (instancetype)initWithId:(NSString *)id pan:(NSString *)pan expiry:(NSString *)expiry cardholderName:(NSString *)cardholderName status:(PCTSMSDKCredentialStatus *)status token:(NSString *)token __attribute__((swift_name("init(id:pan:expiry:cardholderName:status:token:)"))) __attribute__((objc_designated_initializer));
- (PCTSMSDKCredentialInfo *)doCopyId:(NSString *)id pan:(NSString *)pan expiry:(NSString *)expiry cardholderName:(NSString *)cardholderName status:(PCTSMSDKCredentialStatus *)status token:(NSString *)token __attribute__((swift_name("doCopy(id:pan:expiry:cardholderName:status:token:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *cardholderName __attribute__((swift_name("cardholderName")));
@property (readonly) NSString *expiry __attribute__((swift_name("expiry")));
@property (readonly) NSString *id __attribute__((swift_name("id")));
@property (readonly) NSString *pan __attribute__((swift_name("pan")));
@property (readonly) PCTSMSDKCredentialStatus *status __attribute__((swift_name("status")));
@property (readonly) NSString *token __attribute__((swift_name("token")));
@end

__attribute__((swift_name("KotlinComparable")))
@protocol PCTSMSDKKotlinComparable
@required
- (int32_t)compareToOther:(id _Nullable)other __attribute__((swift_name("compareTo(other:)")));
@end

__attribute__((swift_name("KotlinEnum")))
@interface PCTSMSDKKotlinEnum<E> : PCTSMSDKBase <PCTSMSDKKotlinComparable>
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) PCTSMSDKKotlinEnumCompanion *companion __attribute__((swift_name("companion")));
- (int32_t)compareToOther:(E)other __attribute__((swift_name("compareTo(other:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@property (readonly) int32_t ordinal __attribute__((swift_name("ordinal")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CredentialStatus")))
@interface PCTSMSDKCredentialStatus : PCTSMSDKKotlinEnum<PCTSMSDKCredentialStatus *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) PCTSMSDKCredentialStatus *pendingInstall __attribute__((swift_name("pendingInstall")));
@property (class, readonly) PCTSMSDKCredentialStatus *installed __attribute__((swift_name("installed")));
@property (class, readonly) PCTSMSDKCredentialStatus *personalized __attribute__((swift_name("personalized")));
@property (class, readonly) PCTSMSDKCredentialStatus *activated __attribute__((swift_name("activated")));
@property (class, readonly) PCTSMSDKCredentialStatus *suspended __attribute__((swift_name("suspended")));
@property (class, readonly) PCTSMSDKCredentialStatus *deleted __attribute__((swift_name("deleted")));
+ (PCTSMSDKKotlinArray<PCTSMSDKCredentialStatus *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<PCTSMSDKCredentialStatus *> *entries __attribute__((swift_name("entries")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DeviceRegistrationRequest")))
@interface PCTSMSDKDeviceRegistrationRequest : PCTSMSDKBase
- (instancetype)initWithDeviceType:(NSString *)deviceType deviceName:(NSString *)deviceName os:(NSString *)os osVersion:(NSString *)osVersion secureElementInfo:(PCTSMSDKSecureElementInfo *)secureElementInfo __attribute__((swift_name("init(deviceType:deviceName:os:osVersion:secureElementInfo:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) PCTSMSDKDeviceRegistrationRequestCompanion *companion __attribute__((swift_name("companion")));
- (PCTSMSDKDeviceRegistrationRequest *)doCopyDeviceType:(NSString *)deviceType deviceName:(NSString *)deviceName os:(NSString *)os osVersion:(NSString *)osVersion secureElementInfo:(PCTSMSDKSecureElementInfo *)secureElementInfo __attribute__((swift_name("doCopy(deviceType:deviceName:os:osVersion:secureElementInfo:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *deviceName __attribute__((swift_name("deviceName")));
@property (readonly) NSString *deviceType __attribute__((swift_name("deviceType")));
@property (readonly) NSString *os __attribute__((swift_name("os")));
@property (readonly) NSString *osVersion __attribute__((swift_name("osVersion")));
@property (readonly) PCTSMSDKSecureElementInfo *secureElementInfo __attribute__((swift_name("secureElementInfo")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DeviceRegistrationRequest.Companion")))
@interface PCTSMSDKDeviceRegistrationRequestCompanion : PCTSMSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) PCTSMSDKDeviceRegistrationRequestCompanion *shared __attribute__((swift_name("shared")));
- (id<PCTSMSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("IdvMethodInfo")))
@interface PCTSMSDKIdvMethodInfo : PCTSMSDKBase
- (instancetype)initWithMethod:(NSString *)method displayName:(NSString *)displayName maskedDestination:(NSString * _Nullable)maskedDestination isRecommended:(BOOL)isRecommended __attribute__((swift_name("init(method:displayName:maskedDestination:isRecommended:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) PCTSMSDKIdvMethodInfoCompanion *companion __attribute__((swift_name("companion")));
- (PCTSMSDKIdvMethodInfo *)doCopyMethod:(NSString *)method displayName:(NSString *)displayName maskedDestination:(NSString * _Nullable)maskedDestination isRecommended:(BOOL)isRecommended __attribute__((swift_name("doCopy(method:displayName:maskedDestination:isRecommended:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *displayName __attribute__((swift_name("displayName")));
@property (readonly) BOOL isRecommended __attribute__((swift_name("isRecommended")));
@property (readonly) NSString * _Nullable maskedDestination __attribute__((swift_name("maskedDestination")));
@property (readonly) NSString *method __attribute__((swift_name("method")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("IdvMethodInfo.Companion")))
@interface PCTSMSDKIdvMethodInfoCompanion : PCTSMSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) PCTSMSDKIdvMethodInfoCompanion *shared __attribute__((swift_name("shared")));
- (id<PCTSMSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("InitiateIdvRequest")))
@interface PCTSMSDKInitiateIdvRequest : PCTSMSDKBase
- (instancetype)initWithTokenId:(NSString *)tokenId preferredMethod:(NSString * _Nullable)preferredMethod deviceId:(NSString * _Nullable)deviceId customerId:(PCTSMSDKLong * _Nullable)customerId __attribute__((swift_name("init(tokenId:preferredMethod:deviceId:customerId:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) PCTSMSDKInitiateIdvRequestCompanion *companion __attribute__((swift_name("companion")));
- (PCTSMSDKInitiateIdvRequest *)doCopyTokenId:(NSString *)tokenId preferredMethod:(NSString * _Nullable)preferredMethod deviceId:(NSString * _Nullable)deviceId customerId:(PCTSMSDKLong * _Nullable)customerId __attribute__((swift_name("doCopy(tokenId:preferredMethod:deviceId:customerId:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) PCTSMSDKLong * _Nullable customerId __attribute__((swift_name("customerId")));
@property (readonly) NSString * _Nullable deviceId __attribute__((swift_name("deviceId")));
@property (readonly) NSString * _Nullable preferredMethod __attribute__((swift_name("preferredMethod")));
@property (readonly) NSString *tokenId __attribute__((swift_name("tokenId")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("InitiateIdvRequest.Companion")))
@interface PCTSMSDKInitiateIdvRequestCompanion : PCTSMSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) PCTSMSDKInitiateIdvRequestCompanion *shared __attribute__((swift_name("shared")));
- (id<PCTSMSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("InitiateIdvResponse")))
@interface PCTSMSDKInitiateIdvResponse : PCTSMSDKBase
- (instancetype)initWithVerificationId:(NSString *)verificationId method:(NSString *)method status:(NSString *)status maskedDestination:(NSString * _Nullable)maskedDestination expiresInSeconds:(int32_t)expiresInSeconds deepLinkUrl:(NSString * _Nullable)deepLinkUrl availableMethods:(NSArray<PCTSMSDKIdvMethodInfo *> *)availableMethods __attribute__((swift_name("init(verificationId:method:status:maskedDestination:expiresInSeconds:deepLinkUrl:availableMethods:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) PCTSMSDKInitiateIdvResponseCompanion *companion __attribute__((swift_name("companion")));
- (PCTSMSDKInitiateIdvResponse *)doCopyVerificationId:(NSString *)verificationId method:(NSString *)method status:(NSString *)status maskedDestination:(NSString * _Nullable)maskedDestination expiresInSeconds:(int32_t)expiresInSeconds deepLinkUrl:(NSString * _Nullable)deepLinkUrl availableMethods:(NSArray<PCTSMSDKIdvMethodInfo *> *)availableMethods __attribute__((swift_name("doCopy(verificationId:method:status:maskedDestination:expiresInSeconds:deepLinkUrl:availableMethods:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSArray<PCTSMSDKIdvMethodInfo *> *availableMethods __attribute__((swift_name("availableMethods")));
@property (readonly) NSString * _Nullable deepLinkUrl __attribute__((swift_name("deepLinkUrl")));
@property (readonly) int32_t expiresInSeconds __attribute__((swift_name("expiresInSeconds")));
@property (readonly) NSString * _Nullable maskedDestination __attribute__((swift_name("maskedDestination")));
@property (readonly) NSString *method __attribute__((swift_name("method")));
@property (readonly) NSString *status __attribute__((swift_name("status")));
@property (readonly) NSString *verificationId __attribute__((swift_name("verificationId")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("InitiateIdvResponse.Companion")))
@interface PCTSMSDKInitiateIdvResponseCompanion : PCTSMSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) PCTSMSDKInitiateIdvResponseCompanion *shared __attribute__((swift_name("shared")));
- (id<PCTSMSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PersonalizationData")))
@interface PCTSMSDKPersonalizationData : PCTSMSDKBase
- (instancetype)initWithAppletInstanceAID:(NSString *)appletInstanceAID apduCommands:(NSArray<PCTSMSDKApduCommand *> *)apduCommands track2EquivalentData:(NSString * _Nullable)track2EquivalentData tokenizedPan:(NSString * _Nullable)tokenizedPan expirationDate:(NSString * _Nullable)expirationDate panSequenceNumber:(NSString * _Nullable)panSequenceNumber serviceCode:(NSString * _Nullable)serviceCode cardholderName:(NSString * _Nullable)cardholderName applicationInterchangeProfile:(NSString * _Nullable)applicationInterchangeProfile applicationFileLocator:(NSString * _Nullable)applicationFileLocator storeDataCommands:(NSArray<NSString *> * _Nullable)storeDataCommands dgiCount:(int32_t)dgiCount cvnVersion:(NSString * _Nullable)cvnVersion lukValue:(NSString * _Nullable)lukValue lukKeyIndex:(NSString * _Nullable)lukKeyIndex lukRemainingTransactions:(int32_t)lukRemainingTransactions lukTimeToLiveSeconds:(int32_t)lukTimeToLiveSeconds accountParametersIndex:(NSString * _Nullable)accountParametersIndex formFactorIndicator:(NSString * _Nullable)formFactorIndicator __attribute__((swift_name("init(appletInstanceAID:apduCommands:track2EquivalentData:tokenizedPan:expirationDate:panSequenceNumber:serviceCode:cardholderName:applicationInterchangeProfile:applicationFileLocator:storeDataCommands:dgiCount:cvnVersion:lukValue:lukKeyIndex:lukRemainingTransactions:lukTimeToLiveSeconds:accountParametersIndex:formFactorIndicator:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) PCTSMSDKPersonalizationDataCompanion *companion __attribute__((swift_name("companion")));
- (PCTSMSDKPersonalizationData *)doCopyAppletInstanceAID:(NSString *)appletInstanceAID apduCommands:(NSArray<PCTSMSDKApduCommand *> *)apduCommands track2EquivalentData:(NSString * _Nullable)track2EquivalentData tokenizedPan:(NSString * _Nullable)tokenizedPan expirationDate:(NSString * _Nullable)expirationDate panSequenceNumber:(NSString * _Nullable)panSequenceNumber serviceCode:(NSString * _Nullable)serviceCode cardholderName:(NSString * _Nullable)cardholderName applicationInterchangeProfile:(NSString * _Nullable)applicationInterchangeProfile applicationFileLocator:(NSString * _Nullable)applicationFileLocator storeDataCommands:(NSArray<NSString *> * _Nullable)storeDataCommands dgiCount:(int32_t)dgiCount cvnVersion:(NSString * _Nullable)cvnVersion lukValue:(NSString * _Nullable)lukValue lukKeyIndex:(NSString * _Nullable)lukKeyIndex lukRemainingTransactions:(int32_t)lukRemainingTransactions lukTimeToLiveSeconds:(int32_t)lukTimeToLiveSeconds accountParametersIndex:(NSString * _Nullable)accountParametersIndex formFactorIndicator:(NSString * _Nullable)formFactorIndicator __attribute__((swift_name("doCopy(appletInstanceAID:apduCommands:track2EquivalentData:tokenizedPan:expirationDate:panSequenceNumber:serviceCode:cardholderName:applicationInterchangeProfile:applicationFileLocator:storeDataCommands:dgiCount:cvnVersion:lukValue:lukKeyIndex:lukRemainingTransactions:lukTimeToLiveSeconds:accountParametersIndex:formFactorIndicator:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString * _Nullable accountParametersIndex __attribute__((swift_name("accountParametersIndex")));
@property (readonly) NSArray<PCTSMSDKApduCommand *> *apduCommands __attribute__((swift_name("apduCommands")));
@property (readonly) NSString *appletInstanceAID __attribute__((swift_name("appletInstanceAID")));
@property (readonly) NSString * _Nullable applicationFileLocator __attribute__((swift_name("applicationFileLocator")));
@property (readonly) NSString * _Nullable applicationInterchangeProfile __attribute__((swift_name("applicationInterchangeProfile")));
@property (readonly) NSString * _Nullable cardholderName __attribute__((swift_name("cardholderName")));
@property (readonly) NSString * _Nullable cvnVersion __attribute__((swift_name("cvnVersion")));
@property (readonly) int32_t dgiCount __attribute__((swift_name("dgiCount")));
@property (readonly) NSString * _Nullable expirationDate __attribute__((swift_name("expirationDate")));
@property (readonly) NSString * _Nullable formFactorIndicator __attribute__((swift_name("formFactorIndicator")));
@property (readonly) NSString * _Nullable lukKeyIndex __attribute__((swift_name("lukKeyIndex")));
@property (readonly) int32_t lukRemainingTransactions __attribute__((swift_name("lukRemainingTransactions")));
@property (readonly) int32_t lukTimeToLiveSeconds __attribute__((swift_name("lukTimeToLiveSeconds")));
@property (readonly) NSString * _Nullable lukValue __attribute__((swift_name("lukValue")));
@property (readonly) NSString * _Nullable panSequenceNumber __attribute__((swift_name("panSequenceNumber")));
@property (readonly) NSString * _Nullable serviceCode __attribute__((swift_name("serviceCode")));
@property (readonly) NSArray<NSString *> * _Nullable storeDataCommands __attribute__((swift_name("storeDataCommands")));
@property (readonly) NSString * _Nullable tokenizedPan __attribute__((swift_name("tokenizedPan")));
@property (readonly) NSString * _Nullable track2EquivalentData __attribute__((swift_name("track2EquivalentData")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PersonalizationData.Companion")))
@interface PCTSMSDKPersonalizationDataCompanion : PCTSMSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) PCTSMSDKPersonalizationDataCompanion *shared __attribute__((swift_name("shared")));
- (id<PCTSMSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ResendOtpRequest")))
@interface PCTSMSDKResendOtpRequest : PCTSMSDKBase
- (instancetype)initWithVerificationId:(NSString *)verificationId newMethod:(NSString * _Nullable)newMethod __attribute__((swift_name("init(verificationId:newMethod:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) PCTSMSDKResendOtpRequestCompanion *companion __attribute__((swift_name("companion")));
- (PCTSMSDKResendOtpRequest *)doCopyVerificationId:(NSString *)verificationId newMethod:(NSString * _Nullable)newMethod __attribute__((swift_name("doCopy(verificationId:newMethod:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly, getter=doNewMethod) NSString * _Nullable newMethod __attribute__((swift_name("newMethod")));
@property (readonly) NSString *verificationId __attribute__((swift_name("verificationId")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ResendOtpRequest.Companion")))
@interface PCTSMSDKResendOtpRequestCompanion : PCTSMSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) PCTSMSDKResendOtpRequestCompanion *shared __attribute__((swift_name("shared")));
- (id<PCTSMSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ResendOtpResponse")))
@interface PCTSMSDKResendOtpResponse : PCTSMSDKBase
- (instancetype)initWithVerificationId:(NSString *)verificationId status:(NSString *)status maskedDestination:(NSString * _Nullable)maskedDestination expiresInSeconds:(int32_t)expiresInSeconds resendCooldownSeconds:(PCTSMSDKInt * _Nullable)resendCooldownSeconds __attribute__((swift_name("init(verificationId:status:maskedDestination:expiresInSeconds:resendCooldownSeconds:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) PCTSMSDKResendOtpResponseCompanion *companion __attribute__((swift_name("companion")));
- (PCTSMSDKResendOtpResponse *)doCopyVerificationId:(NSString *)verificationId status:(NSString *)status maskedDestination:(NSString * _Nullable)maskedDestination expiresInSeconds:(int32_t)expiresInSeconds resendCooldownSeconds:(PCTSMSDKInt * _Nullable)resendCooldownSeconds __attribute__((swift_name("doCopy(verificationId:status:maskedDestination:expiresInSeconds:resendCooldownSeconds:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t expiresInSeconds __attribute__((swift_name("expiresInSeconds")));
@property (readonly) NSString * _Nullable maskedDestination __attribute__((swift_name("maskedDestination")));
@property (readonly) PCTSMSDKInt * _Nullable resendCooldownSeconds __attribute__((swift_name("resendCooldownSeconds")));
@property (readonly) NSString *status __attribute__((swift_name("status")));
@property (readonly) NSString *verificationId __attribute__((swift_name("verificationId")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ResendOtpResponse.Companion")))
@interface PCTSMSDKResendOtpResponseCompanion : PCTSMSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) PCTSMSDKResendOtpResponseCompanion *shared __attribute__((swift_name("shared")));
- (id<PCTSMSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SecureElementInfo")))
@interface PCTSMSDKSecureElementInfo : PCTSMSDKBase
- (instancetype)initWithVmpaVersion:(NSString *)vmpaVersion aidArray:(NSArray<NSString *> *)aidArray sequenceCounter:(NSString *)sequenceCounter keyVersionNumber:(NSString *)keyVersionNumber __attribute__((swift_name("init(vmpaVersion:aidArray:sequenceCounter:keyVersionNumber:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) PCTSMSDKSecureElementInfoCompanion *companion __attribute__((swift_name("companion")));
- (PCTSMSDKSecureElementInfo *)doCopyVmpaVersion:(NSString *)vmpaVersion aidArray:(NSArray<NSString *> *)aidArray sequenceCounter:(NSString *)sequenceCounter keyVersionNumber:(NSString *)keyVersionNumber __attribute__((swift_name("doCopy(vmpaVersion:aidArray:sequenceCounter:keyVersionNumber:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSArray<NSString *> *aidArray __attribute__((swift_name("aidArray")));
@property (readonly) NSString *keyVersionNumber __attribute__((swift_name("keyVersionNumber")));
@property (readonly) NSString *sequenceCounter __attribute__((swift_name("sequenceCounter")));
@property (readonly) NSString *vmpaVersion __attribute__((swift_name("vmpaVersion")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SecureElementInfo.Companion")))
@interface PCTSMSDKSecureElementInfoCompanion : PCTSMSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) PCTSMSDKSecureElementInfoCompanion *shared __attribute__((swift_name("shared")));
- (id<PCTSMSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TokenInfo")))
@interface PCTSMSDKTokenInfo : PCTSMSDKBase
- (instancetype)initWithTokenId:(NSString *)tokenId tokenType:(NSString *)tokenType status:(NSString *)status needsDeviceBinding:(BOOL)needsDeviceBinding personalizationData:(PCTSMSDKPersonalizationData * _Nullable)personalizationData __attribute__((swift_name("init(tokenId:tokenType:status:needsDeviceBinding:personalizationData:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) PCTSMSDKTokenInfoCompanion *companion __attribute__((swift_name("companion")));
- (PCTSMSDKTokenInfo *)doCopyTokenId:(NSString *)tokenId tokenType:(NSString *)tokenType status:(NSString *)status needsDeviceBinding:(BOOL)needsDeviceBinding personalizationData:(PCTSMSDKPersonalizationData * _Nullable)personalizationData __attribute__((swift_name("doCopy(tokenId:tokenType:status:needsDeviceBinding:personalizationData:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) BOOL needsDeviceBinding __attribute__((swift_name("needsDeviceBinding")));
@property (readonly) PCTSMSDKPersonalizationData * _Nullable personalizationData __attribute__((swift_name("personalizationData")));
@property (readonly) NSString *status __attribute__((swift_name("status")));
@property (readonly) NSString *tokenId __attribute__((swift_name("tokenId")));
@property (readonly) NSString *tokenType __attribute__((swift_name("tokenType")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TokenInfo.Companion")))
@interface PCTSMSDKTokenInfoCompanion : PCTSMSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) PCTSMSDKTokenInfoCompanion *shared __attribute__((swift_name("shared")));
- (id<PCTSMSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TokenLifecycleRequest")))
@interface PCTSMSDKTokenLifecycleRequest : PCTSMSDKBase
- (instancetype)initWithReason:(NSString *)reason reasonCode:(NSString *)reasonCode __attribute__((swift_name("init(reason:reasonCode:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) PCTSMSDKTokenLifecycleRequestCompanion *companion __attribute__((swift_name("companion")));
- (PCTSMSDKTokenLifecycleRequest *)doCopyReason:(NSString *)reason reasonCode:(NSString *)reasonCode __attribute__((swift_name("doCopy(reason:reasonCode:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *reason __attribute__((swift_name("reason")));
@property (readonly) NSString *reasonCode __attribute__((swift_name("reasonCode")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TokenLifecycleRequest.Companion")))
@interface PCTSMSDKTokenLifecycleRequestCompanion : PCTSMSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) PCTSMSDKTokenLifecycleRequestCompanion *shared __attribute__((swift_name("shared")));
- (id<PCTSMSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TokenLifecycleResponse")))
@interface PCTSMSDKTokenLifecycleResponse : PCTSMSDKBase
- (instancetype)initWithTokenId:(NSString *)tokenId status:(NSString *)status success:(BOOL)success errorMessage:(NSString * _Nullable)errorMessage __attribute__((swift_name("init(tokenId:status:success:errorMessage:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) PCTSMSDKTokenLifecycleResponseCompanion *companion __attribute__((swift_name("companion")));
- (PCTSMSDKTokenLifecycleResponse *)doCopyTokenId:(NSString *)tokenId status:(NSString *)status success:(BOOL)success errorMessage:(NSString * _Nullable)errorMessage __attribute__((swift_name("doCopy(tokenId:status:success:errorMessage:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString * _Nullable errorMessage __attribute__((swift_name("errorMessage")));
@property (readonly) NSString *status __attribute__((swift_name("status")));
@property (readonly) BOOL success __attribute__((swift_name("success")));
@property (readonly) NSString *tokenId __attribute__((swift_name("tokenId")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TokenLifecycleResponse.Companion")))
@interface PCTSMSDKTokenLifecycleResponseCompanion : PCTSMSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) PCTSMSDKTokenLifecycleResponseCompanion *shared __attribute__((swift_name("shared")));
- (id<PCTSMSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("VerifyIdvRequest")))
@interface PCTSMSDKVerifyIdvRequest : PCTSMSDKBase
- (instancetype)initWithVerificationId:(NSString *)verificationId otpCode:(NSString * _Nullable)otpCode biometricToken:(NSString * _Nullable)biometricToken appConfirmationToken:(NSString * _Nullable)appConfirmationToken __attribute__((swift_name("init(verificationId:otpCode:biometricToken:appConfirmationToken:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) PCTSMSDKVerifyIdvRequestCompanion *companion __attribute__((swift_name("companion")));
- (PCTSMSDKVerifyIdvRequest *)doCopyVerificationId:(NSString *)verificationId otpCode:(NSString * _Nullable)otpCode biometricToken:(NSString * _Nullable)biometricToken appConfirmationToken:(NSString * _Nullable)appConfirmationToken __attribute__((swift_name("doCopy(verificationId:otpCode:biometricToken:appConfirmationToken:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString * _Nullable appConfirmationToken __attribute__((swift_name("appConfirmationToken")));
@property (readonly) NSString * _Nullable biometricToken __attribute__((swift_name("biometricToken")));
@property (readonly) NSString * _Nullable otpCode __attribute__((swift_name("otpCode")));
@property (readonly) NSString *verificationId __attribute__((swift_name("verificationId")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("VerifyIdvRequest.Companion")))
@interface PCTSMSDKVerifyIdvRequestCompanion : PCTSMSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) PCTSMSDKVerifyIdvRequestCompanion *shared __attribute__((swift_name("shared")));
- (id<PCTSMSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("VerifyIdvResponse")))
@interface PCTSMSDKVerifyIdvResponse : PCTSMSDKBase
- (instancetype)initWithVerificationId:(NSString *)verificationId status:(NSString *)status isVerified:(BOOL)isVerified errorCode:(NSString * _Nullable)errorCode errorMessage:(NSString * _Nullable)errorMessage remainingAttempts:(PCTSMSDKInt * _Nullable)remainingAttempts tokenStatus:(NSString * _Nullable)tokenStatus activationCode:(NSString * _Nullable)activationCode __attribute__((swift_name("init(verificationId:status:isVerified:errorCode:errorMessage:remainingAttempts:tokenStatus:activationCode:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) PCTSMSDKVerifyIdvResponseCompanion *companion __attribute__((swift_name("companion")));
- (PCTSMSDKVerifyIdvResponse *)doCopyVerificationId:(NSString *)verificationId status:(NSString *)status isVerified:(BOOL)isVerified errorCode:(NSString * _Nullable)errorCode errorMessage:(NSString * _Nullable)errorMessage remainingAttempts:(PCTSMSDKInt * _Nullable)remainingAttempts tokenStatus:(NSString * _Nullable)tokenStatus activationCode:(NSString * _Nullable)activationCode __attribute__((swift_name("doCopy(verificationId:status:isVerified:errorCode:errorMessage:remainingAttempts:tokenStatus:activationCode:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString * _Nullable activationCode __attribute__((swift_name("activationCode")));
@property (readonly) NSString * _Nullable errorCode __attribute__((swift_name("errorCode")));
@property (readonly) NSString * _Nullable errorMessage __attribute__((swift_name("errorMessage")));
@property (readonly) BOOL isVerified __attribute__((swift_name("isVerified")));
@property (readonly) PCTSMSDKInt * _Nullable remainingAttempts __attribute__((swift_name("remainingAttempts")));
@property (readonly) NSString *status __attribute__((swift_name("status")));
@property (readonly) NSString * _Nullable tokenStatus __attribute__((swift_name("tokenStatus")));
@property (readonly) NSString *verificationId __attribute__((swift_name("verificationId")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("VerifyIdvResponse.Companion")))
@interface PCTSMSDKVerifyIdvResponseCompanion : PCTSMSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) PCTSMSDKVerifyIdvResponseCompanion *shared __attribute__((swift_name("shared")));
- (id<PCTSMSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SecureChannel")))
@interface PCTSMSDKSecureChannel : PCTSMSDKBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)decryptApduEncryptedData:(PCTSMSDKKotlinByteArray *)encryptedData session:(PCTSMSDKSecureSession *)session completionHandler:(void (^)(PCTSMSDKKotlinByteArray * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("decryptApdu(encryptedData:session:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)encryptApduApdu:(PCTSMSDKKotlinByteArray *)apdu session:(PCTSMSDKSecureSession *)session completionHandler:(void (^)(PCTSMSDKKotlinByteArray * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("encryptApdu(apdu:session:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)establishSessionDomainId:(NSString *)domainId completionHandler:(void (^)(PCTSMSDKSecureSession * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("establishSession(domainId:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SecureSession")))
@interface PCTSMSDKSecureSession : PCTSMSDKBase
- (instancetype)initWithSessionId:(NSString *)sessionId encryptionKey:(PCTSMSDKKotlinByteArray *)encryptionKey macKey:(PCTSMSDKKotlinByteArray *)macKey __attribute__((swift_name("init(sessionId:encryptionKey:macKey:)"))) __attribute__((objc_designated_initializer));
- (PCTSMSDKSecureSession *)doCopySessionId:(NSString *)sessionId encryptionKey:(PCTSMSDKKotlinByteArray *)encryptionKey macKey:(PCTSMSDKKotlinByteArray *)macKey __attribute__((swift_name("doCopy(sessionId:encryptionKey:macKey:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) PCTSMSDKKotlinByteArray *encryptionKey __attribute__((swift_name("encryptionKey")));
@property (readonly) PCTSMSDKKotlinByteArray *macKey __attribute__((swift_name("macKey")));
@property (readonly) NSString *sessionId __attribute__((swift_name("sessionId")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SHA256Kt")))
@interface PCTSMSDKSHA256Kt : PCTSMSDKBase
+ (PCTSMSDKKotlinByteArray *)sha256Data:(PCTSMSDKKotlinByteArray *)data __attribute__((swift_name("sha256(data:)")));
@end

__attribute__((swift_name("KotlinThrowable")))
@interface PCTSMSDKKotlinThrowable : PCTSMSDKBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(PCTSMSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(PCTSMSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));

/**
 * @note annotations
 *   kotlin.experimental.ExperimentalNativeApi
*/
- (PCTSMSDKKotlinArray<NSString *> *)getStackTrace __attribute__((swift_name("getStackTrace()")));
- (void)printStackTrace __attribute__((swift_name("printStackTrace()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) PCTSMSDKKotlinThrowable * _Nullable cause __attribute__((swift_name("cause")));
@property (readonly) NSString * _Nullable message __attribute__((swift_name("message")));
- (NSError *)asError __attribute__((swift_name("asError()")));
@end

__attribute__((swift_name("KotlinException")))
@interface PCTSMSDKKotlinException : PCTSMSDKKotlinThrowable
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(PCTSMSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(PCTSMSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((swift_name("KotlinRuntimeException")))
@interface PCTSMSDKKotlinRuntimeException : PCTSMSDKKotlinException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(PCTSMSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(PCTSMSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((swift_name("KotlinIllegalStateException")))
@interface PCTSMSDKKotlinIllegalStateException : PCTSMSDKKotlinRuntimeException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(PCTSMSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(PCTSMSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.4")
*/
__attribute__((swift_name("KotlinCancellationException")))
@interface PCTSMSDKKotlinCancellationException : PCTSMSDKKotlinIllegalStateException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(PCTSMSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(PCTSMSDKKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinByteArray")))
@interface PCTSMSDKKotlinByteArray : PCTSMSDKBase
+ (instancetype)arrayWithSize:(int32_t)size __attribute__((swift_name("init(size:)")));
+ (instancetype)arrayWithSize:(int32_t)size init:(PCTSMSDKByte *(^)(PCTSMSDKInt *))init __attribute__((swift_name("init(size:init:)")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (int8_t)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (PCTSMSDKKotlinByteIterator *)iterator __attribute__((swift_name("iterator()")));
- (void)setIndex:(int32_t)index value:(int8_t)value __attribute__((swift_name("set(index:value:)")));
@property (readonly) int32_t size __attribute__((swift_name("size")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreFlow")))
@protocol PCTSMSDKKotlinx_coroutines_coreFlow
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)collectCollector:(id<PCTSMSDKKotlinx_coroutines_coreFlowCollector>)collector completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("collect(collector:completionHandler:)")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreSerializationStrategy")))
@protocol PCTSMSDKKotlinx_serialization_coreSerializationStrategy
@required
- (void)serializeEncoder:(id<PCTSMSDKKotlinx_serialization_coreEncoder>)encoder value:(id _Nullable)value __attribute__((swift_name("serialize(encoder:value:)")));
@property (readonly) id<PCTSMSDKKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreDeserializationStrategy")))
@protocol PCTSMSDKKotlinx_serialization_coreDeserializationStrategy
@required
- (id _Nullable)deserializeDecoder:(id<PCTSMSDKKotlinx_serialization_coreDecoder>)decoder __attribute__((swift_name("deserialize(decoder:)")));
@property (readonly) id<PCTSMSDKKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreKSerializer")))
@protocol PCTSMSDKKotlinx_serialization_coreKSerializer <PCTSMSDKKotlinx_serialization_coreSerializationStrategy, PCTSMSDKKotlinx_serialization_coreDeserializationStrategy>
@required
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinEnumCompanion")))
@interface PCTSMSDKKotlinEnumCompanion : PCTSMSDKBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) PCTSMSDKKotlinEnumCompanion *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinArray")))
@interface PCTSMSDKKotlinArray<T> : PCTSMSDKBase
+ (instancetype)arrayWithSize:(int32_t)size init:(T _Nullable (^)(PCTSMSDKInt *))init __attribute__((swift_name("init(size:init:)")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (T _Nullable)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (id<PCTSMSDKKotlinIterator>)iterator __attribute__((swift_name("iterator()")));
- (void)setIndex:(int32_t)index value:(T _Nullable)value __attribute__((swift_name("set(index:value:)")));
@property (readonly) int32_t size __attribute__((swift_name("size")));
@end

__attribute__((swift_name("KotlinIterator")))
@protocol PCTSMSDKKotlinIterator
@required
- (BOOL)hasNext __attribute__((swift_name("hasNext()")));
- (id _Nullable)next __attribute__((swift_name("next()")));
@end

__attribute__((swift_name("KotlinByteIterator")))
@interface PCTSMSDKKotlinByteIterator : PCTSMSDKBase <PCTSMSDKKotlinIterator>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (PCTSMSDKByte *)next __attribute__((swift_name("next()")));
- (int8_t)nextByte __attribute__((swift_name("nextByte()")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreFlowCollector")))
@protocol PCTSMSDKKotlinx_coroutines_coreFlowCollector
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)emitValue:(id _Nullable)value completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("emit(value:completionHandler:)")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreEncoder")))
@protocol PCTSMSDKKotlinx_serialization_coreEncoder
@required
- (id<PCTSMSDKKotlinx_serialization_coreCompositeEncoder>)beginCollectionDescriptor:(id<PCTSMSDKKotlinx_serialization_coreSerialDescriptor>)descriptor collectionSize:(int32_t)collectionSize __attribute__((swift_name("beginCollection(descriptor:collectionSize:)")));
- (id<PCTSMSDKKotlinx_serialization_coreCompositeEncoder>)beginStructureDescriptor:(id<PCTSMSDKKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("beginStructure(descriptor:)")));
- (void)encodeBooleanValue:(BOOL)value __attribute__((swift_name("encodeBoolean(value:)")));
- (void)encodeByteValue:(int8_t)value __attribute__((swift_name("encodeByte(value:)")));
- (void)encodeCharValue:(unichar)value __attribute__((swift_name("encodeChar(value:)")));
- (void)encodeDoubleValue:(double)value __attribute__((swift_name("encodeDouble(value:)")));
- (void)encodeEnumEnumDescriptor:(id<PCTSMSDKKotlinx_serialization_coreSerialDescriptor>)enumDescriptor index:(int32_t)index __attribute__((swift_name("encodeEnum(enumDescriptor:index:)")));
- (void)encodeFloatValue:(float)value __attribute__((swift_name("encodeFloat(value:)")));
- (id<PCTSMSDKKotlinx_serialization_coreEncoder>)encodeInlineDescriptor:(id<PCTSMSDKKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("encodeInline(descriptor:)")));
- (void)encodeIntValue:(int32_t)value __attribute__((swift_name("encodeInt(value:)")));
- (void)encodeLongValue:(int64_t)value __attribute__((swift_name("encodeLong(value:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (void)encodeNotNullMark __attribute__((swift_name("encodeNotNullMark()")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (void)encodeNull __attribute__((swift_name("encodeNull()")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (void)encodeNullableSerializableValueSerializer:(id<PCTSMSDKKotlinx_serialization_coreSerializationStrategy>)serializer value:(id _Nullable)value __attribute__((swift_name("encodeNullableSerializableValue(serializer:value:)")));
- (void)encodeSerializableValueSerializer:(id<PCTSMSDKKotlinx_serialization_coreSerializationStrategy>)serializer value:(id _Nullable)value __attribute__((swift_name("encodeSerializableValue(serializer:value:)")));
- (void)encodeShortValue:(int16_t)value __attribute__((swift_name("encodeShort(value:)")));
- (void)encodeStringValue:(NSString *)value __attribute__((swift_name("encodeString(value:)")));
@property (readonly) PCTSMSDKKotlinx_serialization_coreSerializersModule *serializersModule __attribute__((swift_name("serializersModule")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreSerialDescriptor")))
@protocol PCTSMSDKKotlinx_serialization_coreSerialDescriptor
@required

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (NSArray<id<PCTSMSDKKotlinAnnotation>> *)getElementAnnotationsIndex:(int32_t)index __attribute__((swift_name("getElementAnnotations(index:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id<PCTSMSDKKotlinx_serialization_coreSerialDescriptor>)getElementDescriptorIndex:(int32_t)index __attribute__((swift_name("getElementDescriptor(index:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (int32_t)getElementIndexName:(NSString *)name __attribute__((swift_name("getElementIndex(name:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (NSString *)getElementNameIndex:(int32_t)index __attribute__((swift_name("getElementName(index:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (BOOL)isElementOptionalIndex:(int32_t)index __attribute__((swift_name("isElementOptional(index:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
@property (readonly) NSArray<id<PCTSMSDKKotlinAnnotation>> *annotations __attribute__((swift_name("annotations")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
@property (readonly) int32_t elementsCount __attribute__((swift_name("elementsCount")));
@property (readonly) BOOL isInline __attribute__((swift_name("isInline")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
@property (readonly) BOOL isNullable __attribute__((swift_name("isNullable")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
@property (readonly) PCTSMSDKKotlinx_serialization_coreSerialKind *kind __attribute__((swift_name("kind")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
@property (readonly) NSString *serialName __attribute__((swift_name("serialName")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreDecoder")))
@protocol PCTSMSDKKotlinx_serialization_coreDecoder
@required
- (id<PCTSMSDKKotlinx_serialization_coreCompositeDecoder>)beginStructureDescriptor:(id<PCTSMSDKKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("beginStructure(descriptor:)")));
- (BOOL)decodeBoolean __attribute__((swift_name("decodeBoolean()")));
- (int8_t)decodeByte __attribute__((swift_name("decodeByte()")));
- (unichar)decodeChar __attribute__((swift_name("decodeChar()")));
- (double)decodeDouble __attribute__((swift_name("decodeDouble()")));
- (int32_t)decodeEnumEnumDescriptor:(id<PCTSMSDKKotlinx_serialization_coreSerialDescriptor>)enumDescriptor __attribute__((swift_name("decodeEnum(enumDescriptor:)")));
- (float)decodeFloat __attribute__((swift_name("decodeFloat()")));
- (id<PCTSMSDKKotlinx_serialization_coreDecoder>)decodeInlineDescriptor:(id<PCTSMSDKKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("decodeInline(descriptor:)")));
- (int32_t)decodeInt __attribute__((swift_name("decodeInt()")));
- (int64_t)decodeLong __attribute__((swift_name("decodeLong()")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (BOOL)decodeNotNullMark __attribute__((swift_name("decodeNotNullMark()")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (PCTSMSDKKotlinNothing * _Nullable)decodeNull __attribute__((swift_name("decodeNull()")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id _Nullable)decodeNullableSerializableValueDeserializer:(id<PCTSMSDKKotlinx_serialization_coreDeserializationStrategy>)deserializer __attribute__((swift_name("decodeNullableSerializableValue(deserializer:)")));
- (id _Nullable)decodeSerializableValueDeserializer:(id<PCTSMSDKKotlinx_serialization_coreDeserializationStrategy>)deserializer __attribute__((swift_name("decodeSerializableValue(deserializer:)")));
- (int16_t)decodeShort __attribute__((swift_name("decodeShort()")));
- (NSString *)decodeString __attribute__((swift_name("decodeString()")));
@property (readonly) PCTSMSDKKotlinx_serialization_coreSerializersModule *serializersModule __attribute__((swift_name("serializersModule")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreCompositeEncoder")))
@protocol PCTSMSDKKotlinx_serialization_coreCompositeEncoder
@required
- (void)encodeBooleanElementDescriptor:(id<PCTSMSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(BOOL)value __attribute__((swift_name("encodeBooleanElement(descriptor:index:value:)")));
- (void)encodeByteElementDescriptor:(id<PCTSMSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(int8_t)value __attribute__((swift_name("encodeByteElement(descriptor:index:value:)")));
- (void)encodeCharElementDescriptor:(id<PCTSMSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(unichar)value __attribute__((swift_name("encodeCharElement(descriptor:index:value:)")));
- (void)encodeDoubleElementDescriptor:(id<PCTSMSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(double)value __attribute__((swift_name("encodeDoubleElement(descriptor:index:value:)")));
- (void)encodeFloatElementDescriptor:(id<PCTSMSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(float)value __attribute__((swift_name("encodeFloatElement(descriptor:index:value:)")));
- (id<PCTSMSDKKotlinx_serialization_coreEncoder>)encodeInlineElementDescriptor:(id<PCTSMSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("encodeInlineElement(descriptor:index:)")));
- (void)encodeIntElementDescriptor:(id<PCTSMSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(int32_t)value __attribute__((swift_name("encodeIntElement(descriptor:index:value:)")));
- (void)encodeLongElementDescriptor:(id<PCTSMSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(int64_t)value __attribute__((swift_name("encodeLongElement(descriptor:index:value:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (void)encodeNullableSerializableElementDescriptor:(id<PCTSMSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index serializer:(id<PCTSMSDKKotlinx_serialization_coreSerializationStrategy>)serializer value:(id _Nullable)value __attribute__((swift_name("encodeNullableSerializableElement(descriptor:index:serializer:value:)")));
- (void)encodeSerializableElementDescriptor:(id<PCTSMSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index serializer:(id<PCTSMSDKKotlinx_serialization_coreSerializationStrategy>)serializer value:(id _Nullable)value __attribute__((swift_name("encodeSerializableElement(descriptor:index:serializer:value:)")));
- (void)encodeShortElementDescriptor:(id<PCTSMSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(int16_t)value __attribute__((swift_name("encodeShortElement(descriptor:index:value:)")));
- (void)encodeStringElementDescriptor:(id<PCTSMSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(NSString *)value __attribute__((swift_name("encodeStringElement(descriptor:index:value:)")));
- (void)endStructureDescriptor:(id<PCTSMSDKKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("endStructure(descriptor:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (BOOL)shouldEncodeElementDefaultDescriptor:(id<PCTSMSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("shouldEncodeElementDefault(descriptor:index:)")));
@property (readonly) PCTSMSDKKotlinx_serialization_coreSerializersModule *serializersModule __attribute__((swift_name("serializersModule")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreSerializersModule")))
@interface PCTSMSDKKotlinx_serialization_coreSerializersModule : PCTSMSDKBase

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (void)dumpToCollector:(id<PCTSMSDKKotlinx_serialization_coreSerializersModuleCollector>)collector __attribute__((swift_name("dumpTo(collector:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id<PCTSMSDKKotlinx_serialization_coreKSerializer> _Nullable)getContextualKClass:(id<PCTSMSDKKotlinKClass>)kClass typeArgumentsSerializers:(NSArray<id<PCTSMSDKKotlinx_serialization_coreKSerializer>> *)typeArgumentsSerializers __attribute__((swift_name("getContextual(kClass:typeArgumentsSerializers:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id<PCTSMSDKKotlinx_serialization_coreSerializationStrategy> _Nullable)getPolymorphicBaseClass:(id<PCTSMSDKKotlinKClass>)baseClass value:(id)value __attribute__((swift_name("getPolymorphic(baseClass:value:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id<PCTSMSDKKotlinx_serialization_coreDeserializationStrategy> _Nullable)getPolymorphicBaseClass:(id<PCTSMSDKKotlinKClass>)baseClass serializedClassName:(NSString * _Nullable)serializedClassName __attribute__((swift_name("getPolymorphic(baseClass:serializedClassName:)")));
@end

__attribute__((swift_name("KotlinAnnotation")))
@protocol PCTSMSDKKotlinAnnotation
@required
@end


/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
__attribute__((swift_name("Kotlinx_serialization_coreSerialKind")))
@interface PCTSMSDKKotlinx_serialization_coreSerialKind : PCTSMSDKBase
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreCompositeDecoder")))
@protocol PCTSMSDKKotlinx_serialization_coreCompositeDecoder
@required
- (BOOL)decodeBooleanElementDescriptor:(id<PCTSMSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeBooleanElement(descriptor:index:)")));
- (int8_t)decodeByteElementDescriptor:(id<PCTSMSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeByteElement(descriptor:index:)")));
- (unichar)decodeCharElementDescriptor:(id<PCTSMSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeCharElement(descriptor:index:)")));
- (int32_t)decodeCollectionSizeDescriptor:(id<PCTSMSDKKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("decodeCollectionSize(descriptor:)")));
- (double)decodeDoubleElementDescriptor:(id<PCTSMSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeDoubleElement(descriptor:index:)")));
- (int32_t)decodeElementIndexDescriptor:(id<PCTSMSDKKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("decodeElementIndex(descriptor:)")));
- (float)decodeFloatElementDescriptor:(id<PCTSMSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeFloatElement(descriptor:index:)")));
- (id<PCTSMSDKKotlinx_serialization_coreDecoder>)decodeInlineElementDescriptor:(id<PCTSMSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeInlineElement(descriptor:index:)")));
- (int32_t)decodeIntElementDescriptor:(id<PCTSMSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeIntElement(descriptor:index:)")));
- (int64_t)decodeLongElementDescriptor:(id<PCTSMSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeLongElement(descriptor:index:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id _Nullable)decodeNullableSerializableElementDescriptor:(id<PCTSMSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index deserializer:(id<PCTSMSDKKotlinx_serialization_coreDeserializationStrategy>)deserializer previousValue:(id _Nullable)previousValue __attribute__((swift_name("decodeNullableSerializableElement(descriptor:index:deserializer:previousValue:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (BOOL)decodeSequentially __attribute__((swift_name("decodeSequentially()")));
- (id _Nullable)decodeSerializableElementDescriptor:(id<PCTSMSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index deserializer:(id<PCTSMSDKKotlinx_serialization_coreDeserializationStrategy>)deserializer previousValue:(id _Nullable)previousValue __attribute__((swift_name("decodeSerializableElement(descriptor:index:deserializer:previousValue:)")));
- (int16_t)decodeShortElementDescriptor:(id<PCTSMSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeShortElement(descriptor:index:)")));
- (NSString *)decodeStringElementDescriptor:(id<PCTSMSDKKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeStringElement(descriptor:index:)")));
- (void)endStructureDescriptor:(id<PCTSMSDKKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("endStructure(descriptor:)")));
@property (readonly) PCTSMSDKKotlinx_serialization_coreSerializersModule *serializersModule __attribute__((swift_name("serializersModule")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinNothing")))
@interface PCTSMSDKKotlinNothing : PCTSMSDKBase
@end


/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
__attribute__((swift_name("Kotlinx_serialization_coreSerializersModuleCollector")))
@protocol PCTSMSDKKotlinx_serialization_coreSerializersModuleCollector
@required
- (void)contextualKClass:(id<PCTSMSDKKotlinKClass>)kClass provider:(id<PCTSMSDKKotlinx_serialization_coreKSerializer> (^)(NSArray<id<PCTSMSDKKotlinx_serialization_coreKSerializer>> *))provider __attribute__((swift_name("contextual(kClass:provider:)")));
- (void)contextualKClass:(id<PCTSMSDKKotlinKClass>)kClass serializer:(id<PCTSMSDKKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("contextual(kClass:serializer:)")));
- (void)polymorphicBaseClass:(id<PCTSMSDKKotlinKClass>)baseClass actualClass:(id<PCTSMSDKKotlinKClass>)actualClass actualSerializer:(id<PCTSMSDKKotlinx_serialization_coreKSerializer>)actualSerializer __attribute__((swift_name("polymorphic(baseClass:actualClass:actualSerializer:)")));
- (void)polymorphicDefaultBaseClass:(id<PCTSMSDKKotlinKClass>)baseClass defaultDeserializerProvider:(id<PCTSMSDKKotlinx_serialization_coreDeserializationStrategy> _Nullable (^)(NSString * _Nullable))defaultDeserializerProvider __attribute__((swift_name("polymorphicDefault(baseClass:defaultDeserializerProvider:)"))) __attribute__((deprecated("Deprecated in favor of function with more precise name: polymorphicDefaultDeserializer")));
- (void)polymorphicDefaultDeserializerBaseClass:(id<PCTSMSDKKotlinKClass>)baseClass defaultDeserializerProvider:(id<PCTSMSDKKotlinx_serialization_coreDeserializationStrategy> _Nullable (^)(NSString * _Nullable))defaultDeserializerProvider __attribute__((swift_name("polymorphicDefaultDeserializer(baseClass:defaultDeserializerProvider:)")));
- (void)polymorphicDefaultSerializerBaseClass:(id<PCTSMSDKKotlinKClass>)baseClass defaultSerializerProvider:(id<PCTSMSDKKotlinx_serialization_coreSerializationStrategy> _Nullable (^)(id))defaultSerializerProvider __attribute__((swift_name("polymorphicDefaultSerializer(baseClass:defaultSerializerProvider:)")));
@end

__attribute__((swift_name("KotlinKDeclarationContainer")))
@protocol PCTSMSDKKotlinKDeclarationContainer
@required
@end

__attribute__((swift_name("KotlinKAnnotatedElement")))
@protocol PCTSMSDKKotlinKAnnotatedElement
@required
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.1")
*/
__attribute__((swift_name("KotlinKClassifier")))
@protocol PCTSMSDKKotlinKClassifier
@required
@end

__attribute__((swift_name("KotlinKClass")))
@protocol PCTSMSDKKotlinKClass <PCTSMSDKKotlinKDeclarationContainer, PCTSMSDKKotlinKAnnotatedElement, PCTSMSDKKotlinKClassifier>
@required

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.1")
*/
- (BOOL)isInstanceValue:(id _Nullable)value __attribute__((swift_name("isInstance(value:)")));
@property (readonly) NSString * _Nullable qualifiedName __attribute__((swift_name("qualifiedName")));
@property (readonly) NSString * _Nullable simpleName __attribute__((swift_name("simpleName")));
@end

#pragma pop_macro("_Nullable_result")
#pragma clang diagnostic pop
NS_ASSUME_NONNULL_END
