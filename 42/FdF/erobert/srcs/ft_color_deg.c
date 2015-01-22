/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_deg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 17:43:16 by erobert           #+#    #+#             */
/*   Updated: 2013/12/19 21:10:35 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_color_deg(float z, t_data *d)
{
	t_color	c;

	(c.rgba)[3] = 0;
	if (z > 0)
	{
		(c.rgba)[2] = 255;
		(c.rgba)[0] = 255 - z * 255 * 1 / (d->max * d->height);
		(c.rgba)[1] = 255 - z * 255 * 1 / (d->max * d->height);
	}
	else if (z < 0)
	{
		(c.rgba)[0] = 255;
		(c.rgba)[1] = 255 + z * 255 * 1 / (d->max * d->height);
		(c.rgba)[2] = 255 + z * 255 * 1 / (d->max * d->height);
	}
	else
		return (0xFFFFFF);
	return (c.c);
}
