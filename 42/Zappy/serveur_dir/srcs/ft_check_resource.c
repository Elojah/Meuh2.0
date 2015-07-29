/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_resource.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/16 10:49:59 by erobert           #+#    #+#             */
/*   Updated: 2014/06/16 11:10:25 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

static int	ft_check_1_4(int level, int *resrc)
{
	if (level == '3' && resrc[LINE] < 2)
		return (-1);
	if ((level == '2' || level == '4') && resrc[DERA] < 1)
		return (-1);
	if (level > '1' && resrc[SIBU] < 1)
		return (-1);
	if (level == '3' && resrc[PHIR] < 2)
		return (-1);
	if (level == '4' && (resrc[SIBU] < 2 || resrc[PHIR] < 1))
		return (-1);
	return (0);
}

static int	ft_check_5_7(int level, int *resrc)
{
	if (resrc[DERA] < 2)
		return (-1);
	if (resrc[SIBU] < 1)
		return (-1);
	if (level == '5' && resrc[MEND] < 3)
		return (-1);
	if (level == '6' && (resrc[SIBU] < 3 || resrc[PHIR] < 1))
		return (-1);
	if (level == '7' && (resrc[LINE] < 2 || resrc[SIBU] < 2 || resrc[THYS] < 1))
		return (-1);
	if (level == '7' && (resrc[MEND] < 2 || resrc[PHIR] < 2))
		return (-1);
	return (0);
}

int			ft_check_resource(t_fd *fd, t_cell **trantor)
{
	int		*resrc;

	resrc = trantor[fd->pos[0]][fd->pos[1]].resource;
	if (resrc[LINE] < 1)
		return (-1);
	if (fd->level < 5)
		return (ft_check_1_4(fd->level, resrc));
	else
		return (ft_check_5_7(fd->level, resrc));
}
