#include "scop.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

static void		read_bmp_file(t_object *obj, char *filename)
{
	int				fd;
	unsigned char	header[54];

	ft_exit((fd = open(filename, O_RDONLY)) < 0, "Can't read BMP file");
	ft_exit(read(fd, header, 54) < 0, "BMP file not valid");
	ft_exit(header[0] != 'B' || header[1] != 'M', "BMP file not valid");
	obj->bmp.data_pos = *(int *)&(header[0x0A]);
	obj->bmp.size = *(int *)&(header[0x22]);
	obj->bmp.width = *(int *)&(header[0x12]);
	obj->bmp.height = *(int *)&(header[0x16]);
	if (!obj->bmp.size)
		obj->bmp.size = obj->bmp.width * obj->bmp.height * 3;
	if (!obj->bmp.data_pos)
		obj->bmp.data_pos = 54;
	ft_exit(obj->bmp.size >= MAX_SIZE_BMP, "BMP file too fat");
	ft_exit(read(fd, obj->bmp.data, obj->bmp.size) < 0
		, "BMP file not valid");
}

void		load_bmp(t_object *obj, char *filename)
{
	read_bmp_file(obj, filename);
	glGenTextures(1, &(obj->tex_id));
	glBindTexture(GL_TEXTURE_2D, obj->tex_id);
	glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, obj->bmp.width, obj->bmp.height, 0
		, GL_BGR, GL_UNSIGNED_BYTE, obj->bmp.data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}
