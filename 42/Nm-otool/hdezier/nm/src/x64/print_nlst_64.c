/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nlst_64.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 18:41:04 by hdezier           #+#    #+#             */
/*   Updated: 2016/06/22 16:33:14 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"
#include <unistd.h>
#include <mach-o/nlist.h>
#include <limits.h>

static void				ft_putstr_endl(const char *s)
{
	unsigned int		i;

	i = 0;
	while (s[i++] != '\0')
		;
	write(1, s, i - 1);
	write(1, "\n", 1);
}

static void				ft_strcpy(const char *input, char *output)
{
	uint32_t			i;

	if (input == NULL || output == NULL)
		return ;
	i = 0;
	while (input[i] != '\0')
	{
		output[i] = input[i];
		++i;
	}
	output[i] = '\0';
}

static void				putuint64_t(uint64_t n)
{
	static const char	symbols[] = "0123456789abcdef";
	char				result[16 + 1];
	uint32_t			i;

	ft_strcpy("0000000000000000", result);
	i = 1;
	while (i < 16)
	{
		result[16 - i] = symbols[n % 16];
		n /= 16;
		++i;
	}
	write(1, result, 16);
}

void					print_nlst_64(const t_nlist_64 *nlst
	, const char *stringtable, const char *file)
{
	char				type;

	if ((nlst->n_type & N_STAB) != 0)
		return ;
	if (nlst->n_value != 0 || (nlst->n_type & N_TYPE) == N_SECT
		|| (nlst->n_type & N_TYPE) == N_ABS)
		putuint64_t(nlst->n_value);
	else
		write(1, "                ", 16);
	write(1, " ", 1);
	type = get_char_type_64(nlst, file);
	write(1, &type, 1);
	write(1, " ", 1);
	ft_putstr_endl(stringtable + nlst->n_un.n_strx);
}
