#version 330 core
layout(location = 0) in vec3 triangle;
void	main() {
	gl_Position.xyz = triangle;
	gl_Position.w = 1.0;
}
