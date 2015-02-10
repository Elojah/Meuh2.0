#ifndef MEMBER_TEMPLATE_H
# define MEMBER_TEMPLATE_H

# include <string>

class MemberTemplate
{
public:
	MemberTemplate(const std::string&);
	~MemberTemplate(void);
	std::string											create(const std::string&);
protected:
private:
	std::string		_path;
	MemberTemplate(void);
};

#endif
