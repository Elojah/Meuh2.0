/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_char_type_32.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 17:32:24 by hdezier           #+#    #+#             */
/*   Updated: 2016/06/08 06:36:23 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"
#include <mach-o/nlist.h>
#include <mach-o/loader.h>

static char	to_case(const char c, int upper)
{
	if (upper && c >= 'a' && c <= 'z')
		return (c + ('A' - 'a'));
	else if (!upper && c >= 'A' && c <= 'Z')
		return (c + ('a' - 'A'));
	return (c);
}

static char						ft_getchar(const void *offset, const uint32_t n)
{
	struct segment_command		*seg_cmd;
	struct section				*sect;
	uint32_t					i;

	seg_cmd = (struct segment_command *)offset;
	offset = (void *)offset + sizeof(struct segment_command);
	i = 0;
	while (++i < seg_cmd->nsects + 1)
	{
		sect = (struct section *)offset;
		if (i == n)
			return (type_to_char(sect->sectname));
		offset = (void *)offset + sizeof(struct section);
	}
	return (0);
}

static char						get_section(uint32_t n, const char *file)
{
	struct mach_header			*header;
	struct segment_command		*seg_cmd;
	void						*offset;
	char						tmp;
	int							ncmds;

	header = (struct mach_header *)file;
	offset = (void *)file + sizeof(struct mach_header);
	ncmds = header->ncmds;
	while (ncmds-- > 0 && n > 0)
	{
		seg_cmd = (struct segment_command *)offset;
		if (seg_cmd->cmd != LC_SEGMENT)
			return (' ');
		tmp = ft_getchar(offset, n);
		if (tmp != 0)
			return (tmp);
		n -= seg_cmd->nsects;
		offset = (void *)offset + seg_cmd->cmdsize;
	}
	return (' ');
}

/*
** U (undefined), A (absolute), T (text section symbol), D (data section symbol), B (bss
** section symbol), C (common symbol), - (for debugger symbol table entries; see -a below), S (symbol in a section other than those  above),
** or I (indirect symbol)
*/
char		get_char_type_32(const t_nlist_32 *nlst, const char *file)
{
	char	result;
	char	type;

	if ((nlst->n_type & N_STAB) != 0)
		return('-');
	type = nlst->n_type & N_TYPE;
	result = ' ';
	if (type == N_UNDF)
		result = 'U';
	else if (type == N_ABS)
		result = 'A';
	else if (type == N_SECT)
		result = get_section(nlst->n_sect, file);
	else if (type == N_INDR)
		result = 'I';
	return (to_case(result, (nlst->n_type & N_EXT) != 0));
}
