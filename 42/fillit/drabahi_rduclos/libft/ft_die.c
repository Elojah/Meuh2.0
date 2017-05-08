/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_die.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:27:18 by rduclos           #+#    #+#             */
/*   Updated: 2017/02/20 17:14:27 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_die(int error, char *where)
{
	if (where)
		ft_putendl_fd(where, 2);
	else
		ft_putstr_fd("\n", 2);
	exit(error);
}
