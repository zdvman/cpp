/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:45:17 by dzuiev            #+#    #+#             */
/*   Updated: 2024/08/16 17:55:20 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

// ********************************************************************** //
// Default constructor                                                     //
// Initializes the Harl object.                                             //
// ********************************************************************** //
Harl::Harl() {
	// You could initialize data members here if there were any.
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

	// Array of string levels to match the input string to the correct function.
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	// Iterate through the levels array and find a match with the provided level.
	for (int i = 0; i < 4; i++) {
		if (levels[i] == level) {
			callLevel(functions[i]);  // Call the matched function
			return;
		}
	}

	std::cerr << "Unknown level: " << level << std::endl;  // Handle invalid input
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
	std::cout << "DEBUG: I love having extra bacon for my "
			<< "7XL-double-cheese-triple-pickle-special-ketchup burger. "
			<< "I really do!" << std::endl;
}

// ********************************************************************** //
// INFO level complaint method                                              //
// Provides informational messages to trace program execution.              //
// ********************************************************************** //
void Harl::info() {
	std::cout << "INFO: I cannot believe adding extra bacon costs more money. "
			<< "You didn’t put enough bacon in my burger! If you did, "
			<< "I wouldn’t be asking for more!" << std::endl;
}

// ********************************************************************** //
// WARNING level complaint method                                           //
// Warns of a potential issue that may or may not require attention.        //
// ********************************************************************** //
void Harl::warning() {
	std::cout << "WARNING: I think I deserve to have some extra bacon for free. "
			<< "I’ve been coming for years whereas you started working "
			<< "here since last month." << std::endl;
}

// ********************************************************************** //
// ERROR level complaint method                                             //
// Indicates a serious issue that requires immediate attention.             //
// ********************************************************************** //
void Harl::error() {
	std::cout << "ERROR: This is unacceptable! I want to speak to the manager now."
			<< std::endl;
}
