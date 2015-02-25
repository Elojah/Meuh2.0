/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabahi <drabahi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 19:06:36 by drabahi           #+#    #+#             */
/*   Updated: 2015/02/22 19:06:36 by drabahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>
# include <fcntl.h>
# include "libfts.h"

void		test_ft_bzero(void);
void		test_ft_isstuff(int (*f)(int), int (*f2)(int));
void		test_ft_tostuff(int (*f)(int), int (*f2)(int));
void		test_ft_puts(void);
void		test_ft_putchar(void);
void		test_ft_putstr(void);
void		test_ft_strlen(void);
void		test_ft_strcat(void);
void		test_ft_memset(void);
void		test_ft_memcpy(void);
void		test_ft_strdup(void);
void		test_ft_cat(void);
void		test_ft_swap(void);

#endif
