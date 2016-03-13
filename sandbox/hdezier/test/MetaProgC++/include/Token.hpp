#ifndef TOKEN_HPP
# define TOKEN_HPP

# include <string>
# include <vector>
# include <iostream>
# include <type_traits>

typedef const std::vector<std::string>	tLexicon;

enum class	eResponse
{
	NONE = 0,
	OK,
	COMPLETE
};

namespace	TokensDefinitions
{
	struct		sOperator
	{
		sOperator(void) = default;
		virtual ~sOperator(void) = default;
		static tLexicon	words;
	};
	struct		sOperand
	{
		sOperand(void) = default;
		virtual ~sOperand(void) = default;
		static tLexicon	words;
	};
	struct		sEntity
	{
		sEntity(void) = default;
		virtual ~sEntity(void) = default;
		static eResponse		detect(const std::string &str)
		{
			if (std::isalnum(str.back()))
				return (eResponse::OK);
			else if (std::isalnum(str.at(0)))
				return (eResponse::COMPLETE);
			else
				return (eResponse::NONE);
		}
	};
};

enum class	eSpecialization
{
	NONE = 0,
	DETECT_METH,
	WORDS_ATT
};

template<typename TokenDef>
class Token
{
public:
	Token(void) = default;
	virtual ~Token(void) = default;
protected:
private:

	typedef std::integral_constant<int, 0>	spe_none;
	template <typename T, typename = int>
	struct spe_check : spe_none {};

	typedef std::integral_constant<int, 1>	spe_detect;
	template <typename T>
	struct spe_check <T, decltype((void) T::detect, 0)> : spe_detect {};

	typedef std::integral_constant<int, 2>	spe_words;
	template <typename T>
	struct spe_check <T, decltype((void) T::words, 0)> : spe_words {};

	static const spe_check<TokenDef>	_specialization;

	/*
	**
	** Detect implementations
	**
	*/

	/*
	** Words attribute
	*/
	template<typename T>
	static eResponse	_detect_impl(const std::string &readToken, spe_words)
	{
		std::cerr << "call to WORDS_ATT" << std::endl;
		size_t		readSize = readToken.size();
		for (const auto word : T::words)
		{
			size_t	sizeToCompare = std::min(readSize, word.size());
			if (word.compare(0, sizeToCompare, readToken.c_str(), sizeToCompare) == 0)
			{
				if (readSize > word.size())
					return (eResponse::COMPLETE);
				else
					return (eResponse::OK);
			}
		}
		return (eResponse::NONE);
	};

	/*
	** Detect method
	*/
	template<typename T>
	static eResponse	_detect_impl(const std::string &readToken, spe_detect)
	{
		std::cerr << "call to DETECT_METH" << std::endl;
		return (T::detect(readToken));
	};

	/*
	** Default fallback
	*/
	template<typename T>
	static eResponse	_detect_impl(const std::string &readToken, spe_none)
	{
		std::cerr << "call to NONE" << std::endl;
		(void)readToken;
		return (eResponse::NONE);
	};
	/*
	**
	**!Detect implementations
	**
	*/

public:
	static eResponse	detect(const std::string &readToken)
	{
		return (_detect_impl<TokenDef>(readToken, _specialization));
	};
};

#endif
