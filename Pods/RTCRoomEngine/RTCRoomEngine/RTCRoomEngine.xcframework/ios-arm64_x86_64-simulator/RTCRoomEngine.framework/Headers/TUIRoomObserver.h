/**
 * Copyright (c) 2024 Tencent. All rights reserved.
 * Module:   TUIRoomObserver @ TUIKitEngine
 * Function: TUIRoomEngine的事件回调接口
 */
#import <Foundation/Foundation.h>
#import "TUIRoomDefine.h"
#import "TUIRoomDeviceManager.h"

NS_ASSUME_NONNULL_BEGIN

@protocol TUIRoomObserver <NSObject>
@optional

/////////////////////////////////////////////////////////////////////////////////
//
//                      错误事件回调
//
///////////////////////////////////////////////////////////////

/**
 * 1.1 错误事件回调
 *
 * 错误事件，表示 SDK 抛出的不可恢复的错误，例如进入房间失败或设备开启失败等。
 * @param errorCode 错误码，请参见：{@link TUIError}。
 * @param message  错误信息。
 */
- (void)onError:(TUIError)errorCode message:(NSString *)message NS_SWIFT_NAME(onError(error:message:));

/////////////////////////////////////////////////////////////////////////////////
//
//                   登录状态事件回调
//
/////////////////////////////////////////////////////////////////////////////////

/**
 * 2.1 用户被踢下线
 *
 * @param message 被踢下线的描述。
 */
- (void)onKickedOffLine:(NSString *)message NS_SWIFT_NAME(onKickedOffLine(message:));

/**
 * 2.2 用户凭证超时事件
 */
- (void)onUserSigExpired NS_SWIFT_NAME(onUserSigExpired());

/////////////////////////////////////////////////////////////////////////////////
//
//                   房间内事件回调
//
/////////////////////////////////////////////////////////////////////////////////

/**
 * 3.1 房间名称更改事件
 *
 * @param roomId 房间ID。
 * @param roomName 房间名称。
 */
- (void)onRoomNameChanged:(NSString *)roomId roomName:(NSString *)roomName NS_SWIFT_NAME(onRoomNameChanged(roomId:roomName:));

/**
 * 3.2 房间内所有用户麦克风被禁用事件
 *
 * @param roomId 房间ID。
 * @param isDisable 是否被禁用。
 */
- (void)onAllUserMicrophoneDisableChanged:(NSString *)roomId isDisable:(BOOL)isDisable NS_SWIFT_NAME(onAllUserMicrophoneDisableChanged(roomId:isDisable:));

/**
 * 3.3 房间内所有用户摄像头被禁用事件
 *
 * @param roomId 房间ID。
 * @param isDisable 是否被禁用。
 */
- (void)onAllUserCameraDisableChanged:(NSString *)roomId isDisable:(BOOL)isDisable NS_SWIFT_NAME(onAllUserCameraDisableChanged(roomId:isDisable:));

/**
 * 3.4 房间内所有用户屏幕分享被禁用事件
 *
 * @param roomId 房间ID。
 * @param isDisable 是否被禁用。
 */
- (void)onScreenShareForAllUserDisableChanged:(NSString *)roomId isDisable:(BOOL)isDisable NS_SWIFT_NAME(onScreenShareForAllUserDisableChanged(roomId:isDisable:));

/**
 * 3.5 房间内用户发送文本消息被禁用事件
 *
 * @param roomId 房间ID。
 * @param isDisable 是否被禁用。
 */
- (void)onSendMessageForAllUserDisableChanged:(NSString *)roomId isDisable:(BOOL)isDisable NS_SWIFT_NAME(onSendMessageForAllUserDisableChanged(roomId:isDisable:));

/**
 * 3.6 房间被解散事件
 *
 * @param roomId 房间ID。
 * @param reason 房间解散原因，请参见：{@link TUIRoomDismissedReason}。
 */
- (void)onRoomDismissed:(NSString *)roomId reason:(TUIRoomDismissedReason)reason NS_SWIFT_NAME(onRoomDismissed(roomId:reason:));

/**
 * 3.7 被踢出房间事件
 *
 * @param roomId 房间ID。
 * @param reason 被踢出原因。
 * @param message 被踢出的描述。
 */
- (void)onKickedOutOfRoom:(NSString *)roomId reason:(TUIKickedOutOfRoomReason)reason message:(NSString *)message NS_SWIFT_NAME(onKickedOutOfRoom(roomId:reason:message:));

