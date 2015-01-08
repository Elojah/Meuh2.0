/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabahi <drabahi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 23:23:36 by drabahi           #+#    #+#             */
/*   Updated: 2013/12/01 22:23:50 by drabahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	len;
	int		i;
	int		n;

	i = 0;
	n = 0;
	len = (ft_strlen(s1) + ft_strlen(s2));
	s = (char *)malloc(sizeof(*s) * (len + 1));
	if (s == NULL)
		return (NULL);
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	while (s2[n])
	{
		s[i] = s2[n];
		i++;
		n++;
	}
	s[i] = '\0';
	return (s);
}
