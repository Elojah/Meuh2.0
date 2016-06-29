/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabahi <drabahi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 17:51:36 by drabahi           #+#    #+#             */
/*   Updated: 2015/11/13 17:51:36 by drabahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <unistd.h>
# include <sys/mman.h>

# define TINY 512
# define SMALL 32768

t_alloc		g_alloc;

/*
** malloc.c
*/

void	*malloc(size_t size);

/*
**	free.c
*/

void	free(void *ptr);

/*
**	realloc.c
*/

void	*realloc(void *ptr, size_t size);

/*
**	print_res.c
*/

void	show_alloc_mem();





void	alloc_tism(size_t n, t_header **stock, size_t type);


#endif
