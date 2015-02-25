/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_puts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabahi <drabahi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 19:06:28 by drabahi           #+#    #+#             */
/*   Updated: 2015/02/22 19:06:28 by drabahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	test_ft_puts_sub(char *str)
{
	int		ret;

	printf("-- string : {%s} --\n", str);
	ret = ft_puts(str);
	printf("ret = %d\n", ret);
	ret = puts(str);
	printf("ret = %d\n", ret);
}

void		test_ft_puts(void)
{
	printf("== %s ==\n", __func__);
	test_ft_puts_sub("Longue vie a l'asm.");
	test_ft_puts_sub("test");
	test_ft_puts_sub(NULL);
	return ;
}
