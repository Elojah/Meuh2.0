/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_serveur_loop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 15:12:20 by erobert           #+#    #+#             */
/*   Updated: 2014/05/14 18:12:34 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void			ft_serveur_loop(int sock)
{
	t_request	req;
	static char	*pwd = NULL;
	static int	r = 0;

	pwd = ft_strnew(1);
	pwd[0] = '/';
	while (read(sock, &req, sizeof(req)))
	{
		if (req.cmd == QUIT)
			return ;
		if (req.cmd == GET)
			ft_getfile(sock, req.av);
		else if (req.cmd == PUT)
			ft_putfile(sock, req.av);
		else if (req.cmd == PWD)
			ft_pwd(sock, pwd);
		else if (req.cmd == CD)
			r = ft_cd(sock, &pwd, req.av, r);
		else if (req.cmd == LS)
			ft_ls(sock);
	}
}
