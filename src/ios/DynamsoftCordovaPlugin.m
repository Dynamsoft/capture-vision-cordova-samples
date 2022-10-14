/********* DynamsoftCordovaPlugin.m Cordova Plugin Implementation *******/

#import <Cordova/CDV.h>
#import <DynamsoftBarcodeReader/DynamsoftBarcodeReader.h>
#import <DynamsoftCameraEnhancer/DynamsoftCameraEnhancer.h>
#import "DynamsoftConvertManager.h"
#import "DynamsoftSDKManager.h"
#import "DynamsoftToolsManager.h"
#import "DynamsoftCameraView.h"
#import <WebKit/WebKit.h>

@interface DynamsoftCordovaPlugin : CDVPlugin<UIGestureRecognizerDelegate> {
  // Member variables go here.
}

@property (nonatomic, strong) DynamsoftCameraView *dynamsoftCameraView;

/// When the  webview.superview color  is not white and the webView is clear, there will not  suitable appearance happened, so we add a special maskView to avoid this happend.
@property (nonatomic, strong) UIView *sdkMaskView;

- (void)coolMethod:(CDVInvokedUrlCommand*)command;

// MARK: - Plugin interface
- (void)initLicense:(CDVInvokedUrlCommand *)command;

// MARK: - DBR interface
- (void)createDbrInstance:(CDVInvokedUrlCommand *)command;

- (void)getVersion:(CDVInvokedUrlCommand *)command;

- (void)startScanning:(CDVInvokedUrlCommand *)command;

- (void)stopScanning:(CDVInvokedUrlCommand *)command;

- (void)setTextResultListener:(CDVInvokedUrlCommand *)command;

- (void)outputSettingsToString:(CDVInvokedUrlCommand *)command;

- (void)getRuntimeSettings:(CDVInvokedUrlCommand *)command;

- (void)updateRuntimeSettings:(CDVInvokedUrlCommand *)command;

- (void)resetRuntimeSettings:(CDVInvokedUrlCommand *)command;

// MARK: - DCE interface
- (void)createDceInstance:(CDVInvokedUrlCommand *)command;

- (void)setScanRegion:(CDVInvokedUrlCommand *)command;

- (void)setScanRegionVisible:(CDVInvokedUrlCommand *)command;

- (void)setTorchState:(CDVInvokedUrlCommand *)command;

- (void)open:(CDVInvokedUrlCommand *)command;

- (void)close:(CDVInvokedUrlCommand *)command;

- (void)updateCameraViewPosition:(CDVInvokedUrlCommand *)command;//SDK private method.

- (void)setCameraViewVisible:(CDVInvokedUrlCommand *)command;//SDK private method.

// MARK: - DCECameraView interface
- (void)bindCameraViewToElement:(CDVInvokedUrlCommand *)command;

- (void)setOverlayVisible:(CDVInvokedUrlCommand *)command;

- (void)setTorchButton:(CDVInvokedUrlCommand *)command;

@end

@implementation DynamsoftCordovaPlugin

- (void)dealloc {
    [self.webView removeObserver:self forKeyPath:@"URL" context:nil];
    [[NSNotificationCenter defaultCenter] removeObserver:self forKeyPath:UIApplicationDidEnterBackgroundNotification context:nil];
    [[NSNotificationCenter defaultCenter] removeObserver:self forKeyPath:UIApplicationWillEnterForegroundNotification context:nil];
}

- (void)coolMethod:(CDVInvokedUrlCommand*)command
{
    CDVPluginResult* pluginResult = nil;
    NSString* echo = [command.arguments objectAtIndex:0];

    if (echo != nil && [echo length] > 0) {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:echo];
    } else {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR];
    }

    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

