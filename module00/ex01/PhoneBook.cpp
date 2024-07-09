/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:56:11 by dzuiev            #+#    #+#             */
/*   Updated: 2024/07/09 19:00:24 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {};
PhoneBook::~PhoneBook() {};

void	PhoneBook::addContact(void) {
	Contact contact;
	
}

void	PhoneBook::displayContacts(void) const {

}

void	PhoneBook::searchContact(void) const {

}

int		PhoneBook::paddingSize(int width, std::string str) const {
	int	size = str.size();
	return (((width - size) / 2) + size);
}

void PhoneBook::welcomeMessage(void) const {
	int			width = 50;
	int			leftPadding = 8;
	std::string	welcome = "Welcome to Tiny Phone Book!";
	std::string	details1 = "You can store up to 9 contacts.";
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
