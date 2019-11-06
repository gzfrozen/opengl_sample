#pragma once
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

// ウィンドウ関連の処理
class Window
{
	// ウィンドウのハンドル
	GLFWwindow* const window;

	// ウィンドウのサイズ
	GLfloat size[2];

	// ワールド座標系に対するデバイス座標系の拡大率
	GLfloat scale;

	// 図形の正規化デバイス座標系上での位置
	GLfloat location[2];

	// キーボードの状態
	int keyStatus;

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
		return glfwWindowShouldClose(window) || glfwGetKey(window, GLFW_KEY_ESCAPE);
	}

	// カラーバッファを入れ替えてイベントを取り出す
	void swapBuffers();

	// ウィンドウのサイズを取り出す
	const GLfloat* getSize() const { return size; }

	// ワールド座標系に対するデバイス座標系の拡大率を取り出す
	GLfloat getScale() const { return scale; }

	// 位置を取り出す
	const GLfloat* getLocation() const { return location; }

	// ウィンドウのサイズ変更時の処理
	static void resize(GLFWwindow* const window, int width, int height);

	// マウスホイール操作時の処理
	static void wheel(GLFWwindow* window, double x, double y);

	// キーボード操作時の処理
	static void keyboard(GLFWwindow* window, int key, int scancode, int action, int mods);
};