/* cocos2d for iPhone
 *
 * http://www.cocos2d-iphone.org
 *
 * Copyright (C) 2009 Ricardo Quesada
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the 'cocos2d for iPhone' license.
 *
 * You will find a copy of this license within the cocos2d for iPhone
 * distribution inside the "LICENSE" file.
 *
 */

#import <Foundation/Foundation.h>
#import "CCNode.h"
#import "CCProtocols.h"

#pragma mark -
#pragma mark CCSpriteFrame

/** A CCSpriteFrame is an NSObject that encapsulates a CGRect.
 * And a CGRect represents a frame within the CCSpriteSheet
 */
@interface CCSpriteFrame : NSObject <NSCopying>
{
	CGRect			rect_;
	CGPoint			offset_;
	CCTexture2D		*texture_;
	BOOL			flipX_;
	BOOL			flipY_;
}
/** rect of the frame */
@property (nonatomic,readwrite) CGRect rect;

/** offset of the frame */
@property (nonatomic,readwrite) CGPoint offset;

/** texture of the frame */
@property (nonatomic, retain, readwrite) CCTexture2D *texture;

/** whether or not the frame is flipped horizontally */
@property (nonatomic,readwrite)	BOOL flipX;

/** whether or not the frame is flipped vertically */
@property (nonatomic,readwrite)	BOOL flipY;

/** Create a CCSpriteFrame with a texture, rect and offset.
 The frame won't be flipped by default.
 */
+(id) frameWithTexture:(CCTexture2D*)texture rect:(CGRect)rect offset:(CGPoint)offset;

/** Create a CCSpriteFrame with a texture, rect and offset, flipX and flipY.
 */
+(id) frameWithTexture:(CCTexture2D*)texture rect:(CGRect)rect offset:(CGPoint)offset flipX:(BOOL)flipX flipY:(BOOL)flipY;

/** Initializes a CCSpriteFrame with a texture, rect and offset.
 The frame won't be flipped by default
 */
-(id) initWithTexture:(CCTexture2D*)texture rect:(CGRect)rect offset:(CGPoint)offset;

/** Initializes a CCSpriteFrame with a texture, rect and offset, flipX and flipY. */
-(id) initWithTexture:(CCTexture2D*)texture rect:(CGRect)rect offset:(CGPoint)offset flipX:(BOOL)flipX flipY:(BOOL)flipY;

@end

#pragma mark -
#pragma mark CCAnimation

/** an Animation object used within Sprites to perform animations */
@interface CCAnimation : NSObject <CCAnimationProtocol>
{
	NSString			*name_;
	float				delay_;
	NSMutableArray		*frames_;
}

/** name of the animation */
@property (nonatomic,readwrite,retain) NSString *name;
/** delay between frames in seconds. */
@property (nonatomic,readwrite,assign) float delay;
/** array of frames */
@property (nonatomic,readwrite,retain) NSMutableArray *frames;

/** Creates a CCAnimation with a name and delay between frames. */
+(id) animationWithName:(NSString*)name delay:(float)delay;

/** Creates a CCAnimation with a name, delay and an array of CCSpriteFrames. */
+(id) animationWithName:(NSString*)name delay:(float)delay array:(NSArray*)array;

/** Initializes a CCAnimation with a name and delay between frames. */
-(id) initWithName:(NSString*)name delay:(float)delay;

/** Initializes a CCAnimation with a name, delay and an array of CCSpriteFrames. */
-(id) initWithName:(NSString*)name delay:(float)delay array:(NSArray*)array;

/** Adds a frame to a CCAnimation. */
-(void) addFrame:(CCSpriteFrame*)frame;

/** Adds a frame with an image filename. */
-(void) addFrameWithFilename:(NSString*)filename;

/** Adds a frame with a texture and a rect */
-(void) addFrameWithTexture:(CCTexture2D*)texture rect:(CGRect)rect;
@end