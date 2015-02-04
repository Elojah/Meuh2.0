/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:47:06 by erobert           #+#    #+#             */
/*   Updated: 2014/04/16 16:26:58 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	if (!s1 || !s2)
		return (s1);
	while (n-- > 0)
		((unsigned char *)s1)[n] = ((unsigned char *)s2)[n];
	return (s1);
}
