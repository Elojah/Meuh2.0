#version 400

uniform float angle;
uniform mat4 view;
uniform mat4 projection;
in vec4 vertex;
out float color;

void		main(void)
{
	gl_Position.x = vertex.x * cos(angle) - vertex.z * sin(angle);
	gl_Position.y = vertex.y;
	gl_Position.z = vertex.z * cos(angle) + vertex.x * sin(angle);
	gl_Position.w = 1.;
	gl_Position = projection * view * gl_Position;
	color = vertex.w;
}