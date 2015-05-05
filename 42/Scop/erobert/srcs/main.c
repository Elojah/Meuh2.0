/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/04 09:50:41 by erobert           #+#    #+#             */
/*   Updated: 2015/05/04 15:24:24 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include <stdio.h>
# define BUFFER_OFFSET(i) ((char *)NULL + (i))
static int		ft_key_hook(int key, t_env *e)
{
	(void)e;
	printf("key: %d\n", key);
	if (key == K_ESC)
		exit(1);
	return (0);
}

int				main(int ac, char **av)
{
	t_env		e;
	t_vertex	vbd[8092];
	GLuint		ibd[8092];
	t_vertex	vertex[8092];

	if (ac != 2)
		return (ft_error("scop obj", 0));
	ft_get_obj(vbd, ibd, av[1]);
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

	int i = 0;
	while (i < 8092 && ibd[i] != 0)
	{
		vertex[i] = vbd[ibd[i] - 1];
		i++;
	}

	i = 0;
	while (i < 64)
	{
		printf("%f | %f | %f\n", vertex[i].x, vertex[i].y, vertex[i].z);
		i++;
	}
	i = 0;
	while (i < 64)
	{
		printf("v %f %f %f\n", vbd[i].x, vbd[i].y, vbd[i].z);
		i++;
	}
	i = 0;
	while (i < 64)
	{
		printf("f %d %d %d %d\n", ibd[i], ibd[i + 1], ibd[i + 2], ibd[i + 3]);
		i += 4;
	}

	GLuint vbo = 0;
	glGenBuffers (1, &vbo);
	glBindBuffer (GL_ARRAY_BUFFER, vbo);
	glBufferData (GL_ARRAY_BUFFER, 8092 * sizeof (t_vertex), vertex, GL_STATIC_DRAW);

	GLuint	vbi = 0;
	glGenBuffers(1, &vbi);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbi);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(ibd), ibd, GL_STATIC_DRAW);

	GLuint vao = 0;
	glGenVertexArrays (1, &vao);
	glBindVertexArray (vao);
	glEnableVertexAttribArray (0);
	glBindBuffer (GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer (0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	GLuint	vai = 0;
	glGenVertexArrays(1, &vai);
	glBindVertexArray(vai);

const char* vertex_shader =
"#version 400\n"
"in vec3 vp;"
"void main () {"
"  gl_Position = vec4 (vp, 1.0);"
	"}";
const char* fragment_shader =
"#version 400\n"
"out vec4 frag_colour;"
"void main () {"
"  frag_colour = vec4 (0.5, 0.0, 0.5, 1.0);"
	"}";
	GLuint vs = glCreateShader (GL_VERTEX_SHADER);
	glShaderSource (vs, 1, &vertex_shader, NULL);
	glCompileShader (vs);
	GLuint fs = glCreateShader (GL_FRAGMENT_SHADER);
	glShaderSource (fs, 1, &fragment_shader, NULL);
	glCompileShader (fs);

	GLuint shader_programme = glCreateProgram ();
	glAttachShader (shader_programme, fs);
	glAttachShader (shader_programme, vs);
	glLinkProgram (shader_programme);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(shader_programme);
	glBindVertexArray (vao);
	glDrawArrays(GL_LINES, 0, 8092);

/*	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbi);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo);
	glGenVertexArrays(1, &vai);  glDrawElements(
		GL_TRIANGLE_STRIP,
		1024,
		GL_UNSIGNED_INT,
		BUFFER_OFFSET(0)
		);
	glDisableVertexAttribArray(0);*/

	mlx_opengl_swap_buffers(e.win_ptr);
	mlx_hook(e.win_ptr, 2, 3, ft_key_hook, &e);
	mlx_loop(e.mlx_ptr);
	return (0);
}
