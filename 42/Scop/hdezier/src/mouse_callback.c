#include "scop.h"
#include <math.h>

#include <stdio.h>
void		mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	static t_window		*win = 0x0;
	static double		prev_x = W_WIDTH / 2;
	static double		prev_y = W_HEIGHT / 2;

	if (!win)
		win = (t_window *)glfwGetWindowUserPointer(window);
	printf("win->cam.eye.x:\t%f\tprev_x:\t%f\txpos:\t%f\t\n", win->cam.eye.x, prev_x, xpos);
	win->cam.eye.x += (prev_x - xpos) * MOUSE_SPEED;
	win->cam.eye.y += (prev_y - ypos) * MOUSE_SPEED;
	prev_x = xpos;
	prev_y = ypos;
	refresh(win);
}
