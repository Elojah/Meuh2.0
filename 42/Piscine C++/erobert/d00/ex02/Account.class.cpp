// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Account.class.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/05 15:09:12 by erobert           #+#    #+#             //
//   Updated: 2015/01/06 08:35:03 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <sys/time.h>
#include "Account.class.hpp"

Account::Account(void)
{
	return ;
}
Account::Account(int initial_deposit):
	_amount(initial_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	this->_accountIndex = t::_nbAccounts;
	t::_nbAccounts++;
	t::_totalAmount += this->_amount;
	t::_displayTimestamp();
	std::cout << " index:"
			  << this->_accountIndex
			  << ";amount:"
			  << this->_amount
			  << ";created"
			  << std::endl;
}
Account::~Account(void)
{
	t::_displayTimestamp();
	std::cout << " index:"
			  << this->_accountIndex
			  << ";amount:"
			  << this->_amount
			  << ";closed"
			  << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	t::_displayTimestamp();
	std::cout << " index:"
			  << this->_accountIndex
			  << ";p_amount:"
			  << this->_amount
			  << ";deposit:"
			  << deposit;
	this->_nbDeposits++;
	t::_totalNbDeposits++;
	this->_amount += deposit;
	t::_totalAmount += deposit;
	std::cout << ";amount:"
			  << this->_amount
			  << ";nb_deposit:"
			  << this->_nbDeposits
			  << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	t::_displayTimestamp();
	std::cout << " index:"
			  << this->_accountIndex
			  << ";p_amount:"
			  << this->_amount
			  << ";withdrawal:";
	if (this->_amount >= withdrawal)
	{
		this->_nbWithdrawals++;
		t::_totalNbWithdrawals++;
		this->_amount -= withdrawal;
		t::_totalAmount -= withdrawal;
		std::cout << withdrawal
				  << ";amount:"
				  << this->_amount
				  << ";nb_withdrawals:"
				  << this->_nbWithdrawals
				  << std::endl;
		return (true);
	}
	std::cout << "refused" << std::endl;
	return (false);
}

void	Account::displayAccountsInfos(void)
{
	t::_displayTimestamp();
	std::cout << " account:"
			  << t::_nbAccounts
			  << ";total:"
			  << t::_totalAmount
			  << ";deposits:"
			  << t::_totalNbDeposits
			  << ";withdrawals:"
			  << t::_totalNbWithdrawals
			  << std::endl;
}

void	Account::displayStatus(void) const
{
	t::_displayTimestamp();
	std::cout << " index:"
			  << this->_accountIndex
			  << ";amount:"
			  << this->_amount
			  << ";deposits:"
			  << this->_nbDeposits
			  << ";withdrawals:"
			  << this->_nbWithdrawals
			  << std::endl;
}

int		Account::checkAmount(void) const
{
	return (this->_amount);
}

void	Account::_displayTimestamp(void)
{
	struct timeval tp;

	gettimeofday(&tp, NULL);
	std::cout << "[";
	std::cout << tp.tv_sec;
	std::cout << "_";
	std::cout << tp.tv_usec;
	std::cout << "]";
}

int		Account::_nbAccounts = 0;
int		Account::_totalAmount = 0;
int		Account::_totalNbDeposits = 0;
int		Account::_totalNbWithdrawals = 0;

int		Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int		Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int		Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int		Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}
