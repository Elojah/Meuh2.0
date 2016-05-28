#include<stdio.h>

/*
  This program will print its own source when run.
*/

void		print(void)
{
	;
}

int			main()
{
	char	*a="#include<stdio.h>%c%c/*%c  This program will print its own source when run.%c*/%c%cvoid		print(void)%c{%c	;%c}%c%cint			main()%c{%c	char	*a=%c%s%c;%c%c	/*%c	  This program will print its own source when run.%c	*/%c	print();%c	printf(a,10,10,10,10,10,10,10,10,10,10,10,10,10,34,a,34,10,10,10,10,10,10,10,10);%c}%c";

	/*
	  This program will print its own source when run.
	*/
	print();
	printf(a,10,10,10,10,10,10,10,10,10,10,10,10,10,34,a,34,10,10,10,10,10,10,10,10);
}
