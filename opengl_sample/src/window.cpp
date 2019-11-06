#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "window.h"

Window::Window(int width, int height, const char* title)
	: window(glfwCreateWindow(width, height, title, NULL, NULL))
	, scale(100.f), location{ 0,0 }, keyStatus(GLFW_RELEASE)
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

	// マウスホイール操作時に呼び出す処理の登録
	glfwSetScrollCallback(window, wheel);

	// キーボード操作時に呼び出す処理の登録
	glfwSetKeyCallback(window, keyboard);

	// 開いたウィンドウの初期設定
	resize(window, width, height);
}

void Window::swapBuffers()
{
	// カラーバッファを入れ替える
	glfwSwapBuffers(window);

	// イベントを取り出す
	if (keyStatus == GLFW_RELEASE)
		glfwWaitEvents();
	else
		glfwPollEvents();

	// キーボードの状態を調べる
	if (glfwGetKey(window, GLFW_KEY_LEFT) != GLFW_RELEASE)
		location[0] -= 2.0f / size[0];
	else if (glfwGetKey(window, GLFW_KEY_RIGHT) != GLFW_RELEASE)
		location[0] += 2.0f / size[0];
	if (glfwGetKey(window, GLFW_KEY_DOWN) != GLFW_RELEASE)
		location[1] -= 2.0f / size[1];
	else if (glfwGetKey(window, GLFW_KEY_UP) != GLFW_RELEASE)
		location[1] += 2.0f / size[1];

	// マウスの左ボタンの状態を調べる
	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_1) != GLFW_RELEASE) {
		// マウスの左ボタンが押されていたらマウスカーソルの位置を取得する
		double x, y;
		glfwGetCursorPos(window, &x, &y);
		// マウスカーソルの正規化デバイス座標系上での位置を求める
		location[0] = static_cast<GLfloat>(x) * 2.0f / size[0] - 1.0f;
		location[1] = 1.0f - static_cast<GLfloat>(y) * 2.0f / size[1];
	}
}

void Window::resize(GLFWwindow* const window, int width, int height)
{
	// ウィンドウ全体をビューポートに設定する
	glViewport(0, 0, width, height);

	// このインスタンスの this ポインタを得る
	Window* const instance(static_cast<Window*>(glfwGetWindowUserPointer(window)));
	if (instance != NULL)
	{
		// 開いたウィンドウのサイズを保存する
		instance->size[0] = static_cast<GLfloat>(width);
		instance->size[1] = static_cast<GLfloat>(height);
	}
}

void Window::wheel(GLFWwindow* window, double x, double y)
{
	// このインスタンスの this ポインタを得る
	Window* const instance(static_cast<Window*>(glfwGetWindowUserPointer(window)));
	if (instance != NULL)
	{
		// ワールド座標系に対するデバイス座標系の拡大率を更新する
		instance->scale += static_cast<GLfloat>(y) * 2.0f;
	}
}

void Window::keyboard(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	// このインスタンスの this ポインタを得る
	Window* const instance(static_cast<Window*>(glfwGetWindowUserPointer(window)));
	if (instance != NULL)
	{
		// キーの状態を保存する
		instance->keyStatus = action;
	}
}