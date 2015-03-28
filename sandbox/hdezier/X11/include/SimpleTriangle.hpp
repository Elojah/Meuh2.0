#ifndef SIMPLE_TRIANGLE_H
# define SIMPLE_TRIANGLE_H
# define GL_GLEXT_PROTOTYPES

# include "IObject.hpp"

class Camera;

class SimpleTriangle : public IObject
{
public:
	SimpleTriangle(void);
	~SimpleTriangle(void);
	void	draw(void) const;
	void		init(void);
protected:
private:
};

#endif
