/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Process.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/15 14:00:57 by leeios            #+#    #+#             */
/*   Updated: 2015/08/15 14:38:11 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H

# include <fstream>
# include <json/json.h>

class Process
{
public:
	Process(void);
	~Process(void);
	Process(Process const &src);
	Process&	operator=(Process const &rhs) = default;

	enum eState
	{
		PROC_ERROR = -1,
		PROC_OK
	};

	Process::eState		launch(void);

	void		setParams(Json::Value &);
	void		start(void);

	void		serialize(std::ostream &stream) const;

protected:
private:

	struct sParams {
		std::string		cmd;
		int				numprocs;
		int				umask;
		std::string		workingdir;
		bool			autostart;
		std::string		autorestart;
		int				exitcodes;
		int				startretries;
		int				starttime;
		std::string		stopsignal;
		int				stoptime;
		std::string		stdout;
		std::string		stderr;
		std::string		env;
		std::string		STARTED_BY;
		std::string		ANSWER;
	};

	sParams						_params;

	pid_t						_pid;

	static const std::string	_paramsName[19];
};

std::ostream&	operator<<(std::ostream& stream, Process const &s);

#endif
