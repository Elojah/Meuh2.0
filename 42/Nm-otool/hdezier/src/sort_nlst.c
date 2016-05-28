/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_nlst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 17:50:10 by hdezier           #+#    #+#             */
/*   Updated: 2016/05/28 18:38:44 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"
#include <stdlib.h>
#include <mach-o/nlist.h>

static int			ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (-1);
	while (s1[i] != '\0' && s2[i] != '\0'
		&& s1[i] == s2[i])
		++i;
	return (s1[i] - s2[i]);
}

static uint32_t	*ft_init_index_nlst(uint32_t nsyms)
{
	uint32_t	*result;
	uint32_t	i;

	result = (uint32_t *)malloc(sizeof(uint32_t) * nsyms);
	if (!result)
		return (NULL);
	i = 0;
	while (i < nsyms)
	{
		result[i] = i;
		++i;
	}
	return (result);
}

static void	switch_uint32_t(uint32_t *lhs, uint32_t *rhs)
{
	uint32_t		tmp;

	tmp = *lhs;
	*lhs = *rhs;
	*rhs = tmp;
}

uint32_t			*sort_index_nlst(const struct nlist_64 *nlst
					, uint32_t nsyms
					, const char *stringtable)
{
	uint32_t		*result;
	uint32_t		i;
	uint32_t		j;

	result = ft_init_index_nlst(nsyms);
	if (!result)
		return (NULL);
	i = 0;
	while (i < nsyms - 1)
	{
		j = 0;
		while (j < nsyms - 1)
		{
			if (ft_strcmp(stringtable + nlst[result[j]].n_un.n_strx
				, stringtable + nlst[result[j + 1]].n_un.n_strx) > 0)
				switch_uint32_t(&result[j], &result[j + 1]);
			++j;
		}
		++i;
	}
	return (result);
}
