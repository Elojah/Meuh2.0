/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 17:43:22 by shedelin          #+#    #+#             */
/*   Updated: 2015/02/11 17:43:23 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>
#include "includes/malloc.h"

int		init_glob(void)
{
	ssize_t	size;
	void	*ptr;

	size = ((TINY * 100) + (SMALL * 100) + (200 * sizeof(t_malloc)));
	size = (size / getpagesize() + 1) * getpagesize();
	ptr = mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_SHARED, -1, 0);
	if (ptr == MAP_FAILED)
		return (1);
	g_glob.tiny = ptr;
	g_glob.small = init_tiny(ptr);
	init_small(g_glob.small);
	return (0);
}

void		*init_tiny(void *ptr)
{
	int			i;
	void		*tmp;
	t_malloc	*tt;

	i = 0;
	tmp = ptr;
	tt = (t_malloc *)tmp;
	while (i++ < 100)
	{
		tt->size = 0;
		tt->empty = 0;
		tt->data = tt + 1;
		if (i == 100)
			tt->next = NULL;
		else
		{
			tt->next = (void *)tt + sizeof(t_malloc) + TINY;		
			tt = tt->next;
		}

	}
	return ((void *)tt + sizeof(t_malloc) + TINY);
}

void		init_small(void *ptr)
{
	int			i;
	t_malloc	*tt;

	i = 0;
	tt = (t_malloc *)ptr;
	while (i++ < 100)
	{		
		tt->size = 0;
		tt->empty = 0;
		tt->data = tt + 1;
		if (i == 100)
			tt->next = NULL;
		else
		{
			tt->next = (void *)tt + sizeof(t_malloc) + SMALL;
			tt = tt->next;
		}		
	}
}
