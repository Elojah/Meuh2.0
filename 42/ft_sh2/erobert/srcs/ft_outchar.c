/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 15:21:22 by erobert           #+#    #+#             */
/*   Updated: 2015/02/23 18:49:19 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "ft_minishell2.h"

int			ft_outchar(int c)
{
	char	alpha;

	alpha = c;
	write(ft_tty(), &alpha, sizeof(char));
	return (c);
}
