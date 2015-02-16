/*
* @Author: Latias
* @Date:   2015-02-13 10:41:52
* @Last Modified by:   Latias
* @Last Modified time: 2015-02-13 10:50:54
*/

# include <vector>
#include "X11Win.hpp"
#include "IObject.hpp"
#include "SimpleTriangle.hpp"

int main(void) {
	X11Win			win(800, 600);
	std::vector<IObject>	objects;

	SimpleTriangle	t;

	win.init();
	objects.push_back(t);

	t.draw();/*draw all objects ?*/

	win.loop(objects);
	return (0);
}
