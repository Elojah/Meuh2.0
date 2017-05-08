/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 17:17:11 by rduclos           #+#    #+#             */
/*   Updated: 2017/02/20 17:31:52 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		set_board_size(t_env *env, int size)
{
	int		count;
	int		count2;

	count = 0;
	env->board = (char **)malloc(sizeof(char *) * (size + 1));
	while (count < size)
	{
		env->board[count] = (char *)malloc(sizeof(char) * (size + 1));
		count2 = 0;
		while (count2 < size)
		{
			env->board[count][count2] = '.';
			count2++;
		}
		env->board[count][count2] = '\0';
		count++;
	}
	env->board[count] = NULL;
}

void		init_board(t_env *env)
{
	int		size;

	size = 11;
	while (size > 0 && (size * size) >= (env->nbtetris * 4))
		size--;
	size++;
	env->maxsize = size;
	set_board_size(env, env->maxsize);
}
