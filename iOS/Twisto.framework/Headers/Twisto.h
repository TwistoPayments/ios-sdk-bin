//
//  Twisto.h
//  Twisto
//
//  Created by Petr Slovacek on 05.05.16.
//  Copyright © 2016 Twisto. All rights reserved.
//

#import <Foundation/Foundation.h>

@class Twisto;
@protocol TwistoCheckDelegate <NSObject>
@required
NS_ASSUME_NONNULL_BEGIN
- (void) TwistoCheckAccepted:(NSString *)transactionId;
- (void) TwistoCheckRejected:(NSString *)transactionId reason:(NSString *)reason;
- (void) TwistoCheckError:(NSError *)error;
@optional
- (void) TwistoWillDisplayLoginDialog;
- (void) TwistoDidHideLoginDialog;
NS_ASSUME_NONNULL_END
@end

@interface Twisto : NSObject

@property (nonatomic, weak, nullable) id <TwistoCheckDelegate> delegate;
NS_ASSUME_NONNULL_BEGIN
- (nonnull instancetype)initWithPublicKey:(NSString *)key;
- (nonnull instancetype)initWithPublicKey:(NSString *)key withDelegate: (id<TwistoCheckDelegate>)delegate;
- (void)checkWithPayload: (NSData *)payload;
- (void)checkWithPayload:(NSData *)data acceptedCompletionHandler: (void(^)(NSString * transactionId))acceptedCompletionHandler rejectedCompletionHandler: (void(^)(NSString * transactionId, NSString  * reason))rejectedCompletionHandler errorCompletionHandler: (void(^)(NSError * error))errorCompletionHandler willDisplayLoginDialogHandler: ( void(^ _Nullable )())willDisplayLoginDialogHandler  didHideLoginDialogHandler: (void(^ _Nullable )())didHideLoginDialogHandler;
NS_ASSUME_NONNULL_END
@end
