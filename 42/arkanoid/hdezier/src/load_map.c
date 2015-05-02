#include "arkanoid.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

static int			is_unit(int x)
{
	return (x > -2 && x < 4);
}

static void			add_player(t_window *w)
{
	add_unit(w, WIDTH_MAP / 2, PLAYER_Y, PLAYER);
	add_unit(w, WIDTH_MAP / 2 + 1, PLAYER_Y, PLAYER);
	add_unit(w, WIDTH_MAP / 2 - 1, PLAYER_Y, PLAYER);
	add_unit(w, WIDTH_MAP / 2 + 2, PLAYER_Y, PLAYER);
	add_unit(w, WIDTH_MAP / 2 - 2, PLAYER_Y, PLAYER);
	w->player_x = WIDTH_MAP / 2;
}

void				load_map(t_window *w, char *filename)
{
	int				fd;
	char			*line;
	unsigned int	i;
	unsigned int	n;

	n = 0;
	ft_exit((fd = open(filename, O_RDONLY)) < 0, "Can't read file");
	while (get_next_line(fd, &line))
	{
		i = 0;
		while (line[i] && n < HEIGHT_MAP * WIDTH_MAP)
		{
			if (is_unit(line[i] - '0'))
				add_unit(w, n % WIDTH_MAP, HEIGHT_MAP - 4 - (n / WIDTH_MAP)
					, line[i] - '0');
			else
				add_unit(w, n % WIDTH_MAP, HEIGHT_MAP - 4 - (n / WIDTH_MAP)
					, EMPTY);
			++n;
			++i;
		}
		free(line);
	}
	close(fd);
	while (++n < HEIGHT_MAP * WIDTH_MAP)
		add_unit(w, n % WIDTH_MAP, HEIGHT_MAP - 4 - (n / WIDTH_MAP)
			, EMPTY);
	add_player(w);
}
