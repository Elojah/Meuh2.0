/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putenw_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/22 16:02:37 by erobert           #+#    #+#             */
/*   Updated: 2014/06/22 16:04:25 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void	ft_putenw_fd(t_env *e, int psock, int gsock)
{
	ft_putstr_fd("enw ", gsock);
	ft_putnbr_fd(psock, gsock);
	ft_putstr_fd(" ", gsock);
	ft_putnbr_fd(psock, gsock);
	ft_putstr_fd(" ", gsock);
	ft_putnbr_fd(e->fds[psock].pos[0], gsock);
	ft_putstr_fd(" ", gsock);
	ft_putnbr_fd(e->fds[psock].pos[1], gsock);
	ft_putendl_fd("", gsock);
}
