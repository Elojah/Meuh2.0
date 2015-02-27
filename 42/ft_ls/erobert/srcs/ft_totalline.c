/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_totalline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/09 16:03:40 by erobert           #+#    #+#             */
/*   Updated: 2015/02/25 14:00:13 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_totalline(t_obj *obj, int *arg)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (obj)
	{
		if (!arg[A] && *(obj->name) == '.')
			obj = obj->next;
		else
		{
			i += ft_atoi(obj->blocks);
			obj = obj->next;
			k = 1;
		}
	}
	if (k)
	{
		ft_putstr("total ");
		ft_putendl(ft_itoa(i));
	}
}
