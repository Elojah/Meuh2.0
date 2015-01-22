/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotxy_mat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 15:35:24 by erobert           #+#    #+#             */
/*   Updated: 2013/12/18 15:36:39 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix		ft_rotxy_mat(float cos, float sin)
{
	t_matrix	m;

	m.l1.x = cos;
	m.l1.y = -sin;
	m.l1.z = 0;
	m.l2.x = sin;
	m.l2.y = cos;
	m.l2.z = 0;
	m.l3.x = 0;
	m.l3.y = 0;
	m.l3.z = 1;
	return (m);
}
