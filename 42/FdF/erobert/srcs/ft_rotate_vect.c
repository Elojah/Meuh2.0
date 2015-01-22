/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_vect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 16:59:37 by erobert           #+#    #+#             */
/*   Updated: 2015/01/20 19:47:31 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			ft_init_cos(float *cos)
{
	cos[0] = 0.7071;
	cos[1] = 0.7660;
	cos[2] = 0.8192;
	cos[3] = 0.8660;
	cos[4] = 0.9063;
	cos[5] = 0.9397;
	cos[6] = 0.9659;
	cos[7] = 0.9848;
	cos[8] = 0.9962;
	cos[9] = 1.0000;
}

static void			ft_init_sin(float *sin)
{
	sin[0] = 0.0000;
	sin[1] = 0.0872;
	sin[2] = 0.1736;
	sin[3] = 0.2588;
	sin[4] = 0.3420;
	sin[5] = 0.4226;
	sin[6] = 0.5000;
	sin[7] = 0.5736;
	sin[8] = 0.6428;
	sin[9] = 0.7071;
}

void				ft_rotate_vect(t_vect *a, int angle, t_fct f)
{
	t_matrix		m;
	float			sin[10];
	float			cos[10];

	ft_init_sin(sin);
	ft_init_cos(cos);
	if (angle < 0)
		angle = -angle;
	if (angle > -1 && angle < 9)
		m = f(cos[9 - angle], sin[angle]);
	else if (angle > 8 && angle < 18)
		m = f(sin[9 - angle % 9], cos[angle % 9]);
	else if (angle > 17 && angle < 27)
		m = f(-sin[angle % 9], cos[9 - angle % 9]);
	else if (angle > 26 && angle < 36)
		m = f(-cos[angle % 9], sin[9 - angle % 9]);
	else if (angle > 35 && angle < 45)
		m = f(-cos[9 - angle % 9], -sin[angle % 9]);
	else if (angle > 44 && angle < 54)
		m = f(-sin[9 - angle % 9], -cos[angle % 9]);
	else if (angle > 53 && angle < 63)
		m = f(sin[angle % 9], -cos[9 - angle % 9]);
	else if (angle > 62 && angle < 72)
		m = f(cos[angle % 9], -sin[9 - angle % 9]);
	*a = ft_matrix_vect(a, &m);
}
