/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trantor_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/10 16:41:52 by erobert           #+#    #+#             */
/*   Updated: 2014/06/16 14:16:49 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "serveur.h"

static void	ft_resource_init(int *resource)
{
	resource[FOOD] = rand() % 5;
	resource[LINE] = rand() % 4;
	resource[DERA] = rand() % 4;
	resource[SIBU] = rand() % 3;
	resource[MEND] = rand() % 3;
	resource[PHIR] = rand() % 2;
	resource[THYS] = rand() % 2;
	resource[PLAY] = 0;
}

int			ft_trantor_init(t_env *e)
{
	int		i;
	int		j;

	if (e->width < 10 || e->height < 10)
		return (ft_print_result("error: x < 10 or y < 10", "", -1));
	e->trantor = malloc(sizeof(t_cell *) * e->width);
	if (!e->trantor)
		return (ft_print_result("error: malloc [e->trantor]", "", -1));
	i = -1;
	while (++i < e->width)
	{
		e->trantor[i] = malloc(sizeof(t_cell) * e->height);
		if (!e->trantor[i])
			return (ft_print_result("error: malloc [e->trantor]", "", -1));
		j = -1;
		while (++j < e->height)
			ft_resource_init(e->trantor[i][j].resource);
	}
	return (0);
}
