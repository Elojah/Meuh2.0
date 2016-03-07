/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grow_rect_with_piece.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/27 21:28:46 by leeios            #+#    #+#             */
/*   Updated: 2015/12/27 22:06:54 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetris.h"

static void		balance_rect(t_rect *frame)
{
	int		width_frame;
	int		height_frame;

	width_frame = width(frame);
	height_frame = height(frame);
	if (width_frame > height_frame)
		frame->point_down_right.x += width_frame - height_frame;
	else if (height_frame > width_frame)
		frame->point_down_right.y += height_frame - width_frame;
}

int				grow_rect_with_piece(t_result *result, t_piece *piece
	,t_vec2 *base_position, t_rect *frame)
{
	int			i;
	int			j;

	copy(&result->frame, frame);
	i = -1;
	while (++i < SIZE_PIECE)
	{
		j = -1;
		while (++j < SIZE_PIECE)
		{
			if (piece->data[i][j] == BLOC)
			{
				if (base_position->x + i < 0
					|| base_position->x + i >= MAX_PIECES * SIZE_PIECE
					|| base_position->y + j < 0
					|| base_position->y + j >= MAX_PIECES * SIZE_PIECE
					|| result->data[base_position->x + i][base_position->y + j]
						!= EMPTY)
					return (-1);
				grow_rect(frame, base_position->x + i, base_position->y + j);
			}
		}
	}
	balance_rect(frame);
	return (1);
}
