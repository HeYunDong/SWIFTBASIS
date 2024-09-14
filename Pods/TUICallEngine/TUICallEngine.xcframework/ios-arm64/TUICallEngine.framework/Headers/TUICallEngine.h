//
//  TUICallEngine.h
//  TUICalling
//
//  Created by noah on 2022/4/26.
//  Copyright © 2022 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TUICallEngine/TUICallObserver.h>
#import <TUICallEngine/TUICallDefine.h>
#import <TUICallEngine/TUICommonDefine.h>

@class TRTCCloud;

NS_ASSUME_NONNULL_BEGIN

@interface TUICallEngine : NSObject

/**
 * This API is used to create a TUICallEngine singleton.
 */
+ (TUICallEngine *)createInstance
NS_SWIFT_NAME(createInstance());

/**
 * This API is used to destroy a TUICallEngine singleton.
 */
+ (void)destroyInstance
NS_SWIFT_NAME(destroyInstance());

/**
 * This API is used to initialize TUICallEngine. Call it to authenticate the call service and perform other required actions before you call other APIs.
 *
 * @param sdkAppID  You can view SDKAppID in Application Management > Application Info of the Console.
 * @param userId  The ID of the current user, which is a string that can contain only letters (a-z and A-Z), digits (0-9), hyphens (-), and underscores (_).
 * @param userSig  Tencent Cloud's proprietary security signature. For how to calculate and use it, see UserSig.
 */
- (void)init:(int)sdkAppID userId:(NSString *)userId userSig:(NSString *)userSig succ:(TUICallSucc)succ fail:(TUICallFail)fail;

/**
 * This API is used to register an event listener to listen for TUICallObserver events.
 */
- (void)addObserver:(id<TUICallObserver>)observer
NS_SWIFT_NAME(addObserver(_:));

/**
 * This API is used to unregister an event listener.
 */
- (void)removeObserver:(id<TUICallObserver>)observer
NS_SWIFT_NAME(removeObserver(_:));

/**
 * This API is used to make a (one-to-one) call.
 *
 * @param roomId  The room ID
 * @param userId  The target user ID.
 * @param callMediaType  The call type, which can be video or audio.
 * @param params  An additional parameter. For example, you can use it to customize an offline notification.
 */
- (void)call:(TUIRoomId *)roomId
      userId:(NSString *)userId
callMediaType:(TUICallMediaType)callMediaType
      params:(TUICallParams *)params
        succ:(TUICallSucc)succ
        fail:(TUICallFail)fail
NS_SWIFT_NAME(call(roomId:userId:callMediaType:params:succ:fail:))
__attribute__((deprecated("use call:callMediaType:params:succ:fail:")));

/**
 * This API is used to make a (one-to-one) call.
 *
 * @param userId  The target user ID.
 * @param callMediaType  The call type, which can be video or audio.
 * @param params  An additional parameter. For example, you can use it to customize an offline notification.
 */
- (void)call:(NSString *)userId
callMediaType:(TUICallMediaType)callMediaType
      params:(TUICallParams *)params
        succ:(TUICallSucc)succ
        fail:(TUICallFail)fail
NS_SWIFT_NAME(call(userId:callMediaType:params:succ:fail:));

/**
 * This API is used to make a group call. Note that you need to create an IM group before making a group call.
 *
 * @param roomId  The room ID.
 * @param groupId  The group ID.
 * @param userIdList  The target user IDs.
 * @param callMediaType  The call type, which can be video or audio.
 * @param params  An additional parameter. For example, you can use it to customize an offline notification.
 */
- (void)groupCall:(TUIRoomId *)roomId
          groupId:(NSString *)groupId
       userIdList:(NSArray<NSString *> *)userIdList
    callMediaType:(TUICallMediaType)callMediaType
           params:(TUICallParams *)params
             succ:(TUICallSucc)succ
             fail:(TUICallFail)fail
NS_SWIFT_NAME(groupCall(roomId:groupId:userIdList:callMediaType:params:succ:fail:))
__attribute__((deprecated("use groupCall:userIdList:callMediaType:params:succ:fail:")));

/**
 * This API is used to make a group call. Note that you need to create an IM group before making a group call.
 *
 * @param groupId  The group ID.
 * @param userIdList  The target user IDs.
 * @param callMediaType  The call type, which can be video or audio.
 * @param params  An additional parameter. For example, you can use it to customize an offline notification.
 */
- (void)groupCall:(NSString *)groupId
       userIdList:(NSArray<NSString *> *)userIdList
    callMediaType:(TUICallMediaType)callMediaType
           params:(TUICallParams *)params
             succ:(TUICallSucc)succ
             fail:(TUICallFail)fail
