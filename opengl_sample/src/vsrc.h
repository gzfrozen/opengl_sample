﻿#pragma once
// バーテックスシェーダのソースプログラム
static constexpr GLchar vsrc[] =
"#version 150 core¥n"
"in vec4 position;¥n"
"void main()¥n"
"{¥n"
" gl_Position = position;¥n"
"}¥n";