#version 400

uniform float angle;
uniform mat4 view;
uniform mat4 projection;
in vec4 vertex;
out float color;

layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec2 vertexUV;
 
// Output data ; will be interpolated for each fragment.
out vec2 uv;

void		main(void)
{
	gl_Position.x = vertex.x * cos(angle) - vertex.z * sin(angle);
	gl_Position.y = vertex.y;
	gl_Position.z = vertex.z * cos(angle) + vertex.x * sin(angle);
	gl_Position.w = 1.;
	gl_Position = projection * view * gl_Position;
	color = vertex.w;
	uv.xy = vertex.yz;
}