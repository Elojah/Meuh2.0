#include "scop.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static void		init_gl(t_window *w)
{
	glGenVertexArrays(2, &w->obj.vertex_array_id);
	glBindVertexArray(w->obj.vertex_array_id);
	w->obj.prog_id = load_shaders("./src/shaders/Obj.vert"
									, "./src/shaders/Obj.frag");
	glGenBuffers(1, &w->obj.vertex_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, w->obj.vertex_buffer);
	glBufferData(GL_ARRAY_BUFFER, w->obj.vertex_buffer_size
		, w->obj.vertex_buffer_data, GL_STATIC_DRAW);
	glGenBuffers(1, &w->obj.index_buffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, w->obj.index_buffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, w->obj.index_buffer_size
		, w->obj.index_buffer_data, GL_STATIC_DRAW);
}

static void		destroy_obj(t_object *obj)
{
	glDeleteProgram(obj->prog_id);
	glDeleteBuffers(1, &obj->vertex_buffer);
	glDeleteBuffers(1, &obj->index_buffer);
	ft_memdel((void **)&obj->vertex_buffer_data);
	ft_memdel((void **)&obj->index_buffer_data);
	glDeleteVertexArrays(1, &obj->vertex_array_id);
}

static void		init_window(t_window *w)
{
	ft_exit(!glfwInit(), "init glfw");
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	w->window = glfwCreateWindow(W_WIDTH, W_HEIGHT, "--SC0P--", NULL, NULL);
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

	ft_exit(ac != 2, "Usage:\t./scop [filename]");
	load_obj(&w.obj, av[1]);
	init_window(&w);
	init_gl(&w);
	loop(&w);
	destroy_obj(&w.obj);
	destroy_window(&w);
	return (0);
}
