#ifndef TOKEN_HPP
# define TOKEN_HPP

#include <string>
#include <vector>

enum class	eResponse
{
	NONE,
	OK,
	COMPLETE
};

enum class	eSpecialization
{
	NONE,
	WORDS_ATT,
	DETECT_METH
};

namespace	DetectImpl
{
	template<eSpecialization>
	struct		_detect_impl {};
	/*
	**TokenDef  => NONE
	**/
	template<>
	struct _detect_impl<eSpecialization::NONE>
	{
		template<typename TokenDef>
		static eResponse	call(const std::string &readToken)
		{
			(void)readToken;
		};
	};
	/*
	**TokenDef  => detect
	**/
	template<>
	struct _detect_impl<eSpecialization::DETECT_METH>
	{

		template<typename TokenDef>
		static eResponse	call(const std::string &readToken)
		{
			TokenDef::detect(readToken);
		};
	};

	/*
	**TokenDef  => words
	**/
	template<>
	struct _detect_impl<eSpecialization::WORDS_ATT>
	{
		template<typename TokenDef>
		static eResponse	call(const std::string &readToken)
		{
			size_t		readSize = readToken.size();
			for (const auto word : TokenDef::words)
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
		};
	};
};

namespace TokensDefinitions
{
	struct		sOperator
	{
		sOperator(void) = default;
		virtual ~sOperator(void) = default;
		static const std::vector<std::string>	words;
	};
	struct		sOperand
	{
		sOperand(void) = default;
		virtual ~sOperand(void) = default;
		static const std::vector<std::string>	words;
	};
};

template<typename TokenDef>
class Token
{
public:
	Token(void) = default;
	virtual ~Token(void) = default;
	static eResponse	detect(const std::string &readToken);
protected:
private:
};

#endif
