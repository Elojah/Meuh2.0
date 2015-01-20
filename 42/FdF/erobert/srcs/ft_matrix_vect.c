/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_vect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 13:30:08 by erobert           #+#    #+#             */
/*   Updated: 2013/12/18 14:32:55 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vect		ft_matrix_vect(t_vect *a, t_matrix *m)
{
	t_vect	res;

	res.x = a->x * m->l1.x + a->y * m->l1.y + a->z * m->l1.z;
	res.y = a->x * m->l2.x + a->y * m->l2.y + a->z * m->l2.z;
	res.z = a->x * m->l3.x + a->y * m->l3.y + a->z * m->l3.z;
	return (res);
}
