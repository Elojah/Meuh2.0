#ifndef LANDSCAPE_H
# define LANDSCAPE_H

# include "IObject.hpp"

class Landscape : public IObject
{
public:
	Landscape(void);
	~Landscape(void);
	void	draw(void);
protected:
private:
};

#endif
