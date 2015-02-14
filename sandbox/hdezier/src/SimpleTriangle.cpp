#include "SimpleTriangle.hpp"
#include "LoadShaders.h"

SimpleTriangle::SimpleTriangle(void) {
	GLuint			VertexArrayID;
	static const		GLfloat g_vertex_buffer_data[] = {
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f,  1.0f, 0.0f,
	};

	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	glGenBuffers(1, &_vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, _vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
}

SimpleTriangle::~SimpleTriangle(void) {
}

void	SimpleTriangle::draw(void) {
	GLuint	progID;

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, _vertexBuffer);
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
	progID = LoadShaders("shaders/SimpleTriangleVert.glsl", "shaders/SimpleTriangleFrag.glsl" );
	glUseProgram(progID);
}
