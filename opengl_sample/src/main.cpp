#include <cstdlib>
#include <iostream>
#include <vector>
#include <memory>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "function.h"
#include "window.h"
#include "matrix.h"
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

	// uniform �ϐ��̏ꏊ���擾����
	const GLint modelLoc(glGetUniformLocation(program, "model"));

	// �}�`�f�[�^���쐬����
	std::unique_ptr<const Shape> shape(new Shape(2, 3, triangleVertex));

	// �E�B���h�E���J���Ă���ԌJ��Ԃ�
	while (window.shouldClose() == GL_FALSE)
	{
		// �E�B���h�E����������
		glClear(GL_COLOR_BUFFER_BIT);

		// �V�F�[�_�v���O�����̎g�p�J�n
		glUseProgram(program);

		// �g��k���̕ϊ��s������߂�
		const GLfloat* const size(window.getSize());
		const GLfloat scale(window.getScale() * 2.0f);
		const Matrix scaling(Matrix::scale(scale / size[0], scale / size[1], 1.0f));

		// ���s�ړ��̕ϊ��s������߂�
		const GLfloat* const position(window.getLocation());
		const Matrix translation(Matrix::translate(position[0], position[1], 0.0f));

		// ���f���ϊ��s������߂�
		const Matrix model(translation * scaling);

		// uniform �ϐ��ɒl��ݒ肷��
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, model.data());

		//

		// �����ŕ`�揈�����s��
		// �}�`��`�悷��
		shape->draw();
		//

		// �J���[�o�b�t�@�����ւ��ăC�x���g�����o��
		window.swapBuffers();
	}
}