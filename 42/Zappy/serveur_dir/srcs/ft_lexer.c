/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/03 17:18:41 by erobert           #+#    #+#             */
/*   Updated: 2014/06/14 03:22:08 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

static int	ft_team(int ac, char **av, t_env *e)
{
	int		i;

	if (e->client_nb[0] < 1)
		return (ft_print_result("error: client_nb < 1", "", -1));
	i = 8;
	while (i < ac && i < TEAM_MAX && ft_strcmp(av[i], "-c"))
	{
		if (ft_strlen(av[i]) >= BUF_SIZE)
			return (ft_print_result("error: team_name too long", "", -1));
		ft_strcpy(e->team_name[i - 8], av[i]);
		i++;
	}
	if (i + 4 > ac || ft_strcmp(av[i + 2], "-t"))
		return (ft_print_result(NULL, av[0], -1));
	e->time = ft_atoi(av[i + 3]);
	if (e->time < 1)
		return (ft_print_result("error: time < 1", "", -1));
	return (0);
}

int			ft_lexer(int ac, char **av, t_env *e)
{
	int		i;

	if (ac < 13)
		return (ft_print_result(NULL, av[0], -1));
	if (ft_strcmp(av[1], "-p"))
		return (ft_print_result(NULL, av[0], -1));
	e->port = av[2];
	if (ft_strcmp(av[3], "-x"))
		return (ft_print_result(NULL, av[0], -1));
	e->width = ft_atoi(av[4]);
	if (ft_strcmp(av[5], "-y"))
		return (ft_print_result(NULL, av[0], -1));
	e->height = ft_atoi(av[6]);
	if (ft_strcmp(av[7], "-n"))
		return (ft_print_result(NULL, av[0], -1));
	i = 8;
	while (i < ac - 1 && ft_strcmp(av[i], "-c"))
		i++;
	if (i == ac - 1)
		return (ft_print_result(NULL, av[0], -1));
	e->client_nb[0] = ft_atoi(av[i + 1]);
	i = 0;
	while (++i < TEAM_MAX)
		e->client_nb[i] = e->client_nb[0];
	return (ft_team(ac, av, e));
}
