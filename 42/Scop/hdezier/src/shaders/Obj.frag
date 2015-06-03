#version 330 core
in vec2				UV;
out vec4			color;
uniform sampler2D	color_map;
void main() {
	color = vec4(texture(color_map, UV).rgb, 1.);
}
