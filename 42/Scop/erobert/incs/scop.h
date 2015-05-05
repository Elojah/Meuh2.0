/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/04 10:17:36 by erobert           #+#    #+#             */
/*   Updated: 2015/05/04 14:25:33 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# include <OpenGL/gl3.h>
# include <stdlib.h>
# include "libft.h"
# include "mlx.h"
# include "mlx_opengl.h"

# define K_ESC 53

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
}				t_env;

int				ft_get_obj(t_vertex *vbd, GLuint *ibd, char *file);

#endif
