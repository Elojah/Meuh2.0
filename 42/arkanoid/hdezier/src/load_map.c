#include "arkanoid.h"
#include "libft.h"
#include <unistd.h>
#include <fcntl.h>

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
		while (line[i] && n < HEIGHT * WIDTH)
			w->map[n++] = line[i];
	}
	while (n < HEIGHT * WIDTH)
		w->map[n++] = EMPTY;
}
