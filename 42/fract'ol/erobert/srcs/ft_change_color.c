/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 19:09:28 by erobert           #+#    #+#             */
/*   Updated: 2015/01/30 19:18:08 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_change_color(int *color, int button)
{
	t_color	c;
	int		i;

	button--;
	i = -1;
	while (++i < 256)
	{
		c.c = color[i];
		c.rgba[button] += 10 % 256;
		color[i] = c.c;
	}
}
