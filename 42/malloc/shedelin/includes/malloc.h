/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 15:49:52 by shedelin          #+#    #+#             */
/*   Updated: 2015/02/05 15:49:56 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <sys/types.h>

# define TINY			(size_t)(getpagesize() / 32)
# define SMALL			(size_t)(getpagesize() - sizeof(t_malloc))

#include <stdlib.h>
#include <sys/mman.h>

typedef struct			s_malloc
{
	size_t				size;
	char				empty;
	void				*data;
	struct s_malloc		*next;
}						t_malloc;

typedef struct			s_glob
{
	t_malloc			*tiny;
	t_malloc			*large;
	t_malloc			*small;
}						t_glob;

extern t_glob			g_glob;

void					free(void *ptr);
int						test_list(t_malloc *list, void *ptr);
int						init_glob(void);
void					*init_tiny(void *ptr);
void					init_small(void *ptr);
void					*malloc(size_t size);
void					*malloc_tiny(size_t size);
void					*malloc_small(size_t size);
void					*malloc_large(size_t size);
t_malloc				*new_malloc(t_malloc *tmp, size_t size);
void					*realloc(void *ptr, size_t size);
void					show_alloc_mem(void);
void					ml_print(t_malloc *list, char *type);
void					ml_print_total(char *type, int *total);

#endif