// MARK: - Plugin methods
- (void)initLicense:(CDVInvokedUrlCommand *)command {

    [DynamsoftSDKManager manager].dbrLicenseVerificationCallback = ^(bool isSuccess, NSError * _Nonnull error) {
        if (isSuccess) {
            [self.commandDelegate  sendPluginResult:[CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@"success"] callbackId:command.callbackId];
        } else  {
            NSString *errorString = @"";
            if (!isSuccess && error != nil) {
                errorString =  [error.userInfo valueForKey:@"NSUnderlyingError"];
            }
            [self.commandDelegate  sendPluginResult:[CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:errorString] callbackId:command.callbackId];
        }
    };
    [[DynamsoftSDKManager manager] barcodeReaderInitLicense:(NSString *)command.arguments.firstObject];
}

// MARK: - DBR methods
- (void)createDbrInstance:(CDVInvokedUrlCommand *)command {
    if ([DynamsoftSDKManager manager].dynamsoftDBRIsExisted == NO) {
        [DynamsoftSDKManager manager].dynamsoftDBRIsExisted = YES;
        [DynamsoftSDKManager manager].barcodeReader = [[DynamsoftBarcodeReader alloc] init];
    }
    
    CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@""];
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void)getVersion:(CDVInvokedUrlCommand *)command {
    CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:[DynamsoftBarcodeReader getVersion]];
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void)startScanning:(CDVInvokedUrlCommand *)command {
    [[DynamsoftSDKManager manager].barcodeReader startScanning];
    [DynamsoftSDKManager manager].dynamsoftBarcodeReaderState = DynamsoftBarcodeReaderStateStartScanning;
}

- (void)stopScanning:(CDVInvokedUrlCommand *)command {
    [[DynamsoftSDKManager manager].barcodeReader stopScanning];
    [DynamsoftSDKManager manager].dynamsoftBarcodeReaderState = DynamsoftBarcodeReaderStateStopScanning;
}

- (void)setTextResultListener:(CDVInvokedUrlCommand *)command {
    __block CDVPluginResult* pluginResult = nil;
    
    [DynamsoftSDKManager manager].barcodeTextResultCallBack = ^(NSArray<iTextResult *> * _Nonnull results) {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsArray:[[DynamsoftConvertManager manager] wrapResultsToJson:results]];
        [pluginResult setKeepCallbackAsBool:true];
        [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
    };
}

- (void)outputSettingsToString:(CDVInvokedUrlCommand *)command {
    NSError *error = nil;
    NSString *settingsString = [[DynamsoftSDKManager manager].barcodeReader outputSettingsToString:@"" error:&error];
   
    if ([[DynamsoftToolsManager manager] vertifyOperationResultWithError:error]) {
        CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:settingsString];
        [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
    } else {
        [self.commandDelegate sendPluginResult:[CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:[[DynamsoftToolsManager manager] getErrorMsgWithError:error]] callbackId:command.callbackId];
    }
}

- (void)getRuntimeSettings:(CDVInvokedUrlCommand *)command {
    NSError *error = nil;
    iPublicRuntimeSettings *runtimeSettings = [[DynamsoftSDKManager manager].barcodeReader getRuntimeSettings:&error];
    
    if ([[DynamsoftToolsManager manager] vertifyOperationResultWithError:error]) {
        CDVPluginResult *pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsDictionary:[[DynamsoftConvertManager manager] wrapRuntimeSettingsToJson:runtimeSettings]];
        [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
    } else {
        [self.commandDelegate sendPluginResult:[CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:[[DynamsoftToolsManager manager] getErrorMsgWithError:error]] callbackId:command.callbackId];
    }
}

