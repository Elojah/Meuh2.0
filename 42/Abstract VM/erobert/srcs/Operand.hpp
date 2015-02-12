// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Operand.hpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/27 10:21:18 by erobert           #+#    #+#             //
//   Updated: 2015/02/06 16:44:56 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef OPERAND_HPP
# define OPERAND_HPP

# include <cfloat>
# include <climits>
# include <cstdlib>
# include <sstream> 
# include "IOperand.hpp"
# include "FOperand.hpp"

template<typename T>
class Operand: public IOperand
{
private:
	eOperandType				_type;
	std::string const			_value;
	FOperand					_fO;

	Operand(void);
	Operand(Operand const &rhs);

	Operand					&operator=(Operand const &rhs);

	std::string				doOp(eOperandType type, eInstruction op,
								 std::string const &rhs) const
	{
		std::ostringstream	oss;
		std::stringstream	toss[2];
		double				d[2];
		float				f[2];
		int					i[2];

		if (type == DOUBLE)
		{
			oss.precision(1024);
			toss[1].precision(1024);
			toss[0].precision(1024);
			toss[0] << _value;
			toss[1] << rhs;
			toss[0] >> d[0];
			toss[1] >> d[1];
			if (op == ADD)
				oss << (d[0] + d[1]);
			if (op == SUB)
				oss << (d[0] - d[1]);
			if (op == MUL)
				oss << (d[0] * d[1]);
			if (op == DIV)
			{
				if (d[1] == 0)
					throw ZeroDiv();
				oss << (d[0] / d[1]);
			}
			if (op == MOD)
				throw FloatMod();
		}
		else if (type == FLOAT)
		{
			oss.precision(1024);
			toss[1].precision(1024);
			toss[0].precision(1024);
			toss[0] << _value;
			toss[1] << rhs;
			toss[0] >> f[0];
			toss[1] >> f[1];
			if (op == ADD)
				oss << (f[0] + f[1]);
			if (op == SUB)
				oss << (f[0] - f[1]);
			if (op == MUL)
				oss << (f[0] * f[1]);
			if (op == DIV)
			{
				if (f[1] == 0)
					throw ZeroDiv();
				oss << (f[0] / f[1]);
			}
			if (op == MOD)
				throw FloatMod();
		}
		else
		{
			toss[0] << _value;
			toss[1] << rhs;
			toss[0] >> i[0];
			toss[1] >> i[1];
			if (op == ADD)
				oss << (i[0] + i[1]);
			if (op == SUB)
				oss << (i[0] - i[1]);
			if (op == MUL)
				oss << (i[0] * i[1]);
			if (op == DIV)
			{
				if (i[1] == 0)
					throw ZeroDiv();
				oss << (i[0] / i[1]);
			}
			if (op == MOD)
			{
				if (i[1] == 0)
					throw ZeroDiv();
				oss << (i[0] % i[1]);
			}
		}
		return (oss.str());
	}
public:
	Operand(eOperandType type, std::string const &value):
		_type(type),
		_value(value),
		_fO()
	{
		std::stringstream	oss(value);
		int					i[2];
		float				f;
		double				d;

		if (type < FLOAT)
		{
			oss.precision(1024);
			oss >> i[0];
			if (type == INT8 && (i[0] < SCHAR_MIN || i[0] > SCHAR_MAX))
				throw Overflow();
			if (type == INT16 && (i[0] < SHRT_MIN || i[0] > SHRT_MAX))
				throw Overflow();
			else
			{
				if (i[0] > 0)
					i[1] = i[0] + 1;
				else
					i[1] = i[0] - 1;
				if (i[0] > 0 && !(i[0] < i[1]))
					throw Overflow();
				else if (i[0] < 0 && !(i[0] > i[1]))
					throw Overflow();
			}
		}
		else if (type == FLOAT)
		{
			oss.precision(1024);
			oss >> f;
			if (f == FLT_MAX)
				throw Overflow();
			else if (f < FLT_MIN)
				throw Underflow();
		}
		else
		{
			oss.precision(1024);
			oss >> d;
			if (d == DBL_MAX)
				throw Overflow();
			else if (f < DBL_MIN)
				throw Underflow();
		}
	}
	virtual ~Operand(void) {}

	virtual IOperand const		*operator+(IOperand const &rhs) const
	{
		eOperandType			type;

		type = (getPrecision() > rhs.getPrecision() ? _type : rhs.getType());
		return (_fO.createOperand(type, doOp(type, ADD, rhs.toString())));
	}
	virtual IOperand const		*operator-(IOperand const &rhs) const
	{
		eOperandType			type;

		type = (getPrecision() > rhs.getPrecision() ? _type : rhs.getType());
		return (_fO.createOperand(type, doOp(type, SUB, rhs.toString())));
	}
	virtual IOperand const		*operator*(IOperand const &rhs) const
	{
		eOperandType			type;

		type = (getPrecision() > rhs.getPrecision() ? _type : rhs.getType());
		return (_fO.createOperand(type, doOp(type, MUL, rhs.toString())));
	}
	virtual IOperand const		*operator/(IOperand const &rhs) const
	{
		eOperandType			type;

		type = (getPrecision() > rhs.getPrecision() ? _type : rhs.getType());
		return (_fO.createOperand(type, doOp(type, DIV, rhs.toString())));
	}
	virtual IOperand const		*operator%(IOperand const &rhs) const
	{
		eOperandType			type;

		type = (getPrecision() > rhs.getPrecision() ? _type : rhs.getType());
		return (_fO.createOperand(type, doOp(type, MOD, rhs.toString())));
	}

	virtual int					getPrecision(void) const
	{
		return (static_cast<int>(_type));
	}
	virtual eOperandType		getType(void) const
	{
		return (_type);
	}
	virtual std::string const	&toString(void) const
	{
		return (_value);
	}

	class FloatMod: public std::exception
	{
	private:
		FloatMod				&operator=(FloatMod const &fM);
	public:
		FloatMod(void) {}
		FloatMod(FloatMod const &bI);
		virtual ~FloatMod(void) throw() {}

		virtual char const		*what(void) const throw()
		{
			return ("Float mod.");
		}
	};
	class ZeroDiv: public std::exception
	{
	private:
		ZeroDiv					&operator=(ZeroDiv const &zD);
	public:
		ZeroDiv(void) {}
		ZeroDiv(ZeroDiv const &zD);
		virtual ~ZeroDiv(void) throw() {}

		virtual char const      *what(void) const throw()
		{
			return ("Zero div.");
		}
	};
	class Overflow: public std::exception
	{
	private:
		Overflow				&operator=(Overflow const &zD);
	public:
		Overflow(void) {}
		Overflow(Overflow const &zD);
		virtual ~Overflow(void) throw() {}

		virtual char const      *what(void) const throw()
		{
			return ("Overflow.");
		}
	};
	class Underflow: public std::exception
	{
	private:
		Underflow				&operator=(Underflow const &zD);
	public:
		Underflow(void) {}
		Underflow(Underflow const &zD);
		virtual ~Underflow(void) throw() {}

		virtual char const      *what(void) const throw()
		{
			return ("Underflow.");
		}
	};
};

#endif
