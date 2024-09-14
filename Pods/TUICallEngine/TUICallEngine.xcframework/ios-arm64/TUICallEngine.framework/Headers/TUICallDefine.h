//
//  TUICallDefine.h
//  TUICallKit
//
//  Created by noah on 2022/9/15.
//  Copyright © 2022 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TUICallEngine/TUICommonDefine.h>

@class TUIOfflinePushInfo;

typedef void (^TUICallSucc)(void);
typedef void (^TUICallFail)(int code, NSString *_Nullable errMsg);

/// TUICallEngine Version
static const NSString * _Nullable TUICALL_VERSION = @"2.5.0.1025";

/// You do not have TUICallKit package, please open the free experience in the console or purchase the official package
static const int ERROR_PACKAGE_NOT_PURCHASED = -1001;

/// The package you purchased does not support this ability
static const int ERROR_PACKAGE_NOT_SUPPORTED = -1002;

/// TIM  SDK version is too old, Please upgrade version >= 6.6
static const int ERROR_TIM_VERSION_OUTDATED = -1003;

/// Camera or microphone not authorized
static const int ERROR_PERMISSION_DENIED = -1101;

/// not login , please call init() in TUICallEngine first
static const int ERROR_INIT_FAIL = -1201;

/// Params error
static const int ERROR_PARAM_INVALID = -1202;

/// Current status not support
static const int ERROR_REQUEST_REFUSED = -1203;

/// The current method is calling, Do not call it repeatedly
static const int ERROR_REQUEST_REPEATED = -1204;

/// This function is not supported in the current call scene
static const int ERROR_SCENE_NOT_SUPPORTED = -1205;

/// Signaling send failed
static const int ERROR_SIGNALING_SEND_FAIL = -1401;

/// Media type
typedef NS_ENUM(NSInteger, TUICallMediaType) {
    TUICallMediaTypeUnknown,
    TUICallMediaTypeAudio,
    TUICallMediaTypeVideo,
};

/// Call role
typedef NS_ENUM(NSUInteger, TUICallRole) {
    TUICallRoleNone,
    TUICallRoleCall,
    TUICallRoleCalled,
};

/// Call status
typedef NS_ENUM(NSUInteger, TUICallStatus) {
    TUICallStatusNone,
    TUICallStatusWaiting,
    TUICallStatusAccept,
};

/// Call scene
typedef NS_ENUM(NSUInteger, TUICallScene) {
    TUICallSceneGroup,
    TUICallSceneMulti,
    TUICallSceneSingle,
};

/// CallResult
typedef NS_ENUM(NSUInteger, TUICallResultType) {
    TUICallResultTypeUnknown,
    TUICallResultTypeMissed,
    TUICallResultTypeIncoming,
    TUICallResultTypeOutgoing,
};

typedef NS_ENUM(NSInteger, TUICallIOSOfflinePushType) {
    TUICallIOSOfflinePushTypeAPNs = 0,  // APNs
    TUICallIOSOfflinePushTypeVoIP = 1,  // VoIP
};

/// OfflinePushInfo
NS_ASSUME_NONNULL_BEGIN

@interface TUIOfflinePushInfo : NSObject

@property(nonatomic, copy) NSString *title;

@property(nonatomic, copy) NSString *desc;

@property(nonatomic, assign) BOOL isDisablePush;

/// Default: TUICallIOSOfflinePushTypeAPNs
@property(nonatomic, assign) TUICallIOSOfflinePushType iOSPushType;

@property(nonatomic, assign) BOOL ignoreIOSBadge;

@property(nonatomic, copy) NSString *iOSSound;

@property(nonatomic, copy) NSString *AndroidSound;

@property(nonatomic, copy) NSString *AndroidOPPOChannelID;

@property(nonatomic, copy) NSString *AndroidFCMChannelID;

@property(nonatomic, copy) NSString *AndroidXiaoMiChannelID;

@property(nonatomic, assign) NSInteger AndroidVIVOClassification;

@property(nonatomic, copy) NSString *AndroidHuaWeiCategory;

@end

/// Extension param
@interface TUICallParams : NSObject

@property(nonatomic, strong) TUIRoomId *roomId;

@property(nonatomic, strong) TUIOfflinePushInfo *offlinePushInfo;

@property(nonatomic, assign) int timeout;

/// Extended Fields: Used to add extended information in invitation signaling
@property(nonatomic, copy) NSString *userData;

@end

@interface TUICallRecords : NSObject

@property(nonatomic, copy) NSString *callId;

@property(nonatomic, copy) NSString *inviter;

@property(nonatomic, strong) NSArray *inviteList;

@property(nonatomic, assign) TUICallScene scene;

@property(nonatomic, assign) TUICallMediaType mediaType;

@property(nonatomic, copy) NSString *groupId;

@property(nonatomic, assign) TUICallRole role;

@property(nonatomic, assign) TUICallResultType result;

@property(nonatomic, assign) NSTimeInterval beginTime;

@property(nonatomic, assign) NSTimeInterval totalTime;

@end

@interface TUICallRecentCallsFilter : NSObject

@property(nonatomic, assign) NSTimeInterval begin;

@property(nonatomic, assign) NSTimeInterval end;

@property(nonatomic, assign) TUICallResultType result;

@end

NS_ASSUME_NONNULL_END
