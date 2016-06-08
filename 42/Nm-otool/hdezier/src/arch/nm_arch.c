/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_arch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 06:59:31 by hdezier           #+#    #+#             */
/*   Updated: 2016/06/08 09:45:55 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

#include <mach-o/ranlib.h>
#include <ar.h>
#include <unistd.h>

static void		ft_putstr_endl(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != 0)
		++i;
	write(1, s, i);
	write(1, "\n", 1);
}

static int		ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]
		&& i < n)
		i++;
	if (i == n)
		return (0);
	return (s1[i] - s2[i]);
}

static unsigned int			ft_uatoi(const char *s)
{
	unsigned int		i;
	unsigned int		result;

	i = 0;
	result = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		result = (result * 10) + (s[i] - '0');
		++i;
	}
	return (result);
}

static uint32_t				display_header(const struct ar_hdr *header)
{
	unsigned int			name_size;

	name_size = 0;
	if (ft_strncmp(header->ar_name, AR_EFMT1, 3) == 0)
	{
		name_size = ft_uatoi(header->ar_name + 3);
		ft_putstr_endl((void *)header + sizeof(struct ar_hdr));
	}
	else
		ft_putstr_endl(header->ar_name);
	return (name_size);
}

t_err					nm_arch(const char *file)
{
	struct ar_hdr			*header;
	struct ranlib			*ranlib;
	char					*offset;
	int32_t					n_sym;
	t_byte_to_int			*converter;
	// char					*stringtable;
	// uint32_t				n_string;
	int32_t					i;

	header = (void *)file + SARMAG;
	offset = (void *)header + sizeof(struct ar_hdr) + display_header(header);

	converter = (t_byte_to_int *)offset;
	n_sym = converter->n;
	printf("\nn_sym: %d\n", n_sym);
	offset = (void *)offset + 4;

	i = 0;
	while (i < n_sym)
	{
		printf("%d\n", (int)i);
		ranlib = (struct ranlib *)offset;
		header = (void *)file + ranlib->ran_off;
		display_header(header);
		offset = (void *)offset + sizeof(struct ranlib);
		++i;
	}

	// stringtable = (void *)offset + (n_sym * sizeof(struct ranlib));
	// n_string = READ_INT_4(stringtable);
	// stringtable = (void *)stringtable + 4;
	// printf("n_string:%u\n", n_string);
	// printf("%s\n", header);
	return (NONE);
}
