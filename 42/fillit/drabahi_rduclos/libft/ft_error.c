/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 17:14:50 by rduclos           #+#    #+#             */
/*   Updated: 2017/02/20 17:14:57 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			error(int ret, char *error)
{
	ft_putstr_fd("Error: ", 2);
	if (error)
		ft_putstr_fd(error, 2);
	return (ret);
}
