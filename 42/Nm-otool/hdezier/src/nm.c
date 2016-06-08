/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 16:49:04 by hdezier           #+#    #+#             */
/*   Updated: 2016/06/08 07:21:15 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

#include <mach-o/nlist.h>
#include <mach-o/loader.h>
#include <mach-o/fat.h>
#include <ar.h>

static int		ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]
		&& i < n)
		i++;
	if (i == n)
		return (0);
	return (s1[i] - s2[i]);
}


t_err						nm(const char *file)
{
	unsigned int			magic_number;

	magic_number = *((unsigned int *)file);
	if (magic_number == MH_MAGIC_64 || magic_number == MH_CIGAM_64)
		return (nm_64(file));
	if (magic_number == MH_MAGIC || magic_number == MH_CIGAM)
		return (nm_32(file));
	else if (magic_number == FAT_MAGIC || magic_number == FAT_CIGAM)
		return (nm_fat(file, magic_number));
	else if (ft_strncmp(file, ARMAG, SARMAG) == 0)
		return (nm_arch(file));
	return (ERR_ARCHITECTURE_NOT_FOUND);
}
