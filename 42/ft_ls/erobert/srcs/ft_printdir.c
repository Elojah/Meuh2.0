/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 14:18:12 by erobert           #+#    #+#             */
/*   Updated: 2015/02/25 14:02:59 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_printdir(DIR *dirp, char *dir, int *arg)
{
	t_obj	*obj;

	obj = ft_lstdir(dirp, dir, arg);
	if (!obj)
		return ;
	ft_lstsort(&obj, &ft_objcmp, 0);
	if (arg[T])
		ft_lstsort(&obj, &ft_objcmp, 1);
	if (arg[MS])
	{
		ft_lstsort(&obj, &ft_objcmp, 0);
		ft_lstsort(&obj, &ft_objcmp, 2);
	}
	if (arg[R])
		ft_lstrev(&obj);
	if (arg[L])
		ft_totalline(obj, arg);
	while (obj)
	{
		if (arg[A] || *(obj->name) != '.')
			ft_printobj(obj, arg);
		obj = obj->next;
	}
}
