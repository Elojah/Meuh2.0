/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sixmonth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/09 13:32:07 by erobert           #+#    #+#             */
/*   Updated: 2015/02/25 13:58:54 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "ft_ls.h"

static int	ft_timecmp(time_t epoch, int i)
{
	if (i - epoch > 15778463)
		return (0);
	if (i - epoch < -15778463)
		return (0);
	return (1);
}

int			ft_sixmonth(t_obj *obj)
{
	time_t	now;
	int		i;

	i = time(&now);
	if (ft_timecmp(obj->epoch, i))
		return (0);
	return (1);
}
