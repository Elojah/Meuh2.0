/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 19:58:45 by rduclos           #+#    #+#             */
/*   Updated: 2015/06/10 16:26:45 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_char(const char *str, size_t i, char c)
{
	while (str[i] == c && str[i] != '\0')
		i++;
	return (i);
}

static int		ft_cbc(const char *str, size_t i, char c)
{
	while (str[i] != c && str[i] != '\0')
		i++;
	return (i);
}

static int		ft_count_word(const char *str, char c)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		i = ft_count_char(str, i, c);
		if (str[i] != c && str[i] != '\0')
		{
			i = ft_cbc(str, i, c);
			j++;
		}
		if (str[i] != '\0')
			i++;
	}
	return (j);
}

static char		**ft_mysplit(const char *s, char c)
{
	size_t		i;
	size_t		j;
	size_t		k;
	char		**dest;

	i = 0;
	k = 0;
	dest = (char **)malloc(sizeof(char *) * ft_count_word(s, c) + 1);
	if (ft_count_word(s, c) == 0)
		dest[i] = NULL;
	while (s[k] != '\0' && ft_count_word(s, c) != 0)
	{
		j = 0;
		k = ft_count_char(s, k, c);
		dest[i] = (char *)malloc(sizeof(char) * (ft_cbc(s, k, c) + 1));
		while (s[k] != c && s[k] != '\0')
			dest[i][j++] = s[k++];
		dest[i++][j] = '\0';
		k = ft_count_char(s, k, c);
	}
	dest[i] = NULL;
	return (dest);
}

char			**ft_strsplit(const char *s, char c)
{
	if (s == NULL)
		return (NULL);
	return (ft_mysplit(s, c));
}
