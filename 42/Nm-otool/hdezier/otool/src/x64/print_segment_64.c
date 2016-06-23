/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_segment_64.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 18:41:04 by hdezier           #+#    #+#             */
/*   Updated: 2016/06/23 16:52:37 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"
#include <unistd.h>
#include <mach-o/loader.h>

// static void				ft_putstr_endl(const char *s)
// {
// 	unsigned int		i;

// 	i = 0;
// 	while (s[i++] != '\0')
// 		;
// 	write(1, s, i - 1);
// 	write(1, "\n", 1);
// }

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

void						print_segment_64(const struct segment_command_64 *seg
	, const char *file, const char *filename)
{
	void					*offset;
	uint64_t				current_addr;


	(void)filename;
	(void)file;
	printf("segname:%s, fileoff:%llu, filesize:%llu, vmaddr:%llu, vmsize:%llu\n", seg->segname, seg->fileoff, seg->filesize, seg->vmaddr, seg->vmsize);

	current_addr = seg->vmaddr;
	offset = (void *)seg + (seg->nsects * seg->cmdsize);
	while (current_addr < seg->vmaddr + seg->vmsize)
	{
		putuint64_t(current_addr);
		write(1, " ", 1);
		putuint64_t(*(uint64_t *)(offset));
		write(1, "\n", 1);
		offset = (void *)offset + 16;
		current_addr += 16;
	}
}
