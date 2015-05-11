#version 330 core
in vec2				UV;
out vec3			color;
uniform sampler2D	text_sampler;
void main() {
	color = texture(text_sampler, UV).rgb;
}