- (void)updateRuntimeSettings:(CDVInvokedUrlCommand *)command {
    if (![[DynamsoftConvertManager manager] judgeArgumentsIsAvaiable:command.arguments]) {
        return;
    }
    
    // String | DBRRuntimeSettings | EnumDBRPresetTemplate
    DBRUpdateRuntimeSettingJsonType jsonType = [[DynamsoftConvertManager manager] judgeUpdateRuntimeSettingTypeWithArguments:command.arguments];
    
    NSError *error = nil;
    switch (jsonType) {
        case DBRUpdateRuntimeSettingJsonType_String:{
            [[DynamsoftSDKManager manager].barcodeReader initRuntimeSettingsWithString:[[DynamsoftConvertManager manager] aynlyzeJsonStringWithArguments:command.arguments] conflictMode:EnumConflictModeOverwrite error:&error];
            break;
        }
        case DBRUpdateRuntimeSettingJsonType_RuntimeSettingInstance:
        {
            iPublicRuntimeSettings *runtimeSettings = [[DynamsoftConvertManager manager] aynlyzeRuntimeSettingsWithArguments:command.arguments];
            [[DynamsoftSDKManager manager].barcodeReader updateRuntimeSettings:runtimeSettings error:&error];
            break;
        }
        case DBRUpdateRuntimeSettingJsonType_PresetTemplate:
        {
            [[DynamsoftSDKManager manager].barcodeReader updateRuntimeSettings:[[DynamsoftConvertManager manager] aynlyzePresetTemplateWithArguments:command.arguments]];
            break;
        }
            
        default:
            break;
    }
    if ([[DynamsoftToolsManager manager] vertifyOperationResultWithError:error]) {
        CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@""];
        [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
    } else {
        [self.commandDelegate sendPluginResult:[CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:[[DynamsoftToolsManager manager] getErrorMsgWithError:error]] callbackId:command.callbackId];
    }
}

- (void)resetRuntimeSettings:(CDVInvokedUrlCommand *)command {
    NSError *error = nil;
    [[DynamsoftSDKManager manager].barcodeReader resetRuntimeSettings:&error];
    if ([[DynamsoftToolsManager  manager] vertifyOperationResultWithError:error]) {
        CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@""];
        [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
    } else {
        [self.commandDelegate sendPluginResult:[CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:[[DynamsoftToolsManager manager] getErrorMsgWithError:error]] callbackId:command.callbackId];
    }
}

// MARK: - DCE methods
- (void)createDceInstance:(CDVInvokedUrlCommand *)command {
    
    // WebView url KVO
    if ([DynamsoftSDKManager manager].webViewObserverIsExisted == NO) {
        [DynamsoftSDKManager manager].webViewObserverIsExisted = YES;
        [self.webView addObserver:self forKeyPath:@"URL" options:NSKeyValueObservingOptionNew | NSKeyValueObservingOptionOld context:nil];
        [DynamsoftSDKManager manager].cameraViewPageUrlPath = ((WKWebView *)self.webView).URL.path;
    }
    
    // WebView tapGes.
    if ([DynamsoftSDKManager manager].webViewTapGesIsExisted == NO) {
        [DynamsoftSDKManager manager].webViewTapGesIsExisted = YES;
        UITapGestureRecognizer *webViewTapGes = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(webViewClickAction:)];
        webViewTapGes.delegate = self;
        [self.webView addGestureRecognizer:webViewTapGes];
    }
    
    //  Lifecycle Notification.
    if ([DynamsoftSDKManager manager].appLifecycleObserverIsExisted == NO) {
        [DynamsoftSDKManager manager].appLifecycleObserverIsExisted = YES;
        [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(appEnterBackground:) name:UIApplicationDidEnterBackgroundNotification object:nil];
        [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(appEnterForeground:) name:UIApplicationWillEnterForegroundNotification object:nil];
    }

    // Visible default value.
    [DynamsoftSDKManager manager].dynamsoftCameraViewIsVisible = true;
    [DynamsoftSDKManager manager].customCameraTorchFrame = CGRectZero;
    
    // Mask background.
    self.sdkMaskView.backgroundColor = [UIColor whiteColor];
    [self.webView.superview addSubview:self.sdkMaskView];
    [self.webView.superview sendSubviewToBack:self.sdkMaskView];

    // Create dce and view.
    if ([DynamsoftSDKManager manager].dynamsoftDCEIsExisted == NO) {
        [DynamsoftSDKManager manager].dynamsoftDCEIsExisted = YES;
        [self createDefaultDCEView];
    }
    
    CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@""];
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void)createDefaultDCEView {
    if (self.dynamsoftCameraView) {
        self.dynamsoftCameraView.hidden = YES;
        [self.dynamsoftCameraView removeFromSuperview];
    }

    NSDictionary *argumentsDic = @{@"position":@{@"x":@(0),
                                                 @"y":@(0),
                                                 @"width":@(10),
                                                 @"height":@(10)
                                                 }
    };
    CGFloat cameraX = [[[argumentsDic valueForKey:@"position"] valueForKey:@"x"] floatValue];
    CGFloat cameraY = [[[argumentsDic valueForKey:@"position"] valueForKey:@"y"] floatValue];
    CGFloat cameraWidth = [[[argumentsDic valueForKey:@"position"] valueForKey:@"width"] floatValue];
    CGFloat cameraHeight = [[[argumentsDic valueForKey:@"position"] valueForKey:@"height"] floatValue];
    
    // Create dce and add to webView.superView.
    self.dynamsoftCameraView = [[DynamsoftCameraView alloc] initWithFrame:CGRectMake(cameraX, cameraY, cameraWidth, cameraHeight) withArguments:argumentsDic];
    [self.webView.superview addSubview:self.dynamsoftCameraView];

    // Bind DCE to DBR.
    if ([DynamsoftSDKManager manager].barcodeReader != nil &&  [DynamsoftSDKManager manager].cameraEnhancer != nil) {
        [[DynamsoftSDKManager manager].barcodeReader setDBRTextResultListener:[DynamsoftSDKManager manager]];
        [[DynamsoftSDKManager manager].barcodeReader setCameraEnhancer:[DynamsoftSDKManager manager].cameraEnhancer];
    }
}

