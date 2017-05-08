/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:09:45 by rduclos           #+#    #+#             */
/*   Updated: 2015/01/20 17:43:56 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	void	*s;
	char	*a;
	char	*b;

	s = (char *)malloc(sizeof(char) * n);
	a = s1;
	b = (char *)s2;
	ft_memcpy(s, b, n);
	ft_memcpy(a, s, n);
	free(s);
	return (s1);
}
