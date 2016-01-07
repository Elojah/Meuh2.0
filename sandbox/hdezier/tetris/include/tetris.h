/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 18:49:01 by leeios            #+#    #+#             */
/*   Updated: 2015/12/27 21:32:12 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIS_H
#define TETRIS_H

#define SIZE_MAX_ERR_MSG 63
#define SIZE_PIECE 4
#define MAX_PIECES 26
#define INT_MAX 2147483647
#define MIN(a, b) (((a) < (b) ? (a) : (b)))
#define MAX(a, b) (((a) > (b) ? (a) : (b)))
#define ABS(n) ((n) > 0 ? (n) : -(n))

// DBG
#include <stdio.h>
// !DBG


typedef struct		s_vec2
{
	int				x;
	int				y;
}					t_vec2;

typedef struct		s_rect
{
	t_vec2			point_up_left;
	t_vec2			point_down_right;
}					t_rect;

typedef struct		s_piece
{
	int				data[SIZE_PIECE][SIZE_PIECE];
}					t_piece;

typedef struct		s_result
{
	int				data[MAX_PIECES * SIZE_PIECE][MAX_PIECES * SIZE_PIECE];
	t_rect			frame;
}					t_result;

enum				e_piece
{
	EMPTY = -1,
	BLOC = -2
};

enum				e_coord
{
	X_AND_Y = 0,
	X_ONLY,
	Y_ONLY
};

typedef enum		e_error
{
	NONE = 0,
	NO_ARGS,
	READING_ERROR,
	FILE_INVALID,
	LOST_PIECE,
	SIZE_ENUM_ERROR
}					t_error;

/*
**Library for rectangle manipulation
**/
void				set_as_point(t_rect *rect, int val);
int					width(t_rect *rect);
int					height(t_rect *rect);
void				copy(t_rect *orig, t_rect *dest);
void				grow_rect(t_rect *rect, int new_x, int new_y);
void				set(t_vec2 *vec, int x, int y);

void				exit_with_error(t_error err_value);
t_error				file_to_pieces(t_result *result, char *file_name);
t_error				add_piece_to_result(t_result *result
	, t_piece *piece, int n);
int					grow_rect_with_piece(t_result *result, t_piece *piece
	,t_vec2 *base_position, t_rect *frame);
void				print_pieces(t_result *result);

#endif
