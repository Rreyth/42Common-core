#include "Account.hpp"
#include <iostream>

int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

Account::Account( int initial_deposit ){
    this->_amount = initial_deposit;
    this->_totalAmount += initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    this->_accountIndex = this->_nbAccounts;
    this->_nbAccounts++;
    this->_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:"
        << this->_amount << ";created" << std::endl;
}

Account::~Account( void ){
    this->_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:"
        << this->_amount << ";closed" << std::endl;
}

int	Account::getNbAccounts( void ){
    return _nbAccounts;
}

int	Account::getTotalAmount( void ){
    return _totalAmount;
}

int	Account::getNbDeposits( void ){
    return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void ){
    return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void ){
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";total:"
        << _totalAmount << ";deposits:" << _totalNbDeposits
        << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit ){
    this->_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:"
        << this->_amount << ";deposit:" << deposit
        << ";amount:" << this->_amount + deposit
        << ";nb_deposits:" << this->_nbDeposits + 1
        << std::endl;
    this->_amount += deposit;
    this->_totalAmount += deposit;
    this->_nbDeposits++;
    this->_totalNbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal ){
    if (withdrawal > this->_amount)
    {
        this->_displayTimestamp();
        std::cout << "index:" << this->_accountIndex << ";p_amount:"
            << this->_amount << ";withdrawal:refused" << std::endl;
        return false;
    }
    this->_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:"
        << this->_amount << ";withdrawal:" << withdrawal
        << ";amount:" << this->_amount - withdrawal
        << ";nb_withdrawals:" << this->_nbWithdrawals + 1
        << std::endl;
    this->_amount -= withdrawal;
    this->_totalAmount -= withdrawal;
    this->_nbWithdrawals++;
    this->_totalNbWithdrawals++;
    return (true);
}

int		Account::checkAmount( void ) const{
    return this->_amount;
}

void	Account::displayStatus( void ) const{
    this->_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:"
        << this->_amount << ";deposits:" << this->_nbDeposits
        << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void ){
    std::cout << "TIME ";
}
