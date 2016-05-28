/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_char_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 17:32:24 by hdezier           #+#    #+#             */
/*   Updated: 2016/05/28 20:39:27 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"
#include <mach-o/nlist.h>
#include <mach-o/loader.h>

static char						ft_getchar(void *cursor, uint8_t n)
{
	struct segment_command_64	*seg_cmd;
	struct section_64			*sect;
	uint8_t						i;

	seg_cmd = (struct segment_command_64 *)cursor;
	cursor += sizeof(*seg_cmd);
	i = 0;
	while (++i <= seg_cmd->nsects)
	{
		printf("i=%d, n = %d\n", (int)i, (int)n);
		sect = (struct section_64 *)cursor;
		if (i == n)
		{
			printf("%s\n", sect->sectname);
			return (sect->sectname[2]);
		}
		cursor += sect->size;
	}
	return (' ');
}

static char						get_section(uint8_t n, const char *file)
{
	struct mach_header_64		*header;
	struct segment_command_64	*seg_cmd;
	void						*cursor;
	char						tmp;
	int							i;

	header = (struct mach_header_64 *)file;
	cursor = (void *)file + sizeof(*header);
	i = header->ncmds;
	while (i-- > 0 && n > 0)
	{
		seg_cmd = (struct segment_command_64 *)file;
		if (seg_cmd->cmd != LC_SEGMENT_64)
			return ('U');
		tmp = ft_getchar(cursor, n);
		if (tmp != ' ')
			return (tmp);
		n -= seg_cmd->nsects;
		file += seg_cmd->cmdsize;
	}
	return ('U');
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
	char	n_type;

	result = 'U';
	if (nlst->n_type & N_PEXT)
		return ('u');
	else if ((nlst->n_type & N_STAB) != 0)
		return('-');
	n_type = nlst->n_type & N_TYPE;
	printf("\nntype:%d\n", nlst->n_type);
	if (n_type == N_UNDF)
		result = 'U';
	else if (n_type == N_ABS)
		result = 'A';
	else if (n_type == N_SECT)
		result = get_section(nlst->n_sect, file);
	else if (n_type == N_INDR)
		result = 'I';
	if ((nlst->n_type & N_EXT) == 0)
		result = to_lowercase(result);
	return (result);
}
