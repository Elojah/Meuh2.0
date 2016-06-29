/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabahi <drabahi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 17:50:34 by drabahi           #+#    #+#             */
/*   Updated: 2015/11/13 17:50:34 by drabahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*malloc(size_t size)
{
	void	*ptr;
	if (size = 0)
		return;
	else if (size <= SMALL)
	{
		if (size <= TINY)
			alloc_tism(size, &g_alloc.lst_tiny, TINY);
		else
			alloc_tism(size, &g_alloc.lst_small, SMALL);
	}
	else
		alloc_large(size, g_alloc.lst_large);
	return (ptr);
}




