/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_roption.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 15:13:20 by erobert           #+#    #+#             */
/*   Updated: 2015/02/25 14:03:53 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_ls.h"

static void	ft_dirsort(t_obj **obj, int *arg)
{
	ft_lstsort(obj, &ft_objcmp, 0);
	if (arg[T])
		ft_lstsort(obj, &ft_objcmp, 1);
	if (arg[MS])
	{
		ft_lstsort(obj, &ft_objcmp, 0);
		ft_lstsort(obj, &ft_objcmp, 2);
	}
	if (arg[R])
		ft_lstrev(obj);
}

static void	ft_rdir(char *dir, t_obj *obj, int *arg)
{
	char	*tmp1;
	char	*tmp2;
	int		i;

	ft_dirsort(&obj, arg);
	while (obj)
	{
		i = ft_strcmp(obj->name, "..") && ft_strcmp(obj->name, ".");
		if (*(obj->mode) == 'd' && i)
		{
			if (ft_strcmp(dir, "/"))
				tmp1 = ft_strjoin(dir, "/");
			else
				tmp1 = ft_strdup(dir);
			tmp2 = ft_strjoin(tmp1, obj->name);
			ft_putendl("");
			ft_putstr(tmp2);
			ft_putendl(":");
			free(tmp1);
			ft_roption(tmp2, arg);
			free(tmp2);
		}
		obj = obj->next;
	}
}

int			ft_roption(char *dir, int *arg)
{
	DIR		*dirp;

	if ((dirp = opendir(dir)) == 0)
		return (ft_nopermission(dir));
	ft_printdir(dirp, dir, arg);
	closedir(dirp);
	if ((dirp = opendir(dir)) == 0)
		return (1);
	ft_rdir(dir, ft_lstdir(dirp, dir, arg), arg);
	closedir(dirp);
	return (0);
}
