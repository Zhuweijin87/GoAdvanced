// opengl01.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>


using namespace std;

/* 利用GLFW创建窗口 */

int main()
{
	glfwInit();

	/* 窗口信息初始化 */
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); /* 版本号 3.x */
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); /* 版本号 x.3 */
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	/* 创建窗口 */
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

	/* 视角 */
	int width, heigth;
	glfwGetFramebufferSize(window, &width, &heigth);
	glViewport(0, 0, width, heigth);

	/* 窗口事件监视 */
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents(); /* 检查有没有触发什么事件（比如键盘输入、鼠标移动等） */

		glClearColor(0.3f, 0.5f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT); /* GL_COLOR_BUFFER_BIT，GL_DEPTH_BUFFER_BIT和GL_STENCIL_BUFFER_BIT */

		glfwSwapBuffers(window); /* 交换颜色缓冲 */
	}

	glfwTerminate();

	return 0;
}

