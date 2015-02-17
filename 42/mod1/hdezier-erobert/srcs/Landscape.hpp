// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Landscape.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/02/06 16:11:06 by erobert           #+#    #+#             //
//   Updated: 2015/02/08 15:19:36 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef LANDSCAPE_HPP
# define LANDSCAPE_HPP

# include <GL/gl.h>
# include "IObject.hpp"

class Landscape: public IObject
{
private:
	float				**_map;
	unsigned int		_width;
	unsigned int		_height;

	Landscape(void);
	Landscape(Landscape const &l, unsigned int width);

	Landscape			&operator=(Landscape const &l);
public:
	Landscape(float **map, unsigned int width, unsigned int height);
	virtual ~Landscape(void);

	void				drawPoint(unsigned int x, unsigned int y);
	virtual void		drawObject(void);
};

#endif
