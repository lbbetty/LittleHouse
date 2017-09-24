//
//  Shader.h
//  LittleHouse
//
//  Created by lbbetty on 17/9/24.
//  Copyright (c) 2017年 Xnight. All rights reserved.
//

#ifndef __LittleHouse__Shader__
#define __LittleHouse__Shader__

#include <stdio.h>

#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>

class Shader{
public:
    Shader(char* vs,char* fs);
    ~Shader();
    
    int readShaderSource(GLuint nshader,char* file);
};


#endif /* defined(__LittleHouse__Shader__) */
