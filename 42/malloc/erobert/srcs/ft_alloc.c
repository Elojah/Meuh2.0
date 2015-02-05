/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 15:15:02 by erobert           #+#    #+#             */
/*   Updated: 2014/04/18 14:26:04 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/mman.h>
#include "malloc.h"

t_data	*ft_alloc(t_data *data, size_t size)
{
	data = (t_data *)mmap(NULL, size, PROT_READ | PROT_WRITE,
							MAP_PRIVATE | MAP_ANON, -1, 0);
	if (data == MAP_FAILED)
		return (NULL);
	return (data);
}
