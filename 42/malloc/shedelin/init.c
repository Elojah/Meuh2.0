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
	void	*ptr2;

	size = ((TINY * NB_TINY) + (NB_TINY * sizeof(t_malloc)));
	size = (size / getpagesize() + 1) * getpagesize();
	ptr = mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_SHARED, -1, 0);
	if (ptr == MAP_FAILED)
		return (1);
	size = ((SMALL * NB_SMALL) + (NB_SMALL * sizeof(t_malloc)));
	size = (size / getpagesize() + 1) * getpagesize();
	ptr2 = mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_SHARED, -1, 0);
	if (ptr2 == MAP_FAILED)
		return (1);
	g_glob.tiny = ptr;
	init_tiny(ptr);
	g_glob.small = ptr2;
	init_small(ptr2);
	return (0);
}

void		init_tiny(void *ptr)
{
	int			i;
	void		*tmp;
	t_malloc	*tt;

	i = 0;
	tmp = ptr;
	tt = (t_malloc *)tmp;
	while (i++ < NB_TINY)
	{
		tt->size = 0;
		tt->empty = 0;
		tt->data = tt + 1;
		if (i == NB_TINY)
			tt->next = NULL;
		else
		{
			tt->next = (void *)tt + sizeof(t_malloc) + TINY;		
			tt = tt->next;
		}

	}
}

void		init_small(void *ptr)
{
	int			i;
	t_malloc	*tt;

	i = 0;
	tt = (t_malloc *)ptr;
	while (i++ < NB_SMALL)
	{		
		tt->size = 0;
		tt->empty = 0;
		tt->data = tt + 1;
		if (i == NB_SMALL)
			tt->next = NULL;
		else
		{
			tt->next = (void *)tt + sizeof(t_malloc) + SMALL;
			tt = tt->next;
		}		
	}
}
