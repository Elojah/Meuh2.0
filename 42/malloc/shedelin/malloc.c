/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 14:59:15 by shedelin          #+#    #+#             */
/*   Updated: 2015/02/05 14:59:17 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "includes/malloc.h"
#include <libft.h>

t_glob		g_glob = {NULL, NULL, NULL};

void		*malloc(size_t size)
{
	void	*ptr;

	if (g_glob.tiny == NULL)
		if (init_glob())
			return (NULL);
	if (size < TINY)
		ptr = malloc_tiny(size);
	else if (size <= SMALL)
		ptr = malloc_small(size);
	else
		ptr = malloc_large(size);
	return (ptr);
}

void		*malloc_tiny(size_t size)
{
	t_malloc	*tmp;

	tmp = g_glob.tiny;
	while (tmp)
	{
		if (tmp->empty == 0)
		{
			tmp->empty = 1;
			tmp->size = size;
			return (tmp->data);
		}
		tmp = tmp->next;
	}
	return (malloc_small(size));
}

void		*malloc_small(size_t size)
{
	t_malloc	*tmp;

	tmp = g_glob.small;
	while (tmp)
	{
		if (tmp->empty == 0)
		{
			tmp->empty = 1;
			tmp->size = size;
			return (tmp->data);
		}
		tmp = tmp->next;
	}
	return (malloc_large(size));
}

void		*malloc_large(size_t size)
{
	void		*ptr;
	t_malloc	*tmp;

	tmp = g_glob.large;
	if (tmp)
		return ((void *)new_malloc(tmp, size));
	else
	{
		ptr = mmap(0, size, PROT_READ | PROT_WRITE,
		MAP_ANON | MAP_SHARED, -1, 0);
		if (ptr == MAP_FAILED)
			return (NULL);
		g_glob.large = (t_malloc *)ptr;
		g_glob.large->size = size;
		g_glob.large->empty = 1;
		g_glob.large->data = g_glob.large + 1;
		g_glob.large->next = NULL;
		return ((void *)g_glob.large->data);
	}
}

t_malloc	*new_malloc(t_malloc *tmp, size_t size)
{

	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = mmap(0, size, PROT_READ | PROT_WRITE,
	MAP_ANON | MAP_SHARED, -1, 0);
	if (tmp->next == MAP_FAILED)
		return (NULL);
	tmp = tmp->next;
	tmp->size = size;
	tmp->empty = 1;
	tmp->data = tmp + 1;
	tmp->next = NULL;
	return (tmp->data);
}
