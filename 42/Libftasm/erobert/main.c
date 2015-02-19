/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 16:39:39 by erobert           #+#    #+#             */
/*   Updated: 2015/02/19 16:07:58 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "incs/libfts.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	ft_putnbr(unsigned int n)
{
	unsigned int	quo;
	unsigned int	mod;

	if (n > 9)
	{
		quo = n / 10;
		ft_putnbr(quo);
		mod = n % 10;
		ft_putchar(mod + '0');
	}
	else if ((n > 0) && (n < 10))
		ft_putchar(n + '0');
	else
		ft_putchar(n + '0');
}

int			main(void)
{
	char	str0[] = "abcde\n";
	char	*str1;
	char	str2[20] = "Hello Max";
	char	*str3;
	int		fd;

	ft_puts("bzero-----------");
	ft_putstr("ft_bzero(\"abcde\\n\", 4): ");
	ft_bzero((void *)str0, 4);
	write(1, str0, 6);
	ft_puts("strlen----------");
	ft_putstr("ft_strlen(\"abce\\n\"): ");
	ft_putnbr(ft_strlen("abcde\n"));
	ft_putchar('\n');
	ft_puts("isalpha---------");
	ft_putstr("ft_isalpha(100): ");
	if (ft_isalpha(100))
		ft_putstr("yes\n");
	else
		ft_putstr("no\n");
	ft_putstr("ft_isalpha('e'): ");
	if (ft_isalpha('e'))
		ft_putstr("yes\n");
	else
		ft_putstr("no\n");
	ft_putstr("ft_isalpha('1'): ");
	if (ft_isalpha('1'))
		ft_putstr("yes\n");
	else
		ft_putstr("no\n");
	ft_puts("isdigit---------");
	ft_putstr("ft_isdigit('0' - 1): ");
	if (ft_isdigit('0' - 1))
		ft_putstr("yes\n");
	else
		ft_putstr("no\n");
	ft_putstr("ft_isdigit('9' + 1): ");
	if (ft_isdigit('9' + 1))
		ft_putstr("yes\n");
	else
		ft_putstr("no\n");
	ft_puts("ft_isdigit('0'): ");
	if (ft_isdigit('0'))
		ft_putstr("yes\n");
	else
		ft_putstr("no\n");
	ft_puts("isalnum---------");
	ft_putstr("ft_isalnum('f'): ");
	if (ft_isalnum('f'))
		ft_putstr("yes\n");
	else
		ft_putstr("no\n");
	ft_putstr("ft_isalnum('9' + 1): ");
	if (ft_isalnum('9' + 1))
		ft_putstr("yes\n");
	else
		ft_putstr("no\n");
	ft_putstr("ft_isalnum('7'): ");
	if (ft_isalnum('7'))
		ft_putstr("yes\n");
	else
		ft_putstr("no\n");
	ft_puts("isasci---------");
	ft_putstr("ft_isascii(0): ");
	if (ft_isascii(0))
		ft_putstr("yes\n");
	else
		ft_putstr("no\n");
	ft_putstr("ft_isascii(-1): ");
	if (ft_isascii(-1))
		ft_putstr("yes\n");
	else
		ft_putstr("no\n");
	ft_putstr("ft_isascii(124): ");
	if (ft_isascii(124))
		ft_putstr("yes\n");
	else
		ft_putstr("no\n");
	ft_puts("isprint---------");
	ft_putstr("ft_isprint(85): ");
	if (ft_isprint(85))
		ft_putstr("yes\n");
	else
		ft_putstr("no\n");
	ft_putstr("ft_isprint(10): ");
	if (ft_isprint(10))
		ft_putstr("yes\n");
	else
		ft_putstr("no\n");
	ft_putstr("ft_isprint(124): ");
	if (ft_isprint(124))
		ft_putstr("yes\n");
	else
		ft_putstr("no\n");
	ft_puts("toupper---------");
	ft_putstr("ft_toupper('a'): ");
	ft_putchar(ft_toupper('a'));
	ft_putchar('\n');
	ft_putstr("ft_toupper('z'): ");
	ft_putchar(ft_toupper('z'));
	ft_putchar('\n');
	ft_putstr("ft_toupper('a' - 1): ");
	ft_putchar(ft_toupper('a' - 1));
	ft_putchar('\n');
	ft_puts("tolower---------");
	ft_putstr("ft_tolower('a'): ");
	ft_putchar(ft_tolower('a'));
	ft_putchar('\n');
	ft_putstr("ft_tolower('Z'): ");
	ft_putchar(ft_tolower('Z'));
	ft_putchar('\n');
	ft_putstr("ft_tolower('A' - 1): ");
	ft_putchar(ft_tolower('A' - 1));
	ft_putchar('\n');
	ft_puts("puts------------");
	ft_putstr("ft_puts(\"Hello Max\"): ");
	ft_puts("Hello Max");
	ft_putstr("ft_puts(\"\"): ");
	ft_puts("");
	ft_putstr("ft_puts(NULL): ");
	ft_puts(NULL);
	ft_puts("strcat----------");
	ft_putstr("ft_strcat(str2, \", Mad Max\"): ");
	ft_puts(ft_strcat(str2, ", Mad Max"));
	ft_puts("memset----------");
	ft_putstr("ft_memset(\"abcde\\n\", '6', 6): ");
	ft_bzero(str0, 7);
	ft_puts(ft_memset((void *)str0, '6', 6));
	ft_putstr("ft_memset(str2, '7', 3): ");
	ft_puts(ft_memset((void *)str2, '7', 3));
	ft_puts("memcpy----------");
	ft_putstr("ft_memcpy(str2, \"rsdfdsf\", 6): ");
	ft_puts(ft_memcpy(str2, "rsdfdsf", 6));
	ft_puts("strdup----------");
	ft_putstr("ft_strdup(str2): ");
	ft_puts(ft_strdup(str2));
	ft_putstr("ft_strdup(""): ");
	ft_puts(ft_strdup(""));
	ft_puts("cat-------------");
//	ft_puts("ft_cat(-1): ");
	ft_cat(-1);
	fd = open(__FILE__, O_RDONLY);
//	ft_puts("ft_cat(fd): ");
	ft_cat(fd);
//	ft_puts("ft_cat(0): ");
	ft_cat(0);
	close(fd);
	return (0);
}
