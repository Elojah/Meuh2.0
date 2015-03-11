// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Exec.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/11 13:57:37 by erobert           #+#    #+#             //
//   Updated: 2015/03/11 14:27:24 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef EXEC_H
# define EXEC_H

# include <fstream>
# include <iostream>
# include <string>
# include <vector>
# include "Lexer.hpp"
# include "Parser.hpp"
# include "Puzzle.hpp"

class Exec
{
public:
	Exec(void);
	~Exec(void);

	void				parseAv(int ac, char **av);
	void				solvePuzzle(void);
private:
	bool				_good;
	std::string			_name;
	std::string			_arg[2];
	std::vector<int>	_vector;
	size_t				_size;

	Exec(Exec const &e);

	Exec				&operator=(Exec const &e);

	void				errorAv(void);
	void				parsePuzzle(char *file);
	void				parseHeuristic(char *heuristic);
};

#endif
