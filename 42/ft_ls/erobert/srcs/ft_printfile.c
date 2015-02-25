/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 17:17:34 by erobert           #+#    #+#             */
/*   Updated: 2015/02/25 14:10:46 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	ft_mkdir(char **file)
{
	int		i;

	i = ft_strlen(*file);
	while ((*file)[i] != '/' && i > -1)
		i--;
	if ((*file)[i] == '/')
		(*file)[i] = 0;
	if (i == -1)
	{
		*file = ft_strjoin("./", *file);
		(*file)[1] = 0;
		i = 1;
	}
	return (i);
}

int			ft_printfile(char *file, int *arg, int k)
{
	DIR		*dirp;
	t_obj	*obj;
	int		i;

	i = ft_mkdir(&file);
	dirp = opendir(file);
	if (dirp == NULL)
		return (0);
	obj = ft_lstdir(dirp, file, arg);
	while (obj)
	{
		if (!ft_strcmp(obj->name, file + i + 1) && *(obj->mode) != 'd')
		{
			if (k)
				ft_printobj(obj, arg);
			return (1);
		}
		obj = obj->next;
	}
	return (0);
}
