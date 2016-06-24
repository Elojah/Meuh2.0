/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_32.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 06:16:32 by hdezier           #+#    #+#             */
/*   Updated: 2016/06/24 16:36:35 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"
#include <stdlib.h>
#include <mach-o/loader.h>

static void				ft_putstr(const char *s)
{
	unsigned int		i;

	i = 0;
	while (s[i++] != '\0')
		;
	write(1, s, i - 1);
}

static int					ft_strcmp(const char *s1, const char *s2)
{
	unsigned int			i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		++i;
	return (s1[i] - s2[i]);
}

static void					print_segment_32(const struct segment_command *seg
	, const char *file, const char *filename)
{
	uint32_t			i;
	struct section	*section;

	if (ft_strcmp(seg->segname, SEG_TEXT) != 0)
		return ;
	i = 0;
	section = (void *)seg + sizeof(struct segment_command);
	while (i < seg->nsects)
	{
		if (ft_strcmp(section->sectname, SECT_TEXT) == 0)
		{
			ft_putstr(filename);
			write(1, ":\n(__TEXT,__text) section\n", 26);
			print_section_32(section, file);
		}
		section = (void *)section + sizeof(struct section);
		++i;
	}
}

t_err						otool_32(const char *file, const char *filename)
{
	int						ncmds;
	int						i;
	struct mach_header	*header;
	struct load_command		*lc;
	struct segment_command	*seg;

	header = (struct mach_header *)file;
	ncmds = header->ncmds;
	i = -1;
	lc = (struct load_command *)(file + sizeof(struct mach_header));
	while (++i < ncmds)
	{
		if (lc->cmd == LC_SEGMENT)
		{
			seg = (struct segment_command *)lc;
			print_segment_32(seg, file, filename);
		}
		lc = (void *)lc + lc->cmdsize;
	}
	return (NONE);
}
