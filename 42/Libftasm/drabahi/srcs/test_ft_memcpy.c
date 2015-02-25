/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabahi <drabahi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 19:06:28 by drabahi           #+#    #+#             */
/*   Updated: 2015/02/22 19:06:28 by drabahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	test_ft_memcpy_sub(char *s1, char *s2, char *s3, size_t len)
{
	printf("[%s] {%s} -> ", s1, s3);
	ft_memcpy(s1, s3, len);
	printf("[%s]\n", s1);
	printf("[%s] {%s} -> ", s2, s3);
	ft_memcpy(s2, s3, len);
	printf("[%s]\n", s2);
}

void		test_ft_memcpy(void)
{
	char	s1[20] = "cacahuete";
	char	s2[20] = "cacahuete";

	printf("== %s ==\n", __func__);
	test_ft_memcpy_sub(s1, s2, "abcdefghijklmnopqrs", 20);
	test_ft_memcpy_sub(s1, s2, "                   ", 20);
	test_ft_memcpy_sub(s1, s2, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 20);
	return ;
}
