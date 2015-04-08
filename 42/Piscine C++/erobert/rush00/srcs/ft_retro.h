/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_retro.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 09:31:24 by erobert           #+#    #+#             */
/*   Updated: 2015/01/12 07:31:16 by rbobillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RETRO_H
# define FT_RETRO_H

# include <time.h>
# include <unistd.h>
# include <stdlib.h>
# include <ncurses.h>
# include <string>
# include <iostream>
# include <fstream>

# define WIDTH 20
# define HEIGHT 7
# define ESC 27
# define KEY_SPACE 32
# define RETURN 10

# define QUIT 113
# define PAUSE 112

typedef enum	e_spaceType
{
	PLAYER = 0,
	NPC,
	PROJECTILE,
	ASTEROIDE,
	SPACE
}				t_spaceType;

typedef struct	s_spaceObject
{
	e_spaceType	type;
	int			size[2];
	int			pos[2];
}				t_spaceObject;

void			ft_game_loop(int const *dim, WINDOW *game_win);

#endif
