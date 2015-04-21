#ifndef RAIN_H
# define RAIN_H

# define MAX_RAIN_PARTICLE 1000
# include "AObject.hpp"
class AObject;

class Rain : public AObject
{
public:
	Rain(void);
	virtual ~Rain(void);
	virtual void	init(void);
	virtual void	draw(void) const;
	virtual bool	loop(int const);
	void			downParticles(GLfloat const land[]);
protected:
private:
	GLfloat		vertex_buffer_data[(MAX_RAIN_PARTICLE + 1) * 3];
};

#endif
