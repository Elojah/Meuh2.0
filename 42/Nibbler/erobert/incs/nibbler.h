/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nibbler.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 17:03:39 by erobert           #+#    #+#             */
/*   Updated: 2015/03/27 18:28:07 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NIBBLER_H
# define NIBBLER_H

enum eState
{
	ALIVE,
	DEAD
};

enum eInput
{
	UP,
	LEFT,
	DOWN,
	RIGHT
};

struct sNibbler
{
	int		dir;
	int		x;
	int		y;
}

#endif
