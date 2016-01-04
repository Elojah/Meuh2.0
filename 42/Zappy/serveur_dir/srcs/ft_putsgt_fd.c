/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsgt_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/22 15:54:08 by erobert           #+#    #+#             */
/*   Updated: 2014/06/22 15:54:53 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void	ft_putsgt_fd(t_env *e, int sock)
{
	ft_putstr_fd("sgt ", sock);
	ft_putnbr_fd(e->time, sock);
	ft_putendl_fd("", sock);
}
