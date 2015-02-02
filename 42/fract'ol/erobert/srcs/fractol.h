/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 13:13:38 by erobert           #+#    #+#             */
/*   Updated: 2015/02/02 13:54:51 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <math.h>

typedef enum		e_type
{
	JULIA,
	MANDELBROT,
	CARPET,
	SIERPINSKI,
	EXPONENTIAL,
	NUM_TYPE
}					t_type;

typedef union		u_color
{
	int				c;
	char			rgba[4];
}					t_color;

typedef struct		s_fractal
{
	t_type			type;
	double			pos[2];
	double			p[2];
}					t_fractal;

typedef struct		s_img
{
	void			*ptr;
	int				size;
	char			*data;
	int				bpp;
	int				line;
	int				endian;
}					t_img;

typedef struct		s_data
{
	void			*mlx_ptr;
	void			*mlx_win;
	int				size;
	t_img			img;
	int				color[256];
	int				aut;
	t_fractal		fract;
	int				max_iter;
	double			zoom;
}					t_data;

void				*ft_memcpy(void *s1, const void *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_atoi(const char *str);
void				ft_putstr_fd(char const *s, int fd);
int					ft_error(char const *s, int r);
int					ft_parser(int ac, char **av, t_data *d);
void				ft_put_pixel_to_image(t_data *d, int x, int y, int c);
void				ft_change_color(int *color, int button);
int					ft_draw_julia(t_data *d, int x, int y);
int					ft_draw_mandelbrot(t_data *d, int x, int y);
int					ft_draw_carpet(t_data *d, int x, int y);
int					ft_draw_sierpinski(t_data *d, int x, int y);
void				ft_draw_fractol(t_data *d);

#endif
