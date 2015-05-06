#ifndef U_I_NCURSES_H
# define U_I_NCURSES_H

# include "AWindow.hpp"
class AWindow;

class UINcurses : public AWindow
{
public:
	UINcurses(void);
	UINcurses(int, int, int, int);
	virtual ~UINcurses(void);
	UINcurses(UINcurses const &src);
	UINcurses&	operator=(UINcurses const &rhs);

	virtual void		serialize(std::ostream &stream) const;
protected:
private:
};

#endif
