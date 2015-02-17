// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Landscape.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/02/06 16:15:57 by erobert           #+#    #+#             //
//   Updated: 2015/02/12 14:17:13 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Landscape.hpp"

Landscape::Landscape(float **map, unsigned int width, unsigned int height):
	_map(map),
	_width(width),
	_height(height)
{}
Landscape::~Landscape(void) {}

void				Landscape::drawPoint(unsigned int x, unsigned int y)
{
	float			z(_map[x][y]);

	if (z < 0.)
		glColor3f(1., 1., 1.);
	else
		glColor3f(z, 1. - z, 0.);
	glVertex3f(x, y * -1., z * 300);
}
void				Landscape::drawObject(void)
{
	unsigned int	x(0);
	unsigned int	y(0);

	while (x + 1 < _width)
	{
		y = 0;
		while (y + 1 < _height)
		{
			drawPoint(x, y);
			drawPoint(x + 1, y);
			drawPoint(x, y + 1);
			drawPoint(x + 1, y + 1);
			y++;
		}
		x++;
	}
}