NS_SWIFT_NAME(groupCall(groupId:userIdList:callMediaType:params:succ:fail:));

/**
 * This API is used to accept a call. After receiving the onCallReceived() callback, you can call this API to accept the call.
 */
- (void)accept:(TUICallSucc)succ fail:(TUICallFail)fail
NS_SWIFT_NAME(accept(succ:fail:));

/**
 * This API is used to reject a call. After receiving the onCallReceived() callback, you can call this API to reject the call.
 */
- (void)reject:(TUICallSucc)succ fail:(TUICallFail)fail
NS_SWIFT_NAME(reject(succ:fail:));

/**
 * This API is used to end a call.
 */
- (void)hangup:(TUICallSucc)succ fail:(TUICallFail)fail
NS_SWIFT_NAME(hangup(succ:fail:));

/**
 * This API is used to ignore a call. After receiving the onCallReceived(), you can call this API to ignore the call. The caller will receive the onUserLineBusy callback.
 * Note: If your project involves live streaming or conferencing, you can also use this API to implement the “in a meeting” or “on air” feature.
 */
- (void)ignore:(TUICallSucc)succ fail:(TUICallFail)fail
NS_SWIFT_NAME(ignore(succ:fail:));

/**
 * This API is used to invite users to the current group call.
 * This API is called by a participant of a group call to invite new users.
 *
 * @param userIdList  The target user IDs.
 * @param params  An additional parameter. For example, you can use it to customize an offline notification.
 */
- (void)inviteUser:(NSArray<NSString *> *)userIdList params:(TUICallParams *)params succ:(void(^)(NSArray <NSString *> *userIdList))succ fail:(TUICallFail)fail
NS_SWIFT_NAME(inviteUser(userIdList:params:succ:fail:));

/**
 * This API is used to join a group call.
 * This API is called by a group member to join the group’s call.
 *
 * @param roomId  The room ID.
 * @param groupId  The group ID.
 * @param callMediaType  The call type, which can be video or audio.
 */
- (void)joinInGroupCall:(TUIRoomId *)roomId groupId:(NSString *)groupId callMediaType:(TUICallMediaType)callMediaType succ:(TUICallSucc)succ fail:(TUICallFail)fail
NS_SWIFT_NAME(joinInGroupCall(roomId:groupId:callMediaType:succ:fail:));

/**
 * This API is used to change the call type.
 *
 * @param newType  The call type, which can be video or audio.
 */
- (void)switchCallMediaType:(TUICallMediaType)newType
NS_SWIFT_NAME(switchCallMediaType(_:));

/**
 * This API is used to subscribe to the video stream of a remote user.
 *
 * @param userId  The target user ID.
 * @param videoView  The view to be rendered.
 */
- (void)startRemoteView:(NSString *)userId
              videoView:(TUIVideoView *)videoView
              onPlaying:(void (^)(NSString *userId))onPlaying
              onLoading:(void (^)(NSString *userId))onLoading
                onError:(void (^)(NSString *userId, int code, NSString *errMsg))onError
NS_SWIFT_NAME(startRemoteView(userId:videoView:onPlaying:onLoading:onError:));

/**
 * This API is used to unsubscribe from the video stream of a remote user.
 *
 * @param userId  The target user ID.
 */
- (void)stopRemoteView:(NSString *)userId
NS_SWIFT_NAME(stopRemoteView(userId:));

/**
 * This API is used to turn the camera on.
 *
 * @param camera  The front or rear camera.
 * @param videoView  The view to be rendered.
 */
- (void)openCamera:(TUICamera)camera videoView:(TUIVideoView *)videoView succ:(TUICallSucc)succ fail:(TUICallFail)fail
NS_SWIFT_NAME(openCamera(_:videoView:succ:fail:));

/**
 * This API is used to turn the camera off.
 */
- (void)closeCamera
NS_SWIFT_NAME(closeCamera());

/**
 * This API is used to switch between the front and back cameras.
 *
 * @param camera  The front or rear camera.
 */
- (void)switchCamera:(TUICamera)camera
NS_SWIFT_NAME(switchCamera(_:));

/**
 * This API is used to turn the mic on.
 */
- (void)openMicrophone:(TUICallSucc)succ fail:(TUICallFail)fail
NS_SWIFT_NAME(openMicrophone(succ:fail:));

/**
 * This API is used to turn the mic off.
 */
- (void)closeMicrophone
NS_SWIFT_NAME(closeMicrophone());

