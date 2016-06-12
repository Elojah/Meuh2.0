/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_char_type_64.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 17:32:24 by hdezier           #+#    #+#             */
/*   Updated: 2016/06/12 18:00:14 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"
#include <mach-o/nlist.h>
#include <mach-o/loader.h>

static char						to_case(const char c, int upper)
{
	if (upper && c >= 'a' && c <= 'z')
		return (c + ('A' - 'a'));
	else if (!upper && c >= 'A' && c <= 'Z')
		return (c + ('a' - 'A'));
	return (c);
}

static char						ft_getchar(const void *offset, const uint32_t n)
{
	struct segment_command_64	*seg_cmd;
	struct section_64			*sect;
	uint32_t					i;

	seg_cmd = (struct segment_command_64 *)offset;
	offset = (void *)offset + sizeof(struct segment_command_64);
	i = 0;
	while (++i < seg_cmd->nsects + 1)
	{
		sect = (struct section_64 *)offset;
		if (i == n)
			return (type_to_char(sect->sectname));
		offset = (void *)offset + sizeof(struct section_64);
	}
	return (0);
}

static char						get_section(uint32_t n, const char *file)
{
	struct mach_header_64		*header;
	struct segment_command_64	*seg_cmd;
	void						*offset;
	char						tmp;
	int							ncmds;

	header = (struct mach_header_64 *)file;
	offset = (void *)file + sizeof(struct mach_header_64);
	ncmds = header->ncmds;
	while (ncmds-- > 0 && n > 0)
	{
		seg_cmd = (struct segment_command_64 *)offset;
		if (seg_cmd->cmd != LC_SEGMENT_64)
			return (' ');
		tmp = ft_getchar(offset, n);
		if (tmp != 0)
			return (tmp);
		n -= seg_cmd->nsects;
		offset = (void *)offset + seg_cmd->cmdsize;
	}
	return (' ');
}

char							get_char_type_64(const t_nlist_64 *nlst
	, const char *file)
{
	char						result;
	char						type;

	if ((nlst->n_type & N_STAB) != 0)
		return ('-');
	type = nlst->n_type & N_TYPE;
	result = ' ';
	if (type == N_UNDF && (nlst->n_type & N_EXT) != 0 && nlst->n_value != 0)
		result = 'C';
	else if (type == N_UNDF)
		result = 'U';
	else if (type == N_ABS)
		result = 'A';
	else if (type == N_SECT)
		result = get_section(nlst->n_sect, file);
	else if (type == N_INDR)
		result = 'I';
	return (to_case(result, (nlst->n_type & N_EXT) != 0));
}
