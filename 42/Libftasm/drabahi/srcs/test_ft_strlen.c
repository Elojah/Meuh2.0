/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabahi <drabahi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 19:06:28 by drabahi           #+#    #+#             */
/*   Updated: 2015/02/22 19:06:28 by drabahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void		test_ft_strlen_sub(char *str)
{
	printf("[%s] -> %lu (%lu)\n", str, ft_strlen(str), strlen(str));
	return ;
}

void			test_ft_strlen(void)
{
	printf("== %s ==\n", __func__);
	test_ft_strlen_sub("Chips Nutella un delice.");
	test_ft_strlen_sub("toto");
	test_ft_strlen_sub("");
	return ;
}
