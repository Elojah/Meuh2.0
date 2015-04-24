#ifndef MAP_H
# define MAP_H

# include <vector>
class AObject;
class Camera;

class Map
{
public:
	Map(void);
	~Map(void);
	void	addObject(AObject *obj);
	void	draw(void) const;
	void	refresh(Camera const &cam) const;
protected:
private:
	std::vector<AObject *>	_objects;
};

#endif
