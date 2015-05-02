#version 330 core
flat in int unit;
out vec3 color;
void main() {
	if (unit == 0)
		color = vec3(0.2, 0.2, 0.2);
	else if (unit > 100000000)
		color = vec3(0.7, 0.1, 0.7);
	else if (unit == 2)
		color = vec3(0.5, 0.2, 0.5);
	else if (unit == 3)
		color = vec3(0.5, 0.5, 0.5);
	else
		color = vec3(0.0, 0.0, 0.0);
}
