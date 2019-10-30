#include <cstdlib>
#include <iostream>
#include <vector>
#include <memory>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "function.h"
#include "window.h"
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
	Window window;

	// �w�i�F���w�肷��
	//glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

	// �v���O�����I�u�W�F�N�g���쐬����
	const GLuint program(loadProgram("shaders/point.vert", "shaders/point.frag"));

	// �}�`�f�[�^���쐬����
	std::unique_ptr<const Shape> shape(new Shape(2, 3, triangleVertex));

	// �E�B���h�E���J���Ă���ԌJ��Ԃ�
	while (window.shouldClose() == GL_FALSE)
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

		// �J���[�o�b�t�@�����ւ��ăC�x���g�����o��
		window.swapBuffers();
	}
}