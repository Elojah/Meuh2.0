#include "Gate.hpp"

Gate::Gate(void) {
	_read.type = GATE;
}

Gate::~Gate(void) {
}

int		Gate::detect(const char &c) {
	bool		emptyWord(_read.word.empty());

	if ((emptyWord && (c == '&' || c == '|'))
		|| (!emptyWord && c == _read.word[0])) {
		_read.word.push_back(c);
		return (FOUND);
	}
	if (!emptyWord) {
		return (COMPLETE);
	}
	return (NONE);
}

int		Gate::apply(std::string const &s) {
	(void)s;
	return (0);
}

int		Gate::getPriority(void) const {
	return (1);
}
