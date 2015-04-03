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
	std::cout << "Credits:" << std::endl
	<< "\terobert" << std::endl
	<< "\thdezier" << std::endl
	<< "@42SchoolProject" << std::endl;
}

const Map	*CocoaWin::getMap(void) const {
	return (_map);
}
Camera		*CocoaWin::getCam(void) const {
	return (_cam);
}

void		CocoaWin::init(void) {

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	_window = glfwCreateWindow(_width, _height, "mod1", NULL, NULL);
	glfwMakeContextCurrent(_window);
	glfwSetWindowUserPointer(_window, this);
	glfwSwapInterval(1);
	glfwSetKeyCallback(_window, key_callback);
	glClearColor(0, 0.5, 1, 1);
}

void		CocoaWin::loop(Map const &map, Camera &cam) {

	_map = &map;
	_cam = &cam;
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	_map->refresh(*_cam);
	while (!glfwWindowShouldClose(_window)) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		_map->draw();
		glfwSwapBuffers(_window);
        glfwWaitEvents();//Needed, or you will get a spinning beach ball
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
void		CocoaWin::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	static CocoaWin		*win = static_cast<CocoaWin *>(glfwGetWindowUserPointer(window));

	(void)scancode;
	(void)mods;
	if (key == GLFW_KEY_E && action == GLFW_PRESS) {
		win->getCam()->rotate(LEFT);
		(win->getMap())->refresh(*(win->getCam()));
	} else if (key == GLFW_KEY_Q && action == GLFW_PRESS) {
		win->getCam()->rotate(RIGHT);
		(win->getMap())->refresh(*(win->getCam()));
	} else if (key == GLFW_KEY_Z && action == GLFW_PRESS) {
		win->getCam()->translate(UP);
		(win->getMap())->refresh(*(win->getCam()));
	} else if (key == GLFW_KEY_S && action == GLFW_PRESS) {
		win->getCam()->translate(DOWN);
		(win->getMap())->refresh(*(win->getCam()));
	} else if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
		// if (_e.xkey.keycode == 26) {/*A*/
		// } else if (_e.xkey.keycode == 24) {/*E*/
		// 	cam.rotate(RIGHT);
		// 	map.refresh(cam);
		// } else if (_e.xkey.keycode == 25) {/*Z*/
		// 	cam.translate(UP);
		// 	map.refresh(cam);
		// } else if (_e.xkey.keycode == 39) {/*S*/
		// 	cam.translate(DOWN);
		// 	map.refresh(cam);
		// }
		// else if (_e.xkey.keycode == 9) {/*ESC*/
		// 	break ;
		// }
}
