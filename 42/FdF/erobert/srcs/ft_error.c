/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 19:21:15 by erobert           #+#    #+#             */
/*   Updated: 2015/01/20 19:28:13 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_error(char const *s, int i)
{
	if (!s)
		return (-1);
	write(2, s, ft_strlen(s));
	write(2, "\n", 1);
	return (i);
}