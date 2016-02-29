/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpin_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/22 17:43:59 by erobert           #+#    #+#             */
/*   Updated: 2014/06/22 18:08:47 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void		ft_putpin_fd(t_env *e, int psock, int gsock)
{
	int		i;

	if (psock < 0 || psock >= e->mfds || e->fds[psock].type != PLAYER)
		return ;
	ft_putstr_fd("pin ", gsock);
	ft_putnbr_fd(psock, gsock);
	ft_putstr_fd(" ", gsock);
	ft_putnbr_fd(e->fds[psock].pos[0], gsock);
	ft_putstr_fd(" ", gsock);
	ft_putnbr_fd(e->fds[psock].pos[1], gsock);
	i = -1;
	while (++i < 7)
	{
		ft_putstr_fd(" ", gsock);
		ft_putnbr_fd(e->fds[psock].resource[i], gsock);
	}
	ft_putendl_fd("", gsock);
}
