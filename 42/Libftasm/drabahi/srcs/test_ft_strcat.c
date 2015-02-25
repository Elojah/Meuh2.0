/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strcat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabahi <drabahi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 19:06:28 by drabahi           #+#    #+#             */
/*   Updated: 2015/02/22 19:06:28 by drabahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	test_ft_strcat_sub(char *s1, char *s2, char *s3)
{
	printf("[%s] + [%s] = ", s1, s3);
	ft_strcat(s1, s3);
	printf("[%s]\n", s1);
	printf("[%s] + [%s] = ", s2, s3);
	strcat(s2, s3);
	printf("[%s]\n", s2);
}

void		test_ft_strcat(void)
{
	char	s1[30] = {"Les chips "};
	char	s2[30] = {"Les chips "};
	char	s3[] = {"c'est bon."};

	printf("== %s ==\n", __func__);
	test_ft_strcat_sub(s1, s2, s3);
	strcpy(s1, "toto ");
	strcpy(s2, "toto ");
	strcpy(s3, "tata");
	test_ft_strcat_sub(s1, s2, s3);
	strcpy(s1, "tutu ");
	strcpy(s2, "tutu ");
	strcpy(s3, "");
	test_ft_strcat_sub(s1, s2, s3);
	strcpy(s1, "");
	strcpy(s2, "");
	strcpy(s3, "titi");
	test_ft_strcat_sub(s1, s2, s3);
	return ;
}
