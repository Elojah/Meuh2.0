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
	glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSwapInterval(1);
	glfwSetKeyCallback(_window, key_callback);
	glfwSetCursorPosCallback(_window, cursor_position_callback);
	glClearColor(0, 0, 0, 0);
}

void		CocoaWin::loop(Map const &map, Camera &cam) {
	double	t;
	double	prev_t;

	_map = &map;
	_cam = &cam;
	_cam->setSize(_width, _height);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	_map->refresh(*_cam);
	while (!glfwWindowShouldClose(_window)) {
		if ((t = glfwGetTime()) < prev_t + 0.016) {
			continue ;
		}
		prev_t = t;
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		_map->draw();
		glfwSwapBuffers(_window);
        glfwPollEvents();//Needed, or you will get a spinning beach ball
		_map->refresh(*_cam);
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
	static CocoaWin		*win = reinterpret_cast<CocoaWin *>(glfwGetWindowUserPointer(window));
	static bool			keyValid;

	(void)scancode;
	(void)mods;

	keyValid = (action == GLFW_PRESS || action == GLFW_REPEAT);
	if (!keyValid) {
		return ;
	}
	if (key == GLFW_KEY_UP || key == GLFW_KEY_W) {
		win->getCam()->moveForward();
	} else if (key == GLFW_KEY_DOWN || key == GLFW_KEY_S) {
		win->getCam()->moveBackward();
	} else if (key == GLFW_KEY_RIGHT || key == GLFW_KEY_D) {
		win->getCam()->strafeRight();
	} else if (key == GLFW_KEY_LEFT || key == GLFW_KEY_A) {
		win->getCam()->strafeLeft();
	} else if (key == GLFW_KEY_SPACE) {
		win->getCam()->moveUp();
	} else if (key == GLFW_KEY_C) {
		win->getCam()->moveDown();
	} else if (key == GLFW_KEY_ESCAPE || key == GLFW_KEY_Q) {
		glfwSetWindowShouldClose(window, GL_TRUE);
	} else {
		win->_map->loop(key);
	}
}

void		CocoaWin::cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
	static CocoaWin		*win = static_cast<CocoaWin *>(glfwGetWindowUserPointer(window));

	win->getCam()->moveEye(xpos, ypos);
}
