/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 16:15:40 by hdezier           #+#    #+#             */
/*   Updated: 2016/05/28 18:43:37 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_H
# define NM_H

# include <stdint.h>
# include <stdio.h>

typedef struct nlist_64		t_nlist_64;

typedef enum	e_err
{
				NONE = 0,
				ERR_MMAP,
				ERR_ARG_NUMBER,
				ERR_FILE_OPEN,
				ERR_FILE_STAT,
				ERR_ARCHITECTURE_NOT_FOUND,
				E_ERR
}				t_err;

/*
** Entry point
*/
t_err				nm(const char *file);

/*
** Type search
*/
char				get_char_type(uint8_t type);

/*
** Print list line
*/
void				print_nlst(const t_nlist_64 *nlst
	, const char *symbol);

/*
** Create(malloc) array of nlist index sorted lexically; bubble sort
*/
uint32_t			*sort_index_nlst(const t_nlist_64 *nlst
					, uint32_t nsyms
					, const char *stringtable);

#endif
