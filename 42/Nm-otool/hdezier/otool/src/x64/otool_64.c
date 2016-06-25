/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_64.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 06:16:32 by hdezier           #+#    #+#             */
/*   Updated: 2016/06/25 16:21:41 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"
#include <stdlib.h>
#include <unistd.h>
#include <mach-o/loader.h>

static void				ft_putstr(const char *s)
{
	unsigned int		i;

	i = 0;
	while (s[i++] != '\0')
		;
	write(1, s, i - 1);
}

static int				ft_strcmp(const char *s1, const char *s2)
{
	unsigned int		i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		++i;
	return (s1[i] - s2[i]);
}

static void				print_segment_64(const struct segment_command_64 *seg
	, const char *file, const char *filename)
{
	uint32_t			i;
	struct section_64	*section;

	i = 0;
	section = (void *)seg + sizeof(struct segment_command_64);
	while (i < seg->nsects)
	{
		if (ft_strcmp(section->sectname, SECT_TEXT) == 0)
		{
			if (filename != NULL)
			{
				ft_putstr(filename);
				write(1, ":\n", 2);
			}
			write(1, "(__TEXT,__text) section\n", 24);
			print_section_64(section, file);
		}
		section = (void *)section + sizeof(struct section_64);
		++i;
	}
}

t_err					otool_64(const char *file, const char *filename)
{
	int							ncmds;
	int							i;
	struct mach_header_64		*header;
	struct load_command			*lc;
	struct segment_command_64	*seg;

	header = (struct mach_header_64 *)file;
	ncmds = header->ncmds;
	i = -1;
	lc = (struct load_command *)(file + sizeof(struct mach_header_64));
	while (++i < ncmds)
	{
		if (lc->cmd == LC_SEGMENT_64)
		{
			seg = (struct segment_command_64 *)lc;
			print_segment_64(seg, file, filename);
		}
		lc = (void *)lc + lc->cmdsize;
	}
	return (NONE);
}