- (void)setScanRegion:(CDVInvokedUrlCommand *)command {
    if (![[DynamsoftConvertManager manager] judgeArgumentsIsAvaiable:command.arguments]) {
        return;
    }
    
    if ([DynamsoftSDKManager manager].dynamsoftCameraEnhancerState ==  DynamsoftCameraEnhancerStateClose) {
        return;
    }
    
    iRegionDefinition *scanRegion = [[DynamsoftConvertManager manager] aynlyzeiRegionDefinitionWithArguments:command.arguments];
    NSError *error = nil;
    [[DynamsoftSDKManager manager].cameraEnhancer setScanRegion:scanRegion error:&error];
    if ([[DynamsoftToolsManager manager] vertifyOperationResultWithError:error]) {
        CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@""];
        [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
    } else {
        [self.commandDelegate sendPluginResult:[CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:[[DynamsoftToolsManager manager] getErrorMsgWithError:error]] callbackId:command.callbackId];
    }
}

- (void)setScanRegionVisible:(CDVInvokedUrlCommand *)command {
    if (![[DynamsoftConvertManager manager] judgeArgumentsIsAvaiable:command.arguments]) {
        return;
    }

    BOOL scanRegionIsVisible = [command.arguments.firstObject boolValue];
    [[DynamsoftSDKManager manager].cameraEnhancer setScanRegionVisible:scanRegionIsVisible];
    
    CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@""];
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void)setTorchState:(CDVInvokedUrlCommand *)command {
    if (![[DynamsoftConvertManager manager] judgeArgumentsIsAvaiable:command.arguments]) {
        return;
    }
    BOOL torchState = [command.arguments.firstObject boolValue];
    if (torchState) {
        [[DynamsoftSDKManager manager].cameraEnhancer turnOnTorch];
        [DynamsoftSDKManager manager].dynamsoftCameraViewTorchIsOpen = YES;
    } else {
        [[DynamsoftSDKManager manager].cameraEnhancer turnOffTorch];
        [DynamsoftSDKManager manager].dynamsoftCameraViewTorchIsOpen = NO;
    }
    CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@""];
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void)open:(CDVInvokedUrlCommand *)command {
    [[DynamsoftSDKManager manager].cameraEnhancer open];
    [DynamsoftSDKManager manager].dynamsoftCameraEnhancerState =  DynamsoftCameraEnhancerStateOpen;
    
    CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@""];
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void)close:(CDVInvokedUrlCommand *)command  {
    [[DynamsoftSDKManager manager].cameraEnhancer close];
    [DynamsoftSDKManager manager].dynamsoftCameraEnhancerState =  DynamsoftCameraEnhancerStateClose;
    
    CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@""];
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void)updateCameraViewPosition:(CDVInvokedUrlCommand *)command {
    if (![[DynamsoftConvertManager manager] judgeArgumentsIsAvaiable:command.arguments]) {
        return;
    }
    [[DynamsoftSDKManager manager] updateDCEFrameWithArguments:command.arguments dceView:self.dynamsoftCameraView];
}

