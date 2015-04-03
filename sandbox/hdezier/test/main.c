#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

static int		pow(int n, int p)
{
	if (p < 0)
		return (0);
	if (p == 0)
		return (1);
	if (p == 1)
		return (n);
	return (n * pow(n, p - 1));
}

static char		*uitoa(int n)
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

static char	*substr(int a, int b, char *str)
{
	char	*result;
	int		i;

	i = 0;
	result = (char *)malloc((b - a + 1) * sizeof(char));
	while (a < b)
		result[i++] = str[a++];
	return (result);
}

static int		strlen(char *s)
{
	int		result;

	result = 0;
	while (s[result])
		result++;
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
	char	*sub;
	int		i;
	int		a;
	int		b;

	i = -1;
	while (str[++i])
	{
		a = i;
		if (str[i] == ' ')
		{
			while (str[i] == ' ')
				i++;
			a = i;
		}
		while (str[i] && str[i] != ' ')
			i++;
		b = i;
		sub = substr(a, b, str);
		if (sub[0] == '\0')
			continue ;
		write(1, SumCharsAndDigits(sub), 2);
		write(1, ": ", 2);
		write(1, sub, strlen(sub));
		write(1, "\n", 1);
	}
}

int			main(int ac, char **av)
{
	// printf("%s  /  %s\n", SumCharsAndDigits("Abc"), "Abc");
	// printf("%s  /  %s\n", SumCharsAndDigits(""), "");
	// printf("%s  /  %s\n", SumCharsAndDigits("100153454043543 4 384t=*--*#&"), "100153454043543 4 384t=*--*#&");
	// printf("%s  /  %s\n", SumCharsAndDigits("0"), "0");
	// printf("%s  /  %s\n", SumCharsAndDigits("000000"), "000000");
	PrintWordsSorted("           Abc 45   40   e   0         ");
	return (0);
}
