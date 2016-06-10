/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_arch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 06:59:31 by hdezier           #+#    #+#             */
/*   Updated: 2016/06/10 16:39:32 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

#include <mach-o/ranlib.h>
#include <ar.h>
#include <mach-o/nlist.h>
#include <stdlib.h>
#include <unistd.h>

static int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		++i;
	return (s1[i] - s2[i]);
}

static int				is_duplicate(struct ar_hdr *lhs, struct ar_hdr *rhs)
{
	return (ft_strcmp(lhs->ar_name, rhs->ar_name));
}

static t_err			read_symbols(const char *file, const char *offset
	, const char *filename, uint32_t n_sym)
{
	struct ar_hdr			*header;
	struct ranlib			*ranlib;
	uint32_t				i;
	uint32_t				*sorted_index;
	char					*sym_offset;

	sorted_index = sort_ranlib(offset, n_sym);
	i = 0;
	while (i < n_sym)
	{
		ranlib = RANLIB_I(offset, sorted_index, i);
		header = (void *)file + ranlib->ran_off;
		if (i == 0 || is_duplicate(header
			, (void *)file + RANLIB_I(offset, sorted_index, i - 1)->ran_off) != 0)
		{
			sym_offset = (void *)header + sizeof(struct ar_hdr)
				+ print_header(header, filename, 1);
			nm(sym_offset, filename);
		}
		++i;
	}
	free(sorted_index);
	return (NONE);
}

t_err					nm_arch(const char *file, const char *filename)
{
	const struct ar_hdr		*header;
	char					*offset;
	int32_t					n_sym;
	t_byte_to_int			*converter;

	header = (void *)file + SARMAG;
	offset = (void *)header + sizeof(struct ar_hdr) + print_header(header, filename, 0);

	converter = (t_byte_to_int *)offset;
	n_sym = converter->n / sizeof(struct ranlib);
	offset = (void *)offset + 4;
	return (read_symbols(file, offset, filename, n_sym));
}
