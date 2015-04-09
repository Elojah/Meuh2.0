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
	glfwSetCursorPosCallback(_window, cursor_position_callback);
	glClearColor(0, 0.5, 1, 1);
}

void		CocoaWin::loop(Map const &map, Camera &cam) {

	_map = &map;
	_cam = &cam;
	_cam->setSize(_width, _height);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	_map->refresh(*_cam);
	while (!glfwWindowShouldClose(_window)) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		_map->draw();
		glfwSwapBuffers(_window);
        glfwWaitEvents();//Needed, or you will get a spinning beach ball
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
	static CocoaWin		*win = static_cast<CocoaWin *>(glfwGetWindowUserPointer(window));

	(void)scancode;
	(void)mods;

	if (key == GLFW_KEY_UP && action == GLFW_PRESS) {
		win->getCam()->moveForward();
	} else if (key == GLFW_KEY_DOWN && action == GLFW_PRESS) {
		win->getCam()->moveBackward();
	} else if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS) {
		win->getCam()->strafeRight();
	} else if (key == GLFW_KEY_LEFT && action == GLFW_PRESS) {
		win->getCam()->strafeLeft();
	} else if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
}

void		CocoaWin::cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
	static CocoaWin		*win = static_cast<CocoaWin *>(glfwGetWindowUserPointer(window));

	win->getCam()->moveEye(xpos, ypos);
}
