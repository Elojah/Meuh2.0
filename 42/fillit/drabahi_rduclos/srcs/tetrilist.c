/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrilist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 17:23:32 by rduclos           #+#    #+#             */
/*   Updated: 2017/02/20 17:31:09 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			add_tetri(t_env *env, t_tetri *tetri)
{
	t_tetri		*tmp;

	env->nbtetris++;
	if (env->lc_tetris == NULL)
	{
		env->lc_tetris = tetri;
		tetri->next = NULL;
		tetri->prev = NULL;
	}
	else
	{
		tmp = env->lc_tetris;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = tetri;
		tetri->next = NULL;
		tetri->prev = tmp;
	}
}

void			remove_tetri(t_env *env, t_tetri *tetri)
{
	t_tetri		*tmp;
	t_tetri		*tmp_prev;
	t_tetri		*tmp_next;

	tmp = env->lc_tetris;
	while (tmp != NULL)
	{
		if (tmp->name == tetri->name)
		{
			tmp_prev = tmp->prev;
			tmp_next = tmp->next;
			tmp_prev->next = tmp_next;
			tmp_next->prev = tmp_prev;
			free(tmp);
			return ;
		}
		tmp = tmp->next;
	}
}

void			delete_tetrilc(t_env *env)
{
	t_tetri		*tmp;
	t_tetri		*del;

	tmp = env->lc_tetris;
	while (tmp != NULL)
	{
		del = tmp;
		tmp = tmp->next;
		free(del);
	}
	env->lc_tetris = NULL;
}
