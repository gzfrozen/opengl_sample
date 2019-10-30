#pragma once
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

// ウィンドウ関連の処理
class Window
{
	// ウィンドウのハンドル
	GLFWwindow* const window;
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

	// ウィンドウのサイズ変更時の処理
	static void resize(GLFWwindow* const window, int width, int height)
	{
		// ウィンドウ全体をビューポートに設定する
		glViewport(0, 0, width, height);
	}
};