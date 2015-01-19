/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabahi <drabahi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 23:14:49 by drabahi           #+#    #+#             */
/*   Updated: 2013/12/20 20:16:21 by drabahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_split_count(char const *s, char c);
static void		ft_fill_split(char const *s, char **t, char c);
static int		ft_initialize_split(char const *s, char **p, char c);

char			**ft_strsplit(char const *s, char c)
{
	char	**t;
	int		n;

	if (!s)
		return (NULL);
	n = ft_split_count(s, c);
	t = (char **) malloc((n + 1) * sizeof(*t));
	if (t)
		ft_fill_split(s, t, c);
	return (t);
}

static int		ft_split_count(char const *s, char c)
{
	int		n;
	int		i;

	n = 0;
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		n++;
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (n);
}

static void		ft_fill_split(char const *s, char **t, char c)
{
	int		n;
	int		len;
	int		i;

	n = 0;
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		len = ft_initialize_split(s + i, &t[n], c);
		if (t[n])
			ft_strncpy(t[n], s + i, len);
		n++;
		i += len;
		while (s[i] && s[i] == c)
			i++;
	}
	t[n] = NULL;
}

static int		ft_initialize_split(char const *s, char **p, char c)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	*p = ft_strnew(i);
	return (i);
}
