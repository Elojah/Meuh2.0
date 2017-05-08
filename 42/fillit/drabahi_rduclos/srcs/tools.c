/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 17:24:20 by rduclos           #+#    #+#             */
/*   Updated: 2017/02/20 17:24:38 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		first_char(t_tetri *toplace, int *x, int *y)
{
	*y = 0;
	*x = 0;
	while (*y < 4)
	{
		*x = 0;
		while (*x < 4)
		{
			if (toplace->tetri[*y][*x] == '#')
				return ;
			*x = *x + 1;
		}
		*y = *y + 1;
	}
}

void		clear_pos(int *x, int *y)
{
	*x = 0;
	*y = 0;
}

void		incremy(int *plusy, int *plusx, int posx)
{
	*plusx = 0 - posx;
	*plusy = *plusy + 1;
}
