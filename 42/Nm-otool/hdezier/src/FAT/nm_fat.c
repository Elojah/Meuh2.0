/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_fat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 06:16:25 by hdezier           #+#    #+#             */
/*   Updated: 2016/06/08 07:10:04 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"
#include <mach-o/fat.h>

static uint32_t				reverse_uint32(const uint32_t n)
{
	unsigned char	in_byte_0;
	unsigned char	in_byte_1;
	unsigned char	in_byte_2;
	unsigned char	in_byte_3;

	in_byte_0 = (n & 0xFF);
	in_byte_1 = (n & 0xFF00) >> 8;
	in_byte_2 = (n & 0xFF0000) >> 16;
	in_byte_3 = (n & 0xFF000000) >> 24;
	return ((in_byte_0) << 24) | ((in_byte_1) << 16)
	| ((in_byte_2) << 8) | ((in_byte_3));
}

t_err						nm_fat(const char *file, unsigned int magic_number)
{
	struct fat_header		*header;
	struct fat_arch			*arch;
	unsigned int			i;
	uint32_t				cputype;
	uint32_t				nfat_arch;

	header = (struct fat_header *)file;
	arch = (void *)file + sizeof(struct fat_header);
	i = 0;
	if (magic_number == FAT_MAGIC)
		nfat_arch = header->nfat_arch;
	else
		nfat_arch = reverse_uint32(header->nfat_arch);
	while (i < nfat_arch)
	{
		if (magic_number == FAT_MAGIC)
			cputype = arch->cputype;
		else
			cputype = reverse_uint32(arch->cputype);
		if (cputype == CPU_TYPE_X86_64)
		{
			if (magic_number == FAT_MAGIC)
				return (nm_64((void *)file + arch->offset));
			else
				return (nm_64((void *)file + reverse_uint32(arch->offset)));
		}
		else if (cputype == CPU_TYPE_X86)
		{
			if (magic_number == FAT_MAGIC)
				return (nm_32((void *)file + arch->offset));
			else
				return (nm_32((void *)file + reverse_uint32(arch->offset)));
		}
		arch = (void *)arch + sizeof(struct fat_arch);
		++i;
	}
	return (ERR_ARCHITECTURE_UNRECOGNIZED_IN_FAT);
}
