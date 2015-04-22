#version 330 core
layout(location = 0) in vec2 vertexCoord;
void main() {
	gl_Position.xy = vertexCoord;
	gl_Position.z = 0.0;
	gl_Position.w = 1.0;
}
