/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:54:17 by erobert           #+#    #+#             */
/*   Updated: 2013/12/16 14:58:30 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

list_t		*ft_lstnew(void const *content, size_t content_size)
{
	list_t	*lst;

	lst = (list_t *)malloc(sizeof(*lst));
	if (!lst)
		return (NULL);
	if (!content)
	{
		lst->content = 0;
		lst->content_size = 0;
	}
	else
	{
		lst->content = ft_memalloc(content_size);
		ft_memcpy(lst->content, content, content_size);
		lst->content_size = content_size;
	}
	lst->next = NULL;
	return (lst);
}
