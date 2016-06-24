/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_fat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 06:16:25 by hdezier           #+#    #+#             */
/*   Updated: 2016/06/24 17:15:20 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"
#include <mach-o/fat.h>

static uint32_t				reverse_uint32(const uint32_t n)
{
	unsigned char			in_byte_0;
	unsigned char			in_byte_1;
	unsigned char			in_byte_2;
	unsigned char			in_byte_3;

	in_byte_0 = (n & 0xFF);
	in_byte_1 = (n & 0xFF00) >> 8;
	in_byte_2 = (n & 0xFF0000) >> 16;
	in_byte_3 = (n & 0xFF000000) >> 24;
	return ((in_byte_0) << 24) | ((in_byte_1) << 16)
	| ((in_byte_2) << 8) | ((in_byte_3));
}

static int					launch_otool(const char *file, const char *filename
	, unsigned int magic_number, struct fat_arch *arch)
{
	cpu_subtype_t			cputype;

	if (magic_number == FAT_MAGIC)
		cputype = arch->cputype;
	else
		cputype = reverse_uint32(arch->cputype);
	if (cputype == CPU_TYPE_X86_64)
	{
		if (magic_number == FAT_MAGIC)
			otool((void *)file + arch->offset, filename);
		else
			otool((void *)file + reverse_uint32(arch->offset), filename);
	}
	else
		return (0);
	return (1);
}

t_err						otool_fat(const char *file, const char *filename
	, unsigned int magic_number)
{
	struct fat_header		*header;
	struct fat_arch			*arch;
	unsigned int			i;
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
		if (launch_otool(file, filename, magic_number, arch) == 1)
			return (NONE);
		arch = (void *)arch + sizeof(struct fat_arch);
		++i;
	}
	return (ERR_ARCHITECTURE_UNRECOGNIZED_IN_FAT);
}
