/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 11:08:06 by erobert           #+#    #+#             */
/*   Updated: 2014/04/18 14:32:09 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void		ft_prealloc(void *tmp, size_t size)
{
	int			i;

	i = 0;
	while (i < 99)
	{
		((t_data *)tmp)->next = tmp + size;
		((t_data *)tmp)->free = 1;
		tmp = ((t_data *)tmp)->next;
		i++;
	}
	((t_data *)tmp)->free = 1;
	((t_data *)tmp)->next = NULL;
}

static void		ft_init(int *i)
{
	void		*tmp;
	size_t		size;

	tmp = ft_alloc(NULL, getpagesize());
	ft_mallocated(tmp, 0);
	ft_mallocated(tmp, 1);
	size = (size_t)(getpagesize() / 100);
	ft_prealloc(tmp, size);
	tmp = ft_alloc(tmp, getpagesize() * 100);
	ft_mallocated(tmp, 2);
	ft_mallocated(tmp, 3);
	size = (size_t)getpagesize();
	ft_prealloc(tmp, size);
	*i = 1;
}

static t_data	*ft_free_space(t_data *data, size_t size)
{
	while (data)
	{
		if (data->free)
		{
			data->size = size;
			data->free = 0;
			return (data);
		}
		data = data->next;
	}
	return (NULL);
}

static void		*ft_big_alloc(size_t size)
{
	t_data		*data;

	data = ft_alloc(NULL, size + sizeof(t_data));
	if (!data)
		return (NULL);
	if (!ft_mallocated(NULL, 4))
		ft_mallocated(data, 4);
	data->size = size;
	data->free = 0;
	data->next = NULL;
	if (!ft_mallocated(NULL, 5))
		ft_mallocated(data, 5);
	else
		((t_data *)ft_mallocated(NULL, 5))->next = data;
	ft_mallocated(data, 5);
	return ((void *)data + sizeof(t_data));
}

void			*malloc(size_t size)
{
	static int	init = 0;
	t_data		*data;
	int			i;

	if (!init)
		ft_init(&init);
	if (size + sizeof(t_data) > (size_t)getpagesize())
		return (ft_big_alloc(size));
	i = (size + sizeof(t_data) < (size_t)(getpagesize() / 110) ? 1 : 3);
	data = ft_free_space(ft_mallocated(NULL, i - 1), size);
	if (data)
		return ((void *)data + sizeof(t_data));
	return (ft_big_alloc(size));
}
