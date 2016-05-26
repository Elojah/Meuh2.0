/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 16:49:04 by hdezier           #+#    #+#             */
/*   Updated: 2016/05/26 17:16:54 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

#include <unistd.h>
#include <mach-o/nlist.h>
#include <mach-o/loader.h>

static void					print_elem(struct nlist_64 *elem, char *value)
{
	char					type;

	if (elem->n_type == N_UNDF)
		type = 'U';
	else if (elem->n_type == N_ABS)
		type = 'A';
	else if (elem->n_type == N_SECT)
		type = 'T';
	else if (elem->n_type == N_PBUD)
		type = 'D';
	else if (elem->n_type == N_INDR)
		type = 'I';
	write(1, &type, 1);
	printf(" %s\n", value);

}

static void					print_table(int nsyms, int symoff, int stroff
	, char *file)
{
	int						i;
	char					*stringtable;
	struct nlist_64			*elem;

	elem = (struct nlist_64 *)(file + symoff);
	stringtable = file + stroff;
	i = -1;
	while (++i < nsyms)
		print_elem(elem, stringtable + elem[i].n_un.n_strx);
}

static t_err				handle_64(char *file)
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

t_err						nm(char *file)
{
	unsigned int			magic_number;

	magic_number = *((unsigned int *)file);
	if (magic_number == MH_MAGIC_64)
		return (handle_64(file));
	return (ERR_ARCHITECTURE_NOT_FOUND);
}
