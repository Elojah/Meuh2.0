/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putppo_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/22 17:57:30 by erobert           #+#    #+#             */
/*   Updated: 2014/06/22 18:08:09 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void	ft_putppo_fd(t_env *e, int psock, int gsock)
{
	if (psock < 0 || psock >= e->mfds || e->fds[psock].type != PLAYER)
		return ;
	ft_putstr_fd("ppo ", gsock);
	ft_putnbr_fd(psock, gsock);
	ft_putstr_fd(" ", gsock);
	ft_putnbr_fd(e->fds[psock].pos[0], gsock);
	ft_putstr_fd(" ", gsock);
	ft_putnbr_fd(e->fds[psock].pos[1], gsock);
	ft_putstr_fd(" ", gsock);
	ft_putnbr_fd(e->fds[psock].dir + 1, gsock);
	ft_putendl_fd("", gsock);
}
