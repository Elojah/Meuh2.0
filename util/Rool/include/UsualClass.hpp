#ifndef USUAL_CLASS_H
# define USUAL_CLASS_H

# include "TemplateBehavior.hpp"

class UsualClass : public TemplateBehavior
{
public:
	UsualClass(void);
	~UsualClass(void);
	bool		isBehavior(std::string const&);
	std::string	makeBehavior(void);
protected:
	std::map<std::string, lexNameFn>											createMapName(void);
	loopMap																		createLoopMapName(void);
private:
};

#endif
