//
// Copyright (c) 2023 Tencent. All rights reserved.
//
//
// ===============================================================
// ====================== TIMPush 高级用法 ========================
// ===============================================================
// 【一、基础说明】
// `TIMPushDelegate.h`中的【TIMPush接入指南】 已引导您完成基本推送，另外，我们还提供了一些高级用法:
// 如果您想统计 TIMPush 的推送抵达率，可以参考 【三、统计推送抵达率】
// 如果 TIMPush 依然满足不了您的需求，欢迎点击【 https://zhiliao.qq.com/s/c5GY7HIM62CK/c35MJIIM62CB 】 反馈。
//
// 【二、手动注册推送服务】(仅(pod 'TIMPush') 方式使用推送服务时支持此行为)
// 如果您未接入TUICore组件，不需要使用 TUILogin 的登录/登出，但依然想实现离线推送，您只需：
// - 调用 [TIMPush disableAutoRegisterPush];
// - 在您的 APP/IM 登录完成后，主动调用 registerPush 方法注册推送
// - 退出登录时，主动调用 unRegisterPush 方法 反注册推送
//
// 【三、统计推送抵达率】
// 如果您需要统计推送的抵达和点击数据
// 您需要在 AppDelegate.m 文件中实现 `- applicationGroupID` 方法，返回 App Group ID。
// 并在 Notification Service Extension 的 '- didReceiveNotificationRequest:withContentHandler:' 方法中调用
// 推送抵达率统计函数:'+ (void)onReceiveNotificationRequest:inAppGroupID:callback:'
//
// 【四、关于合规】
// - TIMPush 在您未主动调用 registerPush 之前，不会有其他任何操作，符合相关规定
// - 如果您使用了 TUILogin 的登录登出，TIMPush 会在内部自动调用 registerPush / unRegisterPush。
// ================================================================
// ================================================================
// ================================================================


#import <Foundation/Foundation.h>
#import <UserNotifications/UserNotifications.h>
#import "TIMPushDelegate.h"

NS_ASSUME_NONNULL_BEGIN

typedef void(^TIMPushNotificationExtensionCallback)(UNNotificationContent *content) API_AVAILABLE(macos(10.14), ios(10.0), watchos(3.0), tvos(10.0));
typedef void(^TIMPushCallback)(void);
typedef void(^TIMPushValueCallback)(NSString *value);
typedef void(^TIMPushSuccessCallback)(NSData * deviceToken);
typedef void(^TIMPushFailedCallback)(int code, NSString * desc);

@interface TIMPushManager : NSObject


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                      （一）注册/反注册推送服务
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * 1.1 注册推送服务  [通过 ( pod 'TIMPush' ) 方式使用推送服务时，请您调用这个 API]
 *
 * @note
 * - 在登录完成之后调用
 * - 如果您使用了 [TUILogin](https://github.com/TencentCloud/TIMSDK/blob/master/iOS/TUIKit/TUICore/TUILogin.h) 提供的 login/logout，无需再调用该接口
 */

+ (void)registerPush:(TIMPushSuccessCallback)successCallback
                fail:(TIMPushFailedCallback)failedCallback
                NS_EXTENSION_UNAVAILABLE_IOS("This API is not supported in App Extension");

/**
 * 1.2 注册推送服务  [通过 ( pod 'TPush' ) 方式使用推送服务时，请您调用这个 API]
 *
 * @note 请注意：
 * - 调用该接口就会开启离线推送服务
 * - 考虑上线合规，必须在 APP用户同意了隐私政策，并且确定为 APP用户开始提供推送服务后，再调用该接口使用离线推送服务
 *
 * @param sdkAppId 应用的 SDKAPPID
 * @param appKey 控制台为您分配的 secretKey
 */

+ (void)registerPush:(int)sdkAppId inAppKey:(NSString *)appKey
                succ:(TIMPushSuccessCallback)successCallback
                fail:(TIMPushFailedCallback)failedCallback NS_EXTENSION_UNAVAILABLE_IOS("This API is not supported in App Extension");
/**
 * 1.3 取消注册
 *
 * @note
 * - 在退出登录时调用
 * - 如果您使用了 [TUILogin](https://github.com/TencentCloud/TIMSDK/blob/master/iOS/TUIKit/TUICore/TUILogin.h) 提供的 login/logout，无需再调用该接口
 */
+ (void)unRegisterPush:(TIMPushCallback)successCallback
                  fail:(TIMPushFailedCallback)failedCallback
                                    NS_EXTENSION_UNAVAILABLE_IOS("This API is not supported in App Extension");


/**
 * 1.4 关闭插件在登录后自动注册推送服务，需要在注册推送服务之前调用
 *
 * @note
 *  - 插件默认自动注册推送Service
 *  - 如果您使用了 [TUILogin](https://github.com/TencentCloud/TIMSDK/blob/master/iOS/TUIKit/TUICore/TUILogin.h) 提供的 login/logout，无需再调用该接口
 */
+ (void)disableAutoRegisterPush NS_EXTENSION_UNAVAILABLE_IOS("This API is not supported in App Extension");


/**
 * 1.5 注册离线推送服务成功后，获取注册 ID 标识, 即 RegistrationID
 *
 *  @note 请注意：
 *  - callback 回调值是 registerPush 时候传递的 userId
 *  - 若传递 userId 为空，则为设备的标识 ID，卸载重装会改变。
 *
 */
+ (void)getRegistrationID:(TIMPushValueCallback)callback NS_EXTENSION_UNAVAILABLE_IOS("This API is not supported in App Extension");


/**
 * 1.6 设置注册离线推送服务使用的推送 ID 标识, 即 RegistrationID，需要在注册推送服务之前调用
 *
 *  @param  registrationID 为设备的推送标识 ID，卸载重装会改变。
 *
 */
+ (void)setRegistrationID:(NSString *)registrationID callback:(TIMPushCallback)callback NS_EXTENSION_UNAVAILABLE_IOS("This API is not supported in App Extension");


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                      （二）统计 TIMPush 的推送抵达率
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * 2.1 统计 TIMPush 的推送抵达率
 *
 * @note 请注意：
 * - 仅支持在 Notification Service Extension 的 '- didReceiveNotificationRequest:withContentHandler:' 方法中调用；
 * - appGroup 标识当前主 APP 和 Extension 之间共享的 APP Group，需要在主 APP 的 Capability 中配置 App Groups 能力。
 * - 可以点击[https://cloud.tencent.com/document/product/269/100627#a76b331f-3d49-48c9-99a9-5301c7d7fa99]查阅详细步骤
 */
+ (void)onReceiveNotificationRequest:(UNNotificationRequest *)request inAppGroupID:(NSString *)appGroupID callback:(TIMPushNotificationExtensionCallback)callback NS_SWIFT_NAME(onReceiveNotificationRequest(request:inAppGroupID:callback:));

@end

NS_ASSUME_NONNULL_END

