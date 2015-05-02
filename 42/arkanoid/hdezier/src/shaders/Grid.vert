#version 330 core
layout(location = 0) in vec2 vertex;
layout(location = 1) in int unit_type;
out float unit;
void main() {
	gl_Position.xy = vertex * 2.0 - 0.98;
	gl_Position.z = 0.0;
	unit = float(unit_type);
}
