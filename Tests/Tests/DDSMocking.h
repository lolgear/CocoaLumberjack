// Software License Agreement (BSD License)
//
// Copyright (c) 2010-2019, Deusty, LLC
// All rights reserved.
//
// Redistribution and use of this software in source and binary forms,
// with or without modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice,
//   this list of conditions and the following disclaimer.
//
// * Neither the name of Deusty nor the names of its contributors may be used
//   to endorse or promote products derived from this software without specific
//   prior written permission of Deusty, LLC.

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DDSMocking: NSObject
@end

NS_ASSUME_NONNULL_END

typedef NS_ENUM(NSInteger, DDBasicMockArgumentPositionType) {
    DDBasicMockArgumentPositionType__ReturnValue = 0,
    DDBasicMockArgumentPositionType__Self = 0,
    DDBasicMockArgumentPositionType__Cmd = 1,
    DDBasicMockArgumentPositionType__FirstArgument = 2,
};

@interface DDBasicMockArgument: NSObject <NSCopying>
@property (copy, nonatomic, readwrite) void(^block)(id object);
+ (instancetype)alongsideWithBlock:(void(^)(id object))block;
@end

@interface DDBasicMockArgumentPosition: NSObject <NSCopying>
@property (copy, nonatomic, readwrite) NSString *selector;
@property (copy, nonatomic, readwrite) NSNumber *position;
- (instancetype)initWithSelector:(NSString *)selector position:(NSNumber *)position;
@end

@interface DDBasicMockResult: NSObject <NSCopying>
@property (copy, nonatomic, readwrite) void *(^result)(NSInvocation *invocation);
+ (instancetype)mutatedResult:(void *(^)(NSInvocation *invocation))result;
@end

@interface DDBasicMock<T>: NSProxy
+ (instancetype)decoratedInstance:(T)object;
- (instancetype)enableStub;
- (instancetype)disableStub;
- (void)addArgument:(DDBasicMockArgument *)argument forSelector:(SEL)selector atIndex:(NSInteger)index;
- (void)addResult:(DDBasicMockResult *)result forSelector:(SEL)selector;
@end

@interface DDTweetProxy<T : NSObject*> : NSProxy
+ (instancetype)decoratedInstance:(T)instance;
@end
