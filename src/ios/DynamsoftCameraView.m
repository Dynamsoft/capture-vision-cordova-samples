//
//  DynamsoftCameraView.m
//  HelloCordova
//
//  Created by Dynamsoft's mac on 2022/7/11.
//

#import "DynamsoftCameraView.h"

@implementation DynamsoftCameraView

- (instancetype)initWithFrame:(CGRect)frame withArguments:(id)arguments
{
    self = [super initWithFrame:frame];
    if (self) {
        [self setupUIWithArguments:arguments];
    }
    return self;
}

- (void)setupUIWithArguments:(id)arguments
{
    CGFloat cameraWidth = [[[arguments valueForKey:@"position"] valueForKey:@"width"] floatValue];
    CGFloat cameraHeight = [[[arguments valueForKey:@"position"] valueForKey:@"height"] floatValue];
    self.dceView = [DCECameraView cameraWithFrame:CGRectMake(0, 0, cameraWidth, cameraHeight)];
    [self addSubview:self.dceView];
    
    if ([DynamsoftSDKManager manager].cameraEnhancer != nil) {
        [[DynamsoftSDKManager manager].cameraEnhancer close];
        [DynamsoftSDKManager manager].cameraEnhancer.dceCameraView = self.dceView;
    }
}

- (void)layoutSubviews {
    self.dceView.frame = self.bounds;
}

@end
