/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 19:20:10 by erobert           #+#    #+#             */
/*   Updated: 2015/02/25 13:58:15 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	ft_lstsize(t_obj *obj)
{
	if (!obj)
		return (0);
	return (1 + ft_lstsize(obj->next));
}

static void	ft_startswap(t_obj **obj, int (*cmp)(), int k)
{
	t_obj	*previous;
	t_obj	*current1;
	t_obj	*current2;

	if (!obj || !*obj)
		return ;
	previous = *obj;
	current1 = previous->next;
	if (!current1)
		return ;
	current2 = current1->next;
	if ((*cmp)(previous, current1, k) > 0)
	{
		current1->next = previous;
		previous->next = current2;
		*obj = current1;
	}
}

static void	ft_lstswap(t_obj **obj, int (*cmp)(), int k)
{
	t_obj	*previous;
	t_obj	*current1;
	t_obj	*current2;
	t_obj	*tmp;

	if (!obj || !*obj)
		return ;
	previous = *obj;
	current1 = previous->next;
	if (!current1)
		return ;
	current2 = current1->next;
	if (!current2)
		return ;
	if ((*cmp)(current1, current2, k) > 0)
	{
		tmp = current2->next;
		current2->next = current1;
		current1->next = tmp;
		previous->next = current2;
	}
}

void		ft_lstsort(t_obj **obj, int (*cmp)(), int k)
{
	t_obj	*current;
	int		i;

	if (!obj || !*obj)
		return ;
	i = 0;
	while (i++ < ft_lstsize(*obj))
	{
		current = *obj;
		ft_startswap(obj, cmp, k);
		while (current)
		{
			ft_lstswap(&current, cmp, k);
			current = current->next;
		}
	}
}
