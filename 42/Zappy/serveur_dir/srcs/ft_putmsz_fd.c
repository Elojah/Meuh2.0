/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmsz_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/22 15:46:49 by erobert           #+#    #+#             */
/*   Updated: 2014/06/22 15:49:03 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void	ft_putmsz_fd(t_env *e, int sock)
{
	ft_putstr_fd("msz ", sock);
	ft_putnbr_fd(e->width, sock);
	ft_putstr_fd(" ", sock);
	ft_putnbr_fd(e->height, sock);
	ft_putendl_fd("", sock);
}
