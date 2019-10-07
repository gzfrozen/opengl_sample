#pragma once
#include <GL/glew.h>
GLuint createProgram(const char* vsrc, const char* fsrc);
/*
�v���O�����I�u�W�F�N�g���쐬����
vsrc: �o�[�e�b�N�X�V�F�[�_�̃\�[�X�v���O�����̕�����
fsrc: �t���O�����g�V�F�[�_�̃\�[�X�v���O�����̕�����
*/

bool readShaderSource(const char* name, std::vector<GLchar>& buffer);
/*
�V�F�[�_�̃\�[�X�t�@�C����ǂݍ��񂾃�������Ԃ�
name: �V�F�[�_�̃\�[�X�t�@�C����
buffer: �ǂݍ��񂾃\�[�X�t�@�C���̃e�L�X�g
*/

GLuint loadProgram(const char* vert, const char* frag);
/*
�V�F�[�_�̃\�[�X�t�@�C����ǂݍ���Ńv���O�����I�u�W�F�N�g���쐬����
vert: �o�[�e�b�N�X�V�F�[�_�̃\�[�X�t�@�C����
frag: �t���O�����g�V�F�[�_�̃\�[�X�t�@�C����
*/

GLboolean printShaderInfoLog(GLuint shader, const char* str);
/*
�V�F�[�_�I�u�W�F�N�g�̃R���p�C�����ʂ�\������
shader: �V�F�[�_�I�u�W�F�N�g��
str: �R���p�C���G���[�����������ꏊ������������
*/

GLboolean printProgramInfoLog(GLuint program);
/*
�v���O�����I�u�W�F�N�g�̃����N���ʂ�\������
program: �v���O�����I�u�W�F�N�g��
*/