/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_arch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 06:59:31 by hdezier           #+#    #+#             */
/*   Updated: 2016/06/24 16:44:05 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

#include <mach-o/ranlib.h>
#include <ar.h>
#include <mach-o/nlist.h>
#include <stdlib.h>


static int				ft_strcmp(const char *s1, const char *s2)
{
	unsigned int		i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		++i;
	return (s1[i] - s2[i]);
}

static int				is_duplicate(const struct ar_hdr *lhs
	, const struct ar_hdr *rhs)
{
	return (ft_strcmp(get_header_name(lhs), get_header_name(rhs)));
}

static t_err			read_symbols(const char *file, const char *offset
	, const char *filename, uint32_t n_sym)
{
	struct ar_hdr		*header;
	struct ranlib		*ranlib;
	uint32_t			i;
	uint32_t			*sorted_index;
	char				*sym_offset;

	sorted_index = sort_ranlib(offset, n_sym);
	i = 0;
	while (i < n_sym)
	{
		ranlib = RANLIB_I(offset, sorted_index, i);
		header = (void *)file + ranlib->ran_off;
		if (i == 0 || is_duplicate(header
			, (void *)file
			+ RANLIB_I(offset, sorted_index, i - 1)->ran_off) != 0)
		{
			sym_offset = (void *)header + sizeof(struct ar_hdr)
				+ print_header(header, filename, 1);
			otool(sym_offset, filename);
		}
		++i;
	}
	if (sorted_index != NULL)
		free(sorted_index);
	return (NONE);
}

t_err					otool_arch(const char *file, const char *filename)
{
	const struct ar_hdr	*header;
	char				*offset;
	uint32_t			n_sym;

	header = (void *)file + SARMAG;
	offset = (void *)header + sizeof(struct ar_hdr)
		+ print_header(header, filename, 0);
	n_sym = *(uint32_t *)offset / sizeof(struct ranlib);
	offset = (void *)offset + sizeof(uint32_t);
	return (read_symbols(file, offset, filename, n_sym));
}
