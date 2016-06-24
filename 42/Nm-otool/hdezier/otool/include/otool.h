/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 16:15:40 by hdezier           #+#    #+#             */
/*   Updated: 2016/06/24 16:39:43 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OTOOL_H
# define OTOOL_H

# include <stdint.h>

// DBG
# include <stdio.h>
# include <unistd.h>
// !DBG

# define CAST_RL(n) ((struct ranlib *)(n))
# define RANLIB_I(p, a, i) CAST_RL((p) + ((a)[(i)] * sizeof(struct ranlib)))

struct ar_hdr;
struct section;
struct section_64;

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
t_err						otool(const char *file, const char *filename);

/*
** File type dispatching
*/
t_err						otool_32(const char *file, const char *filename);
t_err						otool_64(const char *file, const char *filename);
t_err						otool_fat(const char *file, const char *filename
	, unsigned int magic_number);
t_err						otool_arch(const char *file, const char *filename);

/*
** Print list line
*/
void						print_section_64(const struct section_64 *seg
	, const char *file);
void						print_section_32(const struct section *seg
	, const char *file);

/*
** Archive internals
*/
uint32_t					print_header(const struct ar_hdr *header
	, const char *filename, uint8_t print);
const char					*get_header_name(const struct ar_hdr *header);
uint32_t					*sort_ranlib(const char *offset, uint32_t n_sym);

#endif
