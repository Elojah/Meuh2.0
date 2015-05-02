#include "arkanoid.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static void		init_buffers(t_window *w)
{
	int			i;
	int			n;

	i = -1;
	while (++i < WIDTH_MAP * HEIGHT_MAP)
	{
		w->display.vertex_buffer_data[i].x = (float)(i / WIDTH_MAP) / WIDTH_MAP;
		w->display.vertex_buffer_data[i].y = (float)(i % WIDTH_MAP) / HEIGHT_MAP;
	}
	i = -1;
	while (++i < (WIDTH_MAP - 1) * HEIGHT_MAP) {
		n = i * 6;
		w->display.index_buffer_data[n] = i;
		w->display.index_buffer_data[n + 1] = i + 1;
		w->display.index_buffer_data[n + 2] = i + WIDTH_MAP;
		w->display.index_buffer_data[n + 3] = i + WIDTH_MAP + 1;
		w->display.index_buffer_data[n + 4] = i + 1;
		w->display.index_buffer_data[n + 5] = i + WIDTH_MAP;
	}
}

static void		init_gl(t_window *w)
{
	init_buffers(w);
	glGenVertexArrays(1, &w->display.vertex_array_ID);
	glBindVertexArray(w->display.vertex_array_ID);
	w->display.prog_ID = load_shaders("./src/shaders/Grid.vert"
									, "./src/shaders/Grid.frag");
	glGenBuffers(1, &w->map_ID);
	glBindBuffer(GL_ARRAY_BUFFER, w->map_ID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(w->map), w->map, GL_STATIC_DRAW);
	glGenBuffers(1, &w->display.vertex_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, w->display.vertex_buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(w->display.vertex_buffer_data)
		, w->display.vertex_buffer_data, GL_STATIC_DRAW);
	glGenBuffers(1, &w->display.index_buffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, w->display.index_buffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(w->display.index_buffer_data)
		, w->display.index_buffer_data, GL_STATIC_DRAW);
}

static void		init_window(t_window *w)
{
	ft_exit(!glfwInit(), "init glfw");
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	w->window = glfwCreateWindow(WIDTH_MAP * 10, HEIGHT_MAP * 10, "--ARKANOID--"
		, NULL, NULL);
	glfwMakeContextCurrent(w->window);
	glfwSetWindowUserPointer(w->window, w);
	glfwSetInputMode(w->window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSwapInterval(1);
	glfwSetKeyCallback(w->window, key_callback);
	glClearColor(0, 0, 0, 0);
}

static void		destroy_window(t_window *w)
{
	glfwDestroyWindow(w->window);
	glfwTerminate();
	write(1, "Credits:\n\thdezier\n\tdrabahi\n@42SchoolProject\n", 44);
}

int			main(int ac, char **av)
{
	t_window	w;

	ft_exit(ac != 2, "Usage:\t./arkanoid [filename]");
	load_map(&w, av[1]);
	init_window(&w);
	init_gl(&w);
	loop(&w);
	destroy_window(&w);
	return (0);
}
