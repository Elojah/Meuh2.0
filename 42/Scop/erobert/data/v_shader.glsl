#version 400

uniform float sinus;
uniform float cosinus;
uniform mat4 mvp;

in vec4 vertex;

out sData
{
	float color;
	vec2 uv;
};

void		main(void)
{
	gl_Position.x = vertex.x * cosinus - vertex.z * sinus;
	gl_Position.y = vertex.y;
	gl_Position.z = vertex.z * cosinus + vertex.x * sinus;
	gl_Position.w = 1.;
	gl_Position = mvp * gl_Position;
	color = vertex.w;
	uv.xy = vertex.yz;
}