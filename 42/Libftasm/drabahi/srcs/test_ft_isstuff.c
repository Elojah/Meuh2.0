/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isstuff.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabahi <drabahi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 19:06:28 by drabahi           #+#    #+#             */
/*   Updated: 2015/02/22 19:06:28 by drabahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <execinfo.h>
#include "test.h"

static void	test_ft_isstuff_sub(int (*f)(int))
{
	char	**temp;
	char	*pch;

	temp = backtrace_symbols((void **)&f, 1);
	pch = strtok (temp[0], " ");
	while (pch != NULL)
	{
		if (!strncmp(pch, "ft_is", 5))
			printf("== test_%s ==\n", pch);
		pch = strtok (NULL, " ");
	}
	return ;
}

void		test_ft_isstuff(int (*f)(int), int (*f2)(int))
{
	test_ft_isstuff_sub(f);
	printf("'%c'  -> %d (%d)\n", 'a', f('a'), f2('a'));
	printf("'%c'  -> %d (%d)\n", 'g', f('g'), f2('g'));
	printf("'%c'  -> %d (%d)\n", 'z', f('z'), f2('z'));
	printf("'%c'  -> %d (%d)\n", 'A', f('A'), f2('A'));
	printf("'%c'  -> %d (%d)\n", 'T', f('T'), f2('T'));
	printf("'%c'  -> %d (%d)\n", 'Z', f('Z'), f2('Z'));
	printf("'%c'  -> %d (%d)\n", '0', f('0'), f2('0'));
	printf("'%c'  -> %d (%d)\n", '4', f('4'), f2('4'));
	printf("'%c'  -> %d (%d)\n", '9', f('9'), f2('9'));
	printf("'%c'  -> %d (%d)\n", ' ', f(' '), f2(' '));
	printf("'\\0' -> %d (%d)\n", f('\0'), f2('\0'));
	printf("'\\n' -> %d (%d)\n", f('\n'), f2('\n'));
	printf("'\\t' -> %d (%d)\n", f('\t'), f2('\t'));
	printf("'%c'  -> %d (%d)\n", '{', f('{'), f2('{'));
	printf("'%c'  -> %d (%d)\n", '&', f('&'), f2('&'));
	printf("'%c'  -> %d (%d)\n", '%', f('%'), f2('%'));
	printf("'%c'  -> %d (%d)\n", '>', f('>'), f2('>'));
	printf("%d   -> %d (%d)\n", -1, f(-1), f2(-1));
	printf("%d  -> %d (%d)\n", 130, f(130), f2(130));
	return ;
}
