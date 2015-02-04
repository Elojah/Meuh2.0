/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/14 10:42:19 by erobert           #+#    #+#             */
/*   Updated: 2014/04/18 11:45:02 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <unistd.h>

typedef struct		s_data
{
	size_t			size;
	int				free;
	struct s_data	*next;
}					t_data;

t_data				*ft_alloc(t_data *data, size_t size);
void				*ft_mallocated(void *ptr, int i);
void				free(void *ptr);
void				*malloc(size_t size);
void				*ft_memcpy(void *s1, const void *s2, size_t n);
void				*realloc(void *ptr, size_t size);
void				show_alloc_mem(void);

#endif
