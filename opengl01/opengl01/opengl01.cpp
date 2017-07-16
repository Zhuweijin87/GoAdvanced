// opengl01.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>


using namespace std;

/* ����GLFW�������� */

int main()
{
	glfwInit();

	/* ������Ϣ��ʼ�� */
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); /* �汾�� 3.x */
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); /* �汾�� x.3 */
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	/* �������� */
	GLFWwindow *window = glfwCreateWindow(800, 600, "MyOpenGL01", nullptr, nullptr);
	if (window == nullptr)
	{
		cout << "Create Window Fail\n";
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		cout << "fail to init glew\n";
		return -1;
	}

	/* �ӽ� */
	int width, heigth;
	glfwGetFramebufferSize(window, &width, &heigth);
	glViewport(0, 0, width, heigth);

	/* �����¼����� */
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents(); /* �����û�д���ʲô�¼�������������롢����ƶ��ȣ� */

		glClearColor(0.3f, 0.5f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT); /* GL_COLOR_BUFFER_BIT��GL_DEPTH_BUFFER_BIT��GL_STENCIL_BUFFER_BIT */

		glfwSwapBuffers(window); /* ������ɫ���� */
	}

	glfwTerminate();

	return 0;
}

