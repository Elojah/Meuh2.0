/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabahi <drabahi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 18:36:43 by drabahi           #+#    #+#             */
/*   Updated: 2013/12/05 22:04:42 by drabahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	i;

	i = c;
	while (*s != i)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}
