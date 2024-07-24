/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 10:31:55 by dzuiev            #+#    #+#             */
/*   Updated: 2024/07/24 14:32:44 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ************************************************************************** //
//                                                                            //
// Explanation of the Account class implementation                            //
//                                                                            //
//     Static member variables:                                               //
//         int Account::_nbAccounts = 0;                                      //
//         int Account::_totalAmount = 0;                                     //
//         int Account::_totalNbDeposits = 0;                                 //
//         int Account::_totalNbWithdrawals = 0;                              //
//         These variables keep track of the total number of accounts,        //
//         total amount of money across all accounts, total number of         //
//         deposits, and total number of withdrawals respectively.            //
//                                                                            //
//     Constructor:                                                           //
//         Account::Account(int initial_deposit);                             //
//         Increments the number of accounts, initializes account-specific    //
//         data members, updates total amount, and prints creation info.      //
//                                                                            //
//     Destructor:                                                            //
//         Account::~Account(void);                                           //
//         Decrements the number of accounts, prints account closure info.    //
//                                                                            //
//     Static methods:                                                        //
//         int Account::getNbAccounts(void);                                  //
//         int Account::getTotalAmount(void);                                 //
//         int Account::getNbDeposits(void);                                  //
//         int Account::getNbWithdrawals(void);                               //
//         void Account::displayAccountsInfos(void);                          //
//         These methods return the total number of accounts, total amount,   //
//         total number of deposits, total number of withdrawals, and display //
//         all accounts info respectively.                                    //
//                                                                            //
//     Member methods:                                                        //
//         void Account::makeDeposit(int deposit);                            //
//         bool Account::makeWithdrawal(int withdrawal);                      //
//         int Account::checkAmount(void) const;                              //
//         void Account::displayStatus(void) const;                           //
//         These methods handle deposits, withdrawals, check account amount,  //
//         and display the account status respectively.                       //
//                                                                            //
//     Private method:                                                        //
//         void Account::_displayTimestamp(void);                             //
//         Prints the current timestamp in a specific format.                 //
//                                                                            //
// ************************************************************************** //

#include <iostream>      // Standard library for input and output streams
#include <ctime>         // Standard library for manipulating date and time
#include <iomanip>       // Standard library for controlling input and output format
#include "Account.hpp"   // Header file for the Account class


// ************************************************************************** //
//                                                                            //
// Explanation of Static Member Functions in C++                              //
//                                                                            //
//     Static Member Functions:                                               //
//         Static member functions belong to the class itself, not to any     //
//         particular instance of the class.                                  //
//                                                                            //
//         Usage:                                                             //
//             - They can be called on the class itself, without creating an  //
//               object of the class.                                         //
//             - They have access only to static member variables and other   //
//               static member functions of the class.                        //
//             - They do not have access to non-static member variables or    //
//               member functions because they are not associated with any    //
//               specific object.                                             //
//                                                                            //
//         Declaration:                                                       //
//             - Inside the class definition, declare using the static        //
//               keyword.                                                     //
//             class MyClass {                                                //
//             public:                                                        //
//                 static void staticFunction();                              //
//             };                                                             //
//                                                                            //
//         Definition:                                                        //
//             - Outside the class, define without the static keyword.        //
//             void MyClass::staticFunction() {                               //
//                 // Function implementation                                 //
//             }                                                              //
//                                                                            //
// ************************************************************************** //
//                                                                            //
// Explanation: Why Initialization Inside the Class Declaration is Not Allowed//
//                                                                            //
//     Language Rules:                                                        //
//         According to the C++ language rules, static member variables must  //
//         be defined outside the class. This ensures that there is only one  //
//         instance of the static member variable for all instances of the    //
//         class.                                                             //
//                                                                            //
//     Separation of Declaration and Definition:                              //
//         The class declaration typically goes into a header file (.hpp or   //
//         .h), and the definition of static members goes into a source file  //
//         (.cpp). This separation helps in maintaining a clear and organized //
//         code structure.                                                    //
//                                                                            //
//     Compilation Error:                                                     //
//         If you attempt to initialize a static member variable inside the   //
//         class declaration, you will get a compilation error:               //
//         Error: ISO C++ forbids in-class initialization of non-const static //
//         member.                                                            //
//                                                                            //
//     Correct Initialization:                                                //
//         Declare the static member variable inside the class and define it  //
//         outside the class. This follows the C++ language rules and ensures //
//         a single instance of the static member variable across all         //
//         instances of the class.                                            //
//                                                                            //
//     Example:                                                               //
//         Class Declaration (Header File)                                    //
//             class MyClass {                                                //
//             public:                                                        //
//                 static int counter;                                        //
//                 static void displayCounter();                              //
//                 MyClass() { counter++; }                                   //
//             };                                                             //
//                                                                            //
//         Static Member Variable Definition (Source File)                    //
//             int MyClass::counter = 0;                                      //
//                                                                            //
// ************************************************************************** //

// Static member variables initialization
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// Constructor: initializes an account with an initial deposit
Account::Account( int initial_deposit ) {
	_nbAccounts++;
	_accountIndex = _nbAccounts - 1;
	_amount = initial_deposit;
	_totalAmount += _amount;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	this->_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "created" << std::endl;
}

// Destructor: handles account closure
Account::~Account( void ) {
	_nbAccounts--;
	this->_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "closed" << std::endl;
}

// Static methods to get the total statistics
int	Account::getNbAccounts( void ) {
	return _nbAccounts;
}

int	Account::getTotalAmount( void ) {
	return _totalAmount;
}

int	Account::getNbDeposits( void ) {
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void ) {
	return _totalNbWithdrawals;
}

// Static method to display all accounts information
void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";"
		<< "total:" << getTotalAmount() << ";"
		<< "deposits:" << getNbDeposits() << ";"
		<< "withdrawals:" << getNbWithdrawals() << std::endl;
}

// Method to handle deposits
void	Account::makeDeposit( int deposit ) {
	this->_displayTimestamp();
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	std::cout << "index:" << _accountIndex << ";"
		<< "p_amount:" << _amount << ";" << std::flush;
	_amount += deposit;
	std::cout << "deposit:" << deposit << ";"
		<< "amount:" << _amount << ";"
		<< "nb_deposits:" << _nbDeposits << std::endl;
}

// Method to handle withdrawals
bool	Account::makeWithdrawal( int withdrawal ) {
	this->_displayTimestamp();
	std::cout <<"index:" << _accountIndex << ";"
		<< "p_amount:" << _amount << ";"
		<< "withdrawals:" << std::flush;
	if (withdrawal > checkAmount()) {
		std::cout << "refused" << std::endl;
		return false;
	}
	std::cout << withdrawal << ";" << std::flush;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_totalAmount -= withdrawal;
	_amount -= withdrawal;
	std::cout << "amount:" << _amount << ";"
		<< "nb_deposit:" << _nbDeposits << std::endl;
	return true;
}

// Method to check the account amount
int		Account::checkAmount( void ) const {
	return _amount;
};

// Method to display the status of the account
void	Account::displayStatus( void ) const {
	this->_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "deposits:" << _nbDeposits << ";"
		<< "withdrawals:" << _nbWithdrawals << std::endl;
}

// Private method to display the current timestamp
void	Account::_displayTimestamp( void ) {
	std::time_t result = std::time(NULL);

	std::cout << std::setfill('0') << "[" << 1900 + std::localtime(&result)->tm_year
		<< std::setw(2) << 1 + std::localtime(&result)->tm_mon
		<< std::setw(2) << std::localtime(&result)->tm_mday
		<< "_"
		<< std::setw(2) <<std::localtime(&result)->tm_hour
		<< std::setw(2) <<std::localtime(&result)->tm_min
		<< std::setw(2) <<std::localtime(&result)->tm_sec
		<< "] " <<std::flush;
};
