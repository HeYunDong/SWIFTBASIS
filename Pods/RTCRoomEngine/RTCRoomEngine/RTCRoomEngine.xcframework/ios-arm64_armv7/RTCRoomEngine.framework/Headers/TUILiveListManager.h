/**
 * Copyright (c) 2024 Tencent. All rights reserved.
 * Module:   TUILiveListManager @ TUIKitEngine
 * Function: 直播相关接口
 */

#import <Foundation/Foundation.h>
#import "TUICommonDefine.h"
#import "TUIRoomDefine.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * 直播间修改标记位
 */
typedef NS_OPTIONS(NSUInteger, TUILiveModifyFlag) {

    TUILiveModifyFlagNone = 0x0000,

    /// ActivityStatus: 直播间活跃状态，支持自定义设置
    TUILiveModifyFlagActivityStatus = 0x0100,

    /// CoverUrl: 直播间封面
    TUILiveModifyFlagCoverUrl = 0x0200,

    /// Category: 直播间分类
    TUILiveModifyFlagCategory = 0x0400,

    /// Publish: 直播间公开标记
    TUILiveModifyFlagPublish = 0x2000,

    /// BackgroundUrl: 直播间背景.
    TUILiveModifyFlagBackgroundUrl = 0x40000,

};

/**
 * 直播信息
 */
TUIENGINE_EXPORT @interface TUILiveInfo : NSObject

/// 房间信息(只读)
@property(nonatomic, strong, readonly) TUIRoomInfo* roomInfo;

/// 直播间封面，最大支持 200 个字节
@property(nonatomic, copy, nonnull) NSString* coverUrl;

/// 直播间背景，最大支持 200 个字节
@property(nonatomic, copy, nonnull) NSString* backgroundUrl;

/// 直播间分类标签，单个房间最大支持3个标记
@property(nonatomic, copy, nonnull) NSArray<NSNumber*>* categoryList;

/// 直播间是否公开
@property(nonatomic, assign) BOOL isPublicVisible;

/// 直播间活跃状态: 用户自定义标记
@property(nonatomic, assign) NSInteger activityStatus;

/// 累计观看次数
@property(nonatomic, assign) NSInteger viewCount;

@end

typedef void (^TUILiveInfoBlock)(TUILiveInfo* _Nonnull liveInfo);
typedef void (^TUILiveInfoListBlock)(NSString* _Nonnull cursor, NSArray<TUILiveInfo*>* _Nonnull liveInfoList);

@protocol TUILiveListManagerObserver <NSObject>

/**
 * 直播信息改变回调
 *
 * @param liveInfo   直播间信息
 * @param modifyFlag 改变类型
 */
- (void)onLiveInfoChanged:(TUILiveInfo*)liveInfo modifyFlag:(TUILiveModifyFlag)modifyFlag NS_SWIFT_NAME(onLiveInfoChanged(liveInfo:modifyFlag:));

@end

TUIENGINE_EXPORT @interface TUILiveListManager : NSObject

/**
 * 设置事件回调
 *
 * 您可以通过 TUILiveListManagerObserver 获得直播间事件通知
 * @param observer 监听的实例
 */
- (void)addObserver:(id<TUILiveListManagerObserver>)observer NS_SWIFT_NAME(addObserver(_:));

/**
 * 移除事件回调
 *
 * @param observer 监听的实例。
 */
- (void)removeObserver:(id<TUILiveListManagerObserver>)observer NS_SWIFT_NAME(removeObserver(_:));

/**
 * 修改直播信息
 *
 * @param liveInfo   直播信息
 * @param modifyFlag 修改标记
 * @param onSuccess  成功回调
 * @param onError    失败回调
 */
- (void)setLiveInfo:(TUILiveInfo*)liveInfo modifyFlag:(TUILiveModifyFlag)modifyFlag onSuccess:(TUISuccessBlock)onSuccess onError:(TUIErrorBlock)onError NS_SWIFT_NAME(setLiveInfo(_:modifyFlag:onSuccess:onError:));

/**
 * 获取直播信息
 *
 * @param roomId    房间ID
 * @param onSuccess 成功回调
 * @param onError   失败回调
 */
- (void)getLiveInfo:(NSString*)roomId onSuccess:(TUILiveInfoBlock)onSuccess onError:(TUIErrorBlock)onError NS_SWIFT_NAME(getLiveInfo(_:onSuccess:onError:));

/**
 * 获取直播列表
 *
 * @note 获取直播间列表，单次拉取最大支持返回 50 个。
 * @param cursor    列表下标
 * @param count     每次拉取个数
 * @param onSuccess 成功回调
 * @param onError   失败回调
 */
- (void)fetchLiveList:(NSString*)cursor count:(NSInteger)count onSuccess:(TUILiveInfoListBlock)onSuccess onError:(TUIErrorBlock)onError NS_SWIFT_NAME(fetchLiveList(cursor:count:onSuccess:onError:));

@end
NS_ASSUME_NONNULL_END
