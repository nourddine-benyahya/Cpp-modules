/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:58:00 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/08/28 16:47:54 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include "iostream"



Account::Account(int initial_deposit)
{
    std::cout << "index:" << this->_nbAccounts << ";amount:" << initial_deposit << ";created" << std::endl;
    this->_accountIndex = this->_nbAccounts;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    this->_nbAccounts++;
    this->_totalAmount += initial_deposit;
}

Account::~Account( void )
{
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

int	Account::getNbAccounts( void )
{
    return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
    return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
    return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
    return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
    std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}
void	Account::makeDeposit( int deposit )
{
    this->_amount += deposit;
    this->_totalAmount += deposit;
    this->_nbDeposits++;
    this->_totalNbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    if (withdrawal > this->_amount)
        return (false);
    this->_nbWithdrawals++;
    this->_totalNbWithdrawals++;
    this->_totalAmount -= withdrawal;
    this->_amount -= withdrawal;
}

int		Account::checkAmount( void ) const
{
    return (this->_amount);
}

void	Account::_displayTimestamp( void )
{
    std::cout << " bbb ";
}

void	Account::displayStatus( void ) const
{
    std::cout << " aaa ";
}
