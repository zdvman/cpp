/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:45:17 by dzuiev            #+#    #+#             */
/*   Updated: 2024/08/19 16:07:58 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

// ********************************************************************** //
// Default constructor                                                     //
// Initializes the Harl object.                                             //
// ********************************************************************** //
Harl::Harl() {
	_levels[0] = "DEBUG";
    _levels[1] = "INFO";
    _levels[2] = "WARNING";
    _levels[3] = "ERROR";
}

// ********************************************************************** //
// Destructor                                                               //
// Cleans up resources (none in this case).                                 //
// ********************************************************************** //
Harl::~Harl() {
	// Nothing to clean up since we don't have dynamic memory or resources.
}

// ********************************************************************** //
// Complain method                                                          //
// Calls the appropriate method based on the provided complaint level.      //
// Avoids the use of multiple if/else statements by using a pointer to      //
// member function array and a helper method to make the call.              //
// ********************************************************************** //
void Harl::complain(std::string level) {
	// Array of function pointers to the member functions corresponding to each level.
	HarlMemFn functions[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	// Iterate through the levels array and find a match with the provided level.
	for (int i = 0; i < 4; i++) {
		if (this->_levels[i] == level) {
			callLevel(functions[i]);  // Call the matched function
			return;
		}
	}

	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

// ********************************************************************** //
// Helper method: callLevel                                                 //
// This method calls the appropriate member function based on the provided //
// pointer to a member function.                                            //
// ********************************************************************** //
void Harl::callLevel(HarlMemFn func) {
	(this->*func)();  // Call the member function using the pointer
}

// ********************************************************************** //
// DEBUG level complaint method                                             //
// Provides detailed debugging information.                                 //
// ********************************************************************** //
void Harl::debug() {
	std::cout << "[ DEBUG ]"
		<< std::endl
		<< "I love having extra bacon for my "
		<< "7XL-double-cheese-triple-pickle-special-ketchup burger. "
		<< "I really do!\n" << std::endl;
}

// ********************************************************************** //
// INFO level complaint method                                              //
// Provides informational messages to trace program execution.              //
// ********************************************************************** //
void Harl::info() {
	std::cout << "[ INFO ]"
		<< std::endl
		<< "I cannot believe adding extra bacon costs more money. "
		<< "You didn’t put enough bacon in my burger! If you did, "
		<< "I wouldn’t be asking for more!\n" << std::endl;
}

// ********************************************************************** //
// WARNING level complaint method                                           //
// Warns of a potential issue that may or may not require attention.        //
// ********************************************************************** //
void Harl::warning() {
	std::cout << "[ WARNING ]"
		<< std::endl
		<< "I think I deserve to have some extra bacon for free. "
		<< "I’ve been coming for years whereas you started working "
		<< "here since last month.\n" << std::endl;
}

// ********************************************************************** //
// ERROR level complaint method                                             //
// Indicates a serious issue that requires immediate attention.             //
// ********************************************************************** //
void Harl::error() {
	std::cout << "[ ERROR ]"
		<< std::endl
		<< "This is unacceptable! I want to speak to the manager now.\n"
		<< std::endl;
}
