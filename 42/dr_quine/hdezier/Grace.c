/*
	COM_TEST
*/
#include <stdio.h>
#include <fcntl.h>
#define BODY char	a[] = "/*%c	COM_TEST%c*/%c#include <stdio.h>%c#include <fcntl.h>%c#define BODY char	a[] = %c%s%c;int fd = open(%cGrace_kid.c%c, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);dprintf(fd, a, 10, 10, 10, 10, 10, 34, a, 34, 34, 34, 10, 10, 10, 10);return (0);%c#define MAIN main%c#define MAIN_PROTO(name,body) int name(void){body}%cMAIN_PROTO(MAIN,BODY)%c";int fd = open("Grace_kid.c", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);dprintf(fd, a, 10, 10, 10, 10, 10, 34, a, 34, 34, 34, 10, 10, 10, 10);return (0);
#define MAIN main
#define MAIN_PROTO(name,body) int name(void){body}
MAIN_PROTO(MAIN,BODY)
