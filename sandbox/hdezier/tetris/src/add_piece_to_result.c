/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_piece_to_result.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 00:02:41 by leeios            #+#    #+#             */
/*   Updated: 2015/12/27 21:58:23 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetris.h"

static t_error	write_piece_to_result(t_result *result, t_piece *piece
	, int n, t_vec2 *min_position)
{
	int			i;
	int			j;

	if (min_position->x == INT_MAX || min_position->y == INT_MAX)
		return (LOST_PIECE);
	i = -1;
	while (++i < SIZE_PIECE)
	{
		j = -1;
		while (++j < SIZE_PIECE)
		{
			if (piece->data[i][j] == BLOC)
			{
				result->data[min_position->x + i][min_position->y + j] = n;
				grow_rect(&result->frame
					, min_position->x + i, min_position->y + j);
			}
		}
	}
	return (NONE);
}

t_error			add_piece_to_result(t_result *result, t_piece *piece, int n)
{
	t_vec2		it;
	t_vec2		min;
	t_vec2		min_position;
	t_vec2		base_position;
	t_rect		frame;

	min_position.x = min_position.y = min.x = min.y = INT_MAX;
	it.x = result->frame.point_up_left.x - SIZE_PIECE - 1;
	while (++it.x < result->frame.point_down_right.x + SIZE_PIECE)
	{
		it.y = result->frame.point_up_left.y - SIZE_PIECE - 1;
		while (++it.y < result->frame.point_down_right.y + SIZE_PIECE)
		{
			set(&base_position, it.x, it.y);
			if (grow_rect_with_piece(result, piece, &base_position, &frame) < 0
				|| width(&frame) + height(&frame) > min.x
				|| (width(&frame) + height(&frame) == min.x
					&& ABS(width(&frame) - height(&frame)) >= min.y))
				continue ;
			set(&min, width(&frame) + height(&frame)
				, ABS(width(&frame) - height(&frame)));
			set(&min_position, it.x, it.y);
		}
	}
	return (write_piece_to_result(result, piece, 'A' + n, &min_position));
}
