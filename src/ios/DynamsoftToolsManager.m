//
//  DynamsoftToolsManager.m
//  HelloCordova
//
//  Created by Dynamsoft's mac on 2022/7/11.
//

#import "DynamsoftToolsManager.h"

@implementation DynamsoftToolsManager

+ (DynamsoftToolsManager *)manager
{
    static DynamsoftToolsManager *toolsManager = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        toolsManager = [super allocWithZone:NULL];
    });
    return toolsManager;
}

+ (instancetype)allocWithZone:(struct _NSZone *)zone
{
    return [DynamsoftToolsManager manager];
}

- (id)copyWithZone:(NSZone *)zone
{
    return [DynamsoftToolsManager manager];
}

- (id)mutableCopyWithZone:(NSZone *)zone
{
    return [DynamsoftToolsManager manager];
}

// MARK: - Methods

- (BOOL)vertifyOperationResultWithError:(NSError *)error
{
    BOOL isSuccess = YES;
    if (error != nil) {
        NSString *msg = error.userInfo[NSUnderlyingErrorKey];
        
        if ([msg isEqualToString:@"Successful."]) {
            isSuccess = YES;
        } else {
            isSuccess = NO;
        }
        
    }
    return  isSuccess;
}

- (NSString *)getErrorMsgWithError:(NSError *)error
{
    NSString *errorString = @"";
    if (error != nil) {
        errorString = error.userInfo[NSUnderlyingErrorKey];
        
    }
    return errorString;
}

//MARK: String methods

/// Checks if the string is empty.
- (BOOL)stringIsEmptyOrNull:(NSString*)string
{
    return ![self notEmptyOrNull:string];
}

/// Checks if the string is not empty.
- (BOOL)notEmptyOrNull:(NSString*)string
{
    if ([string isKindOfClass:[NSNull class]])
        return NO;
    if ([string isEqual:[NSNull null]] || string==nil) {
        return NO;
    }
    if ([string isKindOfClass:[NSNumber class]]) {
        if (string != nil) {
            return YES;
        }
        return NO;
    }
    else {
        string = [self trimString:string];
        if ( [string isEqualToString:@"null"] || [string isEqualToString:@"(null)"] || [string isEqualToString:@" "]|| [string isEqualToString:@""] || [string isEqualToString:@"<null>"]) {
            return NO;
        }
        if (string != nil && string.length > 0) {
            return YES;
        }
        return NO;
    }
}

/// CropString.
- (NSString*)trimString:(NSString*)str
{
    return [str stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]];
}


- (void)makeWebViewTransparency:(UIWebView *)webView {
    [webView setOpaque:false];
    [webView setBackgroundColor:UIColor.clearColor];
    [webView.scrollView setBackgroundColor:UIColor.clearColor];
}

- (void)restoreWebViewBackground:(UIWebView *)webView {
    [webView setOpaque:true];
    [webView setBackgroundColor:UIColor.whiteColor];
    [webView.scrollView setBackgroundColor:UIColor.whiteColor];
}

- (void)hiddenSubviewColor:(UIView *)view {
    NSArray *subViews = view.subviews;
    if (subViews.count > 0) {
        for (int i = 0; i < subViews.count; i++) {
            UIView *tempView = subViews[i];
            tempView.backgroundColor = [UIColor greenColor];
            [self hiddenSubviewColor:tempView];
        }
       
    } else {
        return;
    }
}

@end
