#include <stdlib.h>
#include <stdio.h>

int				pow(int n, int p)
{
	if (p < 0)
		return (0);
	if (p == 0)
		return (1);
	if (p == 1)
		return (n);
	return (n * pow(n, p - 1));
}

/*
**Works only for n >= 0
*/
char			*uitoa(int n)
{
	int			i;
	int			j;
	int			k;
	int			ncpy;
	char		*result;

	i = j = 0;
	ncpy = n;
	if (!n)
		return (0);
	while (ncpy > 0)
	{
		i++;
		ncpy = ncpy / 10;
	}
	i++;
	if (!(result = (char *)malloc(i * sizeof(char))))
		return (result);
	k = pow(10, i - 2);
	while (--i > 0 && k > 0)
	{
		result[j++] = n / k + '0';
		n %= k;
		k /= 10;
	}
	return (result);
}

char			*SumCharsAndDigits(const char* str)
{
	char			*char_res;
	int				int_res;
	int				i;

	if (!str)
		return ((char *)0);
	int_res = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			int_res += str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'z')
			int_res += str[i] - 'a' + 1;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			int_res += str[i] - 'A' + 1;
	}
	if (int_res == 0)
	{
		if (!(char_res = (char *)malloc(2 * sizeof(char))))
			return (char_res);
		char_res[0] = '0';
		char_res[1] = '\0';
		return (char_res);
	}
	char_res = uitoa(int_res);
	while (int_res / 10)
	{
		i = -1;
		int_res = 0;
		while (char_res[++i])
			int_res += char_res[i] - '0';
		if (int_res / 10 == 0)
			break ;
		free (char_res);
		char_res = uitoa(int_res);
	}
	char_res[0] = int_res + '0';
	char_res[1] = '\0';
	return (char_res);
}

void		PrintWordsSorted(char *str)
{
	;
}

int			main(int ac, char **av)
{
	printf("%s  /  %s\n", SumCharsAndDigits("Abc"), "Abc");
	printf("%s  /  %s\n", SumCharsAndDigits(""), "");
	printf("%s  /  %s\n", SumCharsAndDigits("100153454043543 4 384t=*--*#&"), "100153454043543 4 384t=*--*#&");
	printf("%s  /  %s\n", SumCharsAndDigits("0"), "0");
	printf("%s  /  %s\n", SumCharsAndDigits("000000"), "000000");
	return (0);
}
