/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbobillo <rbobillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 16:39:46 by rbobillo          #+#    #+#             */
/*   Updated: 2015/01/12 08:28:21 by rbobillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_retro.h"

int				startx = 0;
int				starty = 0;

const char		*choices[] =
{
	"PLAY",
	"EXIT"
};

int				n_choices = sizeof(choices) / sizeof(char *);

void				printMap()
{
	std::string		line;
	std::ifstream	myfile("spaceMap.txt");
	if (myfile.is_open())
	{
		while ( getline (myfile,line) )
			printw("%s\n", line.c_str());
		myfile.close();
	}
	refresh();
}

void			print_menu(WINDOW *menu_win, int highlight)
{
	int x, y, i;

	x = 8;
	y = 2;
	box(menu_win, 0, 0);
	for(i = 0; i < n_choices; ++i)
	{
		if (highlight == i+1)
		{
			wattron(menu_win, A_REVERSE);
			mvwprintw(menu_win, y, x, "%s", choices[i]);
			wattroff(menu_win, A_REVERSE);
		}
		else
			mvwprintw(menu_win, y, x, "%s", choices[i]);
		++y;
	}
	wrefresh(menu_win);
}

int				main()
{
	WINDOW			*menu_win;
	int				highlight = 1;
	int				choice = 0;
	int				c;
	clock_t			prev = clock();
	clock_t			delay = CLOCKS_PER_SEC / 60;
	clock_t			tmp;
	unsigned int	slep;
	int				dim[2];
	int				ranTab[30] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','.'};

	srand(time(NULL));
	initscr();
	curs_set(0);
	clear();
	noecho();
	cbreak();

	int				i,j;
	std::ofstream	myfile("spaceMap.txt");
	if (myfile.is_open()) {
		for (i=0; i < LINES; i++)
		{
			for (j=0; j < COLS; j++)
				myfile << (char)ranTab[rand()%30];
			myfile << "\n";
		}
		myfile.close();
	}

	dim[0] = COLS;
	dim[1] = LINES;
	startx = (COLS - WIDTH) / 2;
	starty = (LINES - HEIGHT) / 2;

	menu_win = newwin(HEIGHT, WIDTH, starty, startx);
	printMap();
	nodelay(menu_win, TRUE);
	keypad(menu_win, TRUE);
	refresh();
	print_menu(menu_win, highlight);
	while(1)
	{
		tmp = clock() - prev;
		if (tmp < delay)
		{
			tmp = (delay - tmp);
			slep = tmp * CLOCKS_PER_SEC / 1000000;
			usleep(slep);
		}
		refresh();
		switch (c = wgetch(menu_win))
		{
			case KEY_UP:
				if (highlight == 1)
					highlight = n_choices;
				else
					--highlight;
				break;
			case KEY_DOWN:
				if (highlight == n_choices)
					highlight = 1;
				else
					++highlight;
				break;
			case RETURN:
				if (highlight == 1)
					ft_game_loop(dim, menu_win);
				//	refresh(); //	print_menu(menu_win, highlight);
				else
					choice = highlight;
				break;
			default:
				refresh();
				break ;
		}
		print_menu(menu_win, highlight);
		if (choice != 0) /* User did a choice come out of the infinite loop */
			break;
	}
	clrtoeol();
	refresh();
	endwin();
	return 0;
}
