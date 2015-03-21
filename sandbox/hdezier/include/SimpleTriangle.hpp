#ifndef SIMPLE_TRIANGLE_H
# define SIMPLE_TRIANGLE_H
# define GL_GLEXT_PROTOTYPES

# include "IObject.hpp"
# include <GL/gl.h>
# include <GL/glx.h>

class SimpleTriangle : public IObject
{
public:
	SimpleTriangle(void);
	~SimpleTriangle(void);
	void	init(void);
	void	draw(void);
protected:
private:
	GLuint			_vertexBuffer;
	GLuint			_vertexArrayID;
	GLuint			_progID;

};

#endif
