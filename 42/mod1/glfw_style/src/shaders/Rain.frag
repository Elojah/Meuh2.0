#version 330 core
in float zHeight;
out vec3 color;
void main() {
	color = vec3(0.0f, 0.0f, 0.9f + zHeight / 200);
}
