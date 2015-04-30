#ifndef SEA_H
# define SEA_H

# include "AObject.hpp"
class AObject;

class Sea : public AObject
{
public:
	Sea(void);
	virtual ~Sea(void);
	virtual void	init(void);
	virtual void	draw(void) const;
	virtual bool	loop(int const);
	void			setHeight(float waterHeight);
protected:
private:
	sPoint			_vertex_buffer_data[8];
};

#endif
