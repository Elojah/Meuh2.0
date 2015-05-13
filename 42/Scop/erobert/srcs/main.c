/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/04 09:50:41 by erobert           #+#    #+#             */
/*   Updated: 2015/05/13 19:39:24 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static void			ft_init_buffer(t_env *e)
{
	GLchar const	*vertex_shader;
	GLchar const	*fragment_shader;
	GLsizeiptr		size;

	vertex_shader = e->v_shader;
	fragment_shader = e->f_shader;
	glGenBuffers(1, &e->vertex_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, e->vertex_buffer);
	size = e->buffer_size * sizeof(t_vertex);
	glBufferData(GL_ARRAY_BUFFER, size, e->vertices, GL_DYNAMIC_DRAW);
	glGenVertexArrays (1, &e->vertex_array);
	glBindVertexArray (e->vertex_array);
	glEnableVertexAttribArray (0);
	glBindBuffer(GL_ARRAY_BUFFER, e->vertex_buffer);
	glVertexAttribPointer (0, 4, GL_FLOAT, GL_FALSE, 0, NULL);
	e->vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(e->vertex_shader, 1, &vertex_shader, NULL);
	glCompileShader(e->vertex_shader);
	e->fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(e->fragment_shader, 1, &fragment_shader, NULL);
	glCompileShader(e->fragment_shader);
	e->shader_program = glCreateProgram();
	glAttachShader(e->shader_program, e->fragment_shader);
	glAttachShader(e->shader_program, e->vertex_shader);
	glLinkProgram(e->shader_program);
}

static void			ft_init_texture(t_env *e)
{
	GLuint			texture;
	GLint			location;

	glEnable(GL_CULL_FACE);
	ft_load_bmp(e, "data/texture_0.bmp");
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 256, 256, 0, GL_BGR, \
					GL_UNSIGNED_BYTE, e->texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	location = glGetUniformLocation(e->shader_program, "texture_on");
	e->texture_on = 0;
	glUniform1i(location, e->texture_on);
}

static void			ft_main_loop(t_env *e)
{
	GLint			location;
	GLfloat			mvp[16];

	glClearColor(0.1, 0.25, 0.66, 0.3);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	ft_init_buffer(e);
	ft_init_texture(e);
	ft_lookat(e, e->eye, e->at);
	ft_projection_matrix(e, 60, 1., 30.);
	glUseProgram(e->shader_program);
	ft_multmatrix(mvp, e->projection, e->view);
	location = glGetUniformLocation(e->shader_program, "mvp");
	glUniformMatrix4fv(location, 1, 0, mvp);
	glBindVertexArray(e->vertex_array);
	glDrawArrays(GL_TRIANGLES, 0, e->buffer_size * sizeof(t_vertex));
	mlx_opengl_swap_buffers(e->win_ptr);
	mlx_hook(e->win_ptr, 2, 3, ft_key_hook, e);
	mlx_loop_hook(e->mlx_ptr, ft_loop_hook, e);
	mlx_loop(e->mlx_ptr);
}

int					main(int ac, char **av)
{
	t_env			e;

	e.buffer_size = 0;
	e.size[0] = 1024;
	e.size[1] = 768;
	e.eye[0] = 0.;
	e.eye[1] = 0.;
	e.eye[2] = -10.;
	e.at[0] = 0.;
	e.at[1] = 0.;
	e.at[2] = 1.;
	if (ac != 2)
		return (ft_error("scop obj", 0));
	if (ft_load_obj(&e, av[1]))
		return (ft_error("obj load error", -1));
	if (ft_load_shader(&e))
		return (ft_error("shader load error", -1));
	e.mlx_ptr = mlx_init();
	if (!e.mlx_ptr)
		return (ft_error("mlx init error", -1));
	e.win_ptr = mlx_new_opengl_window(e.mlx_ptr, e.size[0], e.size[1], av[0]);
	if (!e.win_ptr)
		return (ft_error("win init error", -1));
	ft_main_loop(&e);
	return (0);
}
