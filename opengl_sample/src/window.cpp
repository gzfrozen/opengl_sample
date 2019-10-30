#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "window.h"

Window::Window(int width, int height, const char* title)
	: window(glfwCreateWindow(width, height, title, NULL, NULL))
{
	if (window == NULL)
	{
		// ウィンドウが作成できなかった
		std::cerr << "Can't create GLFW window." << std::endl;
		exit(1);
	}
	// 現在のウィンドウを処理対象にする
	glfwMakeContextCurrent(window);
	// GLEW を初期化する
	if (glewInit() != GLEW_OK)
	{
		// GLEW の初期化に失敗した
		std::cerr << "Can't initialize GLEW" << std::endl;
		exit(1);
	}
	// 垂直同期のタイミングを待つ
	glfwSwapInterval(1);

	// ウィンドウのサイズ変更時に呼び出す処理の登録
	glfwSetWindowSizeCallback(window, resize);

	// 開いたウィンドウの初期設定
	resize(window, width, height);
}
