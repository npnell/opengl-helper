#ifndef INIT_H
#define INIT_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

class context {
private:
	GLFWwindow* glfw_initialize(int, int, const char*);
public:
	GLFWwindow* window;
	context(int, int, const char*);	
};

class viewport {
private:
	int glad_init(const context&, int, int);
public:
	viewport(const context&, int, int);
};

context::context(int window_width, int window_height, const char *window_title)
{
	this->window = glfw_initialize(window_width, window_height, window_title);
}

GLFWwindow* context::glfw_initialize(int window_width, int window_height, const char *window_title)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(window_width, window_height, window_title, NULL, NULL);
	if (!window) {
		std::cerr << "Failed to create GLFW window\n" << std::endl;
		glfwTerminate();
		return NULL;
	}
	glfwMakeContextCurrent(window);
	return window;
}

viewport::viewport(const context& context, int window_width, int window_height)
{
	glad_init(context, window_width, window_height);
}

void framebuffer_size_callback(GLFWwindow* window, int window_width, int window_height)
{
	glViewport(0, 0, window_width, window_height);
}

int viewport::glad_init(const context& context, int window_width, int window_height)
{
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cerr << "Failed to initialize GLAD" << std::endl;
		return EXIT_FAILURE;
	}
	glViewport(0, 0, window_width, window_height);
	glfwSetFramebufferSizeCallback(context.window, framebuffer_size_callback);
	return EXIT_SUCCESS;
}

void process_input(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

#endif // ! INIT_H
