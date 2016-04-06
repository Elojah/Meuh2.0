#include <stdio.h>
#include <fcntl.h>
#define MAIN(x)\
int		main(void)\
{\
	char	a[] = "#include <stdio.h>%c#include <fcntl.h>%cint		main(void)%c{%c	char	a[] = %c%s%c;%c	int		fd = open(%cGrace_kid.c%c, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);%c	dprintf(fd, a, 10, 10, 10, 10, 34, a, 34, 10, 34, 34, 10, 10, 10);%c}%c";\
	int		fd = open("Grace_kid.c", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);\
	dprintf(fd, a, 10, 10, 10, 10, 34, a, 34, 10, 34, 34, 10, 10, 10);\
}\
\
