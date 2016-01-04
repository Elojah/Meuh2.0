/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpnw_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/22 15:43:44 by erobert           #+#    #+#             */
/*   Updated: 2014/06/22 18:08:17 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void	ft_putpnw_fd(t_env *e, int psock, int gsock)
{
	if (psock < 0 || psock >= e->mfds || e->fds[psock].type != PLAYER)
		return ;
	ft_putstr_fd("pnw ", gsock);
	ft_putnbr_fd(psock, gsock);
	ft_putstr_fd(" ", gsock);
	ft_putnbr_fd(e->fds[psock].pos[0], gsock);
	ft_putstr_fd(" ", gsock);
	ft_putnbr_fd(e->fds[psock].pos[1], gsock);
	ft_putstr_fd(" ", gsock);
	ft_putnbr_fd(e->fds[psock].dir + 1, gsock);
	ft_putstr_fd(" ", gsock);
	ft_putstr_fd(&e->fds[psock].level, gsock);
	ft_putstr_fd(" ", gsock);
	ft_putendl_fd(e->team_name[e->fds[psock].team_number], gsock);
}
