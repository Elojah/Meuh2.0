/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 17:41:06 by erobert           #+#    #+#             */
/*   Updated: 2015/01/20 19:39:13 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"

static void	ft_iter_line(char *line, int **tab)
{
	int		i;

	i = 0;
	while (*line)
	{
		while (*line == ' ')
			line++;
		(*tab)[i++] = ft_atoi(line);
		while (*line != ' ' && *line)
			line++;
	}
}

int			ft_get_tab(char *line, int **tab)
{
	int		i;
	int		k;

	i = -1;
	k = 0;
	if (!line)
		return (-1);
	if (*line != ' ')
		k = 1;
	while (line[++i])
	{
		if (line[i] == ' ' && line[i + 1] != ' ')
			k++;
	}
	*tab = malloc(sizeof(**tab) * k);
	if (!*tab)
		return (ft_error("Malloc error", -1));
	ft_iter_line(line, tab);
	return (k);
}
