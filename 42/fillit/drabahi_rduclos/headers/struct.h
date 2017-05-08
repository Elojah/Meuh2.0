/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 16:35:23 by rduclos           #+#    #+#             */
/*   Updated: 2017/02/20 17:05:19 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct		s_tetri
{
	char			name;
	char			tetri[4][5];
	int				x;
	int				y;
	struct s_tetri	*next;
	struct s_tetri	*prev;
}					t_tetri;

typedef struct		s_env
{
	char			tetris_name;
	t_tetri			*lc_tetris;
	int				maxsize;
	int				nbtetris;
	char			**board;
}					t_env;

#endif
