/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabahi <drabahi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 00:05:11 by drabahi           #+#    #+#             */
/*   Updated: 2015/01/23 00:05:11 by drabahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		l1;
	int		l2;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	str = ft_strnew(l1 + l2);
	if (!str)
		return (NULL);
	while (l2-- > 0)
		str[l1 + l2] = ((char *)s2)[l2];
	while (l1-- > 0)
		str[l1] = ((char *)s1)[l1];
	return (str);
}