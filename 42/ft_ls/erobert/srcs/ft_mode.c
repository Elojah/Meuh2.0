/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/09 13:17:14 by erobert           #+#    #+#             */
/*   Updated: 2015/02/25 13:40:14 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include "ft_ls.h"

static void	ft_rights(int st_mode, char *mode)
{
	if (!(st_mode & 64) && (st_mode & 2048))
		mode[3] = 'S';
	if (st_mode & 64)
		mode[3] = (st_mode & 2048 ? 's' : 'x');
	mode[2] = (st_mode & 128 ? 'w' : '-');
	mode[1] = (st_mode & 256 ? 'r' : '-');
	if (!(st_mode & 8) && (st_mode & 1024))
		mode[6] = 'S';
	if (st_mode & 8)
		mode[6] = (st_mode & 1024 ? 's' : 'x');
	mode[5] = (st_mode & 16 ? 'w' : '-');
	mode[4] = (st_mode & 32 ? 'r' : '-');
	if (!(st_mode & 1) && (st_mode & 512))
		mode[9] = 'T';
	if (st_mode & 1)
		mode[9] = (st_mode & 512 ? 't' : 'x');
	mode[8] = (st_mode & 2 ? 'w' : '-');
	mode[7] = (st_mode & 4 ? 'r' : '-');
}

char		*ft_mode(int st_mode)
{
	char	*mode;
	int		i;

	mode = ft_strnew(11);
	i = 0;
	while (i < 10)
		mode[i++] = '-';
	mode[i] = ' ';
	if (S_ISSOCK(st_mode))
		mode[0] = 's';
	if (S_ISLNK(st_mode))
		mode[0] = 'l';
	if (S_ISREG(st_mode))
		mode[0] = '-';
	if (S_ISBLK(st_mode))
		mode[0] = 'b';
	if (S_ISDIR(st_mode))
		mode[0] = 'd';
	if (S_ISCHR(st_mode))
		mode[0] = 'c';
	if (S_ISFIFO(st_mode))
		mode[0] = 'p';
	ft_rights(st_mode, mode);
	return (mode);
}
