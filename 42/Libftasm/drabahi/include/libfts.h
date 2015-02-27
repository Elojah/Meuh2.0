/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfts.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabahi <drabahi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 19:06:36 by drabahi           #+#    #+#             */
/*   Updated: 2015/02/22 19:06:36 by drabahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTS_H
# define LIBFTS_H
# include <stdlib.h>

void		ft_bzero(void *s, size_t n);
char		*ft_strcat(char *s1, const char *s2);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_puts(const char *s);
size_t		ft_strlen(const char *s);
void		*ft_memset(void *b, int c, size_t len);
void		*ft_memcpy(void *s1, const void *s2, size_t n);
char		*ft_strdup(const char *s1);
void		ft_cat(int c);

int			ft_islower(int c);
int			ft_isupper(int c);
int			ft_putchar(int c);
int			ft_putstr(const char *str);
void		ft_swap(int *a, int *b);

#endif
