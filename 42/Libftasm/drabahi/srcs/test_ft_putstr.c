/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabahi <drabahi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 19:06:28 by drabahi           #+#    #+#             */
/*   Updated: 2015/02/22 19:06:28 by drabahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	test_ft_putstr_sub(char *str)
{
	int		ret;

	printf("-- string : {%s} --\n", str);
	ret = ft_putstr(str);
	printf("\n retour a la ligne\n");
	printf("ret = %d\n", ret);
	printf("%s", str);
	printf("\n retour a la ligne\n");
	printf("ret = %d\n", ret);
}

void		test_ft_putstr(void)
{
	printf("== %s ==\n", __func__);
	test_ft_putstr_sub("Le putstr c'est cool");
	test_ft_putstr_sub("test");
	test_ft_putstr_sub(NULL);
	return ;
}