/**
 * 3.8 房间上麦模式发生变化
 * @param roomId 房间ID。
 * @param seatMode 上麦模式。
 */
- (void)onRoomSeatModeChanged:(NSString *)roomId seatMode:(TUISeatMode)seatMode NS_SWIFT_NAME(onRoomSeatModeChanged(roomId:seatMode:));

/**
 * 3.9 房间内人员数量发生变化
 * @param roomId 房间ID。
 * @param userCount 人员数量。
 */
- (void)onRoomUserCountChanged:(NSString *)roomId userCount:(NSInteger)userCount NS_SWIFT_NAME(onRoomUserCountChanged(roomId:userCount:));

/////////////////////////////////////////////////////////////////////////////////
//
//                   房间内用户事件回调
//
/////////////////////////////////////////////////////////////////////////////////

/**
 * 4.1 远端用户进房事件
 *
 * @param roomId 房间ID。
 * @param userInfo 用户信息。
 */
- (void)onRemoteUserEnterRoom:(NSString *)roomId userInfo:(TUIUserInfo *)userInfo NS_SWIFT_NAME(onRemoteUserEnterRoom(roomId:userInfo:));

/**
 * 4.2 远端用户离开房间事件
 *
 * @param roomId 房间ID。
 * @param userInfo 用户信息。
 */
- (void)onRemoteUserLeaveRoom:(NSString *)roomId userInfo:(TUIUserInfo *)userInfo NS_SWIFT_NAME(onRemoteUserLeaveRoom(roomId:userInfo:));

/**
 * 4.3 房间内用户信息发生变化事件。
 *
 * @param userInfo 用户信息。
 * @param modifyFlag 用户信息参数变更Key, 可参考{@link TUIUserInfoModifyFlag}。
 */
- (void)onUserInfoChanged:(TUIUserInfo *)userInfo modifyFlag:(TUIUserInfoModifyFlag)modifyFlag NS_SWIFT_NAME(onUserInfoChanged(userInfo:modifyFlag:));

/**
 * 4.4 用户视频状态发生变化事件
 *
 * @param userId 用户ID。
 * @param streamType 视频流类型。
 * @param hasVideo 是否有视频流。
 * @param reason 视频流发生变化原因 {@link TUIChangeReasonBySelf}: 自己切换  {@link TUIChangeReasonByAdmin}: 被管理员切换。
 */
- (void)onUserVideoStateChanged:(NSString *)userId streamType:(TUIVideoStreamType)streamType hasVideo:(BOOL)hasVideo reason:(TUIChangeReason)reason NS_SWIFT_NAME(onUserVideoStateChanged(userId:streamType:hasVideo:reason:));

/**
 * 4.5 用户音频状态发生变化事件
 *
 * @param userId 用户ID。
 * @param hasAudio 是否有音频流。
 * @param reason 视频流发生变化原因 {@link TUIChangeReasonBySelf}: 自己切换  {@link TUIChangeReasonByAdmin}: 被管理员切换。
 */
- (void)onUserAudioStateChanged:(NSString *)userId hasAudio:(BOOL)hasAudio reason:(TUIChangeReason)reason NS_SWIFT_NAME(onUserAudioStateChanged(userId:hasAudio:reason:));

/**
 * 4.6 用户音量变化事件
 *
 * @param volumeMap 用户音量字典 key: userId, value: 用于承载所有正在说话的用户的音量大小，取值范围 0 - 100。
 */
- (void)onUserVoiceVolumeChanged:(NSDictionary<NSString *, NSNumber *> *)volumeMap NS_SWIFT_NAME(onUserVoiceVolumeChanged(volumeMap:));

/**
 * 4.7 用户文本消息发送能力发生变化事件
 *
 * @param userId 用户ID。
 * @param isDisable 是否被禁止发送文本消息 {@link YES}: 用户被禁止发送消息 {@link NO}: 用户被解除禁止，可以发送消息。
 */
- (void)onSendMessageForUserDisableChanged:(NSString *)roomId userId:(NSString *)userId isDisable:(BOOL)muted NS_SWIFT_NAME(OnSendMessageForUserDisableChanged(roomId:userId:isDisable:));

/**
 * 4.8 用户网络状态变化事件
 *
 * @param networkList 用户网络状态数组，可参见 {@link TUINetworkInfo} 对象。
 */
