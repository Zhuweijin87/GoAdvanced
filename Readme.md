# OpenGL

# 1. 开发环境
	VS2015 + GLFW + GLEW

参考学习:
	https://learnopengl-cn.github.io/

# 2. github
	关于Visual Studio 2015 配置github:
	1. 工具/拓展与更新，搜索guthub第一个就可以安装
	2. 安装好之后重启，调出 视图/团队资源管理器

# 3. 问题
	1. 使用GLAD, 编译时报错
		错误信息：预编译头文件来自编译器的早期版本，或者预编译头为 C++ 而在 C 中使用它(或相反)
		解决： 右击项目->属性->配置属性->C/C++->预编译头-> 预编译头：选择 “不使用预编译头”
		