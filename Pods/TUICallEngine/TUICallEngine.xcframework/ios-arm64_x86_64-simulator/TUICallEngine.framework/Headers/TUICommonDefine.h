//
//  TUICommonDefine.h
//  TUICallEngine
//
//  Created by noah on 2022/8/4.
//  Copyright © 2022 Tencent. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <TUICallEngine/TUILog.h>

typedef NS_ENUM(NSUInteger, TUIAudioPlaybackDevice) {
    TUIAudioPlaybackDeviceSpeakerphone,
    TUIAudioPlaybackDeviceEarpiece,
};

typedef NS_ENUM(NSUInteger, TUICamera) {
    TUICameraFront,
    TUICameraBack,
};

typedef NS_ENUM(NSInteger, TUINetworkQuality) {
    TUINetworkQualityUnknown,
    TUINetworkQualityExcellent,
    TUINetworkQualityGood,
    TUINetworkQualityPoor,
    TUINetworkQualityBad,
    TUINetworkQualityVbad,
    TUINetworkQualityDown,
};

typedef NS_ENUM(NSInteger, TUIVideoRenderParamsFillMode) {
    
    /// Fill mode: the video image will be centered and scaled to fill the entire display area, where parts that exceed the area will be cropped. The displayed image may be incomplete in this mode.
    TUIVideoRenderParamsFillModeFill = 0,
    
    /// Fit mode: the video image will be scaled based on its long side to fit the display area, where the short side will be filled with black bars. The displayed image is complete in this mode, but there may be black bars.
    TUIVideoRenderParamsFillModeFit = 1,
    
};

typedef NS_ENUM(NSInteger, TUIVideoRenderParamsRotation) {
    
    /// No rotation
    TUIVideoRenderParamsRotation_0 = 0,
    
    /// Clockwise rotation by 90 degrees
    TUIVideoRenderParamsRotation_90 = 1,
    
    /// Clockwise rotation by 180 degrees
    TUIVideoRenderParamsRotation_180 = 2,
    
    /// Clockwise rotation by 270 degrees
    TUIVideoRenderParamsRotation_270 = 3,
    
};

typedef NS_ENUM(NSInteger, TUIVideoEncoderParamsResolutionMode) {
    
    /// Landscape resolution, such as 640_360 + Landscape = 640x360.
    TUIVideoEncoderParamsResolutionModeLandscape = 0,
    
    /// Portrait resolution, such as 640_360 + Portrait = 360x640.
    TUIVideoEncoderParamsResolutionModePortrait = 1,
    
};

typedef NS_ENUM(NSInteger, TUIVideoEncoderParamsResolution) {
    
    /// Aspect ratio: 4:3; resolution: 640x480; recommended bitrate (VideoCall): 600 Kbps;
    TUIVideoEncoderParamsResolution_640_480 = 62,
    
    /// Aspect ratio: 4:3; resolution: 960x720; recommended bitrate (VideoCall): 1000 Kbps;
    TUIVideoEncoderParamsResolution_960_720 = 64,
    
    /// Aspect ratio: 16:9; resolution: 640x360; recommended bitrate (VideoCall): 500 Kbps;
    TUIVideoEncoderParamsResolution_640_360 = 108,
    
    /// Aspect ratio: 16:9; resolution: 960x540; recommended bitrate (VideoCall): 850 Kbps;
    TUIVideoEncoderParamsResolution_960_540 = 110,
    
    /// Aspect ratio: 16:9; resolution: 1280x720; recommended bitrate (VideoCall): 1200 Kbps;
    TUIVideoEncoderParamsResolution_1280_720 = 112,
    
    /// Aspect ratio: 16:9; resolution: 1920x1080; recommended bitrate (VideoCall): 2000 Kbps;
    TUIVideoEncoderParamsResolution_1920_1080 = 114,
    
};

NS_ASSUME_NONNULL_BEGIN

@interface TUIRoomId : NSObject

@property(nonatomic, assign) UInt32 intRoomId;

@property(nonatomic, copy) NSString *strRoomId;

@end

@interface TUINetworkQualityInfo : NSObject

@property(nonatomic, copy, nullable) NSString *userId;

@property(nonatomic, assign) TUINetworkQuality quality;

@end

@interface TUIVideoView : UIView

@end

@interface TUIVideoRenderParams : NSObject

@property(nonatomic, assign) TUIVideoRenderParamsFillMode fillMode;

@property(nonatomic, assign) TUIVideoRenderParamsRotation rotation;

@end

@interface TUIVideoEncoderParams : NSObject

@property(nonatomic, assign) TUIVideoEncoderParamsResolution resolution;

@property(nonatomic, assign) TUIVideoEncoderParamsResolutionMode resolutionMode;

@end

NS_ASSUME_NONNULL_END