- (void)onUserNetworkQualityChanged:(NSArray<TUINetworkInfo *> *)networkList NS_SWIFT_NAME(onUserNetworkQualityChanged(networkList:));

/**
 * 4.10  屏幕分享结束
 *
 * @param reason 停止原因，0：用户主动停止；1：屏幕窗口关闭导致停止；2：表示屏幕分享的显示屏状态变更（如接口被拔出、投影模式变更等）。
 */
- (void)onUserScreenCaptureStopped:(NSInteger)reason NS_SWIFT_NAME(onUserScreenCaptureStopped(reason:));

/////////////////////////////////////////////////////////////////////////////////
//
//                   房间内麦位事件回调
//
/////////////////////////////////////////////////////////////////////////////////

/**
 * 5.1 房间内最大麦位数发生变化事件（仅在会议类型房间生效）
 *
 * @param roomId 房间ID。
 * @param maxSeatCount 房间内最大麦位数量。
 */
- (void)onRoomMaxSeatCountChanged:(NSString *)roomId maxSeatNumber:(NSInteger)maxSeatNumber NS_SWIFT_NAME(onRoomMaxSeatCountChanged(roomId:maxSeatCount:));

/**
 * 5.2 麦位列表发生变化事件
 *
 * @param seatList 目前麦上最新的用户列表，包含新上麦的用户。
 * @param seatedList 新上麦的用户列表。
 * @param leftList 新下麦的用户列表。
 */
- (void)onSeatListChanged:(NSArray<TUISeatInfo *> *)seatList seated:(NSArray<TUISeatInfo *> *)seatedList left:(NSArray<TUISeatInfo *> *)leftList NS_SWIFT_NAME(onSeatListChanged(seatList:seated:left:));

/**
 * 5.3 收到用户被踢下麦事件
 *
 * @param seatIndex 麦位编号。
 * @param operateUser 操作踢人的（主持人/管理员）用户信息。
 */
- (void)onKickedOffSeat:(NSInteger)seatIndex operateUser:(TUIUserInfo *)operateUser NS_SWIFT_NAME(onKickedOffSeat(seatIndex:operateUser:));

/////////////////////////////////////////////////////////////////////////////////
//
//                   请求信令事件回调
//
/////////////////////////////////////////////////////////////////////////////////

/**
 * 6.1 收到请求消息事件
 *
 * @param request 请求内容，可参见 {@link TUIRequest} 对象。
 */
- (void)onRequestReceived:(TUIRequest *)request NS_SWIFT_NAME(onRequestReceived(request:));

/**
 * 6.2 收到请求被取消的事件
 *
 * @param request 请求内容，可参见 {@link TUIRequest} 对象。
 * @param operateUser 取消信令的用户信息。
 */
- (void)onRequestCancelled:(TUIRequest *)request operateUser:(TUIUserInfo *)operateUser NS_SWIFT_NAME(onRequestCancelled(request:operateUser:));

/**
 * 6.3 收到请求被其他 管理员/房主 处理事件
 *
 * @param request 请求内容，可参见 {@link TUIRequest} 对象。
 * @param operateUser 取消信令的用户信息。
 */
- (void)onRequestProcessed:(TUIRequest *)request operateUser:(TUIUserInfo *)operateUser NS_SWIFT_NAME(onRequestProcessed(request:operateUser:));

/////////////////////////////////////////////////////////////////////////////////
//
//                   废弃回调
//
/////////////////////////////////////////////////////////////////////////////////

#if !TARGET_OS_IPHONE && TARGET_OS_MAC

/**
 * 本地设备添加事件
 *
 * @deprecated v2.0 版本开始不推荐使用,建议使用{$TUIRoomDeviceManager$}中的{@link onDeviceChanged}代替。
 * @note 当本地设备（包括摄像头、麦克风以及扬声器）添加时，SDK 便会抛出此事件回调。
 * @param deviceId 设备 ID。
 * @param type 设备类型。
 * @param state 通断状态，0：设备已添加；1：设备已被移除；2：设备已启用。
 */
- (void)onDeviceChanged:(NSString *)deviceId type:(TUIMediaDeviceType)type state:(TUIMediaDeviceState)state NS_SWIFT_NAME(onDeviceChanged(deviceId:type:state:)) __attribute__((deprecated("use onDeviceChanged in TUIRoomDeviceManager instead")));

#endif

