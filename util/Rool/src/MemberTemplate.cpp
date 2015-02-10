#include "MemberTemplate.hpp"

MemberTemplate::MemberTemplate(void) {
	;
}

MemberTemplate::MemberTemplate(const std::string &path) : _path(path) {
}

MemberTemplate::~MemberTemplate(void) {
}

std::string		MemberTemplate::create(const std::string &str) {
	(void)str;
	return ("");
}
