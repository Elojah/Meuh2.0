/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sock_close.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/22 17:00:59 by erobert           #+#    #+#             */
/*   Updated: 2015/06/12 16:54:31 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void	ft_sock_close(t_env *e, int sock)
{
	close(sock);
	if (e->fds[sock].type == PLAYER)
		e->client_nb[e->fds[sock].team_number]++;
	e->fds[sock].type = 0;
	e->fds[sock].cmd = E_CMD;
	e->fds[sock].fct_read = NULL;
	e->fds[sock].fct_write = NULL;
	ft_putstr("comlink ");
	ft_putnbr(sock);
	ft_putendl(": closed");
}
