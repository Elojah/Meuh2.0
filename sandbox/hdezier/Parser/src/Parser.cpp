#include "Parser.hpp"
#include "Entity.hpp"
#include "Gate.hpp"
#include "Equal.hpp"
#include "Comment.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>

Parser::Parser(void) {
}

Parser::~Parser(void) {
	for (tSetTokens::iterator iTok = _globalTokens.begin(); iTok != _globalTokens.end(); ++iTok) {
		delete (*iTok);
	}
}

Parser::Parser(const std::string &filename) {
	std::ifstream		ifs(filename.c_str());
	char				c;
	size_t				n;
	size_t				nbToken;
	size_t				tokenMask;
	int					response;

	initGlobalTokens();
	nbToken = _globalTokens.size();
	tokenMask = (1L << _globalTokens.size()) - 1;
	if (ifs.fail()) {
		std::cout << "File is not valid" << std::endl;
		return ;
	}
	while (ifs.get(c)) {
		for (n = 0; n < nbToken; ++n) {
			if (!((tokenMask >> n) & 1)) {
				continue ;
			}
			response = _globalTokens[n]->detect(c);
			if (response == COMPLETE) {
				_readTokens.push_back(_globalTokens[n]->getAsRead());
				resetGlobalTokens();
				tokenMask = (1L << _globalTokens.size()) - 1;
			} else if (response == MASTER) {
				tokenMask = (1L << n);
			} else if (response == NONE) {
				tokenMask &= ~(1L << n);
				if (tokenMask == 0) {
					resetGlobalTokens();
					tokenMask = (1L << _globalTokens.size()) - 1;
				}
			}
		}
	}
}

void			Parser::resetGlobalTokens(void) {
	for (tSetTokens::iterator iTok = _globalTokens.begin(); iTok != _globalTokens.end(); ++iTok) {
		(*iTok)->reset();
	}
}

void			Parser::initGlobalTokens(void) {
	_globalTokens.push_back(new Entity());
	_globalTokens.push_back(new Gate());
	_globalTokens.push_back(new Equal());
	_globalTokens.push_back(new Comment());
}

void			Parser::display(void) {
	for (tTokens::iterator iTok = _readTokens.begin(); iTok != _readTokens.end(); ++iTok) {
		std::cout << "READ:\t" << iTok->word << " of type " << iTok->type << std::endl;
	}
}
