/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/03 17:18:41 by erobert           #+#    #+#             */
/*   Updated: 2014/06/10 16:19:44 by jchichep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int			ft_lexer(int ac, char **av, t_env *e)
{
	if (ac < 5)
		return (ft_print_result(NULL, av[0], -1));
	if (ft_strcmp(av[1], "-n"))
		return (ft_print_result(NULL, av[0], -1));
	e->team_name = ft_strdup(av[2]);
	if (ft_strcmp(av[3], "-p"))
		return (ft_print_result(NULL, av[0], -1));
	e->port = av[4];
	if (ac == 7)
	{
		if (ft_strcmp(av[5], "-h"))
			return (ft_print_result(NULL, av[0], -1));
		e->hostname = av[6];
	}
	else
		e->hostname = "localhost";
	return (0);
}
