#include <cstdlib>
#include <iostream>
#include <vector>
#include <GL/glew.h>
#include "function.h"


// �v���O�����I�u�W�F�N�g���쐬����
// vsrc: �o�[�e�b�N�X�V�F�[�_�̃\�[�X�v���O�����̕�����
// fsrc: �t���O�����g�V�F�[�_�̃\�[�X�v���O�����̕�����
GLuint createProgram(const char* vsrc, const char* fsrc)
{
	// ��̃v���O�����I�u�W�F�N�g���쐬����
	const GLuint program(glCreateProgram());

	if (vsrc != NULL)
	{
		// �o�[�e�b�N�X�V�F�[�_�̃V�F�[�_�I�u�W�F�N�g���쐬����
		const GLuint vobj(glCreateShader(GL_VERTEX_SHADER));
		glShaderSource(vobj, 1, &vsrc, NULL);
		glCompileShader(vobj);
		// �o�[�e�b�N�X�V�F�[�_�̃V�F�[�_�I�u�W�F�N�g���v���O�����I�u�W�F�N�g�ɑg�ݍ���
		if (printShaderInfoLog(vobj, "vertex shader"))
			glAttachShader(program, vobj);
		glDeleteShader(vobj);
	}

	if (fsrc != NULL)
	{
		// �t���O�����g�V�F�[�_�̃V�F�[�_�I�u�W�F�N�g���쐬����
		const GLuint fobj(glCreateShader(GL_FRAGMENT_SHADER));
		glShaderSource(fobj, 1, &fsrc, NULL);
		glCompileShader(fobj);
		// �t���O�����g�V�F�[�_�̃V�F�[�_�I�u�W�F�N�g���v���O�����I�u�W�F�N�g�ɑg�ݍ���
		if (printShaderInfoLog(fobj, "fragment shader"))
			glAttachShader(program, fobj);
		glDeleteShader(fobj);
	}

	// �v���O�����I�u�W�F�N�g�������N����
	glBindAttribLocation(program, 0, "position");
	glBindFragDataLocation(program, 0, "fragment");
	glLinkProgram(program);

	// �쐬�����v���O�����I�u�W�F�N�g��Ԃ�
	if (printProgramInfoLog(program))
		return program;

	// �v���O�����I�u�W�F�N�g���쐬�ł��Ȃ���� 0 ��Ԃ�
	glDeleteProgram(program);
	return 0;
}

// �V�F�[�_�I�u�W�F�N�g�̃R���p�C�����ʂ�\������
// shader: �V�F�[�_�I�u�W�F�N�g��
// str: �R���p�C���G���[�����������ꏊ������������
GLboolean printShaderInfoLog(GLuint shader, const char* str)
{
	// �R���p�C�����ʂ��擾����
	GLint status;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
	if (status == GL_FALSE) std::cerr << "Compile Error in " << str << std::endl;
	// �V�F�[�_�̃R���p�C�����̃��O�̒������擾����
	GLsizei bufSize;
	glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &bufSize);
	if (bufSize > 1)
	{
		// �V�F�[�_�̃R���p�C�����̃��O�̓��e���擾����
		std::vector<GLchar> infoLog(bufSize);
		GLsizei length;
		glGetShaderInfoLog(shader, bufSize, &length, &infoLog[0]);
		std::cerr << &infoLog[0] << std::endl;
	}
	return static_cast<GLboolean>(status);
}

// �v���O�����I�u�W�F�N�g�̃����N���ʂ�\������
// program: �v���O�����I�u�W�F�N�g��
GLboolean printProgramInfoLog(GLuint program)
{
	// �����N���ʂ��擾����
	GLint status;
	glGetProgramiv(program, GL_LINK_STATUS, &status);
	if (status == GL_FALSE) std::cerr << "Link Error." << std::endl;
	// �V�F�[�_�̃����N���̃��O�̒������擾����
	GLsizei bufSize;
	glGetProgramiv(program, GL_INFO_LOG_LENGTH, &bufSize);
	if (bufSize > 1)
	{
		// �V�F�[�_�̃����N���̃��O�̓��e���擾����
		std::vector<GLchar> infoLog(bufSize);
		GLsizei length;
		glGetProgramInfoLog(program, bufSize, &length, &infoLog[0]);
		std::cerr << &infoLog[0] << std::endl;
	}
	return static_cast<GLboolean>(status);
}