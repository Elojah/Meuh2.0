#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

/*
	No comment
*/

#define NAME "Grace_kid.c"
#define W "w+"
#define MAIN(X) int	main(void){X}

MAIN(
	FILE	*fp;

	fp = fopen(NAME,W);
	char	*a = "#include <stdio.h>%c#include <fcntl.h>%c#include <unistd.h>%c%c/*%c	No comment%c*/%c%c#define NAME %c%s%c%c#define W %c%s%c%c#define MAIN(X) int	main(void){X}%c%cMAIN(%c	FILE	*fp;%c%c	fp = fopen(NAME,W);%c	char	*a = %c%s%c;%c	fprintf(fp,a,10,10,10,10,10,10,10,10,34,NAME,34,10,34,W,34,10,10,10,10,10,10,10,34,a,34,10,10,10,10,10);%c	fclose(fp);%c	return (0);%c)%c";
	fprintf(fp,a,10,10,10,10,10,10,10,10,34,NAME,34,10,34,W,34,10,10,10,10,10,10,10,34,a,34,10,10,10,10,10);
	fclose(fp);
	return (0);
)
