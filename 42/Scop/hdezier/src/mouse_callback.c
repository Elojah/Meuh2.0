#include "scop.h"
#include <math.h>

static void	set_fps_view(t_camera *cam
	, const float angle_x, const float angle_y)
{
	cam->center.x = sin(angle_x) * cos(angle_y) + cam->eye.x;
	cam->center.y = sin(angle_y) + cam->eye.y;
	cam->center.z = cos(angle_x) * cos(angle_y) + cam->eye.z;
	cam->up.x = cos(angle_y - M_PI / 2.0f);
	cam->up.y = sin(angle_y - M_PI / 2.0f);
	cam->up.z = 0.0f;
}

void		mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	static t_window		*win = 0x0;
	static float		prev_x = W_WIDTH / 2;
	static float		prev_y = W_HEIGHT / 2;
	static float		angle_x = 0;
	static float		angle_y = 0;

	if (!win)
		win = (t_window *)glfwGetWindowUserPointer(window);
	angle_x += MOUSE_SPEED * (prev_x - xpos);
	angle_y += MOUSE_SPEED * (prev_y - ypos);
	prev_x = xpos;
	prev_y = ypos;
	set_fps_view(&(win->cam), angle_x, angle_y);
	refresh(win);
}
