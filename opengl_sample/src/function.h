#pragma once
#include <GL/glew.h>
GLuint createProgram(const char* vsrc, const char* fsrc);
/*
プログラムオブジェクトを作成する
vsrc: バーテックスシェーダのソースプログラムの文字列
fsrc: フラグメントシェーダのソースプログラムの文字列
*/

bool readShaderSource(const char* name, std::vector<GLchar>& buffer);
/*
シェーダのソースファイルを読み込んだメモリを返す
name: シェーダのソースファイル名
buffer: 読み込んだソースファイルのテキスト
*/

GLuint loadProgram(const char* vert, const char* frag);
/*
シェーダのソースファイルを読み込んでプログラムオブジェクトを作成する
vert: バーテックスシェーダのソースファイル名
frag: フラグメントシェーダのソースファイル名
*/

GLboolean printShaderInfoLog(GLuint shader, const char* str);
/*
シェーダオブジェクトのコンパイル結果を表示する
shader: シェーダオブジェクト名
str: コンパイルエラーが発生した場所を示す文字列
*/

GLboolean printProgramInfoLog(GLuint program);
/*
プログラムオブジェクトのリンク結果を表示する
program: プログラムオブジェクト名
*/