// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

// ************************************************************************** //
//                                                                            //
// Explanation of #pragma once and Include Guards                             //
//                                                                            //
//     #pragma once:                                                          //
//         #pragma once is a preprocessor directive that ensures a file is    //
//         included only once in a single compilation. It is a more modern    //
//         and less error-prone way to prevent multiple inclusions of the     //
//         same file. It is supported by most modern compilers (such as GCC,  //
//         Clang, MSVC).                                                      //
//                                                                            //
//     Include Guards:                                                        //
//         Include guards are a traditional way to prevent multiple           //
//         inclusions of a header file. They use preprocessor directives      //
//         #ifndef, #define, and #endif.                                      //
//                                                                            //
//         Example:                                                           //
//             #ifndef __ACCOUNT_H__                                          //
//             #define __ACCOUNT_H__                                          //
//             // Header file content                                         //
//             #endif // __ACCOUNT_H__ //                                     //
//                                                                            //
//     Why Use Both:                                                          //
//         Compatibility: #pragma once is not part of the C++ standard,       //
//         although it is widely supported. Including traditional include     //
//         guards ensures compatibility with compilers that do not support    //
//         #pragma once.                                                      //
//         Redundancy: Using both provides an extra layer of protection. If   //
//         one method fails or is not supported, the other will ensure the    //
//         file is included only once.                                        //
//                                                                            //
// ************************************************************************** //
//                                                                            //
// Explanation of Static Member Functions                                     //
//                                                                            //
//     Declaration and Definition of Static Member Functions:                 //
//         Declaration: The static keyword is used in the class definition    //
//         to indicate that a member function is static. This means the       //
//         function is associated with the class itself rather than any       //
//         particular instance of the class.                                  //
//                                                                            //
//         Definition: When defining a static member function outside the     //
//         class, the static keyword is not used. The function is already     //
//         declared as static in the class declaration, so it is redundant    //
//         and incorrect to use static again.                                 //
//                                                                            //
//         Example:                                                           //
//             class Account {                                                //
//                 public:                                                    //
//                     static int getNbAccounts(void);                        //
//             };                                                             //
//                                                                            //
//             int Account::getNbAccounts(void) {                             //
//                 return _nbAccounts;                                        //
//             }                                                              //
//                                                                            //
// ************************************************************************** //

#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

class Account {


public:

	typedef Account		t;

	static int	getNbAccounts( void );
	static int	getTotalAmount( void );
	static int	getNbDeposits( void );
	static int	getNbWithdrawals( void );
	static void	displayAccountsInfos( void );

	Account( int initial_deposit );
	~Account( void );

	void	makeDeposit( int deposit );
	bool	makeWithdrawal( int withdrawal );
	int		checkAmount( void ) const;
	void	displayStatus( void ) const;


private:

	static int	_nbAccounts;
	static int	_totalAmount;
	static int	_totalNbDeposits;
	static int	_totalNbWithdrawals;

	static void	_displayTimestamp( void );

	int				_accountIndex;
	int				_amount;
	int				_nbDeposits;
	int				_nbWithdrawals;

	Account( void );

};



// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //


#endif // __ACCOUNT_H__ //
