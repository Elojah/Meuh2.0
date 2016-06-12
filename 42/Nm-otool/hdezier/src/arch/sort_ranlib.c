/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ranlib.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 13:42:29 by hdezier           #+#    #+#             */
/*   Updated: 2016/06/12 17:56:39 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

#include <mach-o/ranlib.h>
#include <ar.h>
#include <stdlib.h>

static uint32_t			*init_sort_index(uint32_t n_sym)
{
	uint32_t			*result;
	uint32_t			i;

	result = (uint32_t *)malloc(sizeof(uint32_t) * n_sym);
	if (!result)
		return (NULL);
	i = 0;
	while (i < n_sym)
	{
		result[i] = i;
		++i;
	}
	return (result);
}

static void				switch_uint32_t(uint32_t *lhs, uint32_t *rhs)
{
	uint32_t			tmp;

	tmp = *lhs;
	*lhs = *rhs;
	*rhs = tmp;
}

uint32_t				*sort_ranlib(const char *offset, uint32_t n_sym)
{
	uint32_t			*result;
	uint32_t			i;
	uint32_t			j;
	struct ranlib		*lhs_ranlib;
	struct ranlib		*rhs_ranlib;

	result = init_sort_index(n_sym);
	if (!result)
		return (NULL);
	i = 0;
	while (i < n_sym)
	{
		j = 0;
		while (j < n_sym - 1)
		{
			lhs_ranlib = RANLIB_I(offset, result, j);
			rhs_ranlib = RANLIB_I(offset, result, j + 1);
			if (lhs_ranlib->ran_off > rhs_ranlib->ran_off)
				switch_uint32_t(&result[j], &result[j + 1]);
			++j;
		}
		++i;
	}
	return (result);
}
