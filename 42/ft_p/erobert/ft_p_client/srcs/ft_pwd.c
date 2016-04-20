/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/14 15:17:01 by erobert           #+#    #+#             */
/*   Updated: 2014/05/14 16:43:20 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int				ft_pwd(int sock)
{
	t_request	req;

	req.cmd = PWD;
	write(sock, &req, sizeof(req));
	if (read(sock, &req, sizeof(req)) == -1)
		return (ft_print_result(" read comlink", "", -1));
	ft_putstr_fd(YELLOW, 1);
	ft_putstr_fd(req.av, 1);
	ft_putendl_fd(END, 1);
	ft_print_result(" pwd", "", 1);
	return (0);
}
