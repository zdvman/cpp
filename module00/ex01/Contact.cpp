/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:55:26 by dzuiev            #+#    #+#             */
/*   Updated: 2024/07/24 16:24:31 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// ************************************************************************** //
//                                                                            //
// Constructor: Contact                                                       //
//                                                                            //
// Description:                                                               //
//     Initializes a new instance of the Contact class.                       //
//                                                                            //
// ************************************************************************** //
Contact::Contact() {}; // Constructor

// ************************************************************************** //
//                                                                            //
// Destructor: ~Contact                                                       //
//                                                                            //
// Description:                                                               //
//     Cleans up the instance of the Contact class.                           //
//                                                                            //
// ************************************************************************** //
Contact::~Contact() {}; // Destructor

// ************************************************************************** //
//                                                                            //
// Method: _getInput                                                          //
//                                                                            //
// Description:                                                               //
//     Prompts the user for input and returns the entered string. Ensures     //
//     the input is not empty.                                                //
//                                                                            //
// Parameters:                                                                //
//     std::string prompt - The prompt message to display                     //
//                                                                            //
// Return Value:                                                              //
//     std::string - The user input                                           //
//                                                                            //
// ************************************************************************** //
std::string	Contact::_getInput(std::string prompt) const {
	std::string input = "";
	while (true) {
		// std::flush - ensure the prompt message is displayed immediately
		std::cout << prompt << std::flush;
		std::getline(std::cin, input);
		
		if (std::cin.good() && !input.empty()) {
			break ;
		}
		else {
			// Clear any error flags
			std::cin.clear();
			std::cout << "Invalid input, try again." << std::endl;
		}
	}
	return (input);
}

// ************************************************************************** //
//                                                                            //
// Method: _getFormattedSubstring                                             //
//                                                                            //
// Description:                                                               //
//     Returns a formatted substring of the input string with a specified     //
//     maximum size. If the string is longer than the specified size, it      //
//     truncates and appends a dot.                                           //
//                                                                            //
// Parameters:                                                                //
//     std::string input - The input string to format                         //
//     size_t size - The maximum size of the formatted substring              //
//                                                                            //
// Return Value:                                                              //
//     std::string - The formatted substring                                  //
//                                                                            //
// ************************************************************************** //
std::string	Contact::_getFormattedSubstring(std::string input, size_t size) const {
	if (input.size() > size)
		return input.substr(0, size - 1) + '.';
	return input.substr(0, size);
}

// ************************************************************************** //
//                                                                            //
// Method: init                                                               //
//                                                                            //
// Description:                                                               //
//     Initializes the contact with user-provided information.                //
//                                                                            //
// ************************************************************************** //
void	Contact::init(void) {
	// std::cin.ignore() is used to clear
	// any leftover newline characters
	// from the input buffer
	// std::cin.ignore();
	this->_firstName = _getInput("Enter your name: ");
	this->_lastName = _getInput("Enter your surname: ");
	this->_nickName = _getInput("Enter your nickname: ");
	this->_phoneNumber = _getInput("Enter your phone number :");
	this->_secretQuestion = _getInput("Enter your secret question: ");
	this->_secretAnswer = _getInput("Enter your answer on secret question: ");
	std::cout << std::endl;
}

// ************************************************************************** //
//                                                                            //
// Method: noContactInBook                                                    //
//                                                                            //
// Description:                                                               //
//     Checks if the contact book is empty by verifying if essential fields   //
//     are empty.                                                             //
//                                                                            //
// Return Value:                                                              //
//     int - Returns 1 if the contact book is empty, 0 otherwise              //
//                                                                            //
// ************************************************************************** //
int	Contact::noContactInBook() const {
	if (this->_firstName.empty()
		|| this->_lastName.empty()
		|| this->_nickName.empty())
		return (1);
	return (0);
}

// ************************************************************************** //
//                                                                            //
// Method: displayContact                                                     //
//                                                                            //
// Description:                                                               //
//     Displays the contact information in a formatted manner.                //
//                                                                            //
// Parameters:                                                                //
//     int index - The index of the contact                                   //
//                                                                            //
// Return Value:                                                              //
//     int - Returns 0 if successful, otherwise an error code                 //
//                                                                            //
// ************************************************************************** //
int	Contact::displayContact(int index) const {

	if (this->noContactInBook())
		return 1;
	std::cout << "│" << std::setfill(' ')<< std::setw(10) << index << std::flush;
	std::cout << "│" << std::setw(10) << this->_getFormattedSubstring(this->_firstName, 10) << std::flush;
	std::cout << "│" << std::setw(10) << this->_getFormattedSubstring(this->_lastName, 10) << std::flush;
	std::cout << "│" << std::setw(10) << this->_getFormattedSubstring(this->_nickName, 10) << std::flush;
	std::cout << "│" << std::endl;
	return (0);
}

// ************************************************************************** //
//                                                                            //
// Method: paddingSize                                                        //
//                                                                            //
// Description:                                                               //
//     Calculates the padding size required to center-align text within a     //
//     specified width.                                                       //
//                                                                            //
// Parameters:                                                                //
//     int width - The total width available                                  //
//     std::string str - The string to be centered                            //
//                                                                            //
// Return Value:                                                              //
//     int - The padding size                                                 //
//                                                                            //
// ************************************************************************** //
int		Contact::paddingSize(int width, std::string str) const {
	int	size = str.size();
	return (((width - size) / 2) + size);
}

// ************************************************************************** //
//                                                                            //
// Method: viewContact                                                        //
//                                                                            //
// Description:                                                               //
//     Displays detailed contact information for a specific contact.          //
//                                                                            //
// Parameters:                                                                //
//     int index - The index of the contact                                   //
//                                                                            //
// ************************************************************************** //
void	Contact::viewContact(int index) const {
	int	width = 46;
	int	leftPadding = 3;
	std::string firstName = this->_getFormattedSubstring("First Name: " + this->_firstName, 37);
	std::string lastName = this->_getFormattedSubstring("Last Name:  " + this->_lastName, 37);
	std::string nickName = this->_getFormattedSubstring("Nickname:   " + this->_nickName, 37);

	if (this->noContactInBook())
		return ;
	std::cout << std::endl;
	std::cout << "╔═══════════ >>> CONTACT # " << index << " <<< ═══════════╗" << std::endl;
	std::cout << "║" << std::setfill(' ') << std::setw(width - 3) << " " << "║" << std::endl;
	std::cout << "║" << std::setw(leftPadding) << " " << firstName << std::setw(width - leftPadding - firstName.length()) << "║" << std::endl;
	std::cout << "║" << std::setw(leftPadding) << " " << lastName << std::setw(width - leftPadding - lastName.length()) << "║" << std::endl;
	std::cout << "║" << std::setw(leftPadding) << " " << nickName << std::setw(width - leftPadding - nickName.length()) << "║" << std::endl;
	std::cout << "║" << std::setw(width - 3) << " " << "║" << std::endl;
	std::cout << "╚═══════════════════════════════════════════╝" << std::endl;
	std::cout << std::endl;
}

// ************************************************************************** //
//                                                                            //
// Method: assignIndex                                                        //
//                                                                            //
// Description:                                                               //
//     Assigns an index to the contact.                                       //
//                                                                            //
// Parameters:                                                                //
//     int i - The index to be assigned                                       //
//                                                                            //
// ************************************************************************** //
void	Contact::assignIndex(int i) {
	this->_index = i;
}
