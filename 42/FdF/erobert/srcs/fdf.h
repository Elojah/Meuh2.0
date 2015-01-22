/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 17:01:24 by erobert           #+#    #+#             */
/*   Updated: 2015/01/20 19:28:10 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <unistd.h>

typedef struct		s_map
{
	int				**tab;
	int				c;
	int				l;
}					t_map;

typedef union		u_color
{
	int				c;
	char			rgba[4];
}					t_color;

typedef struct		s_vect
{
	float			x;
	float			y;
	float			z;
}					t_vect;

typedef struct		s_matrix
{
	t_vect			l1;
	t_vect			l2;
	t_vect			l3;
}					t_matrix;

typedef struct		s_img
{
	void			*ptr;
	int				size[2];
	char			*data;
	int				bpp;
	int				line;
	int				endian;
}					t_img;

typedef struct		s_data
{
	void			*mlx_ptr;
	void			*mlx_win;
	int				size[2];
	int				pos[2];
	t_img			img;
	int				angle_xy;
	int				angle_yz;
	int				scale;
	int				height;
	int				max;
	struct s_map	map;
}					t_data;

typedef t_matrix	(*t_fct)(float, float);

void				*ft_memcpy(void *s1, const void *s2, size_t n);
int					ft_atoi(const char *str);
size_t				ft_strlen(const char *s);
int					ft_error(char const *s, int i);
int					ft_get_line(int const fd, char **line);
int					ft_get_tab(char *line, int **tab);
int					ft_get_map(t_map *map, char *av);
int					ft_max_height(t_map *map);
t_vect				ft_matrix_vect(t_vect *a, t_matrix *m);
t_matrix			ft_rotxy_mat(float cos, float sin);
t_matrix			ft_rotyz_mat(float cos, float sin);
void				ft_translate_vect(t_vect *a, int x, int y);
void				ft_rotate_vect(t_vect *a, int angle, t_fct f);
void				ft_projection_vect(t_vect *a, t_vect *b, t_data *d);
int					ft_color_deg(float z, t_data *d);
void				ft_put_pixel_to_image(t_data *d, int x, int y, int c);
void				ft_draw_line(t_vect *a, t_vect *b, t_data *d);
void				ft_draw_map(t_data *d);

#endif
