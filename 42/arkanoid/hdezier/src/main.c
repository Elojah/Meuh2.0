#include "arkanoid.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static void		init_window(t_window *w)
{
	ft_exit(!glfwInit(), "init glfw");
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	w->window = glfwCreateWindow(WIDTH * 10, HEIGHT * 10, "--ARKANOID--", NULL, NULL);
	glfwMakeContextCurrent(w->window);
	glfwSetWindowUserPointer(w->window, w);
	glfwSetInputMode(w->window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSwapInterval(1);
	glfwSetKeyCallback(w->window, key_callback);
	// glfwSetCursorPosCallback(w->window, cursor_position_callback);
	glClearColor(0, 0, 0, 0);
}

static void		destroy_window(t_window *w)
{
	glfwDestroyWindow(w->window);
	glfwTerminate();
	write(1, "Credits:\n\thdezier\n\tdrabahi\n@42SchoolProject\n", 44);
}

int			main(void)
{
	t_window	w;

	init_window(&w);
	loop(&w);
	destroy_window(&w);
	return (0);
}
