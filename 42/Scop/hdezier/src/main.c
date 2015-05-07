#include "scop.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static void		init_gl(t_window *w)
{
	glGenVertexArrays(6, &w->obj.vertex_array_id);
	glBindVertexArray(w->obj.vertex_array_id);
	w->obj.prog_id = load_shaders("./src/shaders/Obj.vert"
									, "./src/shaders/Obj.frag");
	glGenBuffers(1, &w->obj.vertex_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, w->obj.vertex_buffer);
	glBufferData(GL_ARRAY_BUFFER, w->obj.vertex_buffer_size
		, w->obj.vertex_buffer_data, GL_STATIC_DRAW);
	glGenBuffers(1, &w->obj.normal_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, w->obj.normal_buffer);
	glBufferData(GL_ARRAY_BUFFER, w->obj.normal_buffer_size
		, w->obj.normal_buffer_data, GL_STATIC_DRAW);
	glGenBuffers(1, &w->obj.tex_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, w->obj.tex_buffer);
	glBufferData(GL_ARRAY_BUFFER, w->obj.tex_buffer_size
		, w->obj.tex_buffer_data, GL_STATIC_DRAW);
	glGenBuffers(1, &w->obj.ve_index_buffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, w->obj.ve_index_buffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, w->obj.index_buffer_size * 3
		, w->obj.ve_index_buffer_data, GL_STATIC_DRAW);
	glGenBuffers(1, &w->obj.no_index_buffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, w->obj.no_index_buffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, w->obj.index_buffer_size * 3
		, w->obj.no_index_buffer_data, GL_STATIC_DRAW);
	glGenBuffers(1, &w->obj.te_index_buffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, w->obj.te_index_buffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, w->obj.index_buffer_size * 3
		, w->obj.te_index_buffer_data, GL_STATIC_DRAW);
}

static void		destroy_obj(t_object *obj)
{
	glDeleteProgram(obj->prog_id);
	glDeleteBuffers(1, &obj->vertex_buffer);
	glDeleteBuffers(1, &obj->normal_buffer);
	glDeleteBuffers(1, &obj->tex_buffer);
	glDeleteBuffers(1, &obj->ve_index_buffer);
	glDeleteBuffers(1, &obj->no_index_buffer);
	glDeleteBuffers(1, &obj->te_index_buffer);
	glDeleteVertexArrays(6, &obj->vertex_array_id);
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
	write(1, "Credits:\n\thdezier\n@42SchoolProject\n", 35);
}

int			main(int ac, char **av)
{
	t_window	w;

	ft_exit(ac != 2, "Usage:\t./scop [filename]");
	load_obj(&(w.obj), av[1]);
	init_gl(&w);
	init_window(&w);
	loop(&w);
	destroy_obj(&(w.obj));
	destroy_window(&w);
	return (0);
}
