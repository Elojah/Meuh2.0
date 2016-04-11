#include <stdio.h>
/*
	COM_EXTERN
*/
int		main(void)
{
	/*
		COM_INTERN
	*/
	char	s[] = "#include <stdio.h>%c/*%c	COM_EXTERN%c*/%cint		main(void)%c{%c	/*%c		COM_INTERN%c	*/%c	char	s[] = %c%s%c;%c	printf(s, 10, 10, 10, 10, 10, 10, 10, 10, 10, 34, s, 34, 10, 10, 10);%c}%c";
	printf(s, 10, 10, 10, 10, 10, 10, 10, 10, 10, 34, s, 34, 10, 10, 10);
}
