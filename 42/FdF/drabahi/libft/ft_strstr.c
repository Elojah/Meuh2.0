/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabahi <drabahi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 00:05:11 by drabahi           #+#    #+#             */
/*   Updated: 2015/01/23 00:05:11 by drabahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int	i;
	int	k;

	if (!s1 || !s2)
		return ((char *)s1);
	i = 0;
	k = 0;
	while (s1[i])
	{
		if (!s2[k])
			return ((char *)s1 + i - k);
		else if (s1[i] != s2[k])
		{
			i -= k;
			k = 0;
		}
		else if (s1[i] == s2[k])
			k++;
		i++;
	}
	if (s1[i] == s2[k])
		return ((char *)s1 + i - k);
	return (NULL);
}
