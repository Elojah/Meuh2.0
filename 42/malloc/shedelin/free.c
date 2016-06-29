/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 14:59:47 by shedelin          #+#    #+#             */
/*   Updated: 2015/02/05 14:59:49 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/malloc.h"
#include <libft.h>

void	free(void *ptr)
{
	t_malloc	*tmp;

	if (ptr == NULL)
		return ;
	tmp = g_glob.tiny;
	if (test_list(tmp, ptr))
		return ;
	tmp = g_glob.small;
	if (test_list(tmp, ptr))
		return ;
	tmp = g_glob.large;
	if (test_list(tmp, ptr))
		return ;
	ft_putendl("pointer being free was not allocated");
}

int		test_list(t_malloc *list, void *ptr)
{
	while (list)
	{
		if (list->data == ptr)
		{
			list->empty = 0;
			return (1);
		}
		list = list->next;
	}
	return (0);
}
