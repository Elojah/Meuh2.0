// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Parser.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/02/17 13:27:56 by hdezier           #+#    #+#             //
//   Updated: 2015/02/17 13:27:56 by hdezier          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PARSER_HPP
# define PARSER_HPP

# define WIDTH_DIVIDE 40
# define HEIGHT_DIVIDE 40
# define Z_MAX 7000
# define WIDTH_MAP 500
# define HEIGHT_MAP 500

# include <vector>

class Parser
{
public:
								Parser(void);
								~Parser(void);

	void						parseFile(char const *);
	float						**getArray(void) const;
	void						printArray(void) const;
protected:
private:
	typedef struct						sPoint {
		unsigned int					x;
		unsigned int					y;
		float							z;
	}									tPoint;
	typedef std::vector<tPoint>			tPoints;
	typedef std::vector<char *>			tCharPs;

	float						**_array;
	tPoints						_mainPoints;

	static tCharPs				parseStrPoints(char const*);
	static char					*getNextDigit(char *);

	void						assignMainPoints(tCharPs&);
	void						clearArray(void);
	void						calculus(void);
	void						calculusPoint(unsigned int i, unsigned int j);
};

#endif
