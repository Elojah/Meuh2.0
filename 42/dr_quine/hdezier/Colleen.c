#include <stdio.h>
int		main(void)
{
	char	*a="#include <stdio.h>%cint		main(void)%c{%c	char	*a=%c%s%c;%c	printf(a, 10, 10, 10, 34, a, 34, 10, 10, 10);%c}%c";
	printf(a, 10, 10, 10, 34, a, 34, 10, 10, 10);
}
