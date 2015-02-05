/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/14 12:51:35 by erobert           #+#    #+#             */
/*   Updated: 2014/04/18 12:53:54 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/mman.h>
#include "malloc.h"

void		free(void *ptr)
{
	if (!ptr)
		return ;
	ptr -= sizeof(t_data);
	if (!((t_data *)ptr)->free)
		((t_data *)ptr)->free = 1;
	if (((t_data *)ptr)->size > (size_t)getpagesize())
		munmap(ptr + sizeof(t_data), ((t_data *)ptr)->size);
}
