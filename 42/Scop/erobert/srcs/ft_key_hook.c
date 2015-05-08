/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 18:59:58 by erobert           #+#    #+#             */
/*   Updated: 2015/05/08 17:06:12 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include <stdio.h>
int				ft_key_hook(int key, t_env *e)
{
	static float    zoom = .3;
	static float    x = 0.;
	static float    y = 0.;
	static float    z = 0.;

	printf("key: %d\n", key);
	if (key == K_ESC)
		exit(1);
	else if (key == K_PLUS)
	{
		zoom *= 2.;
		glUniform1f(glGetUniformLocation(e->shader_program, "zoom"), zoom);
	}
	else if (key == K_MINUS)
	{
		zoom /= 2.;
		glUniform1f(glGetUniformLocation(e->shader_program, "zoom"), zoom);
	}
	else if (key == K_UP)
	{
		y += .1;
		glUniform1f(glGetUniformLocation(e->shader_program, "y"), y);
	}
	else if (key == K_DOWN)
	{
		y -= .1;
		glUniform1f(glGetUniformLocation(e->shader_program, "y"), y);
	}
	else if (key == K_RIGHT)
	{
		x += .1;
		glUniform1f(glGetUniformLocation(e->shader_program, "x"), x);
	}
	else if (key == K_LEFT)
	{
		x -= .1;
		glUniform1f(glGetUniformLocation(e->shader_program, "x"), x);
	}
	else if (key == K_HOME)
	{
		z += .1;
		glUniform1f(glGetUniformLocation(e->shader_program, "z"), z);
	}
	else if (key == K_END)
	{
		z -= .1;
		glUniform1f(glGetUniformLocation(e->shader_program, "z"), z);
	}
	return (0);
}
