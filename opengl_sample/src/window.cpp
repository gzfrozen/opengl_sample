#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "window.h"

Window::Window(int width, int height, const char* title)
	: window(glfwCreateWindow(width, height, title, NULL, NULL))
	, scale(100.f), location{ 0,0 }, keyStatus(GLFW_RELEASE)
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

	// �}�E�X�z�C�[�����쎞�ɌĂяo�������̓o�^
	glfwSetScrollCallback(window, wheel);

	// �L�[�{�[�h���쎞�ɌĂяo�������̓o�^
	glfwSetKeyCallback(window, keyboard);

	// �J�����E�B���h�E�̏����ݒ�
	resize(window, width, height);
}

void Window::swapBuffers()
{
	// �J���[�o�b�t�@�����ւ���
	glfwSwapBuffers(window);

	// �C�x���g�����o��
	if (keyStatus == GLFW_RELEASE)
		glfwWaitEvents();
	else
		glfwPollEvents();

	// �L�[�{�[�h�̏�Ԃ𒲂ׂ�
	if (glfwGetKey(window, GLFW_KEY_LEFT) != GLFW_RELEASE)
		location[0] -= 2.0f / size[0];
	else if (glfwGetKey(window, GLFW_KEY_RIGHT) != GLFW_RELEASE)
		location[0] += 2.0f / size[0];
	if (glfwGetKey(window, GLFW_KEY_DOWN) != GLFW_RELEASE)
		location[1] -= 2.0f / size[1];
	else if (glfwGetKey(window, GLFW_KEY_UP) != GLFW_RELEASE)
		location[1] += 2.0f / size[1];

	// �}�E�X�̍��{�^���̏�Ԃ𒲂ׂ�
	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_1) != GLFW_RELEASE) {
		// �}�E�X�̍��{�^����������Ă�����}�E�X�J�[�\���̈ʒu���擾����
		double x, y;
		glfwGetCursorPos(window, &x, &y);
		// �}�E�X�J�[�\���̐��K���f�o�C�X���W�n��ł̈ʒu�����߂�
		location[0] = static_cast<GLfloat>(x) * 2.0f / size[0] - 1.0f;
		location[1] = 1.0f - static_cast<GLfloat>(y) * 2.0f / size[1];
	}
}

void Window::resize(GLFWwindow* const window, int width, int height)
{
	// �E�B���h�E�S�̂��r���[�|�[�g�ɐݒ肷��
	glViewport(0, 0, width, height);

	// ���̃C���X�^���X�� this �|�C���^�𓾂�
	Window* const instance(static_cast<Window*>(glfwGetWindowUserPointer(window)));
	if (instance != NULL)
	{
		// �J�����E�B���h�E�̃T�C�Y��ۑ�����
		instance->size[0] = static_cast<GLfloat>(width);
		instance->size[1] = static_cast<GLfloat>(height);
	}
}

void Window::wheel(GLFWwindow* window, double x, double y)
{
	// ���̃C���X�^���X�� this �|�C���^�𓾂�
	Window* const instance(static_cast<Window*>(glfwGetWindowUserPointer(window)));
	if (instance != NULL)
	{
		// ���[���h���W�n�ɑ΂���f�o�C�X���W�n�̊g�嗦���X�V����
		instance->scale += static_cast<GLfloat>(y) * 2.0f;
	}
}

void Window::keyboard(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	// ���̃C���X�^���X�� this �|�C���^�𓾂�
	Window* const instance(static_cast<Window*>(glfwGetWindowUserPointer(window)));
	if (instance != NULL)
	{
		// �L�[�̏�Ԃ�ۑ�����
		instance->keyStatus = action;
	}
}