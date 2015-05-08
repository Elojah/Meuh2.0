/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/04 10:17:36 by erobert           #+#    #+#             */
/*   Updated: 2015/05/08 18:51:13 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# include <OpenGL/gl3.h>
# include <stdlib.h>
# include "libft.h"
# include "mlx.h"
# include "mlx_opengl.h"

# define MAX_SIZE 30720
# define READ_SIZE 2048
# define K_ESC 53
# define K_LEFT 123
# define K_RIGHT 124
# define K_UP 126
# define K_DOWN 125
# define K_PLUS 69
# define K_MINUS 78
# define K_HOME 115
# define K_END 119

typedef struct	s_vertex
{
	GLfloat		x;
	GLfloat		y;
	GLfloat		z;
}				t_vertex;

typedef struct	s_env
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			size[2];
	GLfloat		view[16];
	GLfloat		projection[16];
	t_vertex	vertices[MAX_SIZE];
	GLsizeiptr	buffer_size;
	GLuint		vertex_buffer;
	GLchar		f_shader[READ_SIZE];
	GLchar		v_shader[READ_SIZE];
	GLuint		vertex_array;
	GLuint		vertex_shader;
	GLuint		fragment_shader;	
	GLuint		shader_program;
}				t_env;

int				ft_load_obj(t_env *e, t_vertex *vbd, GLuint *ibd, char *file);
int				ft_load_shader(t_env *e);
void			ft_cross_product(float *result, float *u, float *v);
void			ft_addsub_vect(float *result, float *u, float *v, char opp);
void			ft_projection_matrix(t_env *e, int fov, float near, float far);
void			ft_lookat(t_env *e, float *eye, float *at);
int				ft_loop_hook(t_env *e);
int				ft_key_hook(int key, t_env *e);

#endif
