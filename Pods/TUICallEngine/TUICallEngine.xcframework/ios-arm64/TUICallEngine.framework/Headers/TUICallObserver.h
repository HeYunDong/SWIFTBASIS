//
//  TUICallObserver.h
//  TUICalling
//
//  Created by noah on 2022/7/8.
//  Copyright © 2022 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TUICallEngine/TUICallDefine.h>

@class TUIRoomId, TUINetworkQualityInfo;

NS_ASSUME_NONNULL_BEGIN

@protocol TUICallObserver <NSObject>

@optional

/**
 * An error occurred inside the SDK.
 *
 * @param code Error code
 * @param message  Error message
 */
- (void)onError:(int)code message:(NSString * _Nullable)message
NS_SWIFT_NAME(onError(code:message:));

/**
 * Callback for receiving a call request (received only by the callee)
 *
 * @param callerId      Caller
 * @param calleeIdList  List of callee
 * @param groupId       GroupID
 * @param callMediaType Call type，eg: audio、video
 * @param userData The extended field added by the user, corresponding to the TUICallDefine.CallParams.userData field set when the caller sends an invitation.
 */
- (void)onCallReceived:(NSString *)callerId
          calleeIdList:(NSArray<NSString *> *)calleeIdList
               groupId:(NSString * _Nullable)groupId
         callMediaType:(TUICallMediaType)callMediaType
              userData:(NSString * _Nullable)userData
NS_SWIFT_NAME(onCallReceived(callerId:calleeIdList:groupId:callMediaType:userData:));

/**
 * Callback for receiving a call request (received only by the callee)
 *
 * @param callerId      Caller
 * @param calleeIdList  List of callee
 * @param groupId       GroupID
 * @param callMediaType Call type，eg: audio、video
 */
- (void)onCallReceived:(NSString *)callerId
          calleeIdList:(NSArray<NSString *> *)calleeIdList
               groupId:(NSString * _Nullable)groupId
         callMediaType:(TUICallMediaType)callMediaType
NS_SWIFT_NAME(onCallReceived(callerId:calleeIdList:groupId:callMediaType:))
__attribute__((deprecated("use onCallReceived:calleeIdList:groupId:callMediaType:userData:")));

/**
 * A user who cancel the call
 *
 * @param callerId User who cancel the call request
 */
- (void)onCallCancelled:(NSString *)callerId
NS_SWIFT_NAME(onCallCancelled(callerId:));

/**
 * Call start(received by both caller and callee)
 *
 * @param roomId        Current call room ID
 * @param callMediaType Call type，eg: audio、video
 * @param callRole      Call role
 */
- (void)onCallBegin:(TUIRoomId *)roomId callMediaType:(TUICallMediaType)callMediaType callRole:(TUICallRole)callRole
NS_SWIFT_NAME(onCallBegin(roomId:callMediaType:callRole:));

/**
 * Call end(received by both caller and callee)
 *
 * @param roomId        Current call room ID
 * @param callMediaType Call type，eg: audio、video
 * @param callRole      Call role
 * @param totalTime     Total time of the call
 */
- (void)onCallEnd:(TUIRoomId *)roomId callMediaType:(TUICallMediaType)callMediaType callRole:(TUICallRole)callRole totalTime:(float)totalTime
NS_SWIFT_NAME(onCallEnd(roomId:callMediaType:callRole:totalTime:));

/**
 * Call type change
 *
 * @param oldCallMediaType  Old call type
 * @param newCallMediaType  New call type
 */
- (void)onCallMediaTypeChanged:(TUICallMediaType)oldCallMediaType newCallMediaType:(TUICallMediaType)newCallMediaType
NS_SWIFT_NAME(onCallMediaTypeChanged(oldCallMediaType:newCallMediaType:));

/**
 * A user who reject the call
 *
 * @param userId  User who reject the call
 */
- (void)onUserReject:(NSString *)userId
NS_SWIFT_NAME(onUserReject(userId:));

/**
 * A user who did not answer the call
 *
 * @param userId  User who did not answer the call
 */
- (void)onUserNoResponse:(NSString *)userId
NS_SWIFT_NAME(onUserNoResponse(userId:));

/**
 * A user who is busy
 *
 * @param userId  User who is busy
 */
- (void)onUserLineBusy:(NSString *)userId
NS_SWIFT_NAME(onUserLineBusy(userId:));

/**
 * A user who join the call
 *
 * @param userId  User who join the call
 */
- (void)onUserJoin:(NSString *)userId
NS_SWIFT_NAME(onUserJoin(userId:));

/**
 * A user who leave the call
 *
 * @param userId  User who leave the call
 */
- (void)onUserLeave:(NSString *)userId
NS_SWIFT_NAME(onUserLeave(userId:));

/**
 * A remote user published/unpublished primary stream video
 *
 * @param userId  User ID of the remote user
 * @param isVideoAvailable  Whether the user published (or unpublished) primary stream video
 */
- (void)onUserVideoAvailable:(NSString *)userId isVideoAvailable:(BOOL)isVideoAvailable
NS_SWIFT_NAME(onUserVideoAvailable(userId:isVideoAvailable:));

/**
 * A remote user published/unpublished audio
 *
 * @param userId  User ID of the remote user
 * @param isAudioAvailable  Whether the user published (or unpublished) audio.
 */
- (void)onUserAudioAvailable:(NSString *)userId isAudioAvailable:(BOOL)isAudioAvailable
NS_SWIFT_NAME(onUserAudioAvailable(userId:isAudioAvailable:));

/**
 * All user volume change
 *
 * @param volumeMap The total volume of all users. Value range: 0 - 100
 */
- (void)onUserVoiceVolumeChanged:(NSDictionary<NSString *, NSNumber *> *)volumeMap
NS_SWIFT_NAME(onUserVoiceVolumeChanged(volumeMap:));

/**
 * Real-time network quality statistics
 *
 * @param networkQualityList All users Real-time network quality statistics
 */
- (void)onUserNetworkQualityChanged:(NSArray<TUINetworkQualityInfo *> *)networkQualityList
NS_SWIFT_NAME(onUserNetworkQualityChanged(networkQualityList:));

/**
 * The callback of the current user being kicked off, the user can be prompted on the UI at this time, and call init() function of TUICallEngine to log in again.
 */
- (void)onKickedOffline
NS_SWIFT_NAME(onKickedOffline());

/**
 * The callback of the login credentials expired when online, you need to generate a new userSig and call init() function of TUICallEngine to log in again.
 */
- (void)onUserSigExpired
NS_SWIFT_NAME(onUserSigExpired());

@end

NS_ASSUME_NONNULL_END
