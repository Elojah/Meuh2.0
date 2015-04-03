#include "CocoaWin.hpp"
#include "Map.hpp"
#include <iostream>

CocoaWin::CocoaWin(void) {
}

CocoaWin::CocoaWin(std::size_t width, std::size_t height) :
															_width(width),
															_height(height)
{
	if (!glfwInit())
	    exit(EXIT_FAILURE);
}

CocoaWin::~CocoaWin(void) {
	glfwDestroyWindow(_window);
	glfwTerminate();
}

void		CocoaWin::init(void) {

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	_window = glfwCreateWindow(_width, _height, "mod1", NULL, NULL);
	glfwMakeContextCurrent(_window);
	glfwSwapInterval(1);
	// glClearColor(0, 0.5, 1, 1);
}

void		CocoaWin::loop(Map const &map, Camera &cam) {
	// static int		err;

	// glEnable(GL_DEPTH_TEST);
	// glDepthFunc(GL_LESS);
	// map.refresh(cam);
	(void)map;
	(void)cam;
	while (!glfwWindowShouldClose(_window)) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glfwSwapBuffers(_window);
        glfwPollEvents();//Needed, or you will get a spinning beach ball
		// glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// map.draw();
		// if ((err = glGetError()) == GL_NO_ERROR) {
		// 	std::cout << "Rendering ok" << std::endl;
		// } else {
		// 	std::cout << "Rendering error:\t" << err << std::endl;
		// }
	}
}
/*
GL_NO_ERROR
GL_INVALID_ENUM
GL_INVALID_VALUE
GL_INVALID_OPERATION
GL_INVALID_FRAMEBUFFER_OPERATION
GL_OUT_OF_MEMORY
GL_STACK_UNDERFLOW
GL_STACK_OVERFLOW
*/
