/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_projection_vect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 15:13:13 by erobert           #+#    #+#             */
/*   Updated: 2013/12/19 20:10:58 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_projection_vect(t_vect *a, t_vect *b, t_data *d)
{
	t_vect		tmp;

	tmp.x = a->z * d->height;
	tmp.y = b->z * d->height;
	a->z = tmp.x;
	b->z = tmp.y;
	ft_rotate_vect(a, d->angle_xy, &ft_rotxy_mat);
	ft_rotate_vect(b, d->angle_xy, &ft_rotxy_mat);
	ft_rotate_vect(a, d->angle_yz, &ft_rotyz_mat);
	ft_rotate_vect(b, d->angle_yz, &ft_rotyz_mat);
	a->z = tmp.x;
	b->z = tmp.y;
}
