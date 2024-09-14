/**
 * Copyright (c) 2024 Tencent. All rights reserved.
 */
#import "TUIRoomEngine.h"

@class TRTCCloud;
@class TXDeviceManager;
@class TXAudioEffectManager;
@class TXBeautyManager;

NS_ASSUME_NONNULL_BEGIN
@interface TUIRoomEngine (deprecated)

/////////////////////////////////////////////////////////////////////////////////
//
//                    弃用接口（建议使用对应的新接口）
//
/////////////////////////////////////////////////////////////////////////////////

/**
 * 开始推送本地音频
 *
 * @deprecated v1.5.0 版本开始不推荐使用,建议使用{@link unmuteLocalAudio}代替。
 */
- (void)startPushLocalAudio NS_SWIFT_NAME(startPushLocalAudio()) __attribute__((deprecated("use muteLocalAudio instead")));

/**
 * 停止推送本地音频
 *
 * @deprecated v1.5.0 版本开始不推荐使用,建议使用{@link muteLocalAudio}代替。
 */
- (void)stopPushLocalAudio NS_SWIFT_NAME(stopPushLocalAudio()) __attribute__((deprecated("use muteLocalAudio instead")));

/**
 * 获得TRTC实例对象
 *
 * @deprecated v1.5.0 版本开始不推荐使用。
 */
- (TRTCCloud *)getTRTCCloud NS_SWIFT_NAME(getTRTCCloud()) __attribute__((deprecated("Deprecated from v1.5.0")));

/**
 * 获得设备管理对象
 *
 * @deprecated v1.5.0 版本开始不推荐使用。
 */
- (TXDeviceManager *)getDeviceManager NS_SWIFT_NAME(getDeviceManager()) __attribute__((deprecated("Deprecated from v1.5.0")));

/**
 * 获得音效管理对象
 *
 * @deprecated v1.5.0 版本开始不推荐使用。
 */
- (TXAudioEffectManager *)getAudioEffectManager NS_SWIFT_NAME(getAudioEffectManager()) __attribute__((deprecated("Deprecated from v1.5.0")));

/**
 * 获得美颜管理对象
 *
 * @deprecated v1.5.0 版本开始不推荐使用。
 */
- (TXBeautyManager *)getBeautyManager NS_SWIFT_NAME(getBeautyManager()) __attribute__((deprecated("Deprecated from v1.5.0")));

/**
 * 设置本地用户视频渲染的视图控件
 *
 * @deprecated v1.6.1 版本开始不推荐使用。
 */
- (void)setLocalVideoView:(TUIVideoStreamType)streamType view:(TUIVideoView *__nullable)view NS_SWIFT_NAME(setLocalVideoView(streamType:view:)) __attribute__((deprecated("Deprecated from v1.6.1")));

#if TARGET_OS_IPHONE

/**
 * 切换前置或后置摄像头（仅适用于移动端）
 *
 * @deprecated v2.0 版本开始不推荐使用,建议使用{$TUIRoomDeviceManager$}中的{@link switchCamera}代替。
 * @return 0：操作成功；负数：操作失败。
 */
- (NSInteger)switchCamera:(BOOL)frontCamera NS_SWIFT_NAME(switchCamera(frontCamera:)) __attribute__((deprecated("Deprecated from v2.0")));

#endif

#if !TARGET_OS_IPHONE && TARGET_OS_MAC

/**
 * 获取设备列表（仅适用于桌面端）
 *
 * @deprecated v2.0 版本开始不推荐使用,建议使用{$TUIRoomDeviceManager$}中的{@link getDevicesList}代替。
 * @param type  设备类型，指定需要获取哪种设备的列表。详见 TXMediaDeviceType 定义。
 * @note
 * - 使用完毕后请调用 release 方法释放资源，这样可以让 SDK 维护 ITXDeviceCollection 对象的生命周期。
 *   - 不要使用 delete 释放返回的 Collection 对象，delete ITXDeviceCollection* 指针会导致异常崩溃。
 *   - type 只支持 TXMediaDeviceTypeMic、TXMediaDeviceTypeSpeaker、TXMediaDeviceTypeCamera。
 *   - 此接口只支持 Mac 和 Windows 平台。
 */
- (NSArray<TXMediaDeviceInfo *> *_Nullable)getDevicesList:(TUIMediaDeviceType)type NS_SWIFT_NAME(getDevicesList(type:)) __attribute__((deprecated("Deprecated from v2.0")));

/**
 * 设置当前要使用的设备（仅适用于桌面端）
 *
 * @deprecated v2.0 版本开始不推荐使用,建议使用{$TUIRoomDeviceManager$}中的{@link setCurrentDevice}代替。
 * 设置当前要使用的设备后,SDK会通过 {@link $TUIRoomObserver$} 中的 {@link onDeviceChanged} 通知您。
 * @param type 设备类型，详见 TXMediaDeviceType 定义。
 * @param deviceId 设备ID，您可以通过接口 {@link getDevicesList} 获得设备 ID。
 * @return 0：操作成功；负数：操作失败。
 */
- (NSInteger)setCurrentDevice:(TUIMediaDeviceType)type deviceId:(NSString *)deviceId NS_SWIFT_NAME(setCurrentDevice(type:deviceId:)) __attribute__((deprecated("Deprecated from v2.0")));

#endif

/**
 * 发送文本消息
 *
 * @deprecated v2.4.0 版本开始，该接口已废弃，建议使用 [IMSDK](https://im.sdk.qcloud.com/doc/zh-cn/index.html) 发送消息接口代替。
 * 消息发送后,SDK会通过 {@link $TUIRoomObserver$} 中的 {@link onReceiveTextMessage} 通知房间内用户。
 * @param message 消息内容。
 * @param onSuccess 成功回调。
 * @param onError 错误回调。
 */
- (void)sendTextMessage:(NSString *)message onSuccess:(TUISuccessBlock)onSuccess onError:(TUIErrorBlock)onError NS_SWIFT_NAME(sendTextMessage(_:onSuccess:onError:)) __attribute__((deprecated("Deprecated from v2.4.0")));

/**
 * 发送自定义消息
 *
 * @deprecated v2.4.0 版本开始，该接口已废弃，建议使用 [IMSDK](https://im.sdk.qcloud.com/doc/zh-cn/index.html) 发送消息接口代替。
 * 消息发送后,SDK会通过 {@link $TUIRoomObserver$} 中的 {@link onReceiveCustomMessage} 通知房间内用户。
 * @param message 消息内容。
 * @param onSuccess 成功回调。
 * @param onError 错误回调。
 */
- (void)sendCustomMessage:(NSString *)message onSuccess:(TUISuccessBlock)onSuccess onError:(TUIErrorBlock)onError NS_SWIFT_NAME(sendCustomMessage(_:onSuccess:onError:)) __attribute__((deprecated("Deprecated from v2.4.0")));

NS_ASSUME_NONNULL_END
@end
