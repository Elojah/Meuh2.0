/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/14 12:14:34 by erobert           #+#    #+#             */
/*   Updated: 2014/04/18 11:44:03 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void	*ft_newptr(void *ptr, size_t new, size_t old)
{
	void	*newptr;

	newptr = malloc(new);
	ft_memcpy(newptr, ptr, old);
	free(ptr);
	return (newptr);
}

void		*realloc(void *ptr, size_t size)
{
	void	*data;

	if (!ptr)
		return (NULL);
	data = ptr - sizeof(t_data);
	if (((t_data *)data)->size + sizeof(t_data) > (size_t)getpagesize())
	{
		if (ft_alloc(ft_mallocated(data, 5), size + sizeof(t_data)))
			((t_data *)data)->size = size;
		else
			ptr = ft_newptr(ptr, size, ((t_data *)data)->size);
	}
	else if (size + sizeof(t_data) < (size_t)getpagesize() / 100)
		((t_data *)data)->size = size;
	else if (size + sizeof(t_data) < (size_t)getpagesize())
		((t_data *)data)->size = size;
	else
		ptr = ft_newptr(ptr, size, ((t_data *)data)->size);
	return (ptr);
}
