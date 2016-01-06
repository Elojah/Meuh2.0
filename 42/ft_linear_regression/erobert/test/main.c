/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 15:04:39 by erobert           #+#    #+#             */
/*   Updated: 2016/01/04 19:17:48 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>

static float	t0 = 0;
static float	t1 = 0;

float		ft_estimate_price(float mileage, float t0, float t1)
{
	return (t0 + t1 * mileage);
}

void		ft_linear_regression(float rate, int m, float *tab)
{
	float	tmp;
	float	tmp0;
	float	tmp1;
	int		i;

	tmp0 = 0;
	tmp1 = 0;
	i = -1;
	while (++i < m)
	{
		tmp = ft_estimate_price(tab[i * 2], t0, t1) - tab[i * 2 + 1];
		tmp0 += tmp;
		tmp1 += tmp * tab[i * 2];
	}
	t0 = t0 - rate / m * tmp0;
	t1 = t1 - rate / m * tmp1;
	printf("%f %f\n", t0, t1);
}

int		main(void)
{
	float tab[48] = {
		240000,3650,
		139800,3800,
		150500,4400,
		185530,4450,
		176000,5250,
		114800,5350,
		166800,5800,
		89000,5990,
		144500,5999,
		84000,6200,
		82029,6390,
		63060,6390,
		74000,6600,
		97500,6800,
		67000,6800,
		76025,6900,
		48235,6900,
		93000,6990,
		60949,7490,
		65674,7555,
		54000,7990,
		68500,7990,
		22899,7990,
		61789,8290
	};
	int i = -1;
	while (++i < 24)
	{
		tab[i * 2] /= 300000;
	}
	i = 0;
	float tmp = 1;
	while (fabs(tmp - t1) > 0.01)
	{
		tmp = t1;
		ft_linear_regression(1, 24, tab);
		i++;
	}
	printf("%d\n", i);
	printf("%f\n", ft_estimate_price(0, t0, t1));
	printf("%f\n", ft_estimate_price(10 / 300000., t0, t1));
	printf("%f\n", ft_estimate_price(100 / 300000., t0, t1));
	printf("%f\n", ft_estimate_price(240000. / 300000., t0, t1));
	return (0);
}
