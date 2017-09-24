//
//  Shader.cpp
//  LittleHouse
//
//  Created by lbbetty on 17/9/24.
//  Copyright (c) 2017年 Xnight. All rights reserved.
//

#include "Shader.h"
#include <stdlib.h>

Shader::Shader(char*vs, char*fs){
    
    GLuint vshader = glCreateShader(GL_VERTEX_SHADER);
    readShaderSource(vshader, vs);
    glCompileShader(vshader);
    
    GLuint fshader = glCreateShader(GL_FRAGMENT_SHADER);
    readShaderSource(fshader, fs);
    glCompileShader(fshader);
    
    GLuint program = glCreateProgram();
    
    glAttachShader(program, vshader);
    glAttachShader(program, fshader);
    
    glLinkProgram(program);
    
    glDeleteShader(vshader);
    glDeleteShader(fshader);
}

Shader::~Shader(){

}
int Shader::readShaderSource(GLuint nshader,char* file){
    FILE *fp;
    const GLchar *source;
    GLsizei length;
    int ret;
    
    fp = fopen(file, "r");
    if (!fp) {
        perror(file);
        return -1;
    }
    fseek(fp, 0, SEEK_END);
    length = ftell(fp);
    
    source = (GLchar*)malloc(length);
    if (source) {
        fprintf(stderr, "could not allocate read buffer");
        return -1;
    }
    
    fseek(fp,0,SEEK_END);
    ret = fread((void*)source, 1, length, fp)==(size_t)length;
    fclose(fp);
    
    if (ret) {
        glShaderSource(nshader, 1, &source, &length);
    }
    
    free((void *)source);
    
    return 1;
}
