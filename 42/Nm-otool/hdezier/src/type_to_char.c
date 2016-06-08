/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_to_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 03:26:32 by hdezier           #+#    #+#             */
/*   Updated: 2016/06/08 03:34:22 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

static int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

char		type_to_char(const char *type)
{
	// printf("type identified:[%s]\n", type);
	if (ft_strcmp(type, "__text"))
		return ('s');
	else if (ft_strcmp(type, "__cstring"))
		return ('t');
	else if (ft_strcmp(type, "__const"))
		return ('s');
	return (' ');
}
