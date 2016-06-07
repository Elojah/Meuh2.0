/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_char_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 17:32:24 by hdezier           #+#    #+#             */
/*   Updated: 2016/06/07 09:20:54 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"
#include <mach-o/nlist.h>
#include <mach-o/loader.h>

#include <unistd.h>

static char						ft_getchar(const void *offset, const uint32_t n)
{
	struct segment_command_64	*seg_cmd;
	struct section_64			*sect;
	uint32_t						i;

	seg_cmd = (struct segment_command_64 *)offset;
	offset = (void *)offset + sizeof(seg_cmd);
	i = 0;
	while (++i <= seg_cmd->nsects)
	{
		sect = (struct section_64 *)offset;
		printf("sectname:%s\n", sect->sectname);
		if (i == n)
		{
			if (sect->sectname[2] == 0)
				return ('s');
			return (sect->sectname[2]);
		}
		offset = (void *)offset + sect->size;
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
	offset = (void *)file + sizeof(*header);
	seg_cmd = (struct segment_command_64 *)offset;
	offset = (void *)offset + seg_cmd->cmdsize;
	ncmds = header->ncmds;
	while (ncmds-- > 0 && n > 0)
	{
		seg_cmd = (struct segment_command_64 *)offset;
		// printf("ncmds:%d\n", seg_cmd->cmd);
		if (seg_cmd->cmd != LC_SEGMENT_64)// && seg_cmd->cmd != LC_VERSION_MIN_MACOSX)
			return (' ');
		tmp = ft_getchar(offset, n);
		if (tmp != 0)
			return (tmp);
		n -= seg_cmd->nsects;
		offset = (void *)offset + seg_cmd->cmdsize;
	}
	return (' ');
}

static char	to_lowercase(const char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + ('a' - 'A'));
	return (c);
}

/*
** U (undefined), A (absolute), T (text section symbol), D (data section symbol), B (bss
** section symbol), C (common symbol), - (for debugger symbol table entries; see -a below), S (symbol in a section other than those  above),
** or I (indirect symbol)
*/
char		get_char_type(const t_nlist_64 *nlst, const char *file)
{
	char	result;

	result = 'U';
	if ((nlst->n_type & N_TYPE) == N_PEXT)
		return ('u');
	else if (((nlst->n_type & N_TYPE) == N_STAB) != 0)
		return('-');
	if ((nlst->n_type & N_TYPE) == N_UNDF)
		result = 'U';
	else if ((nlst->n_type & N_TYPE) == N_ABS)
		result = 'A';
	else if ((nlst->n_type & N_TYPE) == N_SECT)
		result = get_section(nlst->n_sect, file);
	else if ((nlst->n_type & N_TYPE) == N_INDR)
		result = 'I';
	if ((nlst->n_type & N_TYPE) == N_EXT)
		result = to_lowercase(result);
	return (result);
}
