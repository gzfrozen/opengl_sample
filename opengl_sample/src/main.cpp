#include <cstdlib>
#include <iostream>
#include <vector>
#include <memory>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "function.h"
#include "window.h"
#include "matrix.h"
#include "shape.h"

// 矩形の頂点の位置
constexpr Object::Vertex triangleVertex[] =
{
	{ 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f },
	{ -1.0f, -1.0f, 0.0f, 1.0f, 0.0f, 1.0f },
	{ 1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f }
};

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
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// ウィンドウを作成する
	Window window;

	// 背景色を指定する
	//glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

	// プログラムオブジェクトを作成する
	const GLuint program(loadProgram("shaders/point.vert", "shaders/point.frag"));

	// uniform 変数の場所を取得する
	const GLint modelLoc(glGetUniformLocation(program, "model"));

	// 図形データを作成する
	std::unique_ptr<const Shape> shape(new Shape(2, 3, triangleVertex));

	// ウィンドウが開いている間繰り返す
	while (window.shouldClose() == GL_FALSE)
	{
		// ウィンドウを消去する
		glClear(GL_COLOR_BUFFER_BIT);

		// シェーダプログラムの使用開始
		glUseProgram(program);

		// 拡大縮小の変換行列を求める
		const GLfloat* const size(window.getSize());
		const GLfloat scale(window.getScale() * 2.0f);
		const Matrix scaling(Matrix::scale(scale / size[0], scale / size[1], 1.0f));

		// 平行移動の変換行列を求める
		const GLfloat* const position(window.getLocation());
		const Matrix translation(Matrix::translate(position[0], position[1], 0.0f));

		// モデル変換行列を求める
		const Matrix model(translation * scaling);

		// uniform 変数に値を設定する
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, model.data());

		//

		// ここで描画処理を行う
		// 図形を描画する
		shape->draw();
		//

		// カラーバッファを入れ替えてイベントを取り出す
		window.swapBuffers();
	}
}