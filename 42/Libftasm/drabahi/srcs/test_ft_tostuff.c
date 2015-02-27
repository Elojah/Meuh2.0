/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_tostuff.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabahi <drabahi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 19:06:28 by drabahi           #+#    #+#             */
/*   Updated: 2015/02/22 19:06:28 by drabahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <execinfo.h>
#include "test.h"

static void	test_ft_tostuff_sub(int (*f)(int))
{
	char	**temp;
	char	*pch;

	temp = backtrace_symbols((void **)&f, 1);
	pch = strtok (temp[0], " ");
	while (pch != NULL)
	{
		if (!strncmp(pch, "ft_", 3))
			printf("== test_%s ==\n", pch);
		pch = strtok (NULL, " ");
	}
	return ;
}

void		test_ft_tostuff(int (*f)(int), int (*f2)(int))
{
	test_ft_tostuff_sub(f);
	printf("'%c'  -> %c (%c)\n", 'a', f('a'), f2('a'));
	printf("'%c'  -> %c (%c)\n", 'g', f('g'), f2('g'));
	printf("'%c'  -> %c (%c)\n", 'z', f('z'), f2('z'));
	printf("'%c'  -> %c (%c)\n", 'A', f('A'), f2('A'));
	printf("'%c'  -> %c (%c)\n", 'T', f('T'), f2('T'));
	printf("'%c'  -> %c (%c)\n", 'Z', f('Z'), f2('Z'));
	printf("'%c'  -> %c (%c)\n", '0', f('0'), f2('0'));
	printf("'%c'  -> %c (%c)\n", '4', f('4'), f2('4'));
	printf("'%c'  -> %c (%c)\n", '9', f('9'), f2('9'));
	printf("'%c'  -> %c (%c)\n", ' ', f(' '), f2(' '));
	printf("'\\0' -> %c (%c)\n", f('\0'), f2('\0'));
	printf("'%c'  -> %c (%c)\n", '{', f('{'), f2('{'));
	printf("'%c'  -> %c (%c)\n", '&', f('&'), f2('&'));
	printf("'%c'  -> %c (%c)\n", '%', f('%'), f2('%'));
	printf("'%c'  -> %c (%c)\n", '>', f('>'), f2('>'));
	printf("%d   -> %d (%d)\n", -1, f(-1), f2(-1));
	printf("%d  -> %d (%d)\n", 130, f(130), f2(130));
	return ;
}
