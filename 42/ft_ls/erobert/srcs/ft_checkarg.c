/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkarg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/09 18:34:46 by erobert           #+#    #+#             */
/*   Updated: 2015/02/25 14:50:19 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_ls.h"

char		ft_checkarg(char *av, int *arg)
{
	int		i;

	i = 1;
	while (av[i])
	{
		if (av[i] == 'G')
			arg[MG] = 1;
		else if (av[i] == 'R')
			arg[MR] = 1;
		else if (av[i] == 'S')
			arg[MS] = 1;
		else if (av[i] == 'a')
			arg[A] = 1;
		else if (av[i] == 'l')
			arg[L] = 1;
		else if (av[i] == 'r')
			arg[R] = 1;
		else if (av[i] == 't')
			arg[T] = 1;
		else
			return (av[i]);
		i++;
	}
	return ('l');
}
