int i = 5;
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
int main(void){
	char *s = "int i = %d;%c#include <stdio.h>%c#include <stdlib.h>%c#include <fcntl.h>%c#include <unistd.h>%cint main(void){%c	char *s = %c%s%c;%c	char path[400];sprintf(path,%cSully_%%d.c%c,i-1);%c	int fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR); if (fd == -1){return (1);}%c	dprintf(fd,s,i-1,10,10,10,10,10,10,34,s,34,10,34,34,10,10,10,34,34,34,34,10,10);%c	sprintf(path,%cclang -Wall -Wextra -Werror Sully_%%d.c -o Sully_%%d%c,i-1,i-1);system(path);sprintf(path,%c./Sully_%%d%c,i-1);if (i > 1){system(path);}%c}%c";
	char path[400];sprintf(path,"Sully_%d.c",i-1);
	int fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR); if (fd == -1){return (1);}
	dprintf(fd,s,i-1,10,10,10,10,10,10,34,s,34,10,34,34,10,10,10,34,34,34,34,10,10);
	sprintf(path,"clang -Wall -Wextra -Werror Sully_%d.c -o Sully_%d",i-1,i-1);system(path);sprintf(path,"./Sully_%d",i-1);if (i > 1){system(path);}
}
