/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_64.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 06:16:32 by hdezier           #+#    #+#             */
/*   Updated: 2016/06/23 16:22:56 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"
#include <stdlib.h>
#include <mach-o/loader.h>

static int					ft_strcmp(const char *s1, const char *s2)
{
	unsigned int			i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		++i;
	return (s1[i] - s2[i]);
}

static void					print_table(const struct segment_command_64 *seg
	, const char *file, const char *filename)
{
	if (ft_strcmp(seg->segname, SEG_TEXT) != 0)
		return ;
	print_segment_64(seg, file, filename);
}

t_err						otool_64(const char *file, const char *filename)
{
	int						ncmds;
	int						i;
	struct mach_header_64	*header;
	struct load_command		*lc;
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
			print_table(seg, file, filename);
		}
		lc = (void *)lc + lc->cmdsize;
	}
	return (NONE);
}
