/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabahi <drabahi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 19:06:28 by drabahi           #+#    #+#             */
/*   Updated: 2015/02/22 19:06:28 by drabahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	test_ft_put_sub(char c)
{
	int		ret;

	printf("-- char : {%c} --\n", c);
	ret = ft_putchar(c);
	printf("  ret = %d\n", ret);
	ret = putchar(c);
	printf("  ret = %d\n", ret);
}

void		test_ft_putchar(void)
{
	printf("== %s ==\n", __func__);
	test_ft_put_sub('a');
	test_ft_put_sub('Z');
	test_ft_put_sub('4');
	test_ft_put_sub('g');
	test_ft_put_sub('U');
	test_ft_put_sub('z');
	test_ft_put_sub('B');
	return ;
}
