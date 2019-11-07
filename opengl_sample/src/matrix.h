#pragma once
#include <algorithm>
#include <GL/glew.h>

// �ϊ��s��
class Matrix
{
	// �ϊ��s��̗v�f
	GLfloat matrix[16];
public:
	// �R���X�g���N�^
	Matrix() {}

	// �z��̓��e�ŏ���������R���X�g���N�^
	// a: GLfloat �^�� 16 �v�f�̔z��
	Matrix(const GLfloat* a)
	{
		std::copy(a, a + 16, matrix);
	}

	// �ϊ��s��̔z���Ԃ�
	const GLfloat* data() const
	{
		return matrix;
	}

	// �P�ʍs���ݒ肷��
	void loadIdentity();

	// �P�ʍs����쐬����
	static Matrix identity();

	// (x, y, z) �������s�ړ�����ϊ��s����쐬����
	static Matrix translate(GLfloat x, GLfloat y, GLfloat z);

	// (x, y, z) �{�Ɋg��k������ϊ��s����쐬����
	static Matrix scale(GLfloat x, GLfloat y, GLfloat z);

	// b����a��������s��������f����ϊ��s����쐬����i0�͂����A1��y���A2��z�����Ӗ�����j
	static Matrix shear(GLfloat s, int a, int b);

	// (x, y, z) ������ a ��]����ϊ��s����쐬����
	static Matrix rotate(GLfloat a, GLfloat x, GLfloat y, GLfloat z);

	// ��Z
	Matrix operator*(const Matrix& m) const;
};