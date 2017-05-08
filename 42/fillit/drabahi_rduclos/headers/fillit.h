/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 16:35:11 by rduclos           #+#    #+#             */
/*   Updated: 2017/02/20 17:10:20 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "struct.h"
# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

/*
** solve.c
*/
void	solve(t_env *env);
void	try_replace(t_env *env);
void	try_place(t_env *env, t_tetri *toplace);
void	place_tetri(t_env *env, t_tetri *toplace);
void	remove_last_tetri(t_env *env, t_tetri *toplace);
/*
** solve2.c
*/
int		check_case(t_env *env, t_tetri *toplace, int plusyx[2], int posyx[2]);
int		set_case(t_env *env, t_tetri *toplace, int plusyx[2], int posyx[2]);
int		check_place(t_env *env, t_tetri *toplace, int write);
int		verify_place(t_env *env, t_tetri *toplace);
void	remove_from_board(t_env *env, t_tetri *toplace);
/*
** tools.c
*/
void	first_char(t_tetri *toplace, int *x, int *y);
void	clear_pos(int *x, int *y);
void	incremy(int *plusy, int *plusx, int posx);
/*
** parse.c
*/
int		parse(t_env *env, char **av);
int		check_tetri(char tetris[4][5], int x, int y, int *link);
void	check_links(char tetris[4][5], int x, int y, int *nblink);
int		find_shape(t_env *env, char tetris[4][5]);
int		check_shape(t_env *env, char *line, int nbline);
/*
** save_tetris.c
*/
int		verify_char(char *line);
void	copy_tetri(t_tetri *new, char tetri[4][5]);
int		save_tetri(t_env *env, char tetri[4][5]);
/*
** tetrilist.c
*/
void	add_tetri(t_env *env, t_tetri *tetri);
void	remove_tetri(t_env *env, t_tetri *tetri);
void	delete_tetrilc(t_env *env);
/*
** draw.c
*/
void	draw_tetri(t_tetri *piece);
void	draw_board(t_env *env);
/*
** board.c
*/
void	set_board_size(t_env *env, int size);
void	init_board(t_env *env);

#endif
