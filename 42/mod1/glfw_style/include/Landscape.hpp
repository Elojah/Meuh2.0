// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Landscape.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/30 16:05:12 by hdezier           #+#    #+#             //
//   Updated: 2015/04/30 16:08:19 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef LANDSCAPE_H
# define LANDSCAPE_H

# define WIDTH_DIVIDE 200
# define HEIGHT_DIVIDE 200
# define Z_DIVIDE 7000
# define Z_MAX 7000
# define WIDTH_MAP 100
# define HEIGHT_MAP 100
# define Z_MULT 30

# include "AObject.hpp"

# include <string>
# include <vector>

# include "Rain.hpp"

class Parser;

class Landscape: public AObject
{
public:
						Landscape(std::string const&);
	virtual				~Landscape(void);
	virtual void		init(void);
	virtual void		draw(void) const;
	virtual bool		loop(int const);
	virtual void		refresh(Camera const &cam);
	void				raiseWater(float const);
protected:
private:
	Landscape(void);
	Landscape(Landscape const &rhs);

	Landscape			&operator=(Landscape const &rhs);

	void				lexer(const Parser &p);
	void				initBuffers(void);
	void				smoothMap(void);
	void				smoothPoint(sPoint const&, sPoint const&);
	void				clearMap(void);
	void				useMap(void);
	void				printMap(void) const;
	void				findClosestPoint(sPoint const&, sPoint&) const;
	void				drawPoint(unsigned int const x,
								  unsigned int const y) const;
	std::string			_filename;

	sPoint				_vertex_buffer_data[WIDTH_MAP * HEIGHT_MAP + 1];
	float				_map[WIDTH_MAP + 1][HEIGHT_MAP + 1];
	std::vector<sPoint>	_immovablePoints;
	float				_waterDiff;
	Rain				_rain;
};

#endif
