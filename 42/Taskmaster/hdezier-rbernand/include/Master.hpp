#ifndef MASTER_H
# define MASTER_H

# include <string>

# include "UINcurses"
class UINcurses;

class Master
{
public:
	Master(std::string const &filename);
	virtual ~Master(void);
	Master(Master const &src);
	Master&	operator=(Master const &rhs);

	void			loop(void);
protected:
private:
	Master(void);

	UINcurses		_ui;
};

std::ostream&	operator<<(std::ostream& stream, Master const &s);

#endif
