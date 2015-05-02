#include "arkanoid.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

static int			is_unit(int x)
{
	return (x > -2 && x < 4);
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
				w->map[n++] = line[i] - '0';
			else
				w->map[n++] = EMPTY;
			i++;
		}
		free(line);
	}
	close(fd);
	while (n < HEIGHT_MAP * WIDTH_MAP)
		w->map[n++] = EMPTY;
}
