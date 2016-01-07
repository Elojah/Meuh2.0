/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 18:49:43 by leeios            #+#    #+#             */
/*   Updated: 2015/12/27 17:22:36 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetris.h"

static void	init_result(t_result *result)
{
	int					i;
	int					j;

	i = -1;
	while (++i < MAX_PIECES * SIZE_PIECE)
	{
		j = -1;
		while (++j < MAX_PIECES * SIZE_PIECE)
			result->data[i][j] = EMPTY;
	}
	set_as_point(&result->frame, MAX_PIECES * SIZE_PIECE / 2);
}

static void	exec(int ac, char **av)
{
	t_result			result;
	int					i;

	i = 0;
	init_result(&result);
	while (++i < ac)
		exit_with_error(file_to_pieces(&result, av[i]));
	print_pieces(&result);
}

int			main(int ac, char **av)
{

	if (ac < 2)
		exit_with_error(NO_ARGS);
	exec(ac, av);
}
