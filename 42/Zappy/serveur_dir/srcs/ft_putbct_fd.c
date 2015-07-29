/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbct_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 11:34:45 by erobert           #+#    #+#             */
/*   Updated: 2014/06/23 11:35:04 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void	ft_putbct_fd(t_env *e, int x, int y, int sock)
{
	int	i;
	int	j;

	i = -1;
	if (x == -1 && y == -1)
	{
		while (++i < e->width)
		{
			j = -1;
			while (++j < e->height)
				ft_putbct_fd(e, i, j, sock);
		}
		return ;
	}
	ft_putstr_fd("bct ", sock);
	ft_putnbr_fd(x, sock);
	ft_putstr_fd(" ", sock);
	ft_putnbr_fd(y, sock);
	while (++i < 7)
	{
		ft_putstr_fd(" ", sock);
		ft_putnbr_fd(e->trantor[x][y].resource[i], sock);
	}
	ft_putendl_fd("", sock);
}
