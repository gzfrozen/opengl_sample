#include <cstdlib>
#include <iostream>
#include <GLFW/glfw3.h>
int main()
{
	// GLFW を初期化する
	if (glfwInit() == GL_FALSE)
	{
		// 初期化に失敗した
		std::cerr << "Can't initialize GLFW" << std::endl;
		return 1;
	}

	// プログラム終了時の処理を登録する
	atexit(glfwTerminate);

	// OpenGL Version 3.2 Core Profile を選択する
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// ウィンドウを作成する
	GLFWwindow* const window(glfwCreateWindow(640, 480, "Hello!", NULL, NULL));
	if (window == NULL)
	{
		// ウィンドウが作成できなかった
		std::cerr << "Can't create GLFW window." << std::endl;
		return 1;
	}

	// 作成したウィンドウを OpenGL の処理対象にする
	glfwMakeContextCurrent(window);

	// GLEW を初期化する
	//if (glewInit() != GLEW_OK)
	//{
	//	// GLEW の初期化に失敗した
	//	std::cerr << "Can't initialize GLEW" << std::endl;
	//	return 1;
	//}

	// 垂直同期のタイミングを待つ
	glfwSwapInterval(1);

	// 背景色を指定する
	//glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

	// ウィンドウが開いている間繰り返す
	while (glfwWindowShouldClose(window) == GL_FALSE)
	{
		// ウィンドウを消去する
		glClear(GL_COLOR_BUFFER_BIT);
		//
		// ここで描画処理を行う
		glBegin(GL_TRIANGLES);
		{
			glColor3f(1.0f, 0.0f, 0.0f);
			glVertex2f(0.0f, +1.0f);
			glColor3f(0.0f, 1.0f, 0.0f);
			glVertex2f(-1.0f, -1.0f);
			glColor3f(0.0f, 0.0f, 1.0f);
			glVertex2f(+1.0f, -1.0f);
		}
		glEnd();
		//
		// カラーバッファを入れ替える
		glfwSwapBuffers(window);
		// イベントを取り出す
		glfwWaitEvents();
	}
}