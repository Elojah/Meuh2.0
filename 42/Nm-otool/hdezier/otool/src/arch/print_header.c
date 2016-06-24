/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 13:21:36 by hdezier           #+#    #+#             */
/*   Updated: 2016/06/24 17:34:30 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"
#include <unistd.h>
#include <mach-o/ranlib.h>
#include <ar.h>

static void			ft_putstr(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != 0)
		++i;
	write(1, s, i);
}

static int			ft_strncmp(const char *s1, const char *s2, unsigned int n)
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

static unsigned int	ft_uatoi(const char *s)
{
	unsigned int	i;
	unsigned int	result;

	i = 0;
	result = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		result = (result * 10) + (s[i] - '0');
		++i;
	}
	return (result);
}

const char			*get_header_name(const struct ar_hdr *header)
{
	if (ft_strncmp(header->ar_name, AR_EFMT1, 3) == 0)
		return ((void *)header + sizeof(struct ar_hdr));
	else
		return (header->ar_name);
}

uint32_t			print_header(const struct ar_hdr *header
	, const char *filename, uint8_t print)
{
	uint32_t	name_size;

	name_size = 0;
	if (ft_strncmp(header->ar_name, AR_EFMT1, 3) == 0)
	{
		name_size = ft_uatoi(header->ar_name + 3);
		if (print == 0)
			return (name_size);
		ft_putstr(filename);
		write(1, "(", 1);
		ft_putstr((void *)header + sizeof(struct ar_hdr));
		write(1, "):\n", 3);
	}
	else if (print == 1)
		ft_putstr(header->ar_name);
	return (name_size);
}
