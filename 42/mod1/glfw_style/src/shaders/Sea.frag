#version 330 core
in float zHeight;
out vec3 color;
void main() {
	color = vec3(0.1, 0.1, 0.7 - zHeight / 100);
}
