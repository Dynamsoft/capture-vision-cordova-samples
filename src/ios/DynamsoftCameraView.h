//
//  DynamsoftCameraView.h
//  HelloCordova
//
//  Created by Dynamsoft's mac on 2022/7/11.
//

#import <UIKit/UIKit.h>
#import <DynamsoftBarcodeReader/DynamsoftBarcodeReader.h>
#import <DynamsoftCameraEnhancer/DynamsoftCameraEnhancer.h>
#import "DynamsoftSDKManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface DynamsoftCameraView : UIView

@property (nonatomic, strong) DCECameraView *dceView;

- (instancetype)initWithFrame:(CGRect)frame withArguments:(id)arguments;

@end

NS_ASSUME_NONNULL_END