/**
 * This API is used to select the audio playback device (earpiece or speakerphone). In call scenarios, you can use this API to turn on/off hands-free mode.
 *
 * @param device  The speakerphone or earpiece.
 */
- (void)selectAudioPlaybackDevice:(TUIAudioPlaybackDevice)device
NS_SWIFT_NAME(selectAudioPlaybackDevice(_:));

/**
 * This API is used to set the alias and profile photo. The alias cannot exceed 500 bytes, and the profile photo is specified by a URL.
 *
 * @param nickname  The alias.
 * @param avatar  The URL of the profile photo.
 */
- (void)setSelfInfo:(NSString *_Nullable)nickname avatar:(NSString *_Nullable)avatar succ:(TUICallSucc)succ fail:(TUICallFail)fail
NS_SWIFT_NAME(setSelfInfo(nickname:avatar:succ:fail:));

/**
 * This API is used to set whether to enable multi-device login for TUICallEngine (supported by the premium package).
 *
 * @param enable  true/false.
 */
- (void)enableMultiDeviceAbility:(BOOL)enable succ:(TUICallSucc)succ fail:(TUICallFail)fail
NS_SWIFT_NAME(enableMultiDeviceAbility(enable:succ:fail:));

/**
 * Set the rendering mode of video image
 * The parameters that can be set include video image rotation and fill mode
 *
 * @param userId  ID of the specified user
 * @param params  Video rendering parameters，more details: {@link TUICommonDefine.VideoRenderParams}.
 */
- (void)setVideoRenderParams:(NSString *)userId params:(TUIVideoRenderParams *)params succ:(TUICallSucc)succ fail:(TUICallFail)fail
NS_SWIFT_NAME(setVideoRenderParams(userId:params:succ:fail:));

/**
 * Set the encoding parameters of video encoder
 * This setting can determine the quality of image viewed by remote users,
 * which is also the image quality of on-cloud recording files.
 *
 * @param params  It is used to set relevant parameters for the video encoder，more details: {@link TUICommonDefine.VideoEncoderParams}.
 */
- (void)setVideoEncoderParams:(TUIVideoEncoderParams *)params succ:(TUICallSucc)succ fail:(TUICallFail)fail
NS_SWIFT_NAME(setVideoEncoderParams(_:succ:fail:));

/**
 * Query recent calls
 *
 * @param filter  Query filter conditions
 * @param succ  Query successful result list
 * @param fail  Query failure callback
 */
- (void)queryRecentCalls:(TUICallRecentCallsFilter *)filter succ:(void (^)(NSArray<TUICallRecords *> *callRecords))succ fail:(void (^)(void))fail
NS_SWIFT_NAME(queryRecentCalls(filter:succ:fail:));

/**
 * Delete record calls
 *
 * @param callIdList  List of callIds to be deleted
 * @param succ  List of successfully deleted callIds
 * @param fail  Delete failure callback
 */
- (void)deleteRecordCalls:(NSArray<NSString *> *)callIdList succ:(void (^)(NSArray<NSString *> *succList))succ fail:(void (^)(void))fail
NS_SWIFT_NAME(deleteRecordCalls(_:succ:fail:));

/**
 * Advanced features，get the TRTCCloud instance in calling.
 *
 * @return TRTCCloud instance
 */
- (TRTCCloud *)getTRTCCloudInstance
NS_SWIFT_NAME(getTRTCCloudInstance());

/**
 * Set Beauty
 */
- (void)setBeautyLevel:(CGFloat)level succ:(TUICallSucc)succ fail:(TUICallFail)fail
NS_SWIFT_NAME(setBeautyLevel(_:succ:fail:));

/**
 * Experimental interface
 */
- (void )callExperimentalAPI:(NSString *)jsonObject
NS_SWIFT_NAME(callExperimentalAPI(jsonObject:));

/**
 * Set the video call blurring effect
 *
 * @param level  Blurring level: 0 - turn off the blurring effect;  1 - low;  2 - middle;  3 - high
 * @param fail  Error callback
 */

- (void)setBlurBackground:(NSInteger)level fail:(TUICallFail)fail
NS_SWIFT_NAME(setBlurBackground(_:fail:));

/**
 * Set the video call image background
 *
 * @param imagePath  local path of the image, if empty, the background image effect will be turned off; if not empty, the background image effect will be turned on
 * @param fail  Error callback
 */
- (void)setVirtualBackground:(NSString *)imagePath fail:(TUICallFail)fail
NS_SWIFT_NAME(setVirtualBackground(_:fail:));

@end

NS_ASSUME_NONNULL_END
