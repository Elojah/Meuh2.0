/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printobj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 18:54:53 by erobert           #+#    #+#             */
/*   Updated: 2015/02/25 15:20:35 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "ft_ls.h"

static void	ft_printname(t_obj *obj, int *arg)
{
	if (arg[MG])
	{
		if (obj->mode[0] == 'd')
			ft_putstr(BLUE);
		else if (obj->mode[3] == 'x')
			ft_putstr(RED);
		else
			ft_putstr(YELLOW);
		ft_putendl(obj->name);
		ft_putstr(END);
	}
	else
		ft_putendl(obj->name);
}

void		ft_printobj(t_obj *obj, int *arg)
{
	if (arg[L])
	{
		ft_putstr(obj->mode);
		ft_putstr(obj->links);
		ft_putstr(obj->user);
		ft_putstr(obj->group);
		ft_putstr(obj->size);
		if (ft_sixmonth(obj))
		{
			write(1, ctime(&(obj->epoch)) + 3, 8);
			write(1, ctime(&(obj->epoch)) + 19, 5);
		}
		else
			write(1, ctime(&(obj->epoch)) + 3, 13);
		ft_putstr(" ");
	}
	ft_printname(obj, arg);
}
