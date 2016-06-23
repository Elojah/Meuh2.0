/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 16:49:04 by hdezier           #+#    #+#             */
/*   Updated: 2016/06/23 16:21:39 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

#include <mach-o/nlist.h>
#include <mach-o/loader.h>
#include <mach-o/fat.h>
#include <ar.h>

#include <unistd.h>

static int					ft_strncmp(const char *s1, const char *s2
	, unsigned int n)
{
	unsigned int			i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]
		&& i < n)
		i++;
	if (i == n)
		return (0);
	return (s1[i] - s2[i]);
}

t_err						otool(const char *file, const char *filename)
{
	unsigned int			magic_number;

	magic_number = *((unsigned int *)file);
	if (ft_strncmp(file, ARMAG, SARMAG) == 0)
		return (otool_arch(file, filename));
	else if (magic_number == MH_MAGIC_64 || magic_number == MH_CIGAM_64)
		return (otool_64(file, filename));
	else if (magic_number == MH_MAGIC || magic_number == MH_CIGAM)
		return (otool_32(file, filename));
	else if (magic_number == FAT_MAGIC || magic_number == FAT_CIGAM)
		return (otool_fat(file, filename, magic_number));
	return (ERR_ARCHITECTURE_NOT_FOUND);
}
