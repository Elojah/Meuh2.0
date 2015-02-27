#include "Landscape.hpp"
#include <fstream>
#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

Landscape::Landscape(void) {
}

Landscape::Landscape(std::string const &filename) {
	std::ifstream		ifs(filename.c_str());
	std::string			line;
	char				*tmp;
	char				*toFree;

	if (ifs.fail()) {
		std::cout << "File doesn't exist." << std::endl;
	}
	while (std::getline(ifs, line)) {
		toFree = strdup(line.c_str());
		tmp = strtok(toFree, "(");
		while (tmp != NULL) {
			if (tmp && *tmp) {
				assignValue(tmp);
			}
			tmp = strtok(NULL, "(");
		}
		free(toFree);
	}
}

Landscape::~Landscape(void) {
}

void	Landscape::assignValue(char *str) {
	std::string		value(str);
	std::size_t		found;
	std::size_t		foundEnd;
	float			x;
	float			y;
	float			z;

	foundEnd = 0;
	found = value.find_first_of("0123456789", foundEnd);
	foundEnd = value.find_first_not_of(".0123456789", found + 1);
	x = strtof(value.substr(found, foundEnd - found).c_str(), NULL);
	found = value.find_first_of("0123456789", foundEnd);
	foundEnd = value.find_first_not_of(".0123456789", found + 1);
	y = strtof(value.substr(found, foundEnd - found).c_str(), NULL);
	found = value.find_first_of("0123456789", foundEnd);
	foundEnd = value.find_first_not_of(".0123456789", found + 1);
	z = strtof(value.substr(found, foundEnd - found).c_str(), NULL);

	x = fmod((x / WIDTH_DIVIDE), WIDTH_MAP);
	y = fmod((y / HEIGHT_DIVIDE), HEIGHT_MAP);
	z = fmod((z / Z_DIVIDE), Z_MAX);

	std::cout << "Assign value: " << z << " at point (" << x << ", " << y << ")" << std::endl;
	_immovablePoints.push_back((t_point){static_cast<unsigned int>(x), static_cast<unsigned int>(y), z});
	_map[static_cast<unsigned int>(x)][static_cast<unsigned int>(y)] = z;
}

void	Landscape::smoothMap(void) {
	t_point		closestPoint;
	float		slope;

	for (std::vector<t_point>::iterator it = _immovablePoints.begin(); it != _immovablePoints.end(); ++it) {
		Landscape::findClosestPoint((*it), closestPoint);
		slope = (closestPoint.z - it->z) / sqrt(pow(it->x - closestPoint.x, 2) + pow(it->y - closestPoint.y, 2));
		recursiveFill(it->x, it->y, it->z, slope);
	}
}

void	Landscape::recursiveFill(unsigned int x, unsigned int y, float z, float const &slope) {
	if (x > WIDTH_MAP || y > HEIGHT_MAP || z <= 0 || z < _map[x][y]) {
		return ;
	}
	_map[x][y] = z;
	z -= slope;
	recursiveFill(x - 1, y, z, slope);
	recursiveFill(x + 1, y, z, slope);
	recursiveFill(x, y - 1, z, slope);
	recursiveFill(x, y + 1, z, slope);
}

void	Landscape::findClosestPoint(t_point const &origin, t_point &closest) {
	unsigned int	xDist;
	unsigned int	yDist;

	xDist = origin.x > WIDTH_MAP / 2 ? WIDTH_MAP - origin.x : origin.x;
	yDist = origin.y > HEIGHT_MAP / 2 ? HEIGHT_MAP - origin.y : origin.y;
	if (xDist > yDist) {
		closest.x = origin.x;
		closest.y = origin.y > HEIGHT_MAP / 2 ? HEIGHT_MAP : 0;
	} else {
		closest.x = origin.x > WIDTH_MAP / 2 ? WIDTH_MAP : 0;
		closest.y = origin.y;
	}
	closest.z = 0;
}

void	Landscape::draw(void) {
	;
}
