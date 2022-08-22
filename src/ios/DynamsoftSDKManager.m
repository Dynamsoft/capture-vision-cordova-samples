//
//  DynamsoftSDKManager.m
//  HelloCordova
//
//  Created by Dynamsoft's mac on 2022/7/8.
//

#import "DynamsoftSDKManager.h"
#import "DynamsoftToolsManager.h"
#import "DynamsoftCameraView.h"

@interface DynamsoftSDKManager ()<DBRLicenseVerificationListener>

@end

@implementation DynamsoftSDKManager

+ (DynamsoftSDKManager *)manager
{
    static DynamsoftSDKManager *sdkManager = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sdkManager = [super allocWithZone:NULL];
    });
    return sdkManager;
}

+ (instancetype)allocWithZone:(struct _NSZone *)zone
{
    return [DynamsoftSDKManager manager];
}

- (id)copyWithZone:(NSZone *)zone
{
    return [DynamsoftSDKManager manager];
}

- (id)mutableCopyWithZone:(NSZone *)zone
{
    return [DynamsoftSDKManager manager];
}

// MARK: - DBRLicenseVerificationListener

- (void)DBRLicenseVerificationCallback:(bool)isSuccess error:(NSError *)error{
    if (self.dbrLicenseVerificationCallback) {
        self.dbrLicenseVerificationCallback(isSuccess, error);
    }
}

// MARK: - DBRTextResultListener

- (void)textResultCallback:(NSInteger)frameId imageData:(iImageData *)imageData results:(NSArray<iTextResult *> *)results  {
    if (results.count > 0) {
        if (self.barcodeTextResultCallBack) {
            self.barcodeTextResultCallBack(results);
        }
    }
}

// MARK: - Methods

- (void)barcodeReaderInitLicense:(NSString *)license
{
    [DynamsoftBarcodeReader initLicense:license verificationDelegate:self];
}

- (void)updateDCEFrameWithArguments:(NSArray *)arguments
                            dceView:(DynamsoftCameraView *)dynamsoftCameraView {
    if (arguments.count == 0 || arguments.firstObject == nil || arguments.firstObject == [NSNull null]) {
        return;
    }
   
    NSDictionary *argumentsDic =  arguments.firstObject;
    if (![argumentsDic.allKeys containsObject:@"width"] || dynamsoftCameraView == nil) {
        return;
    }
    CGFloat cameraWidth = [[argumentsDic valueForKey:@"width"] floatValue];
    CGFloat cameraHeight = [[argumentsDic valueForKey:@"height"] floatValue];
    CGFloat cameraX = [[argumentsDic valueForKey:@"x"] floatValue];
    CGFloat cameraY = [[argumentsDic valueForKey:@"y"] floatValue];
    
    [dynamsoftCameraView setFrame:CGRectMake(cameraX, cameraY, cameraWidth, cameraHeight)];
    [dynamsoftCameraView.dceView setFrame:CGRectMake(0, 0, cameraWidth, cameraHeight)];
}

- (void)updateCameraViewVisibleWithState:(BOOL)isVisible
                                 dceView:(DynamsoftCameraView *)dynamsoftCameraView {
    if (isVisible) {
        dynamsoftCameraView.hidden = NO;
        dynamsoftCameraView.dceView.hidden = NO;
        if (self.cameraEnhancer != nil) {
            if (self.dynamsoftCameraEnhancerState == DynamsoftCameraEnhancerStateOpen) {
                [self.cameraEnhancer open];
            } else if (self.dynamsoftCameraEnhancerState == DynamsoftCameraEnhancerStateClose) {
                [self.cameraEnhancer close];
            }
        }
        
        if (self.barcodeReader != nil) {
            if (self.dynamsoftBarcodeReaderState == DynamsoftBarcodeReaderStateStartScanning) {
                [self.barcodeReader startScanning];
            } else if (self.dynamsoftCameraEnhancerState == DynamsoftBarcodeReaderStateStopScanning) {
                [self.barcodeReader stopScanning];
            }
        }
    } else {
        dynamsoftCameraView.hidden = YES;
        dynamsoftCameraView.dceView.hidden = YES;
        if (self.cameraEnhancer != nil) {
            [self.cameraEnhancer close];
        }
        
        if (self.barcodeReader != nil) {
            [self.barcodeReader stopScanning];
        }
    }
}

- (void)updateCameraTorchState {
    
    if ([DynamsoftSDKManager manager].dynamsoftCameraViewIsVisible == YES &&
        [DynamsoftSDKManager manager].dynamsoftCameraViewTorchIsOpen == YES) {
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
            [[DynamsoftSDKManager manager].cameraEnhancer turnOnTorch];
        });
        
    }
}

- (void)updateCustomCameraTorchStateWithTorchFrame:(CGRect)torchFrame
                                        clickPoint:(CGPoint)clickPoint {
    if (CGRectContainsPoint(torchFrame, clickPoint) &&
        [DynamsoftSDKManager manager].dynamsoftCameraViewTorchIsVisible == YES) {
        [DynamsoftSDKManager manager].dynamsoftCameraViewTorchIsOpen = ![DynamsoftSDKManager manager].dynamsoftCameraViewTorchIsOpen;
        if ([DynamsoftSDKManager manager].dynamsoftCameraViewTorchIsOpen == YES) {
            [[DynamsoftSDKManager manager].cameraEnhancer turnOnTorch];
        } else {
            [[DynamsoftSDKManager manager].cameraEnhancer turnOffTorch];
        }
        
    }
}

@end
