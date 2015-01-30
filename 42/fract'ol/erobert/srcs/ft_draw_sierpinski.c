/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_sierpinski.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 18:14:48 by erobert           #+#    #+#             */
/*   Updated: 2015/01/30 19:38:17 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					ft_draw_sierpinski(t_data *d, int x, int y)
{
	x += d->fract.pos[0] * 100;
	y += d->fract.pos[1] * 100;
	x *= d->zoom;
	y *= d->zoom;
	if (x & y)
		return (0);
	return (7);
}
