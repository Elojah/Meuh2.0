#version 330 core
layout(location = 0) in vec3 vertex;
uniform mat4	vp;
void main() {
	gl_Position = vp * vec4(vertex, 1.0);
}
