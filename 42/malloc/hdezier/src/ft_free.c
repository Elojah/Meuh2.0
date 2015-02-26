/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 13:21:51 by hdezier           #+#    #+#             */
/*   Updated: 2015/02/09 13:21:52 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include <sys/mman.h>
#include <sys/stat.h>

static int	free_heap(t_heap *heap, t_mem *ptr)
{
	t_mem	*tmp;

	if (!heap->mem)
		return (0);
	tmp = heap->mem->next;
	while (tmp)
	{
		if (tmp + sizeof(t_mem) == ptr)
		{
			munmap(ptr, tmp->size);
			tmp->free = 1;
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

void		free(void *ptr)
{
	static t_data	*data = NULL;

	if (!data)
		data = set_get_data(NULL);
	if (!ptr)
		return ;
	if (free_heap(&(data->tiny), ptr))
		return ;
	if (free_heap(&(data->small), ptr))
		return ;
	free_heap(&(data->large), ptr);
}
