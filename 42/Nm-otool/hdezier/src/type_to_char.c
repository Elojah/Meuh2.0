/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_to_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 03:26:32 by hdezier           #+#    #+#             */
/*   Updated: 2016/06/12 17:46:41 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

static int			ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

char				type_to_char(const char *type)
{
	if (ft_strcmp(type, "__text") == 0)
		return ('t');
	else if (ft_strcmp(type, "__data") == 0)
		return ('d');
	else if (ft_strcmp(type, "__bss") == 0)
		return ('b');
	return ('s');
}
