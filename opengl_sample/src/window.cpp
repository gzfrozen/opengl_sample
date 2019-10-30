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

	// このインスタンスの this ポインタを記録しておく
	glfwSetWindowUserPointer(window, this);

	// ウィンドウのサイズ変更時に呼び出す処理の登録
	glfwSetWindowSizeCallback(window, resize);

	// 開いたウィンドウの初期設定
	resize(window, width, height);
}

void Window::resize(GLFWwindow* const window, int width, int height)
{
	// ウィンドウ全体をビューポートに設定する
	glViewport(0, 0, width, height);

	// このインスタンスの this ポインタを得る
	Window* const
		instance(static_cast<Window*>(glfwGetWindowUserPointer(window)));
	if (instance != NULL)
	{
		// このインスタンスが保持する縦横比を更新する
		instance->aspect =
			static_cast<GLfloat>(width) / static_cast<GLfloat>(height);
	}
}
