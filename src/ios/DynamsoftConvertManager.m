//
//  DynamsoftConvertManager.m
//  HelloCordova
//
//  Created by Dynamsoft's mac on 2022/7/11.
//

#import "DynamsoftConvertManager.h"

@implementation DynamsoftConvertManager

+ (DynamsoftConvertManager *)manager
{
    static DynamsoftConvertManager *convertManager = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        convertManager = [super allocWithZone:NULL];
    });
    return convertManager;
}


+ (instancetype)allocWithZone:(struct _NSZone *)zone
{
    return [DynamsoftConvertManager manager];
}

- (id)copyWithZone:(NSZone *)zone
{
    return [DynamsoftConvertManager manager];
}

- (id)mutableCopyWithZone:(NSZone *)zone
{
    return [DynamsoftConvertManager manager];
}

// MARK: - General methods
- (BOOL)judgeArgumentsIsAvaiable:(NSArray *)arguments {
    if (arguments.count == 0 || arguments.firstObject == nil || arguments.firstObject == [NSNull null]) {
        return NO;
    }
    return YES;
}

// MARK: - From json

- (iRegionDefinition *)aynlyzeiRegionDefinitionWithArguments:(NSArray *)arguments {
    NSDictionary *scanRegionDic =  arguments.firstObject;
    NSInteger regionTop = [[scanRegionDic valueForKey:@"regionTop"] integerValue];
    NSInteger regionBottom = [[scanRegionDic valueForKey:@"regionBottom"] integerValue];
    NSInteger regionLeft = [[scanRegionDic valueForKey:@"regionLeft"] integerValue];
    NSInteger regionRight = [[scanRegionDic valueForKey:@"regionRight"] integerValue];
    bool regionMeasuredByPercentage = [[scanRegionDic valueForKey:@"regionMeasuredByPercentage"] boolValue];
    iRegionDefinition *regionDefiniton = [[iRegionDefinition alloc] init];
    regionDefiniton.regionTop = regionTop;
    regionDefiniton.regionBottom = regionBottom;
    regionDefiniton.regionLeft = regionLeft;
    regionDefiniton.regionRight = regionRight;
    regionDefiniton.regionMeasuredByPercentage = regionMeasuredByPercentage;
    return  regionDefiniton;
}

- (DBRUpdateRuntimeSettingJsonType)judgeUpdateRuntimeSettingTypeWithArguments:(NSArray *)arguments {
    
    id argumentsData = arguments.firstObject;
    if ([argumentsData isKindOfClass:[NSString class]]) {
        return DBRUpdateRuntimeSettingJsonType_String;
    } else if ([argumentsData isKindOfClass:[NSDictionary class]]) {
        return DBRUpdateRuntimeSettingJsonType_RuntimeSettingInstance;
    } else if ([argumentsData isKindOfClass:[NSNumber class]]) {
        return DBRUpdateRuntimeSettingJsonType_PresetTemplate;
    }
    return DBRUpdateRuntimeSettingJsonType_Undefine;
}

- (NSString *)aynlyzeJsonStringWithArguments:(NSArray *)arguments {
    return arguments.firstObject;
}

- (iPublicRuntimeSettings *)aynlyzeRuntimeSettingsWithArguments:(NSArray *)arguments {
    NSDictionary *settings = arguments.firstObject;
    iPublicRuntimeSettings *publicRuntimeSettings = [[DynamsoftSDKManager manager].barcodeReader getRuntimeSettings:nil];
    publicRuntimeSettings.barcodeFormatIds = [[settings valueForKey:@"barcodeFormatIds"] intValue];
    publicRuntimeSettings.barcodeFormatIds_2 = [[settings valueForKey:@"barcodeFormatIds_2"] intValue];
    publicRuntimeSettings.expectedBarcodesCount = [[settings valueForKey:@"expectedBarcodesCount"] intValue];
    publicRuntimeSettings.timeout = [[settings valueForKey:@"timeout"] intValue];
    
    return publicRuntimeSettings;
}

- (EnumPresetTemplate)aynlyzePresetTemplateWithArguments:(NSArray *)arguments {
    return [arguments.firstObject integerValue];
}

- (CGRect)aynlyzeCustomTorchButtonFrameWithArguments:(NSArray *)arguments
                                    torchDefaultRect:(CGRect)torchDefaultRect {
    NSDictionary *customButtonDic = [arguments.firstObject valueForKey:@"location"];
    CGFloat x = [[customButtonDic valueForKey:@"x"] floatValue];
    CGFloat y = [[customButtonDic valueForKey:@"y"] floatValue];
    CGFloat width = [[customButtonDic valueForKey:@"width"] floatValue];
    CGFloat height = [[customButtonDic valueForKey:@"height"] floatValue];
    return CGRectMake(x, y, width <= torchDefaultRect.size.width ? width : torchDefaultRect.size.width, height <= torchDefaultRect.size.height ? height : torchDefaultRect.size.height);
}

// MARK: - To json

- (NSArray *)wrapResultsToJson:(NSArray<iTextResult *> *)results {
    NSMutableArray *jsonArray = [NSMutableArray array];
    for (iTextResult *textResult in results) {
        NSString *barcodeFormatString = @"";
        if (textResult.barcodeFormat_2 != 0) {
            barcodeFormatString = textResult.barcodeFormatString_2;
        } else {
            barcodeFormatString = textResult.barcodeFormatString;
        }
        
        NSMutableArray *locationPoints = [NSMutableArray array];
        for (NSValue *resultPoint in textResult.localizationResult.resultPoints) {
            CGPoint point = [resultPoint CGPointValue];
            [locationPoints addObject:@{@"x":@((int)point.x),
                                        @"y":@((int)point.y)
                                      }];
        }
    
        [jsonArray addObject:@{@"barcodeText":textResult.barcodeText,
                               @"barcodeFormatString":barcodeFormatString,
                               @"barcodeBytes":[textResult.barcodeBytes base64EncodedStringWithOptions:NSDataBase64EncodingEndLineWithLineFeed],
                               @"barcodeLocation":@{@"angle":@(textResult.localizationResult.angle),
                                                    @"quadrilateral":@{@"points":locationPoints}
                               }
                             }];
    }
    
    return jsonArray;
}

- (NSDictionary *)wrapRuntimeSettingsToJson:(iPublicRuntimeSettings *)runtimeSettings
{
    return @{@"barcodeFormatIds":@(runtimeSettings.barcodeFormatIds),
             @"barcodeFormatIds_2":@(runtimeSettings.barcodeFormatIds_2),
             @"expectedBarcodesCount":@(runtimeSettings.expectedBarcodesCount),
             @"timeout":@(runtimeSettings.timeout)
    };
}

@end
