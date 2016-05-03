/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/14 15:16:20 by erobert           #+#    #+#             */
/*   Updated: 2014/05/14 15:25:40 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

int				ft_pwd(int sock, char *pwd)
{
	t_request	req;

	req.cmd = PWD;
	ft_strcpy(req.av, pwd);
	write(sock, &req, sizeof(req));
	return (0);
}
