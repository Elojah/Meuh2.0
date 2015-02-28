#ifndef LANDSCAPE_H
# define LANDSCAPE_H
# define WIDTH_DIVIDE 40
# define HEIGHT_DIVIDE 40
# define Z_DIVIDE 7000
# define Z_MAX 7000
# define WIDTH_MAP 500
# define HEIGHT_MAP 500
# define Z_MULT 500

# include "IObject.hpp"
# include <string>
# include <vector>

class Landscape : public IObject
{
public:
								Landscape(std::string const&);
								~Landscape(void);
	void						draw(void);
protected:
private:
								Landscape(void);
	typedef struct				s_point {
		unsigned int			x;
		unsigned int			y;
		float					z;
	}							t_point;

	void						assignValue(char *);
	void						smoothMap(void);
	void						smoothPoint(t_point const&, t_point const&);
	void						clearMap(void);
	void						printMap(void) const;
	void						findClosestPoint(t_point const&, t_point&);

	float						_map[WIDTH_MAP + 1][HEIGHT_MAP + 1];
	std::vector<t_point>		_immovablePoints;
};

#endif
