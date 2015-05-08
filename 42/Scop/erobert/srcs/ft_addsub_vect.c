/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addsub_vect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/31 15:23:43 by erobert           #+#    #+#             */
/*   Updated: 2015/05/08 17:27:04 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	ft_addsub_vect(float *result, float *u, float *v, char opp)
{
	if (opp == '+')
	{
		result[0] = u[0] + v[0];
		result[1] = u[1] + v[1];
		result[2] = u[2] + v[2];
	}
	else
	{
		result[0] = u[0] - v[0];
		result[1] = u[1] - v[1];
		result[2] = u[2] - v[2];
	}
}
