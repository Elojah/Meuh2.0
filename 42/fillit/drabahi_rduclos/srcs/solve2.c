/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 16:55:26 by rduclos           #+#    #+#             */
/*   Updated: 2017/02/20 17:32:35 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_case(t_env *env, t_tetri *toplace, int plusyx[2], int posyx[2])
{
	if (toplace->tetri[posyx[0] + plusyx[0]][posyx[1] + plusyx[1]] == '#')
	{
		if ((toplace->y + plusyx[0]) >= env->maxsize ||
			(toplace->x + plusyx[1]) >= env->maxsize)
			return (-1);
		if (env->board[toplace->y + plusyx[0]][toplace->x + plusyx[1]] != '.')
			return (-1);
	}
	return (1);
}

int		set_case(t_env *env, t_tetri *toplace, int plusyx[2], int posyx[2])
{
	static int		nbtetri;
	int				y;
	int				x;

	if (toplace->tetri[posyx[0] + plusyx[0]][posyx[1] + plusyx[1]] == '#')
	{
		if ((toplace->y + plusyx[0]) < env->maxsize)
		{
			if ((toplace->x + plusyx[1]) < env->maxsize)
			{
				nbtetri++;
				y = toplace->y + plusyx[0];
				x = toplace->x + plusyx[1];
				env->board[y][x] = toplace->name;
				if (nbtetri == 4)
				{
					nbtetri = 0;
					return (1);
				}
			}
		}
	}
	return (0);
}

int		check_place(t_env *env, t_tetri *toplace, int write)
{
	static int		plusyx[2];
	int				posyx[12];
	int				ret;

	first_char(toplace, &posyx[1], &posyx[0]);
	if (write == 0 && (ret = check_case(env, toplace, plusyx, posyx)) == -1)
	{
		clear_pos(&(plusyx[1]), &(plusyx[0]));
		return (-1);
	}
	if (write == 1 && set_case(env, toplace, plusyx, posyx) == 1)
	{
		clear_pos(&plusyx[1], &plusyx[0]);
		return (1);
	}
	if ((posyx[1] + plusyx[1]) < 3)
		plusyx[1]++;
	else if ((posyx[1] + plusyx[1]) == 3 && (posyx[0] + plusyx[0]) < 3)
		incremy(&plusyx[0], &plusyx[1], posyx[1]);
	else
	{
		clear_pos(&plusyx[1], &plusyx[0]);
		return (1);
	}
	return (check_place(env, toplace, write));
}

int		verify_place(t_env *env, t_tetri *toplace)
{
	int		start;

	start = 1;
	while (toplace->y < env->maxsize)
	{
		if (start != 1)
			toplace->x = 0;
		while (toplace->x < env->maxsize)
		{
			start = 0;
			if (check_place(env, toplace, 0) == 1)
				return (1);
			toplace->x++;
		}
		toplace->y++;
	}
	return (-1);
}

void	remove_from_board(t_env *env, t_tetri *toplace)
{
	int		x;
	int		y;

	y = 0;
	while (y < env->maxsize)
	{
		x = 0;
		while (x < env->maxsize)
		{
			if (env->board[y][x] == toplace->name)
				env->board[y][x] = '.';
			x++;
		}
		y++;
	}
}
