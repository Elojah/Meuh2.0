#include "Programs.hpp"

const std::string	Programs::_paramsName[19] = {
	"cmd",
	"numprocs",
	"umask",
	"workingdir",
	"autostart",
	"autorestart",
	"exitcodes",
	"startretries",
	"starttime",
	"stopsignal",
	"stoptime",
	"stdout",
	"stderr",
	"env",
	"STARTED_BY",
	"ANSWER"
};

Programs::Programs(void) {
}

Programs::Programs(Programs const &src) {
	if (this != &src)
		*this = src;
}

Programs::~Programs(void) {
}

void			Programs::setParams(Json::Value &params) {
	Json::Value							value;
	std::map<std::string, std::string>	tmp;

	for (int i = 0; i < 19; ++i) {
		value = params.get(Programs::_paramsName[i], "");
		if (value.isArray()) {
			for (Json::ValueIterator j = value.begin(); j != value.end(); ++j) {
				if (!(j->isArray())) {
					;
				}
			}
		} else {
			tmp[_paramsName[i]] = value.asString();
		}
	}
	_params.cmd = tmp["cmd"];
	if (tmp.find("numprocs") != tmp.end()) {
		_params.numprocs = std::stoi(tmp["numprocs"]);
	}
	if (tmp.find("umask") != tmp.end()) {
		_params.umask = std::stoi(tmp["umask"]);
	}
	_params.workingdir = tmp["workingdir"];
	_params.autostart = (tmp["autostart"] == "true");
	_params.autorestart = tmp["autorestart"];
	if (tmp.find("exitcodes") != tmp.end()) {
		_params.exitcodes = std::stoi(tmp["exitcodes"]);
	}
	if (tmp.find("startretries") != tmp.end()) {
		_params.startretries = std::stoi(tmp["startretries"]);
	}
	if (tmp.find("starttime") != tmp.end()) {
		_params.starttime = std::stoi(tmp["starttime"]);
	}
	_params.stopsignal = tmp["stopsignal"];
	if (tmp.find("stoptime") != tmp.end()) {
		_params.stoptime = std::stoi(tmp["stoptime"]);
	}
	_params.stdout = tmp["stdout"];
	_params.stderr = tmp["stderr"];
	_params.env = tmp["env"];
	_params.STARTED_BY = tmp["STARTED_BY"];
	_params.ANSWER = tmp["ANSWER"];
}

Programs		&Programs::operator=(Programs const &rhs) {
	if (this != &rhs) {
		;
	}
	return (*this);
}

void		Programs::serialize(std::ostream &stream) const {
	stream  << "cmd:\t" << _params.cmd << std::endl
			<< "numprocs:\t" << _params.numprocs << std::endl
			<< "umask:\t" << _params.umask << std::endl
			<< "workingdir:\t" << _params.workingdir << std::endl
			<< "autostart:\t" << _params.autostart << std::endl
			<< "autorestart:\t" << _params.autorestart << std::endl
			<< "exitcodes:\t" << _params.exitcodes << std::endl
			<< "startretries:\t" << _params.startretries << std::endl
			<< "starttime:\t" << _params.starttime << std::endl
			<< "stopsignal:\t" << _params.stopsignal << std::endl
			<< "stoptime:\t" << _params.stoptime << std::endl
			<< "stdout:\t" << _params.stdout << std::endl
			<< "stderr:\t" << _params.stderr << std::endl
			<< "env:\t" << _params.env << std::endl
			<< "STARTED_BY:\t" << _params.STARTED_BY << std::endl
			<< "ANSWER:\t" << _params.ANSWER << std::endl;
}

std::ostream&	operator<<(std::ostream& stream, Programs const &s) {
	s.serialize(stream);
	return (stream);
}
