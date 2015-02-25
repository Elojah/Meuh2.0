/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabahi <drabahi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 19:06:28 by drabahi           #+#    #+#             */
/*   Updated: 2015/02/22 19:06:28 by drabahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	test_ft_memset_sub(char *s1, char *s2, char c, size_t len)
{
	ft_memset(s1, c, len);
	memset(s2, c, len);
	s1[19] = '\0';
	s2[19] = '\0';
	printf("c: %c, len = %lu -> [%s] ([%s])\n", c, len, s1, s2);
}

void		test_ft_memset(void)
{
	char	s1[20];
	char	s2[20];

	printf("== %s ==\n", __func__);
	test_ft_memset_sub(s1, s2, '\0', 19);
	test_ft_memset_sub(s1, s2, 'c', 3);
	test_ft_memset_sub(s1, s2, 'd', 19);
	test_ft_memset_sub(s1, s2, 'e', 7);
	return ;
}
