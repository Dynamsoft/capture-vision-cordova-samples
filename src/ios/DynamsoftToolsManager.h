//
//  DynamsoftToolsManager.h
//  HelloCordova
//
//  Created by Dynamsoft's mac on 2022/7/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DynamsoftToolsManager : NSObject<NSCopying, NSMutableCopying>

+ (DynamsoftToolsManager *)manager;


/// Vertify the operation is success or failure.
- (BOOL)vertifyOperationResultWithError:(NSError * _Nullable)error;

/// Return  the error string if error is not nil.
- (NSString *)getErrorMsgWithError:(NSError * _Nullable)error;

/// Checks if the string is empty.
- (BOOL)stringIsEmptyOrNull:(NSString*)string;

/// Make webView clear.
- (void)makeWebViewTransparency:(UIWebView *)webView;

/// Restore webView background.
- (void)restoreWebViewBackground:(UIWebView *)webView;

- (void)hiddenSubviewColor:(UIView *)view;

@end

NS_ASSUME_NONNULL_END
