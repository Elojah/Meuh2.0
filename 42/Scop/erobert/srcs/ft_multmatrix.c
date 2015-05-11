/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multmatrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 19:31:19 by erobert           #+#    #+#             */
/*   Updated: 2015/05/08 19:35:52 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	ft_multmatrix(float *result, float *a, float *b)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			result[i + j * 4] = 0.;
			k = -1;
			while (++k < 4)
				result[i + j * 4] += a[i + k * 4] * b[k + j * 4];
		}
	}
}
