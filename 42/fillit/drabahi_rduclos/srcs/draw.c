/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 17:17:46 by rduclos           #+#    #+#             */
/*   Updated: 2017/02/20 17:31:25 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		draw_tetri(t_tetri *piece)
{
	int		i;

	i = 0;
	while (piece->tetri[i] != NULL)
	{
		ft_putendl(piece->tetri[i]);
		i++;
	}
}

void		draw_board(t_env *env)
{
	int		count;

	count = 0;
	while (count < env->maxsize)
	{
		ft_putendl(env->board[count]);
		count++;
	}
}
