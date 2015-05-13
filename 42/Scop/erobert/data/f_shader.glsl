#version 400

uniform sampler2D color_map;
uniform int texture_on;
uniform float var;

in sData
{
	float color;
	vec2 uv;
};

out vec4 f_color;

void		main(void)
{
	vec3	tmp;

	tmp = vec3(color, color, color);
	tmp *= 1 - var;		
	if (texture_on == 1)
		f_color = vec4(texture(color_map, uv).rgb * var + tmp, 1.);
	else
		f_color = vec4(texture(color_map, uv).rgb * var + tmp, 1.);
}