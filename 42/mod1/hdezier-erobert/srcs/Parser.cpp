// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Parser.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/02/17 13:27:51 by hdezier           #+#    #+#             //
//   Updated: 2015/02/17 13:27:52 by hdezier          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Parser.hpp"
#include <iostream>
#include <fstream>
#include <cmath>
#include <string.h>
#include <stdlib.h>
Parser::Parser(void) {
	unsigned int	i;

	_array = (float **)malloc(sizeof(float *) * (WIDTH_MAP + 1));
	for (i = 0; i < WIDTH_MAP; i++) {
		_array[i] = (float *)malloc(sizeof(float) * (HEIGHT_MAP + 1));
	}
	_mainPoints.push_back((tPoint){0, 0, 0});
	_mainPoints.push_back((tPoint){WIDTH_MAP, 0, 0});
	_mainPoints.push_back((tPoint){0, HEIGHT_MAP, 0});
	_mainPoints.push_back((tPoint){WIDTH_MAP, HEIGHT_MAP, 0});
}
Parser::~Parser(void) {
	unsigned int	i;

	for (i = 0; i < WIDTH_MAP; i++) {
		free(_array[i]);
	}
	free(_array);
}

void		Parser::parseFile(char const *fileName) {
	tCharPs				strPoints;

	clearArray();
	strPoints = parseStrPoints(fileName);
	assignMainPoints(strPoints);
	/*strPoints is invalid after assignMainPoints (segfault)*/
	calculus();
}

float		**Parser::getArray(void) const {
	return(_array);
}

void		Parser::printArray(void) const {
	unsigned int	i;
	unsigned int	j;

	for (i = 0; i < WIDTH_MAP; ++i) {
		for (j = 0; j < HEIGHT_MAP; ++j) {
			// if (_array[i][j] != 0) {
				std::cout << static_cast<int>(_array[i][j]) << " ";
			// }
		}
		std::cout << std::endl;
	}
}

std::vector<char *>	Parser::parseStrPoints(char const *fileName) {
	std::ifstream		ifs(fileName);
	std::string			line;
	char				*tmp;
	char				*toFree;
	tCharPs				result;

	if (ifs.fail()) {
		std::cout << "File doesn't exist." << std::endl;
		return (tCharPs());
	}
	while (std::getline(ifs, line)) {
		toFree = strdup(line.c_str());
		tmp = strtok(toFree, "(");
		while (tmp != NULL) {
			if (tmp && *tmp) {
				result.push_back(strdup(tmp));
			}
			tmp = strtok(NULL, "(");
		}
		free(toFree);
	}
	return (result);
}

char	*Parser::getNextDigit(char *str) {
	char	*result;

	result = str;
	while (result && *result) {
		if (std::isdigit(*result)) {
			return (result);
		}
		result++;
	}
	return (str);
}

void	Parser::assignMainPoints(std::vector<char *> &strPoints) {
	char				*tmp;
	char				*value;
	float				x;
	float				y;
	float				z;

	for (tCharPs::iterator it = strPoints.begin(); it != strPoints.end(); ++it) {
		value = getNextDigit(*it);
		x = strtof(value, &tmp);
		value = getNextDigit(tmp);
		y = strtof(value, &tmp);
		value = getNextDigit(tmp);
		z = strtof(value, &tmp);
		x /= WIDTH_DIVIDE;
		y /= HEIGHT_DIVIDE;
		z /= Z_MAX;
		if (x > WIDTH_MAP || x < 0) {
			x = 0.0f;
		}
		if (y > HEIGHT_MAP || y < 0) {
			y = 0.0f;
		}
		if (z > 1. || z < 0) {
			z = 0.0f;
		}
		std::cout << "Assign value: " << z << " at point (" << x << ", " << y << ")" << std::endl;
		_mainPoints.push_back((tPoint){static_cast<unsigned int>(x), static_cast<unsigned int>(y), z});
		_array[static_cast<unsigned int>(x)][static_cast<unsigned int>(y)] = z;
	}
}

void		Parser::clearArray(void) {
	unsigned int	i;
	unsigned int	j;

	for (i = 0; i < WIDTH_MAP; ++i) {
		for (j = 0; j < HEIGHT_MAP; ++j) {
			_array[i][j] = 0;
		}
	}
}

void		Parser::calculus(void) {
	unsigned int	i;
	unsigned int	j;

	for (i = 0; i < WIDTH_MAP; ++i) {
		for (j = 0; j < HEIGHT_MAP; ++j) {
			calculusPoint(i, j);
		}
	}
}

void		Parser::calculusPoint(unsigned int i, unsigned int j) {
	float	dist;

	for (tPoints::iterator it = _mainPoints.begin(); it != _mainPoints.end(); ++it) {
		if (i == it->x && j == it->y) {
			continue ;
		}
		dist = 0;
		dist += i > it->x ? (i - it->x) : (it->x - i);
		dist += j > it->y ? (j - it->y) : (it->y - j);
		_array[i][j] += (1. - (dist / (WIDTH_MAP + HEIGHT_MAP))) / _mainPoints.size();
	}
}
