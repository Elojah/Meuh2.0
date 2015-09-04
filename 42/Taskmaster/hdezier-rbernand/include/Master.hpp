/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Master.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/15 14:01:11 by leeios            #+#    #+#             */
/*   Updated: 2015/08/15 14:38:19 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MASTER_H
# define MASTER_H

# include <string>

# include "UINcurses.hpp"
# include "Process.hpp"

class Master
{
public:
	Master(void);
	virtual ~Master(void);
	Master(Master const &src);
	Master&	operator=(Master const &rhs) = default;

	bool			readConfig(std::string const &filename);
	void			start(void);
	void			loop(void);

protected:
private:

	UINcurses					_ui;
	Process						*_procs;
	int								_nProcs;

};

std::ostream&	operator<<(std::ostream& stream, Master const &s);

#endif
