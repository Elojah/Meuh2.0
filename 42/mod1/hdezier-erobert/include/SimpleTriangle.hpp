#ifndef SIMPLE_TRIANGLE_H
# define SIMPLE_TRIANGLE_H

# include "IObject.hpp"

class SimpleTriangle : public IObject
{
public:
	SimpleTriangle(void);
	~SimpleTriangle(void);
	void	init(void);
	void	draw(void);
protected:
private:
};

#endif
