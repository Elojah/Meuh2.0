/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 16:49:04 by hdezier           #+#    #+#             */
/*   Updated: 2016/05/28 20:24:46 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

#include <stdlib.h>
#include <mach-o/nlist.h>
#include <mach-o/loader.h>

static void					print_table(int nsyms, int symoff, int stroff
	, const char *file)
{
	int						i;
	const char				*stringtable;
	const t_nlist_64		*nlst;
	uint32_t				*sorted_index;

	nlst = (t_nlist_64 *)(file + symoff);
	stringtable = file + stroff;
	sorted_index = sort_index_nlst(nlst, nsyms, stringtable);
	i = -1;
	while (++i < nsyms)
		print_nlst(nlst + sorted_index[i]
			, stringtable, file);
	free(sorted_index);
}

static t_err				handle_64(const char *file)
{
	int						ncmds;
	int						i;
	struct mach_header_64	*header;
	struct load_command		*lc;
	struct symtab_command	*sym;

	header = (struct mach_header_64 *)file;
	ncmds = header->ncmds;
	i = -1;
	lc = (struct load_command *)(file + sizeof(*header));
	while (++i < ncmds)
	{
		if (lc->cmd == LC_SYMTAB)
		{
			sym = (struct symtab_command *)lc;
			print_table(sym->nsyms, sym->symoff, sym->stroff, file);
		}
		lc = (void *)lc + lc->cmdsize;
	}
	return (NONE);
}

t_err						nm(const char *file)
{
	unsigned int			magic_number;
	struct segment_command_64 a;(void)a;
	struct section_64 b;(void)b;
	struct nlist_64 c;(void)c;

	magic_number = *((unsigned int *)file);
	if (magic_number == MH_MAGIC_64)
		return (handle_64(file));
	return (ERR_ARCHITECTURE_NOT_FOUND);
}
