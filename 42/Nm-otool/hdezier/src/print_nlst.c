/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nlst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 18:41:04 by hdezier           #+#    #+#             */
/*   Updated: 2016/05/28 19:03:51 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"
#include <unistd.h>
#include <mach-o/nlist.h>
#include <limits.h>

static void		ft_putstr_endl(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i++] != '\0')
		;
	write(1, s, i - 1);
	write(1, "\n", 1);
}

static void		ft_strcpy(const char *input, char *output)
{
	uint32_t	i;

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

static void		putuint64_t(uint64_t n)
{
	static const char	symbols[] = "0123456789abcdef";
	char				result[16 + 1];
	uint64_t			quo;
	uint64_t			mod;
	uint32_t			i;

	ft_strcpy("0000000000000000", result);
	i = 0;
	while (i < 16)
	{
		quo = n / 16;
		mod = n % 16;
		result[16 - i] = symbols[mod];
		n = quo;
		++i;
	}
	write(1, result, 16);
}

// static void		putuint32_t(uint32_t n)
// {
// 	uint64_t	i;

// 	if (!n)
// 	{
// 		write(1, "0000000000000000 ", 17);
// 		return ;
// 	}
// 	i = ULLONG_MAX >> 4;
// 	while (i && n / i == 0)
// 	{
// 		write(1, "0", 1);
// 		i >>= 4;
// 	}
// 	putuint32_t(n);
// 	write(1, " ", 1);
// }

void					print_nlst(const t_nlist_64 *nlst
	, const char *symbol)
{
	char					type;

	if (nlst->n_value != 0)
		putuint64_t(nlst->n_value);
	else
		write(1, "                ", 16);
	write(1, " ", 1);
	type = get_char_type(nlst->n_type);
	write(1, &type, 1);
	write(1, " ", 1);
	ft_putstr_endl(symbol);
}
