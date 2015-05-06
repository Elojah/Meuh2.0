#include "scop.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

static void			load_vertex(t_object *obj)
{
	;
}

void				load_obj(t_object *obj, char *filename)
{
	int				fd;
	char			*line;

	ft_exit((fd = open(filename, O_RDONLY)) < 0, "Can't read file");
	obj->vertex_buffer_size = 0;
	obj->index_buffer_size = 0;
	line = NULL;
	while (get_next_line(fd, &line) >= 0)
	{
		if (line[0] == '#')
		{
			ft_memdel((void **)&line);
			continue ;
		}
		else if (line[0] == 'o')
			ft_strcpy(obj->name, line + 2);
		else if (line[0] == 'v' && line[1] == ' ')
		ft_memdel((void **)&line);
	}
	close(fd);
}
