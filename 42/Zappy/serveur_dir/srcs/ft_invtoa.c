/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_invtoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/13 14:55:45 by erobert           #+#    #+#             */
/*   Updated: 2014/06/14 04:46:25 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "serveur.h"

static char	*ft_invjoin(char *str, int nb, char *end)
{
	char	*tmp1;
	char	*tmp2;

	tmp1 = str;
	tmp2 = ft_itoa(nb);
	str = ft_strjoin(str, tmp2);
	free(tmp1);
	free(tmp2);
	tmp1 = str;
	str = ft_strjoin(str, end);
	free(tmp1);
	return (str);
}

char		*ft_invtoa(int *resrc)
{
	char	*str;

	str = ft_strdup("{nourriture ");
	str = ft_invjoin(str, resrc[FOOD], ", linemate ");
	str = ft_invjoin(str, resrc[LINE], ", deraumere ");
	str = ft_invjoin(str, resrc[DERA], ", sibur ");
	str = ft_invjoin(str, resrc[SIBU], ", mendiane ");
	str = ft_invjoin(str, resrc[MEND], ", phiras ");
	str = ft_invjoin(str, resrc[PHIR], ", thystame ");
	str = ft_invjoin(str, resrc[THYS], "}");
	return (str);
}
