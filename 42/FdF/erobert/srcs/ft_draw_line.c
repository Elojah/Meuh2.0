/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 16:50:49 by erobert           #+#    #+#             */
/*   Updated: 2015/01/20 12:10:38 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

void		ft_draw_line(t_vect *a, t_vect *b, t_data *d)
{
	t_vect	m;

	if ((b->x - a->x) * (b->x - a->x) < 2 && (b->y - a->y) * (b->y - a->y) < 2)
		return ;
	m.x = (a->x + b->x) * 0.5;
	m.y = (a->y + b->y) * 0.5;
	m.z = (a->z + b->z) * 0.5;
	ft_put_pixel_to_image(d, m.x, m.y, ft_color_deg(m.z, d));
	ft_draw_line(a, &m, d);
	ft_draw_line(&m, b, d);
}
