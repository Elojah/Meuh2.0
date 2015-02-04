/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mallocated.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/16 11:15:19 by erobert           #+#    #+#             */
/*   Updated: 2014/04/17 12:23:50 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void				*ft_mallocated(void *ptr, int i)
{
	static void		*mallocated[6] = {NULL, NULL, NULL, NULL, NULL, NULL};

	if (!ptr)
		return (mallocated[i]);
	mallocated[i] = ptr;
	return (NULL);
}
