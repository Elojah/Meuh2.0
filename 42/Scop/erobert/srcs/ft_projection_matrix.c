/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_projection_matrix.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 18:36:31 by erobert           #+#    #+#             */
/*   Updated: 2015/05/08 18:47:47 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "scop.h"

void		ft_projection_matrix(t_env *e, int fov, float near, float far)
{
	float	ratio;
	float	f;

	ratio = (1.0f * e->size[0]) / e->size[1];
	f = 1. / tan(fov * M_PI / 360.);
	e->projection[0] = f / ratio;
	e->projection[1] = 0.;
	e->projection[2] = 0.;
	e->projection[3] = 0.;
	e->projection[4] = 0.;
	e->projection[5] = f;
	e->projection[6] = 0.;
	e->projection[7] = 0.;
	e->projection[8] = 0.;
	e->projection[9] = 0.;
	e->projection[10] = (far + near) / (near - far);
	e->projection[11] = -1.;
	e->projection[12] = 0.;
	e->projection[13] = 0.;
	e->projection[14] = (2.0f * far * near) / (near - far);
	e->projection[15] = 0.;
}
