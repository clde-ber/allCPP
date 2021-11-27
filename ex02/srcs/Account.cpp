#include "Account.hpp"
#include "ctime"
#include <iostream>

int Account::_nbAccounts = 8;
int Account::_totalAmount = 20049;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
static int index = 0;

void    Account::_displayTimestamp(void)
{
    time_t time;
    tm *timeinfo;

    std::time(&time);
    timeinfo = std::localtime(&time);
    timeinfo->tm_year += 1900;
    timeinfo->tm_mon += 1;
    std::cout << "[" << timeinfo->tm_year;
    if (timeinfo->tm_mon < 10)
        std::cout << "0";
    std::cout << timeinfo->tm_mon;
    if (timeinfo->tm_mday < 10)
        std::cout << "0";
    std::cout << timeinfo->tm_mday;
    std::cout << "_";
    if (timeinfo->tm_hour < 10)
        std::cout << "0";
    std::cout << timeinfo->tm_hour;
    if (timeinfo->tm_min < 10)
        std::cout << "0";
    std::cout << timeinfo->tm_min;
    if (timeinfo->tm_sec < 10)
        std::cout << "0";
    std::cout << timeinfo->tm_sec << "] ";
}

Account::Account( int initial_deposit ) : _accountIndex(0), \
_amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
    this->_accountIndex = index;
    _displayTimestamp();
    std::cout << "index:";
    std::cout << this->_accountIndex;
    std::cout << ";amount:";
    std::cout << this->_amount; 
    std::cout << ";created";
    std::cout << std::endl;
    index++;
}

Account::~Account( void )
{
    _displayTimestamp();
    std::cout << "index:";
    std::cout << this->_accountIndex;
    std::cout << ";amount:";
    std::cout << this->_amount; 
    std::cout << ";closed";
    std::cout << std::endl;
}

void	Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << "index:";
    std::cout << this->_accountIndex;
    std::cout << ";amount:";
    std::cout << this->_amount; 
    std::cout << ";deposits:";
    std::cout << this->_nbDeposits;
    std::cout << ";withdrawals:";
    std::cout << _nbWithdrawals;
    std::cout << std::endl;
}

void	Account::makeDeposit( int deposit )
{
    this->_nbDeposits++;
    _displayTimestamp();
    std::cout << "index:";
    std::cout << this->_accountIndex;
    std::cout << ";p_amount:";
    std::cout << this->_amount;
    std::cout << ";deposit:";
    std::cout << deposit; 
    std::cout << ";amount:";
    this->_amount = this->_amount + deposit;
    std::cout << this->_amount;
    std::cout << ";nb_deposits:";
    std::cout << 1;
    std::cout << std::endl;
    Account::_totalAmount += deposit;
    _totalNbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
    std::cout << "index:";
    std::cout << this->_accountIndex;
    std::cout << ";p_amount:";
    std::cout << this->_amount;
    if (this->_amount - withdrawal < 0)
    {
        std::cout << ";withdrawal:refused";
        std::cout << std::endl;
    }
    else
    {
        std::cout << ";withdrawal:";
        std::cout << withdrawal; 
        std::cout << ";amount:";
        this->_amount = this->_amount - withdrawal;
        std::cout << this->_amount;
        std::cout << ";nb_withdrawals:";
        std::cout << 1;
        std::cout << std::endl;
        Account::_totalAmount -= withdrawal;
        this->_nbWithdrawals++;
        _totalNbWithdrawals++;
        return 1;
    }
    return 0;
}
