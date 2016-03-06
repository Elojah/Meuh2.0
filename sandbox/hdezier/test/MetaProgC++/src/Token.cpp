#include "Token.hpp"

namespace TokensDefinitions
{
	const std::vector<std::string>	sOperator::words =
	{
		"<=>"
	};
	const std::vector<std::string>	sOperand::words =
	{
		"!"
	};
};

/*
**_____________________SFINAE Specialization
**/
/*
** Words specialization
**/
template<typename TokenDef>
static constexpr auto				has_specialization(void) ->
decltype(TokenDef::words, std::vector<std::string>()) {return (eSpecialization::WORDS_ATT);}
/*
** Detect specialization
**/
template<typename TokenDef>
static constexpr auto				has_specialization(void) ->
decltype(TokenDef::detect(), eResponse()) {return (eSpecialization::DETECT_METH);}
/*
** Default fallback
**/
constexpr eSpecialization	has_specialization(...) { return (eSpecialization::NONE); }
/*
**!_____________________SFINAE Specialization
**/

template<typename TokenDef>
eResponse		Token<TokenDef>::detect(const std::string &readToken)
{
	DetectImpl::_detect_impl<TokenDef::has_specialization()>::call(readToken);
}
