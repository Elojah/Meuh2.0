/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 16:15:40 by hdezier           #+#    #+#             */
/*   Updated: 2016/06/22 17:39:25 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_H
# define NM_H

# include <stdint.h>

// DBG
# include <stdio.h>
# include <unistd.h>
// !DBG

# define CAST_RL(n) ((struct ranlib *)(n))
# define RANLIB_I(p, a, i) CAST_RL((p) + ((a)[(i)] * sizeof(struct ranlib)))

struct ar_hdr;

typedef struct nlist_64		t_nlist_64;
typedef struct nlist		t_nlist_32;

typedef enum				e_err
{
	NONE = 0,
	ERR_MMAP,
	ERR_ARG_NUMBER,
	ERR_FILE_OPEN,
	ERR_FILE_STAT,
	ERR_ARCHITECTURE_NOT_FOUND,
	ERR_ARCHITECTURE_UNRECOGNIZED_IN_FAT,
	E_ERR
}							t_err;

/*
** Entry point
*/
t_err						nm(const char *file, const char *filename);

/*
** File type dispatching
*/
t_err						nm_32(const char *file);
t_err						nm_64(const char *file);
t_err						nm_fat(const char *file, const char *filename
	, unsigned int magic_number);
t_err						nm_arch(const char *file, const char *filename);

/*
** Type search
*/
char						get_char_type_32(const t_nlist_32 *nlst
	, const char *file);
char						get_char_type_64(const t_nlist_64 *nlst
	, const char *file);
char						type_to_char(const char *type);

/*
** Print list line
*/
void						print_nlst_64(const t_nlist_64 *nlst
	, const char *stringtable, const char *file);
void						print_nlst_32(const t_nlist_32 *nlst
	, const char *stringtable, const char *file);

/*
** Create(malloc) array of nlist index sorted lexically; bubble sort
*/
uint32_t					*sort_index_nlst_64(const t_nlist_64 *nlst
					, uint32_t n_sym
					, const char *stringtable);
uint32_t					*sort_index_nlst_32(const t_nlist_32 *nlst
					, uint32_t n_sym
					, const char *stringtable);
uint32_t					*sort_ranlib(const char *offset, uint32_t n_sym);

/*
** Archive internals
*/
uint32_t					print_header(const struct ar_hdr *header
	, const char *filename, uint8_t print);
const char					*get_header_name(const struct ar_hdr *header);

#endif
