#ifndef SIMPLE_TRIANGLE_H
# define SIMPLE_TRIANGLE_H
# define GL_GLEXT_PROTOTYPES

# include "IObject.hpp"

class Camera;

class SimpleTriangle : public IObject
{
public:
	SimpleTriangle(Camera const &cam);
	~SimpleTriangle(void);
	void	draw(void) const;
protected:
private:
	SimpleTriangle(void);
};

#endif
