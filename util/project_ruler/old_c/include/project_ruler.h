#ifndef PROJECT_RULER_H
# define PROJECT_RULER_H

# include <ncurses.h>

/*
**Init
*/
void		init_ncurse(void);

/*
**Menu
*/
void		display_menu(int sig);

/*
**Ft_ncurse
*/
WINDOW	*create_win(int h, int w, int oy, int ox);
void		destroy_win(WINDOW *local_win);

#endif
