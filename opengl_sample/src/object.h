#pragma once
#include <GL/glew.h>

// �}�`�f�[�^
class Object
{
	// ���_�z��I�u�W�F�N�g��
	GLuint vao;
	// ���_�o�b�t�@�I�u�W�F�N�g��
	GLuint vbo;

public:
	// ���_����
	struct Vertex
	{
		// �ʒu
		GLfloat position[2];
		GLfloat color[4];
	};

	// �R���X�g���N�^
	// size: ���_�̈ʒu�̎���
	// vertexcount: ���_�̐�
	// vertex: ���_�������i�[�����z��
	Object(GLint size, GLsizei vertexcount, const Vertex* vertex)
	{
		// ���_�z��I�u�W�F�N�g
		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);
		// ���_�o�b�t�@�I�u�W�F�N�g
		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER,
			vertexcount * sizeof(Vertex), vertex, GL_STATIC_DRAW);
		// ��������Ă��钸�_�o�b�t�@�I�u�W�F�N�g�� in �ϐ�����Q�Ƃł���悤�ɂ���
		glVertexAttribPointer(0, size, GL_FLOAT, GL_FALSE, sizeof(Vertex), static_cast<Vertex*>(0)->position);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), static_cast<Vertex*>(0)->color);
		glEnableVertexAttribArray(1);
	}

	// �f�X�g���N�^
	virtual ~Object()
	{
		// ���_�z��I�u�W�F�N�g���폜����
		glDeleteBuffers(1, &vao);
		// ���_�o�b�t�@�I�u�W�F�N�g���폜����
		glDeleteBuffers(1, &vbo);
	}

	// ���_�z��I�u�W�F�N�g�̌���
	void bind() const
	{
		// �`�悷�钸�_�z��I�u�W�F�N�g���w�肷��
		glBindVertexArray(vao);
	}

private:
	// �R�s�[�R���X�g���N�^�ɂ��R�s�[�֎~
	Object(const Object& o);
	// ����ɂ��R�s�[�֎~
	Object& operator = (const Object& o);
};