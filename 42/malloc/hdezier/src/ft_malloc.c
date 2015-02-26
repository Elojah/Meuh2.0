/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 12:31:02 by hdezier           #+#    #+#             */
/*   Updated: 2015/02/04 12:31:03 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

static t_mem		*ft_alloc(size_t nb_pages)
{
	t_mem		*mem;

	if ((mem = (t_mem *)mmap(0, nb_pages * getpagesize() * sizeof(t_mem)
		, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON
		, -1, 0)) != MAP_FAILED)
	{
		mem->size = 0;
		mem->free = 0;
		mem->next = NULL;
	}
	else
		mem = NULL;
	set_get_data(NULL)->total += nb_pages * getpagesize();
	return (mem);
}

static void			new_local_mem(t_mem *p, size_t size)
{
	p->size = size;
	p->free = 0;
	p->next = 0;
}

static void			*calculus(t_heap *heap, size_t size)
{
	t_mem			*current_mem;

	if (!heap->mem)
		heap->mem = ft_alloc(heap->stock);
	current_mem = heap->mem;
	while (current_mem->next)
		current_mem = current_mem->next;
	heap->head += size + sizeof(t_mem);
	if (heap->head >= heap->stock * getpagesize())
	{
		current_mem->next = ft_alloc(heap->stock);
		current_mem = current_mem->next;
		heap->head = sizeof(t_mem);
	}
	current_mem->next = current_mem + sizeof(t_mem) + current_mem->size;
	new_local_mem(current_mem->next, size);
	return ((void *)(current_mem->next + sizeof(t_mem)));
}

void				*malloc(size_t size)
{
	void				*current;
	static t_data		data = {{(void *)0, sizeof(t_mem), TINY_PAGE}
	, {(void *)0, sizeof(t_mem), SMALL_PAGE}
	, {(void *)0, sizeof(t_mem), LARGE_PAGE}
	, {0, 0}
	, 0};

	set_get_data(&data);
	getrlimit(RLIMIT_AS, &(data.limit));
	if (data.total > (size_t)data.limit.rlim_max || size == 0)
		return (NULL);
	if ((size + sizeof(t_mem)) * 101 < (size_t)TINY_PAGE * getpagesize())
		current = calculus(&(data.tiny), size);
	else if ((size + sizeof(t_mem)) * 101 < (size_t)SMALL_PAGE * getpagesize())
		current = calculus(&(data.small), size);
	else
		current = calculus(&(data.large), size);
	return (current);
}
