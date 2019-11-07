#pragma once
#include <algorithm>
#include <GL/glew.h>

// 変換行列
class Matrix
{
	// 変換行列の要素
	GLfloat matrix[16];
public:
	// コンストラクタ
	Matrix() {}

	// 配列の内容で初期化するコンストラクタ
	// a: GLfloat 型の 16 要素の配列
	Matrix(const GLfloat* a)
	{
		std::copy(a, a + 16, matrix);
	}

	// 変換行列の配列を返す
	const GLfloat* data() const
	{
		return matrix;
	}

	// 単位行列を設定する
	void loadIdentity();

	// 単位行列を作成する
	static Matrix identity();

	// (x, y, z) だけ平行移動する変換行列を作成する
	static Matrix translate(GLfloat x, GLfloat y, GLfloat z);

	// (x, y, z) 倍に拡大縮小する変換行列を作成する
	static Matrix scale(GLfloat x, GLfloat y, GLfloat z);

	// b軸をa軸方向にsだけせん断する変換行列を作成する（0はｘ軸、1はy軸、2はz軸を意味する）
	static Matrix shear(GLfloat s, int a, int b);

	// (x, y, z) を軸に a 回転する変換行列を作成する
	static Matrix rotate(GLfloat a, GLfloat x, GLfloat y, GLfloat z);

	// 乗算
	Matrix operator*(const Matrix& m) const;
};