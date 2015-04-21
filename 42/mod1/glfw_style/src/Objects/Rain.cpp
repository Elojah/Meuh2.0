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

	for (size_t i = 0; i < (MAX_RAIN_PARTICLE + 1) * 3; i += 3) {
		vertex_buffer_data[i] = rand() % HEIGHT_MAP;
		vertex_buffer_data[i + 1] = rand() % 50;
		vertex_buffer_data[i + 2] = rand() % WIDTH_MAP;
	}

	glGenVertexArrays(1, &_vertexArrayID);
	glBindVertexArray(_vertexArrayID);

	_progID = LoadShaders("./src/shaders/MVP.vert", "./src/shaders/Rain.frag");

	glGenBuffers(1, &_vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, _vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_buffer_data), vertex_buffer_data, GL_STATIC_DRAW);
}

void				Rain::draw(void) const {
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

void	Rain::downParticles(GLfloat const land[]) {
	static const int		around[4] = {4, -4, 1 + WIDTH_MAP, -1 - WIDTH_MAP};
	static int				min;
	static bool				down = false;
	int						next;
	size_t					n;

	for (size_t i = 0; i < (MAX_RAIN_PARTICLE + 1) * 3; i += 3) {
		down = false;
		for (size_t j = 0; j < WIDTH_MAP * HEIGHT_MAP * 3; j += 3) {
			// std::cout << "LF rain conflict:\t"
			// 		<< vertex_buffer_data[i] << " =? " << land[j] << std::endl
			// 		<< vertex_buffer_data[i + 1] << " =? " << land[j + 1] << std::endl
			// 		<< vertex_buffer_data[i + 2] << " =? " << land[j + 2] << std::endl;

			if (vertex_buffer_data[i] == land[j]
				&& vertex_buffer_data[i + 1] < land[j + 1]
				&& vertex_buffer_data[i + 2] == land[j + 2]) {
				min = land[j + 1];
				next = -1;
				for (n = 0; n < 4; ++n) {
					if (land[j + around[n]] < min) {
						min = land[j] + around[n];
						next = n;
					}
				}
				if (next != -1) {
					vertex_buffer_data[i] = land[j + around[next] - 1];
					vertex_buffer_data[i + 1] = land[j + around[next]];
					vertex_buffer_data[i + 2] = land[j + around[next] + 1];
					down = true;
					break ;
				}
			}
		}
		if (!down && --vertex_buffer_data[i + 1] < 0) {
			vertex_buffer_data[i] = rand() % HEIGHT_MAP;
			vertex_buffer_data[i + 1] = 50.0f;
			vertex_buffer_data[i + 2] = rand() % WIDTH_MAP;
		}
	}
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_buffer_data), vertex_buffer_data, GL_STATIC_DRAW);
}
