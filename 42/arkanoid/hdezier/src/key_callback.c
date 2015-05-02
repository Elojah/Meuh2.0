#include "arkanoid.h"

void		key_callback(GLFWwindow* window, int key, int scancode
	, int action, int mods)
{
	static t_window		*win = 0x0;
	static int			keyValid;

	if (!win)
		win = (t_window *)glfwGetWindowUserPointer(window);
	(void)scancode;
	(void)mods;
	keyValid = (action == GLFW_PRESS || action == GLFW_REPEAT);
	if (!keyValid) {
		return ;
	}
	if (key == GLFW_KEY_UP || key == GLFW_KEY_W) {
	} else if (key == GLFW_KEY_DOWN || key == GLFW_KEY_S) {
	} else if (key == GLFW_KEY_RIGHT || key == GLFW_KEY_D) {
	} else if (key == GLFW_KEY_LEFT || key == GLFW_KEY_A) {
	} else if (key == GLFW_KEY_SPACE) {
	} else if (key == GLFW_KEY_C) {
	} else if (key == GLFW_KEY_ESCAPE || key == GLFW_KEY_Q) {
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
}
