/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 18:59:45 by erobert           #+#    #+#             */
/*   Updated: 2015/05/07 19:01:33 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int					ft_loop_hook(t_env *e)
{
	static float	angle = 0.;

	angle += .05;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUniform1f(glGetUniformLocation(e->shader_programme, "angle"), angle);
	glBindVertexArray(e->vertex_array);
	glDrawArrays(GL_TRIANGLES, 0, e->buffer_size * 3);
	mlx_opengl_swap_buffers(e->win_ptr);
	return (0);
}
