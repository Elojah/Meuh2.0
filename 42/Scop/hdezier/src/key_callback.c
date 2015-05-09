#include "scop.h"

void		key_callback(GLFWwindow *window, int key, int scancode
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
	if (key == GLFW_KEY_ESCAPE) {
		glfwSetWindowShouldClose(window, GL_TRUE);
	} else if (key == GLFW_KEY_A) {
		move_camera(win, LEFT);
	} else if (key == GLFW_KEY_D) {
		move_camera(win, RIGHT);
	} else if (key == GLFW_KEY_W) {
		move_camera(win, FORWARD);
	} else if (key == GLFW_KEY_S) {
		move_camera(win, BACK);
	} else if (key == GLFW_KEY_SPACE) {
		move_camera(win, UP);
	} else if (key == GLFW_KEY_C) {
		move_camera(win, DOWN);
	}
}
