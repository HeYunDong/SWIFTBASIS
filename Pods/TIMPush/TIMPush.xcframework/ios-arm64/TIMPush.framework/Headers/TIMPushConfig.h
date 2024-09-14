//
//  TIMPushConfig.h
//  TIMPush
//
//  Created by cologne on 2024/7/11.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, PUSH_SDK_RUN_ON_PLATFORM) {
    PUSH_SDK_RUN_ON_NATIVE = 1,
    PUSH_SDK_RUN_ON_UNIAPP = 2,
    PUSH_SDK_RUN_ON_DONUT = 3,
    PUSH_SDK_RUN_ON_FLUTTER = 4,
    PUSH_SDK_RUN_ON_REACT = 5,
};

NS_ASSUME_NONNULL_BEGIN

@interface TIMPushConfig : NSObject
+ (TIMPushConfig *)defaultConfig;

@property (nonatomic, assign) PUSH_SDK_RUN_ON_PLATFORM runningPlatform; //设置 push sdk 使用的平台类型

@property (nonatomic, assign) BOOL isRegisterWithAppKey;

@property (nonatomic, assign) int businessID;

@property (nonatomic, assign) NSString *appGroupID;

@property (nonatomic, assign) int enablePostNotificationInForeground;//应用前台是否推送，默认为 -1:未设置 0:关闭 1:开启

@end

NS_ASSUME_NONNULL_END
