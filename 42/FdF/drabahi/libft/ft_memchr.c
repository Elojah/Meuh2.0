/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabahi <drabahi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 00:05:11 by drabahi           #+#    #+#             */
/*   Updated: 2015/01/23 00:05:11 by drabahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	if (!s || !n)
		return ((unsigned char *)0);
	else if (*(unsigned char *)s == (unsigned char)c)
		return ((unsigned char *)s);
	else
		return (ft_memchr(s + 1, c, n - 1));
}
