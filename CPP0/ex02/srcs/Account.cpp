#include "Account.hpp"
#include <ctime>
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;


Account::Account(int deposit)
{
    this->_accountIndex = _nbAccounts;
    this->_amount = deposit;
    _totalAmount += this->_amount;
    _nbAccounts += 1;
    this->_nbDeposits = 0;
    this->_nbDeposits = 0;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
    return ;
}

Account::~Account(void)
{
    _nbAccounts--;
	_totalAmount -= this->_amount;
	_displayTimestamp();
    std::cout
    << "index:" << this->_accountIndex
    << ";amount:" << this->_amount
    << ";closed" << std::endl;
	return ;


}

void	Account::makeDeposit(int deposit)
{
    int previous = this->_amount;
    this->_amount += deposit;
    this->_nbDeposits += 1;
    _totalAmount += deposit;
    _totalNbDeposits += 1;
    _displayTimestamp();
    std::cout
    << "index:" << this->_accountIndex
    << ";p_amount:" << previous 
    << ";deposit:" << deposit
    << ";amount:" << this->_amount
    << ";nb_deposits:" << this->_nbDeposits
    << std::endl;
    return ;
}

bool	Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    if (withdrawal <= this->_amount)
    {
        int previous = this->_amount;
        this->_amount -= withdrawal;
        this->_nbWithdrawals += 1;
        _totalAmount -= withdrawal;
        _totalNbWithdrawals += 1;
        std::cout
        << "index:" << this->_accountIndex
        << ";p_amount:" << previous 
        << ";withdrawal:" << withdrawal
        << ";amount:" << this->_amount
        << ";nb_withdrawals:" << this->_nbWithdrawals
        << std::endl;
        return true;
    } else {
        std::cout
        << "index:" << this->_accountIndex
        << ";p_amount:" << _amount 
        << ";withdrawal:refused"
        << std::endl;
        return false;
    } 
}

int		Account::checkAmount(void) const
{
    return this->_amount;
}

void	Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout
    << "accounts:" << _nbAccounts
    << ";total:" << _totalAmount
    << ";deposits:" << _totalNbDeposits
    << ";withdrawals:" << _totalNbWithdrawals
    << std::endl;
    return ;
}

void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout
    << "index:" << this->_accountIndex
    << ";amount:" << this->_amount
    << ";deposits:" << this->_nbDeposits
    << ";withdrawals:" << this->_nbWithdrawals
    << std::endl;
    return ; 
}

void	Account::_displayTimestamp(void)
{
    time_t      timestamp = time(NULL);
    struct tm   *datetime = localtime(&timestamp);
    char        output[16];

    strftime(output, sizeof(output), "%Y%m%d_%H%M%S", datetime);
    std::cout << "[" << output << "] ";
    return ;
}

int	Account::getNbAccounts(void)
{
    return _nbAccounts;
}

int	Account::getTotalAmount(void)
{
    return _totalAmount;
}

int	Account::getNbWithdrawals(void)
{
    return _totalNbWithdrawals;
}

int	Account::getNbDeposits(void)
{
    return _totalNbDeposits;
}