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
- (void) TwistoCheckAccepted:(NSString *)transactionId;
- (void) TwistoCheckRejected:(NSString *)transactionId reason:(NSString *)reason;
- (void) TwistoCheckError:(NSError *)error;
@end

@interface Twisto : NSObject

@property (nonatomic, weak) id <TwistoCheckDelegate> delegate;
- (id)initWithPublicKey:(NSString *)key;
- (id)initWithPublicKey:(NSString *)key withDelegate: (id)delegate;
- (void)checkWithPayload: (NSData *)payload;
- (void)checkWithPayload:(NSData *)data acceptedCompletionHandler: (void(^)(NSString * transactionId))acceptedCompletionHandler rejectedCompletionHandler: (void(^)(NSString * transactionId, NSString  * reason))rejectedCompletionHandler errorCompletionHandler: (void(^ )(NSError * error))errorCompletionHandler;

@end
