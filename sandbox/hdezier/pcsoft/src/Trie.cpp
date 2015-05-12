#include "Trie.hpp"

Trie::Trie(void) {
	_root.create();
}

Trie::Trie(Trie const &src) {
	if (this != &src)
		*this = src;
}

Trie::~Trie(void) {
}

Trie		&Trie::operator=(Trie const &rhs) {
	if (this != &rhs) {
		;
	}
	return (*this);
}

// void	Trie::addValue(std::string const &value, char *filename) {
// 	;
// }
