/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_vertex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 16:31:54 by erobert           #+#    #+#             */
/*   Updated: 2015/05/12 16:33:22 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		ft_get_vertex(t_vertex *vbd, char *line)
{
	while (*line == ' ')
		line++;
	vbd->x = ft_atof(line);
	while (*line && *line != ' ')
		line++;
	while (*line == ' ')
		line++;
	vbd->y = ft_atof(line);
	while (*line && *line != ' ')
		line++;
	while (*line == ' ')
		line++;
	vbd->z = ft_atof(line) - 1;
}
