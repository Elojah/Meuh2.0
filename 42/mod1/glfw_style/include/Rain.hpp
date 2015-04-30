#ifndef RAIN_H
# define RAIN_H

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
	float			downParticles(sPoint const land[], float const &waterHeight);
	void			addDrop(sPoint const land[], int index, bool randHeight);
protected:
private:
	sPoint		_vertex_buffer_data[MAX_RAIN_PARTICLE + 1];
	GLfloat		_obstacleHeight[MAX_RAIN_PARTICLE + 1];
};

#endif
