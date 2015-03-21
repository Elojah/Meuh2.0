#ifndef I_OBJECT_H
# define I_OBJECT_H

#include <OpenGL/OpenGL.h>
#include <OpenGL/gl3.h>
#include <iostream>

class IObject
{
public:
	virtual ~IObject(void){};
	virtual void	draw(void) = 0;
	virtual bool	loop(int const) = 0;
protected:
	GLuint			_vertexBuffer;
	GLuint			_vertexArrayID;
	GLuint			_progID;
private:
};

#endif
