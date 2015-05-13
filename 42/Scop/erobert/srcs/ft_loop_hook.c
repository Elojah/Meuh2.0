/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 18:59:45 by erobert           #+#    #+#             */
/*   Updated: 2015/05/13 19:43:57 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "scop.h"

int					ft_loop_hook(t_env *e)
{
	static float	angle = 0.;
	static int		texture_on = 0;
	static float	var = 0.;

	if (texture_on != e->texture_on)
		texture_on = e->texture_on;
	if (e->texture_on && var < 1.)
	{
		var += .001;
		glUniform1f(glGetUniformLocation(e->shader_program, "var"), var);
	}
	else if (!e->texture_on && var > 0.)
	{
		var -= .001;
		glUniform1f(glGetUniformLocation(e->shader_program, "var"), var);
	}
	angle += .05;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUniform1f(glGetUniformLocation(e->shader_program, "sinus"), sin(angle));
	glBindVertexArray(e->vertex_array);
	glUniform1f(glGetUniformLocation(e->shader_program, "cosinus"), cos(angle));
	glBindVertexArray(e->vertex_array);
	glDrawArrays(GL_TRIANGLES, 0, e->buffer_size * sizeof(t_vertex));
	mlx_opengl_swap_buffers(e->win_ptr);
	return (0);
}
