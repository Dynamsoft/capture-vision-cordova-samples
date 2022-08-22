//
//  DynamsoftConvertManager.h
//  HelloCordova
//
//  Created by Dynamsoft's mac on 2022/7/11.
//

#import <Foundation/Foundation.h>
#import <DynamsoftBarcodeReader/DynamsoftBarcodeReader.h>
#import <DynamsoftCameraEnhancer/DynamsoftCameraEnhancer.h>
#import "DynamsoftSDKManager.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, DBRUpdateRuntimeSettingJsonType) {
    DBRUpdateRuntimeSettingJsonType_Undefine,
    DBRUpdateRuntimeSettingJsonType_String,
    DBRUpdateRuntimeSettingJsonType_RuntimeSettingInstance,
    DBRUpdateRuntimeSettingJsonType_PresetTemplate
};

@interface DynamsoftConvertManager : NSObject<NSCopying, NSMutableCopying>

+ (DynamsoftConvertManager *)manager;

// MARK: - General methods

- (BOOL)judgeArgumentsIsAvaiable:(NSArray *)arguments;

// MARK: - From json

/// Convert json to iRegionDefinition
- (iRegionDefinition *)aynlyzeiRegionDefinitionWithArguments:(NSArray *)arguments;

/// Judge updateRuntimeSetting type form json.
- (DBRUpdateRuntimeSettingJsonType)judgeUpdateRuntimeSettingTypeWithArguments:(NSArray *)arguments;

/// Convert json to jsonString.
- (NSString *)aynlyzeJsonStringWithArguments:(NSArray *)arguments;

/// Convert json to iPublicRuntimeSettings.
- (iPublicRuntimeSettings *)aynlyzeRuntimeSettingsWithArguments:(NSArray *)arguments;

/// Convert json to EnumPresetTemplate
- (EnumPresetTemplate)aynlyzePresetTemplateWithArguments:(NSArray *)arguments;

/// Convert json to custom torch button frame.
- (CGRect)aynlyzeCustomTorchButtonFrameWithArguments:(NSArray *)arguments
                                    torchDefaultRect:(CGRect)torchDefaultRect;


// MARK: - To json

/// Wrap textResults to Json.
- (NSArray *)wrapResultsToJson:(NSArray<iTextResult *> *)results;

/// Wrap iPublicRuntimeSettings to Json.
- (NSDictionary *)wrapRuntimeSettingsToJson:(iPublicRuntimeSettings *)runtimeSettings;

@end

NS_ASSUME_NONNULL_END
