/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_objnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 18:14:06 by erobert           #+#    #+#             */
/*   Updated: 2015/02/26 13:54:03 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <grp.h>
#include <pwd.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/xattr.h>
#include "ft_ls.h"

static void		ft_getinfo(char *dir, t_obj *obj)
{
	struct stat	dp_stat;
	time_t		dp_time;

	lstat(dir, &dp_stat);
	obj->mode = ft_mode(dp_stat.st_mode);
	obj->links = ft_strdup(ft_itoa(dp_stat.st_nlink));
	if (getpwuid(dp_stat.st_uid))
		obj->user = ft_strdup(getpwuid(dp_stat.st_uid)->pw_name);
	else
		obj->user = ft_strdup(ft_itoa(dp_stat.st_uid));
	if (getgrgid(dp_stat.st_gid))
		obj->group = ft_strdup(getgrgid(dp_stat.st_gid)->gr_name);
	else
		obj->group = ft_strdup(ft_itoa(dp_stat.st_gid));
	obj->size = ft_strdup(ft_itoa(dp_stat.st_size));
	obj->blocks = ft_strdup(ft_itoa(dp_stat.st_blocks));
	dp_time = dp_stat.st_mtimespec.tv_sec;
	obj->epoch = dp_time;
}

static void		ft_linkname(struct dirent *dp, char *dir, t_obj *obj)
{
	char		buff[256];
	char		*tmp;
	int			i;

	if (listxattr(dp->d_name, NULL, 0, 0) > 1)
		obj->mode[10] = '@';
	if (dir[0] == '/' && dir[1] == '/')
		i = readlink(dir + 1, buff, 255);
	else
		i = readlink(dir, buff, 255);
	if (!i)
		return ;
	buff[i] = '\0';
	tmp = ft_strjoin(" -> ", buff);
	obj->name = ft_strjoin(dp->d_name, tmp);
	free(tmp);
}

t_obj			*ft_objnew(struct dirent *dp, char *dir, int *arg)
{
	t_obj		*obj;

	obj = (t_obj *)malloc(sizeof(*obj));
	if (!obj)
		return (NULL);
	dir = ft_strjoin(dir, "/");
	dir = ft_strjoin(dir, dp->d_name);
	ft_getinfo(dir, obj);
	if (*(obj->mode) == 'l' && arg[L])
		ft_linkname(dp, dir, obj);
	else
	{
		if (listxattr(dir, NULL, 0, 0) > 1)
			obj->mode[10] = '@';
		obj->name = ft_strdup(dp->d_name);
	}
	obj->next = NULL;
	return (obj);
}
