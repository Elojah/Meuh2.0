/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_tetris.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 17:22:26 by rduclos           #+#    #+#             */
/*   Updated: 2017/02/20 17:22:27 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				verify_char(char *line)
{
	int		i;

	if (line[0] != '\0')
	{
		i = 0;
		while (i < 4)
		{
			if (line[i] != '.' && line[i] != '#')
				return (-1);
			i++;
		}
	}
	return (1);
}

void			copy_tetri(t_tetri *new, char tetri[4][5])
{
	int		x;
	int		y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 5)
		{
			new->tetri[y][x] = tetri[y][x];
			x++;
		}
		y++;
	}
}

int				save_tetri(t_env *env, char tetri[4][5])
{
	t_tetri		*new;

	if (env->tetris_name > 90)
		return (-1);
	new = (t_tetri *)malloc(sizeof(t_tetri));
	new->name = env->tetris_name;
	new->x = 0;
	new->y = 0;
	env->tetris_name++;
	copy_tetri(new, tetri);
	add_tetri(env, new);
	return (1);
}
