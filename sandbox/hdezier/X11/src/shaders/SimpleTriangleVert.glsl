#version 330 core
layout(location = 1) in vec3 vertexColor;
layout(location = 0) in vec3 triangle;
out vec3 fragmentColor;
void	main() {
	gl_Position.xyz = triangle;
	gl_Position.w = 1.0;
	fragmentColor = vertexColor;
}
