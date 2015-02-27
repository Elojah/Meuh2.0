/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_bzero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabahi <drabahi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 19:06:28 by drabahi           #+#    #+#             */
/*   Updated: 2015/02/22 19:06:28 by drabahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void		test_ft_bzero(void)
{
	int		nb;
	char	*str;

	printf("== %s ==\n", __func__);
	nb = 42;
	str = strdup("abcdefghijklmnopqrstuvwxyz");
	printf("nb = %d -> ", nb);
	ft_bzero((void *)&nb, 4);
	printf("%d\n", nb);
	printf("[%s] -> [", str);
	ft_bzero(str, 26);
	write(1, str, 26);
	printf("]\n");
	free(str);
	return ;
}
