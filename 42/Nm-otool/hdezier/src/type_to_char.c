/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_to_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 03:26:32 by hdezier           #+#    #+#             */
/*   Updated: 2016/06/08 04:26:30 by hdezier          ###   ########.fr       */
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

/*
** U (undefined), A (absolute), T (text section symbol), D (data section symbol), B (bss
** section symbol), C (common symbol), - (for debugger symbol table entries; see -a below), S (symbol in a section other than those  above),
** or I (indirect symbol)
*/
char		type_to_char(const char *type)
{
	// printf("type identified:[%s]\n", type);
	if (ft_strcmp(type, "__text") == 0)
		return ('t');
	else if (ft_strcmp(type, "__data") == 0)
		return ('d');
	else if (ft_strcmp(type, "__bss") == 0)
		return ('b');
	return ('s');
}
