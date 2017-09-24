//
//  GLHouseView.h
//  LittleHouse
//
//  Created by lbbetty on 17/9/24.
//  Copyright (c) 2017年 Xnight. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <QuartzCore/QuartzCore.h>

#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>

@interface GLHouseView : UIView
{
    CAEAGLLayer* _eaglLayer;
    EAGLContext* _context;
    GLuint _colorRenderBuffer;
    GLuint _frameBuffer;
}

-(void)setupLayer;

-(void)setupContext;

-(void)setupRenderBuffer;

-(void)setupFrameBuffer;

-(void)destroyRenderAndFrameBuffer;

-(void)render;
@end
