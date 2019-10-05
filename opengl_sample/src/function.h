#pragma once
#include <GL/glew.h>
GLuint createProgram(const char* vsrc, const char* fsrc);
GLboolean printShaderInfoLog(GLuint shader, const char* str);
GLboolean printProgramInfoLog(GLuint program);