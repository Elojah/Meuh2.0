#include "SimpleTriangle.hpp"
#include "LoadShaders.h"
#include <iostream>

SimpleTriangle::SimpleTriangle(void) {
}

SimpleTriangle::~SimpleTriangle(void) {
	glDeleteBuffers(1, &_vertexBuffer);
	glDeleteVertexArrays(1, &_vertexArrayID);
	glDeleteProgram(_progID);
}

void	SimpleTriangle::init(void) {
	static const		GLfloat g_vertex_buffer_data[] = {
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f, 1.0f, 0.0f
	};

	glGenVertexArrays(1, &_vertexArrayID);
	glBindVertexArray(_vertexArrayID);

	glGenBuffers(1, &_vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, _vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
	_progID = LoadShaders("./src/shaders/SimpleTriangleVert.glsl", "./src/shaders/SimpleTriangleFrag.glsl");
}

void	SimpleTriangle::draw(void) const {

	std::cout << "Draw simple triangle ..." << std::endl;
	glUseProgram(_progID);
	glBindVertexArray(_vertexArrayID);
	glBindBuffer(GL_ARRAY_BUFFER, _vertexBuffer);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(
		0,// attribut 0. Aucune raison particulière pour 0, mais cela doit correspondre au « layout » dans le shader
		3,// taille
		GL_FLOAT,// type
		GL_FALSE,// normalisé ?
		0,// nombre d'octets séparant deux sommets dans le tampon
		(void*)0// décalage du tableau de tampon
	);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDisableVertexAttribArray(0);
	glBindVertexArray(0);
}
