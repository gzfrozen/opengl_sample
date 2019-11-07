#include <algorithm>
#include <GL/glew.h>
#include "matrix.h"

// 単位行列を設定する
void Matrix::loadIdentity()
{
	std::fill(matrix, matrix + 16, 0.0f);
	matrix[0] = matrix[5] = matrix[10] = matrix[15] = 1.0f;
}

// 単位行列を作成する
Matrix Matrix::identity()
{
	Matrix t;
	t.loadIdentity();
	return t;
}

// (x, y, z) だけ平行移動する変換行列を作成する
Matrix Matrix::translate(GLfloat x, GLfloat y, GLfloat z)
{
	Matrix t;
	t.loadIdentity();
	t.matrix[12] = x;
	t.matrix[13] = y;
	t.matrix[14] = z;
	return t;
}

// (x, y, z) 倍に拡大縮小する変換行列を作成する
Matrix Matrix::scale(GLfloat x, GLfloat y, GLfloat z)
{
	Matrix t;
	t.loadIdentity();
	t.matrix[0] = x;
	t.matrix[5] = y;
	t.matrix[10] = z;
	return t;
}

// b軸をa軸方向にsだけせん断する変換行列を作成する（0はｘ軸、1はy軸、2はz軸を意味する）
Matrix Matrix::shear(GLfloat s, int a, int b)
{
	Matrix t;
	t.loadIdentity();
	if (a == 0) {
		if (b == 1) {
			t.matrix[4] = s;
		}
		else {
			t.matrix[8] = s;
		}
	}
	else if (a == 1) {
		if (b == 0) {
			t.matrix[1] = s;
		}
		else {
			t.matrix[9] = s;
		}
	}
	else {
		if (b == 0) {
			t.matrix[2] = s;
		}
		else {
			t.matrix[6] = s;
		}
	}
	return t;
}

// (x, y, z) を軸に a 回転する変換行列を作成する
Matrix Matrix::rotate(GLfloat a, GLfloat x, GLfloat y, GLfloat z)
{
	Matrix t;
	const GLfloat d(sqrt(x * x + y * y + z * z));
	if (d > 0.0f)
	{
		const GLfloat l(x / d), m(y / d), n(z / d);
		const GLfloat l2(l * l), m2(m * m), n2(n * n);
		const GLfloat lm(l * m), mn(m * n), nl(n * l);
		const GLfloat c(cos(a)), c1(1.0f - c), s(sin(a));
		t.loadIdentity();
		t.matrix[0] = (1.0f - l2) * c + l2;
		t.matrix[1] = lm * c1 + n * s;
		t.matrix[2] = nl * c1 - m * s;
		t.matrix[4] = lm * c1 - n * s;
		t.matrix[5] = (1.0f - m2) * c + m2;
		t.matrix[6] = mn * c1 + l * s;
		t.matrix[8] = nl * c1 + m * s;
		t.matrix[9] = mn * c1 - l * s;
		t.matrix[10] = (1.0f - n2) * c + n2;
	}
	return t;
}

// 乗算
Matrix Matrix::operator*(const Matrix& m) const
{
	Matrix t;
	for (int i = 0; i < 16; ++i)
	{
		const int j(i & 3), k(i & ~3);
		t.matrix[i] =
			matrix[0 + j] * m.matrix[k + 0] +
			matrix[4 + j] * m.matrix[k + 1] +
			matrix[8 + j] * m.matrix[k + 2] +
			matrix[12 + j] * m.matrix[k + 3];
	}
	return t;
}