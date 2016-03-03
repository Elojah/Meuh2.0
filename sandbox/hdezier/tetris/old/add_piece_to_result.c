/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_piece_to_result.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 00:02:41 by leeios            #+#    #+#             */
/*   Updated: 2015/12/31 15:35:07 by leeios           ###   ########.fr       */
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

t_error			add_piece_to_array(t_array_piece *array, t_piece *piece, int n)
{
	if (n > 26 || n < 0)
		return (FILE_INVALID);
	array[n]
}
