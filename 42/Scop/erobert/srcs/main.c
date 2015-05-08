/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/04 09:50:41 by erobert           #+#    #+#             */
/*   Updated: 2015/05/07 19:07:11 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static void			ft_init_gl(t_env *e)
{
	GLchar const	*vertex_shader = e->v_shader;
	GLchar const	*fragment_shader = e->f_shader;

	glClearColor(0.1, 0.25, 0.66, 0.3);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glGenBuffers(1, &e->vertex_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, e->vertex_buffer);
	glBufferData(GL_ARRAY_BUFFER, e->buffer_size * sizeof(t_vertex), e->vertices, GL_DYNAMIC_DRAW);
	glGenVertexArrays (1, &e->vertex_array);
	glBindVertexArray (e->vertex_array);
	glEnableVertexAttribArray (0);
	glBindBuffer(GL_ARRAY_BUFFER, e->vertex_buffer);
	glVertexAttribPointer (0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	e->vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(e->vertex_shader, 1, &vertex_shader, NULL);
	glCompileShader(e->vertex_shader);
	e->fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(e->fragment_shader, 1, &fragment_shader, NULL);
	glCompileShader(e->fragment_shader);
	e->shader_programme = glCreateProgram();
	glAttachShader(e->shader_programme, e->fragment_shader);
	glAttachShader(e->shader_programme, e->vertex_shader);
	glLinkProgram(e->shader_programme);
}

int					main(int ac, char **av)
{
	t_env			e;
	t_vertex		vbd[MAX_SIZE];
	GLuint			ibd[MAX_SIZE];

	if (ac != 2)
		return (ft_error("scop obj", 0));
	if (ft_load_obj(&e, vbd, ibd, av[1]))
		return (ft_error("obj load error", -1));
	if (ft_load_shader(&e))
		return (ft_error("shader load error", -1));
	e.size[0] = 1024;
	e.size[1] = 768;
	e.mlx_ptr = mlx_init();
	if (!e.mlx_ptr)
		return (ft_error("mlx init error", -1));
	e.win_ptr = mlx_new_opengl_window(e.mlx_ptr, e.size[0], e.size[1], av[0]);
	if (!e.win_ptr)
		return (ft_error("win init error", -1));
	ft_init_gl(&e);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(e.shader_programme);
	glUniform1f(glGetUniformLocation(e.shader_programme, "x"), 0.);
	glUniform1f(glGetUniformLocation(e.shader_programme, "y"), 0.);
	glUniform1f(glGetUniformLocation(e.shader_programme, "z"), 0.);
	glUniform1f(glGetUniformLocation(e.shader_programme, "zoom"), .3);
	glBindVertexArray(e.vertex_array);
	glDrawArrays(GL_TRIANGLES, 0, e.buffer_size * 3);
	mlx_opengl_swap_buffers(e.win_ptr);
	mlx_hook(e.win_ptr, 2, 3, ft_key_hook, &e);
	mlx_loop_hook(e.mlx_ptr, ft_loop_hook, &e);
	mlx_loop(e.mlx_ptr);
	return (0);
}
