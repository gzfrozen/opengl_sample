#pragma once
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

// ウィンドウ関連の処理
class Window
{
	// ウィンドウのハンドル
	GLFWwindow* const window;

	// 縦横比
	GLfloat aspect;

public:
	// コンストラクタ
	Window(int width = 640, int height = 480, const char* title = "Hello!");

	// デストラクタ
	virtual ~Window()
	{
		glfwDestroyWindow(window);
	}

	// ウィンドウを閉じるべきかを判定する
	int shouldClose() const
	{
		return glfwWindowShouldClose(window);
	}

	// カラーバッファを入れ替えてイベントを取り出す
	void swapBuffers()
	{
		// カラーバッファを入れ替える
		glfwSwapBuffers(window);
		// イベントを取り出す
		glfwWaitEvents();
	}

	// 縦横比を取り出す
	GLfloat getAspect() const { return aspect; }

	// ウィンドウのサイズ変更時の処理
	static void resize(GLFWwindow* const window, int width, int height);
};