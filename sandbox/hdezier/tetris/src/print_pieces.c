/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pieces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 16:55:39 by leeios            #+#    #+#             */
/*   Updated: 2015/12/31 17:36:39 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetris.h"
#include <unistd.h>

static void	putnbr(int n)
{
	int		decimal;
	char	c;

	decimal = n / 10;
	if (decimal != 0)
	{
		c = '0' + decimal;
		write(1, &c, 1);
	}
	n -= decimal * 10;
	c = '0' + n;
	write(1, &c, 1);
}

void		print_pieces(t_result *result)
{
	int		i;
	int		j;
	char	c;

	i = -1;
	while(++i < result->fit_size)
	{
		j = -1;
		while(++j < result->fit_size)
		{
			if (result->data[i][j] != EMPTY)
			{
				c = result->data[i][j] + 'A' - 1;
				write(1, &c, 1);
			}
			else
				write(1, ".", 1);
		}
		write(1, "\n", 1);
	}
	write(1, "Size: ", 6);
	putnbr(result->fit_size);
	write(1, "\n", 1);
}
