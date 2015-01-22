/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotyz_mat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 15:36:03 by erobert           #+#    #+#             */
/*   Updated: 2013/12/19 20:23:37 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix		ft_rotyz_mat(float cos, float sin)
{
	t_matrix	m;

	m.l1.x = 1;
	m.l1.y = 0;
	m.l1.z = 0;
	m.l2.x = 0;
	m.l2.y = cos;
	m.l2.z = -sin;
	m.l3.x = 0;
	m.l3.y = sin;
	m.l3.z = cos;
	return (m);
}
