/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabahi <drabahi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 00:05:11 by drabahi           #+#    #+#             */
/*   Updated: 2015/01/23 00:05:11 by drabahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*ft_strdup_char(char const *str, char c)
{
	char	*s;
	int		i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (!(s = malloc(sizeof(*s) * (i + 1))))
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

static char	**ft_getwords(int n, char const *str, char c)
{
	char	**tab;

	if (!(tab = malloc(sizeof(*tab) * (n + 1))))
		return (NULL);
	tab[n] = 0;
	n = 0;
	while (*str)
	{
		tab[n] = ft_strdup_char(str, c);
		str += ft_strlen(tab[n++]);
		while (*str == c)
			str++;
	}
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		nb_c;

	while (*s == c)
		s++;
	i = 0;
	nb_c = 0;
	if (*s)
		nb_c = 1;
	while (s[i])
	{
		if (s[i] == c)
		{
			if (s[i + 1] != c && s[i + 1])
				nb_c++;
		}
		i++;
	}
	return (ft_getwords(nb_c, s, c));
}
