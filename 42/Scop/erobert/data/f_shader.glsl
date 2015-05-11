#version 400

uniform sampler2D texture_sampler;
uniform int texture_on;
out vec4 f_color;
in float color;
in vec2 uv;

void	main(void)
{
	if (texture_on == 1)
		f_color = vec4(texture(texture_sampler, uv).rgb, 1.);
	else
		f_color = vec4(color, color, color, 1.);
}