#version 400

out vec4 frag_colour;
in float color;

void	main(void)
{
	frag_colour = vec4(color, color, color, 1.);
}