#include <fcntl.h>
#include <unistd.h>

int			main(int ac, char **av)
{
	int		fd;
	char	str[27];
	char	eof;
	int		i;

	eof = '\n';
	fd = open(av[1], O_RDONLY);
	i = read(fd, str, 26);
	str[i] = '\0';
	write(1, str, 26);
	write(1, &eof, 1);
	i = 0;
	while (i < 26)
	{
		if (i)
			str[i] -= i;
		write(1, &(str[i]), 1);
		i++;
	}
	write(1, &eof, 1);
	return (0);
}
