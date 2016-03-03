/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_rect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/27 16:23:46 by leeios            #+#    #+#             */
/*   Updated: 2015/12/27 21:31:55 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetris.h"

void		set_as_point(t_rect *rect, int val)
{
	rect->point_up_left.x = val;
	rect->point_up_left.y = val;
	rect->point_down_right.x = val;
	rect->point_down_right.y = val;
}

int			width(t_rect *rect)
{
	return (rect->point_down_right.x - rect->point_up_left.x);
}

int			height(t_rect *rect)
{
	return (rect->point_down_right.y - rect->point_up_left.y);
}

void		copy(t_rect *orig, t_rect *dest)
{
	dest->point_up_left.x = orig->point_up_left.x;
	dest->point_up_left.y = orig->point_up_left.y;
	dest->point_down_right.x = orig->point_down_right.x;
	dest->point_down_right.y = orig->point_down_right.y;
}

void	grow_rect(t_rect *rect, int new_x, int new_y)
{
	if (new_x < rect->point_up_left.x)
		rect->point_up_left.x = new_x;
	else if (new_x > rect->point_down_right.x)
		rect->point_down_right.x = new_x;
	if (new_y < rect->point_up_left.y)
		rect->point_up_left.y = new_y;
	else if (new_y > rect->point_down_right.y)
		rect->point_down_right.y = new_y;
}

void	set(t_vec2 *vec, int x, int y)
{
	vec->x = x;
	vec->y = y;
}
