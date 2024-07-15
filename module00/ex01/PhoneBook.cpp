/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:56:11 by dzuiev            #+#    #+#             */
/*   Updated: 2024/07/15 22:10:32 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {};
PhoneBook::~PhoneBook() {};
/*
Use the reminder of 8 to receive digits from 0 to 7
Explanation:
i: 0 i % 8: 0
i: 1 i % 8: 1
i: 2 i % 8: 2
i: 3 i % 8: 3
i: 4 i % 8: 4
i: 5 i % 8: 5
i: 6 i % 8: 6
i: 7 i % 8: 7
i: 8 i % 8: 0
i: 9 i % 8: 1
i: 10 i % 8: 2
i: 11 i % 8: 3
i: 12 i % 8: 4
i: 13 i % 8: 5
i: 14 i % 8: 6
i: 15 i % 8: 7
*/
void	PhoneBook::addContact(void) {
	// static variable declaration
	// to reuse the value of i in the next function call
	static int i = 0;

	this->_contacts[i % 8].init();
	this->_contacts[i % 8].assignIndex(i % 8);
	i++;
}

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

// to draw a specific line according to the position
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

void	PhoneBook::searchContact(void) const {
	int i = this->_readInput();
	if (this->_contacts[i].noContactInBook()) {
		std::cout << "No CONTACT in the PHONEBOOK with INDEX : " << i << std::endl;
		return ;
	}
	this->_contacts[i].viewContact(i);
}

int		PhoneBook::paddingSize(int width, std::string str) const {
	int	size = str.size();
	return (((width - size) / 2) + size);
}

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
