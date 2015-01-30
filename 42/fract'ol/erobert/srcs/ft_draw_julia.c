/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 11:57:53 by erobert           #+#    #+#             */
/*   Updated: 2015/01/30 17:07:31 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			ft_draw_julia(t_data *d, int x, int y)
{
	double	new[2];
	double	old[2];
	int		i;
	int		flag;

	new[0] = 3.0 * (x - d->size / 2) / (d->zoom * d->size) + d->fract.pos[0];
	new[1] = (y - d->size / 2) / (0.5 * d->zoom * d->size) + d->fract.pos[1];
	flag = 1;
	i = -1;
	while (flag && ++i < d->max_iter)
	{
		old[0] = new[0];
		old[1] = new[1];
		new[0] = old[0] * old[0] - old[1] * old[1] + d->fract.p[0];
		new[1] = 2.0 * old[0] * old[1] + d->fract.p[1];
		if ((new[0] * new[0] + new[1] * new[1]) > 4.0)
			flag = 0;
	}
	return (i);
}
