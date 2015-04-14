#ifndef MASTER_H
# define MASTER_H

# include <string>
# include <fstream>

# include "UINcurses.hpp"
class UINcurses;
# include "Process.hpp"
class Process;

class Master
{
public:
	Master(void);
	virtual ~Master(void);
	Master(Master const &src);
	Master&	operator=(Master const &rhs);

	bool			readConfig(std::string const &filename);
	void			loop(void);

	static const char	log[15];
protected:
private:

	UINcurses					_ui;
	Process						*_procs;
	int							_nProcs;
	std::ofstream				_log;

};

std::ostream&	operator<<(std::ostream& stream, Master const &s);

#endif
