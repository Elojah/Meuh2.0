/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 17:22:39 by rduclos           #+#    #+#             */
/*   Updated: 2017/02/20 17:30:30 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		remove_last_tetri(t_env *env, t_tetri *toplace)
{
	remove_from_board(env, toplace);
	if (toplace->x < (env->maxsize - 1))
	{
		toplace->x++;
		try_place(env, toplace);
	}
	else if ((toplace->y) < (env->maxsize - 1))
	{
		toplace->x = 0;
		toplace->y++;
		try_place(env, toplace);
	}
	else if (toplace != env->lc_tetris)
	{
		toplace->y = 0;
		toplace->x = 0;
		toplace = toplace->prev;
		remove_last_tetri(env, toplace);
	}
	else
		try_replace(env);
}

void		place_tetri(t_env *env, t_tetri *toplace)
{
	check_place(env, toplace, 1);
	if (toplace->next != NULL)
		try_place(env, toplace->next);
}

void		try_replace(t_env *env)
{
	t_tetri		*tmp;

	tmp = env->lc_tetris;
	while (tmp != NULL)
	{
		remove_from_board(env, tmp);
		tmp->x = 0;
		tmp->y = 0;
		tmp = tmp->next;
	}
	free(env->board);
	env->maxsize++;
	set_board_size(env, env->maxsize);
	try_place(env, env->lc_tetris);
}

void		try_place(t_env *env, t_tetri *toplace)
{
	if (verify_place(env, toplace) == 1)
		place_tetri(env, toplace);
	else if (toplace != env->lc_tetris)
	{
		toplace->y = 0;
		toplace->x = 0;
		toplace = toplace->prev;
		remove_last_tetri(env, toplace);
	}
	else
		try_replace(env);
}

void		solve(t_env *env)
{
	init_board(env);
	try_place(env, env->lc_tetris);
	draw_board(env);
}
