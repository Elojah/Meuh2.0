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
	clearMap();
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
	smoothMap();
	useMap();
	// printMap();
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
	found = value.find_first_of("0123456789", foundEnd + 1);
	foundEnd = value.find_first_not_of(".0123456789", found);
	y = strtof(value.substr(found, foundEnd - found).c_str(), NULL);
	found = value.find_first_of("0123456789", foundEnd + 1);
	foundEnd = value.find_first_not_of(".0123456789", found);
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

	for (std::vector<t_point>::iterator it = _immovablePoints.begin(); it != _immovablePoints.end(); ++it) {
		findClosestPoint((*it), closestPoint);
		std::cout << "Closest point from:\t" << it->x << ", " << it->y << ", " << it->z << std::endl
		<< "found at:\t\t" << closestPoint.x << ", " << closestPoint.y << ", " << closestPoint.z << std::endl;
		smoothPoint(*it, closestPoint);
		std::cout << "Fill map: DONE" << std::endl;
	}
}

void	Landscape::smoothPoint(t_point const &originPoint, t_point const &closestPoint) {
	unsigned int	i;
	unsigned int	j;
	float			z;
	float			dist;
	float			maxDist;

	if (originPoint.z == 0.) {
		return ;
	}
	maxDist = (pow(originPoint.x > closestPoint.x ? originPoint.x - closestPoint.x : closestPoint.x - originPoint.x, 2)
			+ pow(originPoint.y > closestPoint.y ? originPoint.y - closestPoint.y : closestPoint.y - originPoint.y, 2));
	std::cout << "Dist: " << (maxDist) << std::endl;
	for (i = 0; i < WIDTH_MAP; ++i) {
		for (j = 0; j < HEIGHT_MAP; ++j) {
			dist = pow(originPoint.x > i ? originPoint.x - i : i - originPoint.x, 2)
					+ pow(originPoint.y > j ? originPoint.y - j : j - originPoint.y, 2);
			if (dist != 0. && dist < maxDist) {
				z = ((sin((M_PI / 2) + sqrt(dist / maxDist) * M_PI) + 1.) / 2.) * (originPoint.z);
				if (_map[i][j] == -1.) {
					_map[i][j] = z;
				} else {
					_map[i][j] += z;
				}
				// } else if (_map[i][j] <= z) {
				// 	_map[i][j] = z + magicFunction(_map[i][j]);
				// } else if (_map[i][j] > z) {
				// 	_map[i][j] = _map[i][j] + magicFunction(z);
				// }
			}
		}
	}
}

void		Landscape::printMap(void) const {
	unsigned int	i;
	unsigned int	j;

	for (i = 0; i < WIDTH_MAP; ++i) {
		for (j = 0; j < HEIGHT_MAP; ++j) {
			// if (_map[i][j] != 0.) {
				std::cout << _map[i][j] << "\t";
			// }
		}
		std::cout << std::endl;
	}
}

void		Landscape::clearMap(void) {
	unsigned int	i;
	unsigned int	j;

	for (i = 0; i < WIDTH_MAP; ++i) {
		for (j = 0; j < HEIGHT_MAP; ++j) {
			_map[i][j] = -1.;
		}
	}
}

void		Landscape::useMap(void) {
	unsigned int	i;
	unsigned int	j;

	for (i = 0; i < WIDTH_MAP; ++i) {
		for (j = 0; j < HEIGHT_MAP; ++j) {
			if (_map[i][j] == -1.) {
				_map[i][j] = 0.;
			}
		}
	}
}

void	Landscape::findClosestPoint(t_point const &origin, t_point &closest) const {
	unsigned int	xDist;
	unsigned int	yDist;
	unsigned int	xTmp;
	unsigned int	yTmp;
	unsigned int	dist;


	xDist = origin.x > WIDTH_MAP / 2 ? WIDTH_MAP - origin.x : origin.x;
	yDist = origin.y > HEIGHT_MAP / 2 ? HEIGHT_MAP - origin.y : origin.y;
	if (xDist > yDist) {
		closest.x = origin.x;
		closest.y = origin.y > HEIGHT_MAP / 2 ? HEIGHT_MAP : 0;
		xDist = 0;
	} else {
		closest.x = origin.x > WIDTH_MAP / 2 ? WIDTH_MAP : 0;
		closest.y = origin.y;
		yDist = 0;
	}
	closest.z = 0;

	dist = xDist * xDist + yDist * yDist;
	for (std::vector<t_point>::const_iterator it = _immovablePoints.begin(); it != _immovablePoints.end(); ++it) {
		xTmp = it->x > origin.x ? it->x - origin.x : origin.x - it->x;
		yTmp = it->y > origin.y ? it->y - origin.y : origin.y - it->y;
		if ((xTmp != 0 || yTmp != 0)
			&& xTmp * xTmp + yTmp * yTmp < dist) {
			closest.x = it->x;
			closest.y = it->y;
			closest.z = it->z;
			dist = xTmp * xTmp + yTmp * yTmp;
		}
	}
}

void	Landscape::drawPoint(unsigned int const x, unsigned int const y) const {
	static float		z;

	z = _map[x][y];
	if (z < 0.15) {
		glColor3f(z, z, 0.7 + z);
	} else if (z < 0.155) {
		glColor3f(1., 1., 1 - z);
	} else if (z < 0.4) {
		glColor3f(0.2, z, 0.2);
	} else if (z < 0.7) {
		glColor3f(0.1 + z, z, 0.1);
	} else {
		glColor3f(0.9, 0.8, 0.7);
	}
	glVertex3f(x, y, z * Z_MULT);
}

void	Landscape::draw(void) {
	unsigned int	x;
	unsigned int	y;

	for (x = 0; x < WIDTH_MAP - 1; ++x) {
		for (y = 0; y < HEIGHT_MAP - 1; ++y) {
			drawPoint(x, y);
			drawPoint(x + 1, y);
			drawPoint(x + 1, y + 1);
			drawPoint(x, y + 1);
		}
	}
}
