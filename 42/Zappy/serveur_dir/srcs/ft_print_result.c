/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_result.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 15:16:51 by erobert           #+#    #+#             */
/*   Updated: 2015/06/09 15:34:32 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

static int	ft_usage(char *str, int res)
{
	ft_putstr_fd("usage: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(" -p <port> -x <width> -y <height> -n <team> [<team>]", 2);
	ft_putendl_fd(" [<team>] ... -c <nb> -t <t>", 2);
	ft_putendl_fd(" -p numero de port", 2);
	ft_putendl_fd(" -x largeur du Monde", 2);
	ft_putendl_fd(" -y hauteur du Monde", 2);
	ft_putendl_fd(" -n nom_equipe_1 nom_equipe_2 ...", 2);
	ft_putendl_fd(" -c nombre de client autorises au commencement du jeu", 2);
	ft_putstr_fd(" -t diviseur de l'unite de temps (plus t est grand,", 2);
	ft_putendl_fd(" plus le jeu va vite)", 2);
	return (res);
}

int			ft_print_result(char *s1, char *s2, int res)
{
	if (!s1)
		return (ft_usage(s2, res));
	ft_putstr_fd(s1, 2);
	ft_putendl_fd(s2, 2);
	return (res);
}
