/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 15:22:18 by shedelin          #+#    #+#             */
/*   Updated: 2015/02/05 15:23:00 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "includes/malloc.h"

void		show_alloc_mem(void)
{
	t_malloc	*tmp;

	tmp = g_glob.tiny;
	ml_print(tmp, "TINY");
	tmp = g_glob.small;
	ml_print(tmp, "SMALL");
	tmp = g_glob.large;
	ml_print(tmp, "LARGE");
	ft_putendl("\n\n");
}

void		ml_print(t_malloc *list, char *type)
{
	static int	total = 0;

	if (list == NULL)
		return ;
	ft_putstr(type);
	ft_putstr(" : ");
	ft_putnbr((unsigned long int)list);
	ft_putendl("");
	while (list)
	{
		if (list->empty == 0)
		{
			list = list->next;
			continue ;
		}
		ft_putnbr((unsigned long int)list->data);
		ft_putstr(" - ");
		ft_putnbr((unsigned long int)(list->data + list->size));
		ft_putstr(" : ");
		ft_putnbr((int)list->size);
		total += list->size;
		ft_putendl(" octets");
		list = list->next;
	}
	ml_print_total(type, &total);
}

void		ml_print_total(char *type, int *total)
{
	if (ft_strequ(type, "LARGE"))
	{
		ft_putstr("Total : ");
		ft_putnbr(*total);
		ft_putendl(" octets");
		*total = 0;
	}
}
