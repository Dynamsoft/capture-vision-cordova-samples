//
//  DynamsoftSDKManager.h
//  HelloCordova
//
//  Created by Dynamsoft's mac on 2022/7/8.
//

#import <Foundation/Foundation.h>
#import <DynamsoftBarcodeReader/DynamsoftBarcodeReader.h>
#import <DynamsoftCameraEnhancer/DynamsoftCameraEnhancer.h>
@class DynamsoftCameraView;

typedef NS_ENUM(NSInteger, DynamsoftBarcodeReaderState) {
    DynamsoftBarcodeReaderStateStartScanning,
    DynamsoftBarcodeReaderStateStopScanning
};

typedef NS_ENUM(NSInteger, DynamsoftCameraEnhancerState) {
    DynamsoftCameraEnhancerStateOpen,
    DynamsoftCameraEnhancerStateClose
};

NS_ASSUME_NONNULL_BEGIN

typedef void(^DBRLicenseVerificationCallback) (bool isSuccess, NSError *error);

typedef void(^BarcodeTextResultCallBack)(NSArray<iTextResult *> *results);

@interface DynamsoftSDKManager : NSObject<NSCopying, NSMutableCopying, DBRTextResultListener>

+ (DynamsoftSDKManager *)manager;

// MARK: - SDK instance

/// SDK
@property (nonatomic, strong) DynamsoftBarcodeReader *barcodeReader;

@property (nonatomic, strong, nullable) DynamsoftCameraEnhancer *cameraEnhancer;

// MARK: - Block

/// DBRLicenseVerificationCallback
@property (nonatomic, copy) DBRLicenseVerificationCallback dbrLicenseVerificationCallback;

/// TextResultCallBackBlock
@property (nonatomic, copy) BarcodeTextResultCallBack barcodeTextResultCallBack;

// MARK: - State

/// WebView url observer is created or not.
@property (nonatomic, assign) BOOL webViewObserverIsExisted;

/// Webview ges is create or not.
@property (nonatomic, assign) BOOL webViewTapGesIsExisted;

/// App lifecycle notication observer is created or not.
@property (nonatomic, assign) BOOL appLifecycleObserverIsExisted;

/// DynamsoftCameraView is visible or not.
@property (nonatomic, assign) BOOL dynamsoftCameraViewIsVisible;

/// Dynamsoft camera torch is open or not.
@property (nonatomic, assign) BOOL dynamsoftCameraViewTorchIsOpen;

/// Dynamsoft camera torch is visible or not.
@property (nonatomic, assign) BOOL dynamsoftCameraViewTorchIsVisible;

@property (nonatomic, assign) BOOL dynamsoftDBRIsExisted;

@property (nonatomic, assign) BOOL dynamsoftDCEIsExisted;

/// The url of CameraView attatch to page.
/// Use this propery to judge the cameraView is visible or  not.
@property (nonatomic, copy) NSString *cameraViewPageUrlPath;

@property (nonatomic, assign) DynamsoftBarcodeReaderState dynamsoftBarcodeReaderState;

@property (nonatomic, assign) DynamsoftCameraEnhancerState dynamsoftCameraEnhancerState;

/// Default is CGRectZero.
/// This property is only useful when custom torch button.
@property (nonatomic, assign) CGRect customCameraTorchFrame;

// MARK: - Methods

/// DBR set license
- (void)barcodeReaderInitLicense:(NSString *)license;

/// Update dce frame.
- (void)updateDCEFrameWithArguments:(NSArray *)arguments
                            dceView:(DynamsoftCameraView *)dynamsoftCameraView;

/// Update CameraView visible  state.
- (void)updateCameraViewVisibleWithState:(BOOL)isVisible
                                 dceView:(DynamsoftCameraView *)dynamsoftCameraView;

/// Update Camera torch state.
/// Should invoke this method when appEnterForeground. cameraView is visible.
- (void)updateCameraTorchState;

/// Update custom Camera torch state when click.
/// Should invoke this method when click the camraView.
- (void)updateCustomCameraTorchStateWithTorchFrame:(CGRect)torchFrame
                                        clickPoint:(CGPoint)clickPoint;

@end

NS_ASSUME_NONNULL_END
