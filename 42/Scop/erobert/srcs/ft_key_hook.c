/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 18:59:58 by erobert           #+#    #+#             */
/*   Updated: 2015/05/13 19:38:10 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static void	ft_move_object(int key, t_env *e)
{
	float	tmp[32];
	GLint	location;

	if (key == K_UP)
		ft_translation_matrix(tmp, 0., 0., -.1);
	else if (key == K_DOWN)
		ft_translation_matrix(tmp, 0., 0., .1);
	else if (key == K_LEFT)
		ft_translation_matrix(tmp, -.1, 0., 0.);
	else if (key == K_RIGHT)
		ft_translation_matrix(tmp, .1, 0., 0.);
	else if (key == K_PLUS)
		ft_translation_matrix(tmp, 0., .1, 0.);
	else if (key == K_MINUS)
		ft_translation_matrix(tmp, 0., -.1, 0.);
	ft_multmatrix(tmp + 16, e->projection, tmp);
	ft_memcpy(e->projection, tmp + 16, sizeof(float) * 16);
	ft_multmatrix(tmp, e->projection, e->view);
	location = glGetUniformLocation(e->shader_program, "mvp");
	glUniformMatrix4fv(location, 1, 0, tmp);
}

static void	ft_move_camera(int key, t_env *e)
{
	float	move[3];
	GLint	location;
	GLfloat	mvp[16];

	move[0] = 0.;
	move[1] = 0.;
	move[2] = 0.;
	if (key == K_W)
		move[2] = .1;
	else if (key == K_S)
		move[2] = -.1;
	else if (key == K_A)
		move[0] = .1;
	else if (key == K_D)
		move[0] = -.1;
	e->eye[0] += move[0];
	e->eye[2] += move[2];
	e->at[0] += move[0];
	e->at[2] += move[2];
	ft_lookat(e, e->eye, e->at);
	ft_multmatrix(mvp, e->projection, e->view);
	location = glGetUniformLocation(e->shader_program, "mvp");
	glUniformMatrix4fv(location, 1, 0, mvp);
}

int			ft_key_hook(int key, t_env *e)
{
	GLint	location;

	if (key == K_ESC)
		exit(1);
	if ((key >= K_A && key <= K_D) || key == K_W || key == K_Q || key == K_E)
		ft_move_camera(key, e);
	else if ((key <= K_UP && key >= K_LEFT) || key == K_PLUS || key == K_MINUS)
		ft_move_object(key, e);
	else if (key == K_T)
	{
		e->texture_on = !e->texture_on;
		location = glGetUniformLocation(e->shader_program, "texture_on");
		glUniform1i(location, e->texture_on);
	}
	return (0);
}
