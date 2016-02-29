/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_celltoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/13 14:54:00 by erobert           #+#    #+#             */
/*   Updated: 2014/06/16 14:15:41 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "serveur.h"

static char	*ft_resrcjoin(char *str, char *name, int nb)
{
	int		i;
	char	*tmp;

	i = -1;
	while (++i < nb)
	{
		tmp = str;
		if (!*str)
			str = ft_strjoin(str, name);
		else
			str = ft_strjoin(str, ft_strjoin(" ", name));
		free(tmp);
	}
	return (str);
}

char		*ft_celltoa(int *resrc)
{
	char	*str;

	str = ft_strnew(1);
	str = ft_resrcjoin(str, "nourriture", resrc[FOOD]);
	str = ft_resrcjoin(str, "linemate", resrc[LINE]);
	str = ft_resrcjoin(str, "deraumere", resrc[DERA]);
	str = ft_resrcjoin(str, "sibur", resrc[SIBU]);
	str = ft_resrcjoin(str, "mendiane", resrc[MEND]);
	str = ft_resrcjoin(str, "phiras", resrc[PHIR]);
	str = ft_resrcjoin(str, "thystame", resrc[THYS]);
	str = ft_resrcjoin(str, "joueur", resrc[PLAY]);
	return (str);
}
