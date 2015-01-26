/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabahi <drabahi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 00:05:11 by drabahi           #+#    #+#             */
/*   Updated: 2015/01/23 00:05:11 by drabahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned int	i;

	if (!s1 || !s2)
		return (s1);
	i = 0;
	while (i < n)
	{
		((char *)s1)[i] = ((char *)s2)[i];
		if (((char *)s2)[i] == c)
			return (((char *)s1) + i + 1);
		i++;
	}
	return (NULL);
}
