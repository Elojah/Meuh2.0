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

	initGlobalTokens();
	if (ifs.fail()) {
		std::cout << "File is not valid" << std::endl;
		return ;
	}
	exec(ifs);
}

void			Parser::exec(std::ifstream &ifs) {
	char				c;
	size_t				n;
	size_t				nbToken;
	size_t				tokenMask;
	int					response;

	nbToken = _globalTokens.size();
	tokenMask = (1L << _globalTokens.size()) - 1;
	while (ifs.get(c)) {
		for (n = 0; n < nbToken; ++n) {
			if (!((tokenMask >> n) & 1)) {
				continue ;
			}
			response = _globalTokens[n]->detect(c);
			std::cout << "Char:\t" << c << std::endl;
			std::cout << "Response:\t" << response << std::endl;
			std::cout << "Mask:\t" << tokenMask << std::endl;
			if (response == FOUND) {
				continue ;
			} else if (response == COMPLETE) {
				_readTokens.push_back(_globalTokens[n]->getAsRead());
				resetGlobalTokens();
				tokenMask = (1L << _globalTokens.size()) - 1;
			} else if (response == MASTER) {
				tokenMask = (1L << n);
			} else if (response == NONE) {
				tokenMask &= ~(1L << n);
				std::cout << "tokmas:\t" << tokenMask << std::endl;
				if (tokenMask == 0) {
					if (c != ' ' && c != '\t' && c != '\n') {
						std::cout << "Parsing error on char:\t" << c << std::endl;
						return ;
					}
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
