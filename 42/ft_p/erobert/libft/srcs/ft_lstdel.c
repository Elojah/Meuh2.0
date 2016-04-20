/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 14:39:00 by erobert           #+#    #+#             */
/*   Updated: 2013/12/16 12:42:29 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(list_t **alst, void (*del)(void *, size_t))
{
	list_t	*lst;
	list_t	*trash;

	if (!alst)
		return ;
	lst = *alst;
	while (lst)
	{
		trash = lst;
		(*del)(lst->content, lst->content_size);
		lst = lst->next;
		free(trash);
	}
	*alst = NULL;
}