/**
 * 房间被解散事件
 *
 * @deprecated v2.3.0 版本开始不推荐使用,建议使用带{@link TUIRoomDismissedReason}的{@link onRoomDismissed}代替。
 * @note 此回调将于v2.8.0版本删除，建议您使用新的回调代替。
 * @param roomId 房间ID。
 */
- (void)onRoomDismissed:(NSString *)roomId NS_SWIFT_NAME(onRoomDismissed(roomId:)) __attribute__((deprecated("Deprecated from v2.3.0")));

/**
 * 用户角色发生变化事件
 *
 * @param userInfo 用户信息。
 */
- (void)onUserRoleChanged:(TUIUserInfo *)userInfo NS_SWIFT_NAME(onUserRoleChanged(userInfo:)) __attribute__((deprecated("Deprecated from v2.5.0")));

/**
 * 用户角色发生变化事件
 *
 * @deprecated v2.3.0 版本开始不推荐使用,建议使用带{@link TUIUserInfo}的{@link onUserRoleChanged}代替。
 * @note 此回调将于v2.8.0版本删除，建议您使用新的回调代替。
 * @param userId 用户ID。
 * @param userRole 用户角色 可参见 {@link TUIRole} 枚举定义。
 */
- (void)onUserRoleChanged:(NSString *)userId userRole:(TUIRole)userRole NS_SWIFT_NAME(onUserRoleChanged(userId:userRole:)) __attribute__((deprecated("Deprecated from v2.3.0")));

/**
 * 收到用户被踢下麦事件
 *
 * @deprecated v2.3.0 版本开始不推荐使用,建议使用带{@link TUIUserInfo}的{@link onKickedOffSeat}代替。
 * @note 此回调将于v2.8.0版本删除，建议您使用新的回调代替。
 * @param userId 操作踢人的（主持人/管理员）用户id。
 */
- (void)onKickedOffSeat:(NSString *)userId NS_SWIFT_NAME(onKickedOffSeat(userId:)) __attribute__((deprecated("Deprecated from v2.3.0")));

/**
 * 收到请求被取消的事件
 *
 * @deprecated v2.3.0 版本开始不推荐使用,建议使用带{@link TUIRequest}的{@link onRequestCancelled}代替。
 * @note 此回调将于v2.8.0版本删除，建议您使用新的回调代替。
 * @param requestId 请求ID。
 * @param userId 取消信令的用户ID。
 */
- (void)onRequestCancelled:(NSString *)requestId userId:(NSString *)userId NS_SWIFT_NAME(onRequestCancelled(requestId:userId:)) __attribute__((deprecated("Deprecated from v2.3.0")));

/**
 * 收到请求被其他 管理员/房主 处理事件
 *
 * @deprecated v2.3.0 版本开始不推荐使用,建议使用带{@link TUIRequest}的{@link onRequestProcessed}代替。
 * @note 此回调将于v2.8.0版本删除，建议您使用新的回调代替。
 * @param requestId 请求ID。
 * @param userId 管理员/房主 的用户ID。
 */
- (void)onRequestProcessed:(NSString *)requestId userId:(NSString *)userId NS_SWIFT_NAME(onRequestProcessed(requestId:userId:)) __attribute__((deprecated("Deprecated from v2.3.0")));

/**
 * 收到普通文本消息事件
 *
 * @deprecated v2.4.0 版本开始不推荐使用,建议使用 [IMSDK](https://im.sdk.qcloud.com/doc/zh-cn/index.html) 相关回调代替。
 * @param roomId 房间ID。
 * @param message 消息内容, 请参见: {@link TUIMessage} 定义。
 */
- (void)onReceiveTextMessage:(NSString *)roomId message:(TUIMessage *)message NS_SWIFT_NAME(onReceiveTextMessage(roomId:message:)) __attribute__((deprecated("Deprecated from v2.4.0")));

/**
 * 收到自定义消息事件
 *
 * @deprecated v2.4.0 版本开始不推荐使用,建议使用 [IMSDK](https://im.sdk.qcloud.com/doc/zh-cn/index.html) 相关回调代替。
 * @param roomId 房间ID。
 * @param message 消息内容, 请参见: {@link TUIMessage} 定义。
 */
- (void)onReceiveCustomMessage:(NSString *)roomId message:(TUIMessage *)message NS_SWIFT_NAME(onReceiveCustomMessage(roomId:message:)) __attribute__((deprecated("Deprecated from v2.4.0")));

@end
NS_ASSUME_NONNULL_END
