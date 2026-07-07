#include "Account.hpp"
#include <ctime>
#include <string>
#include <iostream>

// securely initialize all global variables
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp() {
	std::time_t rawTime = std::time(NULL);
	std::tm *timeInfo = std::localtime(&rawTime);
	char buffer[20];

	std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", timeInfo);
	std::cout << "[" << buffer << "] ";
}

// constructor
Account::Account(int initial_deposit) {
	// 1. initialize current account's attributes
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	// 2. update total amount value
	_totalAmount += this->_amount;

	// 3. print timestamp and current account's basic infos
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;

	// 4. increment total number of accounts
	_nbAccounts++;
}

// destructor
Account::~Account() {
	// 1. print timestamp and current account's basic infos
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}



// getters
int 	Account::getNbAccounts(void) {
	return (_nbAccounts);
}

int		Account::getTotalAmount(void) {
	return (_totalAmount);
}

int		Account::getNbDeposits(void) {
	return (_totalNbDeposits);
}

int		Account::getNbWithdrawals(void) {
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void) {
	// 1. get account attributes
	int	nbAccs = getNbAccounts();
	int	ttlA = getTotalAmount();
	int	ttlNbDep = getNbDeposits();
	int	ttlNbWit = getNbWithdrawals();
	
	// 2. print timestamp and global accounts's infos
	_displayTimestamp();
	std::cout << "accounts:" << nbAccs << ";total:" << ttlA << ";deposits:" << ttlNbDep << ";withdrawals:" << ttlNbWit << std::endl;
}



// setters
void    Account::makeDeposit(int deposit) {
    int p_amount = this->_amount; // Save the previous amount before modifying it

    this->_amount += deposit;
    _totalAmount += deposit;
    this->_nbDeposits++;
    _totalNbDeposits++;

    // Add this print statement:
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << p_amount << ";deposit:" << deposit << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool    Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";";

    // 1. check if there is enough value to withdraw
    if (withdrawal > this->_amount) {
        std::cout << "withdrawal:refused" << std::endl;
        return (false);
    }
    
    this->_amount -= withdrawal;
    _totalAmount -= withdrawal;
    this->_nbWithdrawals++;
    _totalNbWithdrawals++;

    std::cout << "withdrawal:" << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
              
    return (true);
}

int		Account::checkAmount(void) const {
	return (this->_amount);
}

void	Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}
