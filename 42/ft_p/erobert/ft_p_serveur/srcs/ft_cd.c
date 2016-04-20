/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/14 15:16:36 by erobert           #+#    #+#             */
/*   Updated: 2014/05/14 18:16:59 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "serveur.h"

static int		ft_goroot(int r)
{
	while (r-- > 0)
	{
		if (chdir("..") == -1)
			return (-1);
	}
	return (r);
}

static void		ft_getpwd(char **pwd, char *path)
{
	char		*new;

	if (!ft_strcmp(path, "/"))
		ft_strcpy(*pwd, path);
	else
	{
		new = ft_strjoin(*pwd, path);
		free(*pwd);
		*pwd = new;
	}
}

static int		ft_chdir(int sock, char **pwd, char *path, int r)
{
	t_request	req;

	req.cmd = CD;
	ft_strcpy(req.av, path);
	if (!ft_strcmp(path, "/"))
	{
		r = ft_goroot(r);
		write(sock, &req, sizeof(req));
	}
	else
	{
		if (chdir(path) == -1)
		{
			req.cmd = 0;
			write(sock, &req, sizeof(req));
			return (r);
		}
		else
		{
			r = (!ft_strcmp(path, "../") ? r - 1 : r + 1);
			write(sock, &req, sizeof(req));
		}
	}
	ft_getpwd(pwd, path);
	return (r);
}

int				ft_cd(int sock, char **pwd, char *path, int r)
{
	t_request	req;

	req.cmd = CD;
	ft_strcpy(req.av, path);
	if (!r && !ft_strcmp(path, "../"))
	{
		req.cmd = 0;
		write(sock, &req, sizeof(req));
		return (r);
	}
	r = ft_chdir(sock, pwd, path, r);
	return (r);
}
