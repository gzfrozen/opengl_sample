#pragma once
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

// �E�B���h�E�֘A�̏���
class Window
{
	// �E�B���h�E�̃n���h��
	GLFWwindow* const window;

	// �E�B���h�E�̃T�C�Y
	GLfloat size[2];

	// ���[���h���W�n�ɑ΂���f�o�C�X���W�n�̊g�嗦
	GLfloat scale;

	// �}�`�̐��K���f�o�C�X���W�n��ł̈ʒu
	GLfloat location[2];

	// �L�[�{�[�h�̏��
	int keyStatus;

public:
	// �R���X�g���N�^
	Window(int width = 640, int height = 480, const char* title = "Hello!");

	// �f�X�g���N�^
	virtual ~Window()
	{
		glfwDestroyWindow(window);
	}

	// �E�B���h�E�����ׂ����𔻒肷��
	int shouldClose() const
	{
		return glfwWindowShouldClose(window) || glfwGetKey(window, GLFW_KEY_ESCAPE);
	}

	// �J���[�o�b�t�@�����ւ��ăC�x���g�����o��
	void swapBuffers();

	// �E�B���h�E�̃T�C�Y�����o��
	const GLfloat* getSize() const { return size; }

	// ���[���h���W�n�ɑ΂���f�o�C�X���W�n�̊g�嗦�����o��
	GLfloat getScale() const { return scale; }

	// �ʒu�����o��
	const GLfloat* getLocation() const { return location; }

	// �E�B���h�E�̃T�C�Y�ύX���̏���
	static void resize(GLFWwindow* const window, int width, int height);

	// �}�E�X�z�C�[�����쎞�̏���
	static void wheel(GLFWwindow* window, double x, double y);

	// �L�[�{�[�h���쎞�̏���
	static void keyboard(GLFWwindow* window, int key, int scancode, int action, int mods);
};