#ifndef MEMBER_LIST_H
# define MEMBER_LIST_H

# include <string>
# include "Menu.hpp"
# include "IModule.hpp"

class MemberList : public IModule, public Menu
{
public:
	MemberList(int, int, int, int);
	~MemberList(void);
	void		init(const std::string&, const std::string&);
protected:
private:
	std::string		_path;
	std::string		_name;

	MemberList(void);
	void		createItems(void);
	void		newMember(ITEM *);
};

#endif
