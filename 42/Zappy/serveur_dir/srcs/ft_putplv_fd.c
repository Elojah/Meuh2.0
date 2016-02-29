/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putplv_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/22 18:01:52 by erobert           #+#    #+#             */
/*   Updated: 2014/06/26 17:56:25 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void	ft_putplv_fd(t_env *e, int psock, int gsock)
{
	if (psock < 0 || psock >= e->mfds || e->fds[psock].type != PLAYER)
		return ;
	ft_putstr_fd("plv ", gsock);
	ft_putnbr_fd(psock, gsock);
	ft_putstr_fd(" ", gsock);
	ft_putendl_fd(&e->fds[psock].level, gsock);
}
