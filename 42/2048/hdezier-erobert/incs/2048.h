/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2048.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 15:14:09 by erobert           #+#    #+#             */
/*   Updated: 2015/02/28 18:45:31 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _2048_H_
# define _2048_H_

# include <fcntl.h>
# include <ncurses.h>
# include <unistd.h>

# define KEY_ESC 27
# define TPL_WIDTH 7
# define TPL_HEIGHT 3
# define TPL_SIZE 24
# define TPL_FOLDER "tpls/"

typedef enum	e_const
{
	WIN_VALUE = 2048
}				t_const;

typedef enum	e_numbers
{
	N_0 = 0,
	N_2,
	N_4,
	N_8,
	N_16,
	N_32,
	N_64,
	N_128,
	N_256,
	N_512,
	N_1024,
	N_2048,
	N_4096,
	N_8192,
	NB
}				t_numbers;

typedef struct	s_data
{
	char		tpls[NB][TPL_SIZE];
	int			size;
	int			grid[5][5];
}				t_data;

int				ft_strcmp(const char *s1, const char *s2);
char			*ft_itoa(int n);
char			*ft_strjoin(char const *s1, char const *s2);
void			ft_display_grid(t_data *d);
int				ft_play(t_data *data, char input);

#endif
