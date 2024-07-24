// ************************************************************************** //
//                                                                            //
//                tests.cpp for GlobalBanksters United                        //
//                Created on  : Thu Nov 20 23:45:02 1989                      //
//                Last update : Wed Jan 04 09:23:52 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

/* ************************************************************************** */
/*                                                                            */
/* Detailed Explanation of Concepts                                           */
/*                                                                            */
/*     std::vector:                                                           */
/*         std::vector is a sequential container that can dynamically change  */
/*         its size. It stores elements in a contiguous block of memory.      */
/*         Example: std::vector<int> v; creates a vector of integers.         */
/*                                                                            */
/*     std::pair:                                                             */
/*         std::pair is a template class that holds two values, which can be  */
/*         of different types. It provides a convenient way to return two     */
/*         values from a function.                                            */
/*         Example: std::pair<int, std::string> p(10, "example"); creates a   */
/*         pair where first is an int and second is a std::string.            */
/*                                                                            */
/*     Iterators:                                                             */
/*         Iterators are objects that allow you to traverse through elements  */
/*         in a container (like a vector). They are similar to pointers and   */
/*         support operations like increment (++) and dereference (*).        */
/*         Example: std::vector<int>::iterator it = v.begin(); initializes an */
/*         iterator pointing to the beginning of the vector v.                */
/*                                                                            */
/*     std::for_each:                                                         */
/*         std::for_each is a standard algorithm that applies a function to   */
/*         each element in a range.                                           */
/*         Example: std::for_each(v.begin(), v.end(), print); applies the     */
/*         function print to each element in the vector v.                    */
/*                                                                            */
/*     std::mem_fun_ref:                                                      */
/*         std::mem_fun_ref is a function adapter that converts a pointer to  */
/*         a class member function into a functional object that can be used  */
/*         with standard library algorithms.                                  */
/*         Example: std::mem_fun_ref(&MyClass::method) allows the method of   */
/*         MyClass to be used in algorithms like std::for_each.               */
/*                                                                            */
/* ************************************************************************** */

#include <vector>        // Includes the vector library, which provides the std::vector container
#include <algorithm>     // Includes the algorithm library, which provides standard algorithms like std::for_each
#include <functional>    // Includes the functional library, which provides utilities to use with algorithms like std::mem_fun_ref
#include "Account.hpp"   // Includes the Account class definition, which is specific to this project

int		main( void ) {

	// Defining type aliases (typedef) for ease of use

	// accounts_t is a type alias for a vector of Account objects
	typedef std::vector<Account::t>	accounts_t;
	// ints_t is a type alias for a vector of integers
	typedef std::vector<int>	ints_t;
	// acc_int_t is a type alias for a pair of iterators: one for accounts_t and one for ints_t
	typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t;

	// Initializing an array of initial amounts for accounts

	// Array of initial deposit amounts for each account
	int	const				amounts[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 };
	// Calculates the size of the amounts array (number of elements)
	size_t const			amounts_size( sizeof(amounts) / sizeof(int) );

	// Creating a vector of accounts using the initial amounts

	// Initializes accounts vector with elements from amounts array
	accounts_t				accounts( amounts, amounts + amounts_size );
	// Iterator to the beginning of the accounts vector
	accounts_t::iterator	acc_begin	= accounts.begin();
	// Iterator to the end of the accounts vector
	accounts_t::iterator	acc_end		= accounts.end();

	// Initializing an array of deposit amounts

	// Array of deposit amounts
	int	const			d[]			= { 5, 765, 564, 2, 87, 23, 9, 20 };
	// Calculates the size of the deposits array (number of elements)
	size_t const		d_size( sizeof(d) / sizeof(int) );
	// Initializes deposits vector with elements from d array
	ints_t				deposits( d, d + d_size );
	// Iterator to the beginning of the deposits vector
	ints_t::iterator	dep_begin	= deposits.begin();
	// Iterator to the end of the deposits vector
	ints_t::iterator	dep_end		= deposits.end();

	// Initializing an array of withdrawal amounts

	// Array of withdrawal amounts
	int	const			w[]			= { 321, 34, 657, 4, 76, 275, 657, 7654 };
	// Calculates the size of the withdrawals array (number of elements)
	size_t const		w_size( sizeof(w) / sizeof(int) );
	// Initializes withdrawals vector with elements from w array
	ints_t				withdrawals( w, w + w_size );
	// Iterator to the beginning of the withdrawals vector
	ints_t::iterator	wit_begin	= withdrawals.begin();
	// Iterator to the end of the withdrawals vector
	ints_t::iterator	wit_end		= withdrawals.end();

	// Displaying initial account information

	// Calls a static method to display information about all accounts
	Account::displayAccountsInfos();
	// Applies the displayStatus method to each element in the accounts vector
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	// Processing deposits

	// Initialize a pair of iterators: it.first for accounts, it.second for deposits
	for ( acc_int_t it( acc_begin, dep_begin );
		// Continue loop while both iterators have not reached the end of their vectors
		it.first != acc_end && it.second != dep_end;
		// Increment both iterators
		++(it.first), ++(it.second) ) {
		// Dereference iterators and call makeDeposit on the account with the corresponding deposit amount
		(*(it.first)).makeDeposit( *(it.second) );
	}

	// Displaying account information after deposits

	// Display updated information about all accounts
	Account::displayAccountsInfos();
	// Applies the displayStatus method to each element in the accounts vector
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	// Processing withdrawals

	// Initialize a pair of iterators: it.first for accounts, it.second for withdrawals
	for ( acc_int_t it( acc_begin, wit_begin );
		// Continue loop while both iterators have not reached the end of their vectors
		it.first != acc_end && it.second != wit_end;
		// Increment both iterators
		++(it.first), ++(it.second) ) {
		// Dereference iterators and call makeWithdrawal on the account with the corresponding withdrawal amount
		(*(it.first)).makeWithdrawal( *(it.second) );
	}

	// Displaying final account information after withdrawals

	// Display final information about all accounts
	Account::displayAccountsInfos();
	// Applies the displayStatus method to each element in the accounts vector
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	// Return 0 to indicate successful execution
	return 0;
}


// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //
