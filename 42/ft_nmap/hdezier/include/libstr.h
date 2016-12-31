/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libstr.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 14:02:55 by leeios            #+#    #+#             */
/*   Updated: 2016/12/30 14:16:14 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_STR_H
# define LIB_STR_H

int		ft_strcmp(const char *lhs, const char *rhs);
int		ft_strncmp(const char *lhs,const char *rhs, int n);
int		ft_uatoi(char **s);
char	*get_next_token(char **s, char c);

#endif
