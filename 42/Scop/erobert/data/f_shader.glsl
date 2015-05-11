#version 400

uniform sampler2D texture_sampler;
uniform int texture_on;
uniform float var;
out vec4 f_color;
in float color;
in vec2 uv;

void		main(void)
{
	vec3	tmp;

	tmp = vec3(color, color, color);
	tmp *= 1 - var;		
	if (texture_on == 1)
		f_color = vec4(texture(texture_sampler, uv).rgb * var + tmp, 1.);
	else
		f_color = vec4(texture(texture_sampler, uv).rgb * var + tmp, 1.);
}