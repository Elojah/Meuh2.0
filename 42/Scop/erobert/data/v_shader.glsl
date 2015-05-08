#version 400

uniform float x;
uniform float y;
uniform float z;
uniform float angle;
uniform float zoom;
uniform mat4 proj;
uniform mat4 view, projection;
in vec3 vertex;
out vec3 color;

void		main(void)
{
	gl_Position.x = vertex.x * cos(angle) - vertex.z * sin(angle) + x;
	gl_Position.y = vertex.y + y;
	gl_Position.z = vertex.z * cos(angle) + vertex.x * sin(angle) + z;
	gl_Position *= zoom;
	gl_Position.w = 1.;
	gl_Position = projection * view * gl_Position;
	color = vertex;
}