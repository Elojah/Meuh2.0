#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define W "w+"
#define SRC "Sully_%d.c"
#define CMD "clang -Wall -Wextra -Werror -o Sully_%d %s"
#define EXE "./Sully_%d"

int			main(int ac, char **av)
{
	char	name[10];
	char	cmd[255];
	FILE	*fp;
	int		i = 8;
	char	*a = "#include <stdio.h>%c#include <fcntl.h>%c#include <unistd.h>%c#include <stdlib.h>%c%c#define W %c%s%c%c#define SRC %c%s%c%c#define CMD %c%s%c%c#define EXE %c%s%c%c%cint			main(int ac, char **av)%c{%c	char	name[10];%c	char	cmd[255];%c	FILE	*fp;%c	int		i = %d;%c	char	*a = %c%s%c;%c%c	(void)ac;%c	if (av[0][7] != 95)%c		i = i + 1;%c	sprintf(name, SRC, i - 1);%c	fp = fopen(name,W);%c	i--;%c	fprintf(fp,a,10,10,10,10,10,34,W,34,10,34,SRC,34,10,34,CMD,34,10,34,EXE,34,10,10,10,10,10,10,10,i,10,34,a,34,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10);%c	fclose(fp);%c	sprintf(cmd, CMD, i, name);%c	system(cmd);%c	if (i > 0)%c	{%c		sprintf(cmd, EXE, i);%c		system(cmd);%c	}%c	return (0);%c}%c";

	(void)ac;
	if (av[0][7] != 95)
		i = i + 1;
	sprintf(name, SRC, i - 1);
	fp = fopen(name,W);
	i--;
	fprintf(fp,a,10,10,10,10,10,34,W,34,10,34,SRC,34,10,34,CMD,34,10,34,EXE,34,10,10,10,10,10,10,10,i,10,34,a,34,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10);
	fclose(fp);
	sprintf(cmd, CMD, i, name);
	system(cmd);
	if (i > 0)
	{
		sprintf(cmd, EXE, i);
		system(cmd);
	}
	return (0);
}
