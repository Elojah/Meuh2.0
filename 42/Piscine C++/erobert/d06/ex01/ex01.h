/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 13:41:26 by erobert           #+#    #+#             */
/*   Updated: 2015/01/13 15:19:35 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX01_H
# define EX01_H

# include <string>
# include <iostream>

struct Data
{
	std::string	s1;
	int			n;
	std::string	s2;
};
typedef union	u_u0
{
	int			n;
	char		s[4];
}				t_u0;
typedef struct	s_s0
{
	char		s1[8];
	t_u0		n;
	char		s2[8];
}				t_s0;

void			*serialize(void);
Data			*deserialize(void *raw);

#endif
