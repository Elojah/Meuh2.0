/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_section_64.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 18:41:04 by hdezier           #+#    #+#             */
/*   Updated: 2016/06/24 16:36:01 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"
#include <unistd.h>
#include <mach-o/loader.h>

static void				ft_strcpy(const char *input
	, unsigned char *output)
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

static void				write_byte(const char *s, uint32_t n_to_print)
{
	uint32_t			i;

	i = 1;
	while (i <= n_to_print && i <= 8)
	{
		write(1, s + ((8 - i) * 2), 2);
		write(1, " ", 1);
		++i;
	}
}

static void				putbytes(uint64_t n, uint32_t n_to_print)
{
	static const char	symbols[] = "0123456789abcdef";
	unsigned char		result[16 + 1];
	uint32_t			i;

	ft_strcpy("0000000000000000", result);
	i = 1;
	while (i <= 16)
	{
		result[16 - i] = symbols[n % 16];
		n /= 16;
		++i;
	}
	write_byte((char *)result, n_to_print);
}

static void				putuint64_t(uint64_t n)
{
	static const char	symbols[] = "0123456789abcdef";
	unsigned char		result[16 + 1];
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

void						print_section_64(const struct section_64 *section
	, const char *file)
{
	void					*offset;
	uint64_t				i;

	i = 0;
	offset = (void *)file + section->offset;
	while (i < section->size)
	{
		putuint64_t(section->addr + i);
		write(1, " ", 1);
		putbytes(*(uint64_t *)(offset), section->size - i);
		i += 8;
		if (i >= section->size)
		{
			write(1, "\n", 1);
			return ;
		}
		putbytes(*(uint64_t *)((void *)offset + 8), section->size - i);
		write(1, "\n", 1);
		offset = (void *)offset + 16;
		i += 8;
	}
}