- (void)setCameraViewVisible:(CDVInvokedUrlCommand *)command {
    if (![[DynamsoftConvertManager manager] judgeArgumentsIsAvaiable:command.arguments]) {
        return;
    }
    
    BOOL isVisible = [command.arguments.firstObject boolValue];
    
    if (self.dynamsoftCameraView.dceView != nil) {
        self.dynamsoftCameraView.dceView.hidden = !isVisible;
    }
}

// MARK: - DCECameraView methods
- (void)bindCameraViewToElement:(CDVInvokedUrlCommand *)command  {
    if (![[DynamsoftConvertManager manager] judgeArgumentsIsAvaiable:command.arguments]) {
        return;
    }
    
    NSDictionary *argumentsDic =  command.arguments.firstObject;
    CGFloat cameraWidth = [[[argumentsDic valueForKey:@"position"] valueForKey:@"width"] floatValue];
    CGFloat cameraHeight = [[[argumentsDic valueForKey:@"position"] valueForKey:@"height"] floatValue];
    CGFloat cameraX = [[[argumentsDic valueForKey:@"position"] valueForKey:@"x"] floatValue];
    CGFloat cameraY = [[[argumentsDic valueForKey:@"position"] valueForKey:@"y"] floatValue];
    BOOL underWebView = [[argumentsDic valueForKey:@"underWebView"] boolValue];
    
    [self.dynamsoftCameraView setFrame:CGRectMake(cameraX, cameraY, cameraWidth, cameraHeight)];
    self.dynamsoftCameraView.dceView.frame = CGRectMake(0, 0, cameraWidth, cameraHeight);
    
    if (underWebView == YES) {
        [[DynamsoftToolsManager manager] makeWebViewTransparency:(UIWebView *)self.webView];
        [self.webView.superview bringSubviewToFront:self.webView];
    }
    
}

- (void)setOverlayVisible:(CDVInvokedUrlCommand *)command {
    if (![[DynamsoftConvertManager manager] judgeArgumentsIsAvaiable:command.arguments]) {
        return;
    }
    BOOL overlayIsVisible = [command.arguments.firstObject boolValue];
    self.dynamsoftCameraView.dceView.overlayVisible = overlayIsVisible;
}

