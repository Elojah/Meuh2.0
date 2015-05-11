/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_translation_matrix.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 19:41:22 by erobert           #+#    #+#             */
/*   Updated: 2015/05/08 19:42:18 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	ft_translation_matrix(float *a, float x, float y, float z)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (i == j)
				a[i + j * 4] = 1.;
			else
				a[i + j * 4] = 0.;
		}
	}
	a[12] = x;
	a[13] = y;
	a[14] = z;
}
