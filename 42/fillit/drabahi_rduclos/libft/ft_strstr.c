/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 10:02:15 by rduclos           #+#    #+#             */
/*   Updated: 2015/06/10 15:00:09 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *s1, const char *s2)
{
	unsigned int	len1;
	unsigned int	lentmp;
	int				len2;

	len1 = 0;
	len2 = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (len1 < ft_strlen(s1) + 1)
	{
		if (s2[len2] == '\0')
			return ((char *)s1 + (len1 - len2));
		else if (s1[len1] == s2[len2])
		{
			if (len2++ == 0)
				lentmp = (len1 + 1);
		}
		else
		{
			len2 = 0;
			len1 = lentmp++;
		}
		len1++;
	}
	return (NULL);
}
