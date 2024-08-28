/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:58:00 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/08/28 21:49:24 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include "iostream"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

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
    _displayTimestamp();
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
    {
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->checkAmount() << ";withdrawal:refused" << std::endl;
        return (false);
    }
    this->_nbWithdrawals++;
    this->_totalNbWithdrawals++;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->checkAmount() << ";withdrawal:" << withdrawal << ";amount:" << this->checkAmount() - withdrawal  << ";nb_withdrawals:" << getNbWithdrawals() << std::endl;
    this->_totalAmount -= withdrawal;
    this->_amount -= withdrawal;
    return (true);
}

int		Account::checkAmount( void ) const
{
    return (this->_amount);
}

void	Account::_displayTimestamp( void )
{
    time_t time = std::time(NULL);
    std::cout << "[" << time << "] ";
}

void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout <<  "index:"<< this->_accountIndex << ";amount:"<< this->_amount <<";deposits:"<< this->_nbDeposits << ";withdrawals:"<< this->_nbWithdrawals << std::endl;
}
