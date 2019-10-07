#include <cstdlib>
#include <iostream>
#include <vector>
#include <memory>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "function.h"
#include "shape.h"

// ��`�̒��_�̈ʒu
constexpr Object::Vertex triangleVertex[] =
{
	{ 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f },
	{ -1.0f, -1.0f, 0.0f, 1.0f, 0.0f, 1.0f },
	{ 1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f }
};

int main()
{
	// GLFW ������������
	if (glfwInit() == GL_FALSE)
	{
		// �������Ɏ��s����
		std::cerr << "Can't initialize GLFW" << std::endl;
		return 1;
	}

	// �v���O�����I�����̏�����o�^����
	atexit(glfwTerminate);

	// OpenGL Version 3.2 Core Profile ��I������
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// �E�B���h�E���쐬����
	GLFWwindow* const window(glfwCreateWindow(640, 480, "Hello!", NULL, NULL));
	if (window == NULL)
	{
		// �E�B���h�E���쐬�ł��Ȃ�����
		std::cerr << "Can't create GLFW window." << std::endl;
		return 1;
	}

	// �쐬�����E�B���h�E�� OpenGL �̏����Ώۂɂ���
	glfwMakeContextCurrent(window);

	// GLEW ������������
	if (glewInit() != GLEW_OK)
	{
		// GLEW �̏������Ɏ��s����
		std::cerr << "Can't initialize GLEW" << std::endl;
		return 1;
	}

	// ���������̃^�C�~���O��҂�
	glfwSwapInterval(1);

	// �w�i�F���w�肷��
	//glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

	// �v���O�����I�u�W�F�N�g���쐬����
	const GLuint program(loadProgram("shaders/point.vert", "shaders/point.frag"));

	// �}�`�f�[�^���쐬����
	std::unique_ptr<const Shape> shape(new Shape(2, 3, triangleVertex));

	// �E�B���h�E���J���Ă���ԌJ��Ԃ�
	while (glfwWindowShouldClose(window) == GL_FALSE)
	{
		// �E�B���h�E����������
		glClear(GL_COLOR_BUFFER_BIT);

		// �V�F�[�_�v���O�����̎g�p�J�n
		glUseProgram(program);
		//
		// �����ŕ`�揈�����s��
		// �}�`��`�悷��
		shape->draw();
		//
		// �J���[�o�b�t�@�����ւ���
		glfwSwapBuffers(window);
		// �C�x���g�����o��
		glfwWaitEvents();
	}
}