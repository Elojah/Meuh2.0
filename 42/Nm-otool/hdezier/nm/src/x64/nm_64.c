/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_64.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 06:16:32 by hdezier           #+#    #+#             */
/*   Updated: 2016/06/12 15:33:58 by hdezier          ###   ########.fr       */
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
	sorted_index = sort_index_nlst_64(nlst, nsyms, stringtable);
	i = -1;
	while (++i < nsyms)
		print_nlst_64(nlst + sorted_index[i]
			, stringtable, file);
	free(sorted_index);
}

t_err						nm_64(const char *file)
{
	int						ncmds;
	int						i;
	struct mach_header_64	*header;
	struct load_command		*lc;
	struct symtab_command	*sym;

	header = (struct mach_header_64 *)file;
	ncmds = header->ncmds;
	i = -1;
	lc = (struct load_command *)(file + sizeof(struct mach_header_64));
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
