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
void	Account::makeDeposit(int deposit) {
	// 1. increment the current account's amount
	this->_amount += deposit;

	// 2. increment the total amount
	_totalAmount += deposit;

	// 3. increment the current account's number of deposits
	this->_nbDeposits++;

	// 4. increment the total number of deposits
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal) {
	// 1. check if there is enough value to withdraw
	int	value = checkAmount();

	if (withdrawal > value)
		return (false);
	
	// 2. decrease the current account's amount
	this->_amount -= withdrawal;

	// 3. decrease the total amount
	_totalAmount -= withdrawal;

	// 4. increment the current account's number of withdrawals
	this->_nbWithdrawals++;

	// 5. increment the total number of withdrawals
	_totalNbWithdrawals++;
	return (true);
}

int		Account::checkAmount(void) const {
	return (this->_amount);
}

void	Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}
