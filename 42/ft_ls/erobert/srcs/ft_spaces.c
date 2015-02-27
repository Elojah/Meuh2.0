/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spaces.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 17:47:47 by erobert           #+#    #+#             */
/*   Updated: 2015/02/25 13:58:38 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_ls.h"

static void		ft_big_int(t_obj *obj, size_t *big_l, size_t *big_s, int a)
{
	while (obj)
	{
		if (a || *(obj->name) != '.')
		{
			if (*big_l < ft_strlen(obj->links))
				*big_l = ft_strlen(obj->links);
			if (*big_s < ft_strlen(obj->size))
				*big_s = ft_strlen(obj->size);
		}
		obj = obj->next;
	}
}

static void		ft_big_str(t_obj *obj, size_t *big_u, size_t *big_g, int a)
{
	while (obj)
	{
		if (a || *(obj->name) != '.')
		{
			if (*big_u < ft_strlen(obj->user))
				*big_u = ft_strlen(obj->user);
			if (*big_g < ft_strlen(obj->group))
				*big_g = ft_strlen(obj->group);
		}
		obj = obj->next;
	}
}

static void		ft_addfront(char **s, int nb)
{
	char		*tmp;
	size_t		i;
	size_t		j;

	if (!s || !*s)
		return ;
	tmp = ft_strnew(nb);
	if (!tmp)
		return ;
	i = 0;
	while (i < nb - ft_strlen(*s))
		tmp[i++] = ' ';
	j = 0;
	while ((*s)[j])
		tmp[i++] = (*s)[j++];
	free(*s);
	*s = tmp;
}

static void		ft_addback(char **s, int nb)
{
	char		*tmp;
	int			i;
	int			j;

	if (!s || !*s)
		return ;
	tmp = ft_strnew(nb);
	if (!tmp)
		return ;
	tmp[0] = ' ';
	i = 1;
	j = 0;
	while ((*s)[j])
		tmp[i++] = (*s)[j++];
	while (i < nb)
		tmp[i++] = ' ';
	free(*s);
	*s = tmp;
}

void			ft_spaces(t_obj *obj, int *arg)
{
	size_t		biggest_links;
	size_t		biggest_user;
	size_t		biggest_group;
	size_t		biggest_size;

	biggest_links = 0;
	biggest_user = 0;
	biggest_group = 0;
	biggest_size = 0;
	ft_big_int(obj, &biggest_links, &biggest_size, arg[A]);
	ft_big_str(obj, &biggest_user, &biggest_group, arg[A]);
	while (obj)
	{
		if (arg[A] || *(obj->name) != '.')
		{
			ft_addfront(&(obj->links), biggest_links + 1);
			ft_addback(&(obj->user), biggest_user + 2);
			ft_addback(&(obj->group), biggest_group + 1);
			ft_addfront(&(obj->size), biggest_size + 2);
		}
		obj = obj->next;
	}
}