- (void)setTorchButton:(CDVInvokedUrlCommand *)command {
    if (![[DynamsoftConvertManager manager] judgeArgumentsIsAvaiable:command.arguments]) {
        return;
    }
    
    BOOL visibleIsExist = [((NSDictionary *)command.arguments.firstObject).allKeys containsObject:@"visible"];
    BOOL locationIsExist = [((NSDictionary *)command.arguments.firstObject).allKeys containsObject:@"location"];
    BOOL customTurnOnImageIsExist = [((NSDictionary *)command.arguments.firstObject).allKeys containsObject:@"torchOnImage"];
    BOOL customTurnOffImageIsExist = [((NSDictionary *)command.arguments.firstObject).allKeys containsObject:@"torchOffImage"];
    
    BOOL torchIsVisible = YES;
    CGRect customTorchRect = CGRectMake(25, 100, 45, 45);
    NSString *torchOnImagePathString = @"";
    NSString *torchOffImagePathString = @"";
    UIImage *torchOnImage = nil;
    UIImage *torchOffImage = nil;
    
    if (!visibleIsExist) {
        return;
    } else {
        torchIsVisible = [[command.arguments.firstObject valueForKey:@"visible"] boolValue];
        if (!torchIsVisible) {
            return;
        }
    }
    
    if (locationIsExist) {
        customTorchRect = [[DynamsoftConvertManager manager] aynlyzeCustomTorchButtonFrameWithArguments:command.arguments torchDefaultRect:customTorchRect];
    }
    
    if (customTurnOnImageIsExist) {
        torchOnImagePathString = [command.arguments.firstObject valueForKey:@"torchOnImage"];
        torchOnImage = [UIImage imageNamed:[NSString stringWithFormat:@"www/%@", torchOnImagePathString]];
    }
    
    if (customTurnOffImageIsExist) {
        torchOffImagePathString = [command.arguments.firstObject valueForKey:@"torchOffImage"];
        torchOffImage = [UIImage imageNamed:[NSString stringWithFormat:@"www/%@", torchOffImagePathString]];
    }
    
    [self.dynamsoftCameraView.dceView setTorchButton:customTorchRect torchOnImage:torchOnImage torchOffImage:torchOffImage];
    
    [DynamsoftSDKManager manager].customCameraTorchFrame = customTorchRect;
    [DynamsoftSDKManager manager].dynamsoftCameraViewTorchIsVisible = torchIsVisible;
    self.dynamsoftCameraView.dceView.torchButtonVisible = true;
}

// MARK: - KVO
- (void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary<NSKeyValueChangeKey,id> *)change context:(void *)context {
    if ([keyPath  isEqualToString:@"URL"]) {
        NSString *newPath = ((NSURL *)[change valueForKey:NSKeyValueChangeNewKey]).path;
        if ([newPath isEqualToString:[DynamsoftSDKManager manager].cameraViewPageUrlPath]) {
            [DynamsoftSDKManager manager].dynamsoftCameraViewIsVisible = YES;
            [[DynamsoftSDKManager manager] updateCameraViewVisibleWithState:YES dceView:self.dynamsoftCameraView];
            [[DynamsoftSDKManager manager] updateCameraTorchState];
        } else {
            [DynamsoftSDKManager manager].dynamsoftCameraViewIsVisible = NO;
            [[DynamsoftSDKManager manager] updateCameraViewVisibleWithState:NO dceView:self.dynamsoftCameraView];
        }
    }
}

// MARK: - Notification
- (void)appEnterBackground:(NSNotification *)noti {

}

- (void)appEnterForeground:(NSNotification *)noti {
    [[DynamsoftSDKManager manager] updateCameraTorchState];
}

// MARK: - Webview ges
- (void)webViewClickAction:(UITapGestureRecognizer *)tapGes {
    if ([DynamsoftSDKManager manager].dynamsoftCameraViewIsVisible != YES) {
        return;
    }
    
    CGPoint clickPoint = [tapGes locationInView:self.webView];
    CGPoint cameraViewClickPoint = [self.dynamsoftCameraView.layer convertPoint:clickPoint fromLayer:self.webView.layer];
    BOOL isCameraViewContainsPoint = [self.dynamsoftCameraView.layer containsPoint:cameraViewClickPoint];
    if (isCameraViewContainsPoint) {
        [[DynamsoftSDKManager manager].cameraEnhancer setFocus:cameraViewClickPoint];
        [[DynamsoftSDKManager manager] updateCustomCameraTorchStateWithTorchFrame:[DynamsoftSDKManager manager].customCameraTorchFrame clickPoint:cameraViewClickPoint];
    }
}

- (BOOL)gestureRecognizer:(UIGestureRecognizer *)gestureRecognizer shouldRecognizeSimultaneouslyWithGestureRecognizer:(UIGestureRecognizer *)otherGestureRecognizer {
    return YES;
}

// MARK: - Lazy
-  (UIView *)sdkMaskView {
    if (!_sdkMaskView) {
        _sdkMaskView = [[UIView alloc] initWithFrame:self.webView.superview.bounds];
        _sdkMaskView.backgroundColor =  [UIColor whiteColor];
    }
    return _sdkMaskView;
}

@end
