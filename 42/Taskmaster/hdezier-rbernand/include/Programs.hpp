#ifndef PROGRAMS_H
# define PROGRAMS_H

#include <json/json.h>

class Programs
{
public:
	Programs(void);
	~Programs(void);
	Programs(Programs const &src);
	Programs&	operator=(Programs const &rhs);

	void		setParams(Json::Value &);
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

	static const std::string	_paramsName[19];
};

std::ostream&	operator<<(std::ostream& stream, Programs const &s);

#endif
