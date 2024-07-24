/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:56:11 by dzuiev            #+#    #+#             */
/*   Updated: 2024/07/24 14:59:36 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// ************************************************************************** //
//                                                                            //
// Constructor: PhoneBook                                                     //
//                                                                            //
// Description:                                                               //
//     Initializes a new instance of the PhoneBook class.                     //
//                                                                            //
// ************************************************************************** //
PhoneBook::PhoneBook() {}

// ************************************************************************** //
//                                                                            //
// Destructor: ~PhoneBook                                                     //
//                                                                            //
// Description:                                                               //
//     Cleans up the instance of the PhoneBook class.                         //
//                                                                            //
// ************************************************************************** //
PhoneBook::~PhoneBook() {}

// ************************************************************************** //
//                                                                            //
// Method: addContact                                                         //
//                                                                            //
// Description:                                                               //
//     Adds a new contact to the phone book. Uses the remainder of 8 to cycle //
//     through indices from 0 to 7.                                           //
//                                                                            //
// Explanation:                                                               //
//     i: 0  i % 8: 0                                                         //
//     i: 1  i % 8: 1                                                         //
//     i: 2  i % 8: 2                                                         //
//     i: 3  i % 8: 3                                                         //
//     i: 4  i % 8: 4                                                         //
//     i: 5  i % 8: 5                                                         //
//     i: 6  i % 8: 6                                                         //
//     i: 7  i % 8: 7                                                         //
//     i: 8  i % 8: 0                                                         //
//     i: 9  i % 8: 1                                                         //
//     i: 10 i % 8: 2                                                         //
//                                                                            //
// Parameters:                                                                //
//     void                                                                   //
//                                                                            //
// ************************************************************************** //
void	PhoneBook::addContact(void) {
	// Static variable to retain the value of i between function calls
	static int i = 0;

	// Initialize the contact at index i % 8
	this->_contacts[i % 8].init();
	this->_contacts[i % 8].assignIndex(i % 8);
	i++;
}

// ************************************************************************** //
//                                                                            //
// Method: _readInput                                                         //
//                                                                            //
// Description:                                                               //
//     Reads and validates an integer input from the user.                    //
//                                                                            //
// Return Value:                                                              //
//     int - The validated integer input                                      //
//                                                                            //
// ************************************************************************** //
int	PhoneBook::_readInput(void) const {
	int		input = -1;
	bool	validIndex = false;

	do {
		std::cout << "Please enter the contact index: " << std::flush;
		std::cin >> input;
		if (std::cin.good() && (input >= 0 && input < 8)) {
			validIndex = true;
		} else {
			// Clear any error flags that may have been set on std::cin.
			// This is necessary if a previous input operation failed, to allow further input operations to proceed.
			std::cin.clear();

			// Ignore the rest of the current input line, up to and including the newline character.
			// This is done to remove any invalid input remaining in the input buffer, ensuring the buffer is clean for the next input operation.
			// The numeric_limits<std::streamsize>::max() ensures that a very large number of characters will be ignored.
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid contact index, please re-enter from 0 to 7." << std::endl;
		}
	} while (!validIndex);
	return (input);
}

// ************************************************************************** //
//                                                                            //
// Method: drawLine                                                           //
//                                                                            //
// Description:                                                               //
//     Draws a line for the table display in the console.                     //
//                                                                            //
// Parameters:                                                                //
//     int typeOfLine - The type of line to draw                              //
//     int width - The width of the line                                      //
//     std::string str - The string to display within the line                //
//                                                                            //
// ************************************************************************** //
void	PhoneBook::drawLine(int typeOfLine, int width, std::string str) const {
	switch (typeOfLine) {
		case (0): { // welcome string
			std::cout << "┌" << std::setfill('-') << std::setw(width - 3) << "-" << "┐" << std::endl;
			std::cout << "│" << std::setfill(' ') << std::setw(width - 3) << " " << "│" << std::endl;
			std::cout << "│" << std::setw(paddingSize(width, str)) << str << std::setw(width - paddingSize(width, str)) << "│" << std::endl;
			std::cout << "│" << std::setw(width - 3) << " " << "│" << std::endl;
			break ;
		}
		case (1): { // middel line
			std::cout << "├" << std::setfill('-') << std::setw(10) << "-" << std::flush;
			std::cout << "┼" << std::setw(10) << "-" << std::flush;
			std::cout << "┼" << std::setw(10) << "-" << std::flush;
			std::cout << "┼" << std::setw(10) << "-" << std::flush;
			std::cout << "┤" << std::endl;
			break ;
		}
		case (2): { // welcome bottom line
			std::cout << "├" << std::setfill('-') << std::setw(10) << "-" << std::flush;
			std::cout << "┬" << std::setw(10) << "-" << std::flush;
			std::cout << "┬" << std::setw(10) << "-" << std::flush;
			std::cout << "┬" << std::setw(10) << "-" << std::flush;
			std::cout << "┤" << std::endl;
			break ;
		}
		case (3): { // contact table header
			std::cout << "│" << std::setfill(' ')<< std::setw(10) << "INDEX" << std::flush;
			std::cout << "│" << std::setw(10) << "NAME" << std::flush;
			std::cout << "│" << std::setw(10) << "SURNAME" << std::flush;
			std::cout << "│" << std::setw(10) << "NICKNAME" << std::flush;
			std::cout << "│" << std::endl;
			break ;
		}
		case (4): { // bottom line of the contact table
			std::cout << "└" << std::setfill('-') << std::setw(10) << "-" << std::flush;
			std::cout << "┴" << std::setw(10) << "-" << std::flush;
			std::cout << "┴" << std::setw(10) << "-" << std::flush;
			std::cout << "┴" << std::setw(10) << "-" << std::flush;
			std::cout << "┘" << std::endl;
		}
	}
}

// ************************************************************************** //
//                                                                            //
// Method: displayBook                                                        //
//                                                                            //
// Description:                                                               //
//     Displays the list of contacts in the phone book in a formatted manner. //
//                                                                            //
// Return Value:                                                              //
//     int - Returns 0 if successful, otherwise an error code                 //
//                                                                            //
// ************************************************************************** //
int	PhoneBook::displayBook(void) const {
	if (this->_contacts[0].noContactInBook()) {
		std::cout << "There are no CONTACTS in the PHONEBOOK yet" << std::endl;
		return 1;
	}
	int			width = 46;
	std::string	header = " PHONEBOOK CONTACTS ";

	// welcome string
	drawLine(0, width, header);
	// welcome bottom line
	drawLine(2, width, header);
	// table header
	drawLine(3, width, header);
	// middle line
	drawLine(1, width, header);
	// printing all existing contacts
	for (int i = 0; i < 8; i++) {
		if (this->_contacts[i].displayContact(i) == 0 && i < 7) {
			// draw a line if the next contact does exist
			if (this->_contacts[i + 1].noContactInBook() == 0) {
				// middle line
				drawLine(1, width, header);
			}
		}
	}
	// bottom line of the contanct table
	drawLine(4, width, header);
	return (0);
}

// ************************************************************************** //
//                                                                            //
// Method: searchContact                                                      //
//                                                                            //
// Description:                                                               //
//     Searches for a contact by index and displays the contact's details.    //
//                                                                            //
// ************************************************************************** //
void	PhoneBook::searchContact(void) const {
	int i = this->_readInput();
	if (this->_contacts[i].noContactInBook()) {
		std::cout << "No CONTACT in the PHONEBOOK with INDEX : " << i << std::endl;
		return ;
	}
	this->_contacts[i].viewContact(i);
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
int		PhoneBook::paddingSize(int width, std::string str) const {
	int	size = str.size();
	return (((width - size) / 2) + size);
}

// ************************************************************************** //
//                                                                            //
// Method: welcomeMessage                                                     //
//                                                                            //
// Description:                                                               //
//     Displays a welcome message with instructions on how to use the phone   //
//     book.                                                                  //
//                                                                            //
// ************************************************************************** //
void PhoneBook::welcomeMessage(void) const {
	int			width = 46;
	int			leftPadding = 3;
	std::string	welcome = "Welcome to Tiny Phone Book!";
	std::string	details1 = "You can store up to 8 contacts.";
	std::string	details2 = " USAGE ";
	std::string	details3 = "ADD      : save a new contact.";
	std::string	details4 = "SEARCH   : display a specific contact.";
	std::string	details5 = "EXIT     : to close PhoneBook.";

	std::cout << "┌" << std::setfill('-') << std::setw(width - 3) << "-" << "┐" << std::endl;
	std::cout << "│" << std::setfill(' ') << std::setw(width - 3) << " " << "│" << std::endl;
	std::cout << "│" << std::setw(paddingSize(width, welcome)) << welcome << std::setw(width - paddingSize(width, welcome)) << "│" << std::endl;
	std::cout << "│" << std::setw(paddingSize(width, details1)) << details1 << std::setw(width - paddingSize(width, details1)) << "│" << std::endl;
	std::cout << "│" << std::setw(width - 3) << " " << "│" << std::endl;
	std::cout << "│" << std::setfill('-') << std::setw(paddingSize(width, details2)) << details2 << std::setw(width - paddingSize(width, details2)) << "│" << std::endl;
	std::cout << "│" << std::setfill(' ') << std::setw(width - 3) << " " << "│" << std::endl;
	std::cout << "│" << std::setw(leftPadding) << " " << details3 << std::setw(width - leftPadding - details3.length()) << "│" << std::endl;
	std::cout << "│" << std::setw(leftPadding) << " " << details4 << std::setw(width - leftPadding - details4.length()) << "│" << std::endl;
	std::cout << "│" << std::setw(leftPadding) << " " << details5 << std::setw(width - leftPadding - details5.length()) << "│" << std::endl;
	std::cout << "│" << std::setw(width - 3) << " " << "│" << std::endl;
	std::cout << "└" << std::setfill('-') << std::setw(width - 3) << "-" << "┘" << std::endl;
	std::cout << std::setfill(' ') << std::endl;
}
