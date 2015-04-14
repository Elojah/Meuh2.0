#ifndef MASTER_H
# define MASTER_H

# include <string>

# include "UINcurses.hpp"
class UINcurses;
# include "Programs.hpp"
class Programs;

class Master
{
public:
	Master(void);
	virtual ~Master(void);
	Master(Master const &src);
	Master&	operator=(Master const &rhs);

	bool			readConfig(std::string const &filename);
	void			loop(void);

protected:
private:

	UINcurses					_ui;
	Programs					*_progs;
	int							_nProgs;

};

std::ostream&	operator<<(std::ostream& stream, Master const &s);

#endif
