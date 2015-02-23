/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tty.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 13:24:25 by erobert           #+#    #+#             */
/*   Updated: 2015/02/23 12:59:47 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "ft_minishell1.h"

int				ft_tty(void)
{
	static int	fd = 0;

	if (!fd)
		fd = open("/dev/tty", O_RDWR);
	return (fd);
}
