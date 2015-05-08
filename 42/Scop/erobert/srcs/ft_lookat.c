/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lookat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 17:02:06 by erobert           #+#    #+#             */
/*   Updated: 2015/05/08 18:36:06 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "scop.h"

static void	ft_normalize(float *v)
{
	float	tmp;

	tmp = sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
	v[0] /= tmp;
	v[1] /= tmp;
	v[2] /= tmp;
}

static void	ft_setview(float *view, float *dir, float *right, float *up)
{
	view[0] = right[0];
	view[4] = right[1];
	view[8] = right[2];
	view[12] = 0.;
	view[1] = up[0];
	view[5] = up[1];
	view[9] = up[2];
	view[13] = 0.;
	view[2] = -dir[0];
	view[6] = -dir[1];
	view[10] = -dir[2];
	view[14] = 0.;
	view[3] = 0.;
	view[7] = 0.;
	view[11] = 0.;
	view[15] = 1.;
}

static void	ft_translation_matrix(float *a, float *v)
{
	int		i;
	int		j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (i == j)
				a[i + j * 4] = 1.;
			else
				a[i + j * 4] = 0.;
		}
	}
	a[12] = -v[0];
	a[13] = -v[1];
	a[14] = -v[2];
}

static void	ft_multmatrix(float *a, float *b)
{
	float	result[16];
	int		i;
	int		j;
	int		k;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			result[i + j * 4] = 0.;
			k = -1;
			while (++k < 4)
				result[i + j * 4] += a[i + k * 4] * b[k + j * 4];
		}
	}
	ft_memcpy(a, result, 16 * sizeof(float));
}

void		ft_lookat(t_env *e, float *eye, float *at)
{
	float	dir[3];
	float	right[3];
	float	up[3];
	float	tmp[16];

	up[0] = 0.;
	up[1] = 1.;
	up[2] = 0.;
	ft_addsub_vect(dir, at, eye, '-');
	ft_normalize(dir);
	ft_cross_product(right, dir, up);
	ft_normalize(right);
	ft_cross_product(up, right, dir);
	ft_normalize(up);
	ft_setview(e->view, dir, right, up);
	ft_translation_matrix(tmp, eye);
	ft_multmatrix(e->view, tmp);
}
