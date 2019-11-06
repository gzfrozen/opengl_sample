#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "window.h"

Window::Window(int width, int height, const char* title)
	: window(glfwCreateWindow(width, height, title, NULL, NULL))
	, scale(100.f), location{ 0,0 }
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

	// ���̃C���X�^���X�� this �|�C���^���L�^���Ă���
	glfwSetWindowUserPointer(window, this);

	// �E�B���h�E�̃T�C�Y�ύX���ɌĂяo�������̓o�^
	glfwSetWindowSizeCallback(window, resize);

	// �J�����E�B���h�E�̏����ݒ�
	resize(window, width, height);
}

void Window::resize(GLFWwindow* const window, int width, int height)
{
	// �E�B���h�E�S�̂��r���[�|�[�g�ɐݒ肷��
	glViewport(0, 0, width, height);

	// ���̃C���X�^���X�� this �|�C���^�𓾂�
	Window* const
		instance(static_cast<Window*>(glfwGetWindowUserPointer(window)));
	if (instance != NULL)
	{
		// �J�����E�B���h�E�̃T�C�Y��ۑ�����
		instance->size[0] = static_cast<GLfloat>(width);
		instance->size[1] = static_cast<GLfloat>(height);
	}
}

void Window::swapBuffers()
{
	// �J���[�o�b�t�@�����ւ���
	glfwSwapBuffers(window);
	// �C�x���g�����o��
	glfwWaitEvents();
	// �}�E�X�J�[�\���̈ʒu���擾����
	double x, y;
	glfwGetCursorPos(window, &x, &y);
	// �}�E�X�J�[�\���̐��K���f�o�C�X���W�n��ł̈ʒu�����߂�
	location[0] = static_cast<GLfloat>(x) * 2.0f / size[0] - 1.0f;
	location[1] = 1.0f - static_cast<GLfloat>(y) * 2.0f / size[1];
}
