/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_objcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 19:25:53 by erobert           #+#    #+#             */
/*   Updated: 2015/02/25 13:56:17 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_objcmp(t_obj *o1, t_obj *o2, int k)
{
	if (!k)
		return (ft_strcmp(o1->name, o2->name));
	if (k == 1)
		return (o2->epoch - o1->epoch);
	if (k == 2)
		return (ft_atoi(o2->size) - ft_atoi(o1->size));
	return (0);
}
