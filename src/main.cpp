#include <init.h>

static const int WINDOW_WIDTH{ 800 },
				 WINDOW_HEIGHT{ 600 };
static const char* WINDOW_TITLE = "testwindow";

int initialize(void)
{
	// Creating a context object initializes GLFW and instantiates a window
	context context(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	// Creating viewport object initializes GLAD and configures the OpenGL viewport
	viewport viewport(context, WINDOW_WIDTH, WINDOW_HEIGHT);

	while (!glfwWindowShouldClose(context.window)) {
		// Render Loop
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		process_input(context.window);

		glfwSwapBuffers(context.window);
		glfwPollEvents();
	}
	glfwTerminate();
	return EXIT_SUCCESS;
}

int main(int argc, char* argv[])
{
	initialize();
}