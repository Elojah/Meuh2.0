/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 18:59:45 by erobert           #+#    #+#             */
/*   Updated: 2015/05/11 12:33:25 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int					ft_loop_hook(t_env *e)
{
	static float	angle = 0.;

	angle += .05;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUniform1f(glGetUniformLocation(e->shader_program, "angle"), angle);
	glBindVertexArray(e->vertex_array);
	glDrawArrays(GL_TRIANGLES, 0, e->buffer_size * sizeof(t_vertex));
	mlx_opengl_swap_buffers(e->win_ptr);
	return (0);
}
