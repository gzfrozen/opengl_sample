#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "window.h"

Window::Window(int width, int height, const char* title)
	: window(glfwCreateWindow(width, height, title, NULL, NULL))
{
	if (window == NULL)
	{
		// �E�B���h�E���쐬�ł��Ȃ�����
		std::cerr << "Can't create GLFW window." << std::endl;
		exit(1);
	}
	// ���݂̃E�B���h�E�������Ώۂɂ���
	glfwMakeContextCurrent(window);
	// GLEW ������������
	if (glewInit() != GLEW_OK)
	{
		// GLEW �̏������Ɏ��s����
		std::cerr << "Can't initialize GLEW" << std::endl;
		exit(1);
	}
	// ���������̃^�C�~���O��҂�
	glfwSwapInterval(1);

	// �E�B���h�E�̃T�C�Y�ύX���ɌĂяo�������̓o�^
	glfwSetWindowSizeCallback(window, resize);

	// �J�����E�B���h�E�̏����ݒ�
	resize(window, width, height);
}
