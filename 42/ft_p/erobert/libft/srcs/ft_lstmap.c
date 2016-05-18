/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 14:49:06 by erobert           #+#    #+#             */
/*   Updated: 2013/12/16 12:43:42 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

list_t		*ft_lstmap(list_t *lst, list_t *(*f)(list_t *elem))
{
	list_t	*ln;
	list_t	*lststart;

	ln = ft_lstnew(((*f)(lst))->content, ((*f)(lst))->content_size);
	if (!ln)
		return (NULL);
	lststart = ln;
	lst = lst->next;
	while (lst)
	{
		ln->next = ft_lstnew(((*f)(lst))->content, ((*f)(lst))->content_size);
		ln = ln->next;
		if (!ln)
			return (NULL);
		lst = lst->next;
	}
	return (lststart);
}
