/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 17:17:59 by rduclos           #+#    #+#             */
/*   Updated: 2017/02/20 17:28:16 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	my_error(void)
{
	ft_putstr("error\n");
	exit(-42);
}

void	usage(void)
{
	ft_putstr("Usage : ./fillit <filename>\n");
}

void	init_env(t_env *env)
{
	env->tetris_name = 'A';
	env->maxsize = 0;
	env->nbtetris = 0;
}

int		main(int ac, char **av)
{
	t_env		env;

	if (ac != 2)
		usage();
	else
	{
		init_env(&env);
		if (parse(&env, av) == 1)
			solve(&env);
		else
			my_error();
	}
	return (0);
}
