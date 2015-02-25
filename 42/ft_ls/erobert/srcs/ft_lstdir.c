/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 18:08:16 by erobert           #+#    #+#             */
/*   Updated: 2015/02/25 13:56:52 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_objadd(t_obj **obj, t_obj *new)
{
	if (!obj || !*obj || !new)
		return ;
	new->next = *obj;
	*obj = new;
}

t_obj			*ft_lstdir(DIR *dirp, char *dir, int *arg)
{
	struct dirent	*dp;
	t_obj			*obj;

	dp = readdir(dirp);
	obj = ft_objnew(dp, dir, arg);
	dp = readdir(dirp);
	while (dp)
	{
		ft_objadd(&obj, ft_objnew(dp, dir, arg));
		dp = readdir(dirp);
	}
	ft_spaces(obj, arg);
	return (obj);
}
