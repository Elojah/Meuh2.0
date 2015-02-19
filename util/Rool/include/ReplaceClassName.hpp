#ifndef REPLACE_CLASS_NAME_H
# define REPLACE_CLASS_NAME_H

# include <string>
# include "TemplateBehavior.hpp"

class ReplaceClassName : public TemplateBehavior
{
public:
	ReplaceClassName(void);
	~ReplaceClassName(void);
	bool		isBehavior(std::string const&);
	std::string	makeBehavior(void);
protected:
	std::map<std::string, lexNameFn>	createMapName(void);
private:
	static std::string						parseOldName(std::string const&);
	static std::string						parseNewName(std::string const&);
};

#endif
