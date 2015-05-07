/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/04 09:50:41 by erobert           #+#    #+#             */
/*   Updated: 2015/05/07 14:12:31 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include <stdio.h>

static int		ft_expose_hook(t_env *e)
{
	(void)e;
	return (0);
}

static int		ft_key_hook(int key, t_env *e)
{
	(void)e;
	printf("key: %d\n", key);
	if (key == K_ESC)
		exit(1);
	unsigned int	i = 0;
	while (i <  e->buffer_size * sizeof(t_vertex))
	{
		e->vertices[i].x /= 1.5;
		e->vertices[i].y /= 1.5;
		e->vertices[i].z /= 1.5;
		i++;
	}

	const char* vertex_shader =
		"#version 400\n"
		"in vec3 vp;"
		"out vec3 color_vertex;"
		"void main () {"
		"float PI = 3.14159265358979323846264;"
		"float angle = 140.;"
		"float rad_angle = angle * PI / 180.0;"
		"vec4 a = vec4(vp, 1.0);"
		"vec4 b = a;"
		"b.x = a.x * cos(rad_angle) - a.z * sin(rad_angle);"
		"b.z = a.z * cos(rad_angle) + a.x * sin(rad_angle);"
		"b.x /= 3;"
		"b.y /= 3;"
		"b.z /= 3;"
		"gl_Position = b;"
		"color_vertex = vp;"
		"}";
	e->vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(e->vertex_shader, 1, &vertex_shader, NULL);
	glCompileShader(e->vertex_shader);
	e->shader_programme = glCreateProgram();
	glAttachShader(e->shader_programme, e->fragment_shader);
	
	glAttachShader(e->shader_programme, e->vertex_shader);
	glLinkProgram(e->shader_programme);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(e->shader_programme);
	glBindVertexArray(e->vertex_array);
	glDrawArrays(GL_TRIANGLES, 0, e->buffer_size * 3);
	mlx_opengl_swap_buffers(e->win_ptr);
	return (0);
}

int				main(int ac, char **av)
{
	t_env		e;
	t_vertex	vbd[8092];
	GLuint		ibd[8092];

	if (ac != 2)
		return (ft_error("scop obj", 0));
	ft_get_obj(&e, vbd, ibd, av[1]);
	e.size[0] = 1024;
	e.size[1] = 768;
	e.mlx_ptr = mlx_init();
	if (!e.mlx_ptr)
		return (ft_error("mlx init error", -1));
	e.win_ptr = mlx_new_opengl_window(e.mlx_ptr, e.size[0], e.size[1], av[0]);
	if (!e.win_ptr)
		return (ft_error("win init error", -1));
	glClearColor(0.1, 0.25, 0.66, 0.3);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);


	glGenBuffers(1, &e.vertex_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, e.vertex_buffer);
	glBufferData(GL_ARRAY_BUFFER, e.buffer_size * sizeof(t_vertex), e.vertices, GL_DYNAMIC_DRAW);

	glGenVertexArrays (1, &e.vertex_array);
	glBindVertexArray (e.vertex_array);
	glEnableVertexAttribArray (0);
	glBindBuffer(GL_ARRAY_BUFFER, e.vertex_buffer);
	glVertexAttribPointer (0, 3, GL_FLOAT, GL_FALSE, 0, NULL);


	const char* vertex_shader =
		"#version 400\n"
		"in vec3 vp;"
		"out vec3 color_vertex;"
		"void main () {"
		"float PI = 3.14159265358979323846264;"
		"float angle = 45.;"
		"float rad_angle = angle * PI / 180.0;"
		"vec4 a = vec4(vp, 1.0);"
		"vec4 b = a;"
//		"b.x = a.x * cos(rad_angle) - a.y * sin(rad_angle);"
//		"b.y = a.y * cos(rad_angle) + a.x * sin(rad_angle);"
		"gl_Position = b;"
		"color_vertex = vp;"
		"}";
	const char* fragment_shader =
		"#version 400\n"
		"out vec4 frag_colour;"
		"in vec3 color_vertex;"
		"void main () {"
		"  frag_colour = vec4 (color_vertex, 1.);"
		"}";

	e.vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(e.vertex_shader, 1, &vertex_shader, NULL);
	glCompileShader(e.vertex_shader);
	e.fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(e.fragment_shader, 1, &fragment_shader, NULL);
	glCompileShader(e.fragment_shader);

	e.shader_programme = glCreateProgram();
	glAttachShader(e.shader_programme, e.fragment_shader);
	glAttachShader(e.shader_programme, e.vertex_shader);
	glLinkProgram(e.shader_programme);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(e.shader_programme);
	glBindVertexArray(e.vertex_array);
	glDrawArrays(GL_TRIANGLES, 0, e.buffer_size * 3);

	mlx_opengl_swap_buffers(e.win_ptr);
	mlx_hook(e.win_ptr, 2, 3, ft_key_hook, &e);
	mlx_expose_hook(e.win_ptr, ft_expose_hook, &e);
	mlx_loop(e.mlx_ptr);
	return (0);
}
