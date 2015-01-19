/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabahi <drabahi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 16:16:08 by drabahi           #+#    #+#             */
/*   Updated: 2015/01/08 21:34:21 by drabahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <unistd.h>

int	key_hook(int keycode, t_env *e)
{
	if (keycode == 65307)
		exit (0);
	if (keycode == 65361)
		left_key(e);
	if (keycode == 65363)
		right_key(e);
	if (keycode == 65362)
		up_key(e);
	if (keycode == 65364)
		down_key(e);
	if (keycode == 32)
		run_key(e);
	draw_window(e);
	return (0);
}

int	expose_hook(t_env *e)
{
	draw_window(e);
	return (0);
}

void	minilibx(t_env e)
{
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WW, WH, "Wolf3D");
	e.img = mlx_new_image(e.mlx, WW, WH);
	e.data = mlx_get_data_addr(e.img, &(e.bpp), &(e.n_line), &(e.endian));
	e.pos = NULL;
	e.dir = NULL;
	e.plane = NULL;
	coord_init(&e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_hook(e.win, 2, (1L << 0), key_hook, &e);
	mlx_loop(e.mlx);
}

t_env	main2(t_env *e, char *file)
{
	char	*line;
	int		fd;
	size_t	j;

	j = 0;
	e->map = (char ***) malloc(sizeof(char **) * (e->size_map->y));
	if (e->map == NULL)
		exit(0);
	if ((fd = open(file, O_RDONLY)) == -1)
		exit(0);
	while (get_next_line(fd, &line) > 0)
	{
		e->map[j] = ft_strsplit(line, ' ');
		e->size_map->x = ft_cmpmax(e->size_map->x, col_map((e->map)[j]));
		j++;
		free(line);
	}
	if (close(fd) == -1)
		exit(0);
	return (*e);
}

int	main(int argc, char **argv)
{
	t_env	e;

	if (argc < 2)
		return (no_map());
	if (argc > 2)
		return (all_many_ar());
	posi_init(&e, argv[1]);
	main2(&e, argv[1]);
	minilibx(e);
	return (0);
}

