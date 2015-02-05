#ifndef MOD_MEMBERLIST_H
# define MOD_MEMBERLIST_H

#include "WinCurse_menu.h"

class Mod_memberList : public WinCurse_menu
{
public:
	Mod_memberList(void);
	Mod_memberList(int h, int w, int y, int x);
	~Mod_memberList(void);
	void	init(std::string, std::string);
protected:
private:
	std::string			_path;
	std::string			_class;

	void							_showClass(void);
	std::vector<std::string>		_parseAttributes(void);
	std::vector<std::string>		_parseMethods(void);
};

#endif

