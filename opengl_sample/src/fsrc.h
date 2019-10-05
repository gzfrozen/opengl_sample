#pragma once
// フラグメントシェーダのソースプログラム
static constexpr GLchar fsrc[] =
"#version 450 core\n"
"out vec4 fragment;\n"
"void main()\n"
"{\n"
" fragment = vec4(1.0, 0.0, 0.0, 1.0);\n"
"}\n";