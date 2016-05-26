/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 16:49:04 by hdezier           #+#    #+#             */
/*   Updated: 2016/05/26 17:36:58 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

#include <unistd.h>
#include <mach-o/nlist.h>
#include <mach-o/loader.h>

static void		ft_putstr_endl(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i++] != '\0')
		;
	write(1, s, i - 1);
	write(1, "\n", 1);
}

static void					print_elem(struct nlist_64 *elem, const char *value)
{
	char					type;

	type = get_char_type(elem->n_type);
	write(1, &type, 1);
	write(1, " ", 1);
	ft_putstr_endl(value);
}

static void					print_table(int nsyms, int symoff, int stroff
	, const char *file)
{
	int						i;
	const char				*stringtable;
	struct nlist_64			*elem;

	elem = (struct nlist_64 *)(file + symoff);
	stringtable = file + stroff;
	i = -1;
	while (++i < nsyms)
		print_elem(elem, stringtable + elem[i].n_un.n_strx);
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

	magic_number = *((unsigned int *)file);
	if (magic_number == MH_MAGIC_64)
		return (handle_64(file));
	return (ERR_ARCHITECTURE_NOT_FOUND);
}
