#ifndef I_OBJECT_H
# define I_OBJECT_H

# include <GL/gl.h>
# include <GL/glx.h>

class IObject
{
public:
	virtual ~IObject(void){}
	virtual void	draw(void){}
	virtual void	loop(void){
		glBindVertexArray(_vertexArrayID);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glBindVertexArray(0);
	}
protected:
	GLuint			_vertexBuffer;
	GLuint			_vertexArrayID;
	GLuint			_progID;
private:
};

#endif
