/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pieces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 18:49:43 by leeios            #+#    #+#             */
/*   Updated: 2015/12/27 21:46:39 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetris.h"
#include <unistd.h>

void		print_pieces(t_result *result)
{
	int					i;
	int					j;
	char				c;
	int					max;

	max = MAX(width(&result->frame), height(&result->frame));
	i = -1;
	while (++i <= max)
	{
		j = -1;
		while (++j <= max)
		{
			c = result->data[result->frame.point_up_left.x + i]
				[result->frame.point_up_left.y + j] == EMPTY ? '.'
			: result->data[result->frame.point_up_left.x + i]
				[result->frame.point_up_left.y + j];
			write(1, &c, 1);
		}
		write(1, "\n", 1);
	}
}
