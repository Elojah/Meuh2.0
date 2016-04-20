/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/14 13:48:43 by erobert           #+#    #+#             */
/*   Updated: 2014/05/14 14:12:39 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include "serveur.h"

int					ft_ls(int sock)
{
	DIR				*dirp;
	struct dirent	*dp;
	t_request		req;

	dirp = opendir(".");
	if (!dirp)
		return (-1);
	req.cmd = LS;
	dp = readdir(dirp);
	while (dp)
	{
		if (dp->d_name[0] != '.')
		{
			ft_strcpy(req.av, dp->d_name);
			write(sock, &req, sizeof(req));
		}
		dp = readdir(dirp);
	}
	req.cmd = 0;
	write(sock, &req, sizeof(req));
	return (0);
}
