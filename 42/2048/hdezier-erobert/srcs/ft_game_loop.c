/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 14:26:48 by erobert           #+#    #+#             */
/*   Updated: 2015/03/01 16:33:27 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

int			ft_game_loop(t_data *d, char *input, int *score)
{
	int		tmp;

	tmp = ft_play(d, *input);
	if (tmp < 0)
	{
		mvwprintw(stdscr, 0, 0, "You lost !\n Final score: %d", *score);
		return (0);
	}
	*score += (1 << tmp);
	clear();
	ft_display_grid(d);
	if ((1 << tmp) == WIN_VALUE)
		mvwprintw(stdscr, 0, 0, "You won !\n Final score: %d", *score);
	else if (tmp > 0)
		mvwprintw(stdscr, 0, 0, "score: %d", *score);
	refresh();
	*input = getch();
	return (1);
}
