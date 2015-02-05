/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/14 10:40:57 by erobert           #+#    #+#             */
/*   Updated: 2014/04/17 14:40:28 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void			ft_putnbr(unsigned long n, unsigned int base)
{
	const char		tab[] = "0123456789ABCDEF";
	unsigned long	quo;
	unsigned long	mod;

	if (!n)
		return ;
	if (n > base - 1)
	{
		quo = n / base;
		ft_putnbr(quo, base);
		mod = n % base;
		write(1, &tab[mod], 1);
	}
	else
		write(1, &tab[n], 1);
}

static void			ft_print_mem(t_data *d, int *size)
{
	void			*ptr;

	while (d)
	{
		if (!d->free)
		{
			if (d->size)
			{
				ptr = (void *)d + sizeof(t_data);
				write(1, "\n0x", 3);
				ft_putnbr((unsigned long)ptr, 16);
				write(1, " - 0x", 5);
				ft_putnbr((unsigned long)(ptr + d->size), 16);
				write(1, " : ", 3);
				ft_putnbr((unsigned long)d->size, 10);
				write(1, " octets", 7);
				*size += d->size;
			}
		}
		d = d->next;
	}
	write(1, "\n", 1);
}

void				show_alloc_mem(void)
{
	t_data			*d;
	int				size;

	size = 0;
	write(1, "TINY : 0x", 9);
	d = ft_mallocated(NULL, 0);
	ft_putnbr((unsigned long)d, 16);
	ft_print_mem(d, &size);
	write(1, "SMALL : 0x", 10);
	d = ft_mallocated(NULL, 2);
	ft_putnbr((unsigned long)d, 16);
	ft_print_mem(d, &size);
	write(1, "LARGE : 0x", 10);
	d = ft_mallocated(NULL, 4);
	ft_putnbr((unsigned long)d, 16);
	ft_print_mem(d, &size);
	write(1, "Total : ", 8);
	ft_putnbr((unsigned long)size, 10);
	write(1, " octets\n", 8);
}
