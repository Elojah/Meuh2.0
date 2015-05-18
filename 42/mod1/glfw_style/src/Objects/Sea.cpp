#include "Sea.hpp"
#include "LoadShaders.h"
#include <iostream>

Sea::Sea(void) {
}

Sea::~Sea(void) {
}

void	Sea::init(void) {
	static const GLubyte index_buffer_data[36] = {
		0, 1, 2,
		1, 2, 3,
		4, 6, 7,
		4, 5, 7,
		0, 1, 4,
		1, 4, 5,
		1, 3, 5,
		3, 5, 7,
		0, 2, 4,
		2, 4, 6,
		2, 3, 6,
		3, 6, 7
	};

	for (size_t i = 0; i < 8; ++i) {
		_vertex_buffer_data[i].x = i % 2 ? WIDTH_MAP : 0.0f;
		_vertex_buffer_data[i].y = -0.01f;
		_vertex_buffer_data[i].z = (i / 2) % 2 ? HEIGHT_MAP : 0.0f;
	}
	glGenVertexArrays(1, &_vertexArrayID);
	glBindVertexArray(_vertexArrayID);

	_progID = LoadShaders("./src/shaders/MVP.vert", "./src/shaders/Sea.frag");

	glGenBuffers(1, &_vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, _vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(_vertex_buffer_data)
		, _vertex_buffer_data, GL_DYNAMIC_DRAW);

	glGenBuffers(1, &_indexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(index_buffer_data)
		, index_buffer_data, GL_STATIC_DRAW);
}

void	Sea::draw(void) const {
	glUseProgram(_progID);
	glUniformMatrix4fv(_matrixID, 1, GL_FALSE, &mvp[0][0]);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, _vertexBuffer);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _indexBuffer);
	glDrawElements(
		GL_TRIANGLES,
		36,
		GL_UNSIGNED_BYTE,
		BUFFER_OFFSET(0)
	);
	glDisableVertexAttribArray(0);
}

void			Sea::wave(void) {
	static float	tumult = 0.0f;
	static float	derivedTumult = TUMULT_DER;

	for (size_t i = 4; i < 8; ++i) {
		_vertex_buffer_data[i].y += (tumult * (i % 2 ? 1 : -1));
		if (_vertex_buffer_data[i].y <= 0.0f) {
			_vertex_buffer_data[i].y = 0.01f;
		}
	}
	tumult += derivedTumult;
	if (tumult <= -TUMULT_VAL || tumult >= TUMULT_VAL) {
		derivedTumult *= -1;
	}
	glBindBuffer(GL_ARRAY_BUFFER, _vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(_vertex_buffer_data)
		, _vertex_buffer_data, GL_DYNAMIC_DRAW);
}

void			Sea::setHeight(float waterHeight) {
	for (size_t i = 4; i < 8; ++i) {
		_vertex_buffer_data[i].y = waterHeight;
	}
	glBindBuffer(GL_ARRAY_BUFFER, _vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(_vertex_buffer_data)
		, _vertex_buffer_data, GL_DYNAMIC_DRAW);
}

bool	Sea::loop(int const key) {
	(void)key;
	return (false);
}
