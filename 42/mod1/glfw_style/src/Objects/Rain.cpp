#include "Rain.hpp"
#include "Landscape.hpp"
#include "LoadShaders.h"
#include <cstdlib>
#include <time.h>
#include <iostream>

Rain::Rain(void) {
	srand(time(0));
}

Rain::~Rain(void) {
}

void				Rain::init(void) {

	glGenVertexArrays(1, &_vertexArrayID);
	glBindVertexArray(_vertexArrayID);

	_progID = LoadShaders("./src/shaders/MVP.vert", "./src/shaders/Rain.frag");

	glGenBuffers(1, &_vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, _vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(_vertex_buffer_data), _vertex_buffer_data, GL_STATIC_DRAW);
}

void				Rain::addDrop(sPoint const land[], int index, bool randHeight) {
	size_t			position;

	position = rand() % (HEIGHT_MAP * WIDTH_MAP);
	_vertex_buffer_data[index].x = position / WIDTH_MAP;
	if (!randHeight) {
		_vertex_buffer_data[index].y = 50;
	} else {
		_vertex_buffer_data[index].y = rand() % 50;
	}
	_vertex_buffer_data[index].z = position % WIDTH_MAP;
	// std::cout << "Drop xy:\t" << _vertex_buffer_data[index].x << "\t" << _vertex_buffer_data[index].z << std::endl;
	// std::cout << "Land0xy:\t" << land[position].x << "\t" << land[position].z << std::endl;
	// if (position != 0) {
	// 	std::cout << "Land1xy:\t" << land[position - 1].x << "\t" << land[position - 1].z << std::endl;
	// }
	// if (position != WIDTH_MAP * HEIGHT_MAP) {
	// 	std::cout << "Land2xy:\t" << land[position + 1].x << "\t" << land[position + 1].z << std::endl;
	// }
	(void)_obstacleHeight;
	(void)land;
}

void				Rain::draw(void) const {
	glUseProgram(_progID);
	glUniformMatrix4fv(_matrixID, 1, GL_FALSE, &mvp[0][0]);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, _vertexBuffer);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	glDrawArrays(GL_POINTS, 0, WIDTH_MAP * HEIGHT_MAP);
	glDisableVertexAttribArray(0);
}

bool	Rain::loop(int const key) {
	(void)key;
	return (false);
}

void	Rain::downParticles(sPoint const land[]) {
	static int				downSpeed = 0;
	static bool				down = false;
	static const int		around[4] = {1, -1, WIDTH_MAP, -WIDTH_MAP};
	static int				min;
	int						next;
	size_t					n;

	if (++downSpeed < 0) {
		return ;
	}
	downSpeed = 0;
	for (size_t i = 0; i < MAX_RAIN_PARTICLE; ++i) {
		down = false;
		--_vertex_buffer_data[i].y;
		for (size_t j = 0; j < WIDTH_MAP * HEIGHT_MAP; ++j) {
			if (_vertex_buffer_data[i].x == land[j].x
				&& _vertex_buffer_data[i].z == land[j].z
				&& _vertex_buffer_data[i].y < land[j].y) {

				if (_vertex_buffer_data[i].y <= 0.0f) {
					break ;
				}
				min = land[j].y;
				next = -1;
				for (n = 0; n < 4; ++n) {
					if (j + around[n] < WIDTH_MAP * HEIGHT_MAP
						&& land[j + around[n]].y < min) {
						min = land[j + around[n]].y;
						next = n;
					}
				}
				if (next != -1) {

					// std::cout << "LF rain conflict:\t"
					// 		<< _vertex_buffer_data[i].x << " =? " << land[j].x << std::endl
					// 		<< _vertex_buffer_data[i].z << " =? " << land[j].z << std::endl
					// 		<< _vertex_buffer_data[i].y << " <? " << land[j].y << std::endl
					// 		<< _vertex_buffer_data[i].z << " NEXT Y = " << land[j + around[next]].y + 0.1f << "\t" <<land[j + around[next]].x << "\t" <<land[j + around[next]].z
					// 		<< std::endl;

					_vertex_buffer_data[i].x = land[j + around[next]].x;
					_vertex_buffer_data[i].y = land[j + around[next]].y + 0.1f;
					_vertex_buffer_data[i].z = land[j + around[next]].z;
				}
				down = true;
				break ;
			}
		}
		if (!down && --_vertex_buffer_data[i].y < 0) {
			addDrop(land, i, false);
		}
	}
	glBufferData(GL_ARRAY_BUFFER, sizeof(_vertex_buffer_data), _vertex_buffer_data, GL_STATIC_DRAW);
}
