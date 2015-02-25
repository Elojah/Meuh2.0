/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_no_roption.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 17:21:54 by erobert           #+#    #+#             */
/*   Updated: 2015/02/25 14:03:18 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_no_roption(char *dir, int *arg)
{
	DIR	*dirp;

	if ((dirp = opendir(dir)) == 0)
	{
		ft_putendl(dir);
		return (1);
	}
	ft_printdir(dirp, dir, arg);
	closedir(dirp);
	return (0);
}
