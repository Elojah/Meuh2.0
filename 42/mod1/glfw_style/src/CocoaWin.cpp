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
	glfwTerminate();
}

void		CocoaWin::init(void) {

	_window = glfwCreateWindow(_width, _height, "mod1", NULL, NULL);

	// glClearColor(0, 0.5, 1, 1);
}

void		CocoaWin::loop(Map const &map, Camera &cam) {
	// static int		err;

	// glEnable(GL_DEPTH_TEST);
	// glDepthFunc(GL_LESS);
	// map.refresh(cam);
	(void)map;
	(void)cam;
	while (true) {

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
