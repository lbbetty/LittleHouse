//
//  GLHouseView.m
//  LittleHouse
//
//  Created by lbbetty on 17/9/24.
//  Copyright (c) 2017年 Xnight. All rights reserved.
//

#import "GLHouseView.h"

@implementation GLHouseView


// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect {
    // Drawing code
}

+(Class)layerClass{
    return [CAEAGLLayer class];
}

-(void)layoutSubviews{
    [self setupLayer];
    [self setupContext];
    
    [self destroyRenderAndFrameBuffer];
    [self setupRenderBuffer];
    [self setupFrameBuffer];
    
    
    [self render];
}
-(void)setupLayer
{
    _eaglLayer = (CAEAGLLayer*)self.layer;
    
    _eaglLayer.opaque = YES;
    _eaglLayer.drawableProperties =[NSDictionary dictionaryWithObjectsAndKeys:[NSNumber numberWithBool:NO],kEAGLDrawablePropertyRetainedBacking,kEAGLColorFormatRGBA8,kEAGLDrawablePropertyColorFormat, nil];
}

-(void)setupContext{
    EAGLRenderingAPI api = kEAGLRenderingAPIOpenGLES2;
    _context =[[EAGLContext alloc]initWithAPI:api];
    
    if (!_context) {
        NSLog(@"Failed to initialize opengles2\n");
        exit(1);
    }
    
    if (![EAGLContext setCurrentContext:_context]) {
        NSLog(@"Fail to set context\n");
        exit(1);
    }
}

-(void)setupRenderBuffer{
    glGenRenderbuffers(1, &_colorRenderBuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, _colorRenderBuffer);
    [_context renderbufferStorage:GL_RENDERBUFFER fromDrawable:_eaglLayer];
}

-(void)setupFrameBuffer
{
    glGenFramebuffers(1, &_frameBuffer);
    glBindFramebuffer(GL_FRAMEBUFFER, _frameBuffer);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, _colorRenderBuffer);
}

-(void)destroyRenderAndFrameBuffer{
    glDeleteFramebuffers(1, &_frameBuffer);
    _frameBuffer =0;
    glDeleteRenderbuffers(1, &_colorRenderBuffer);
    _colorRenderBuffer =0;
}
-(void)render{
    glClearColor(0, 1.0, 0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    [_context presentRenderbuffer:GL_RENDERBUFFER];
}


@end
