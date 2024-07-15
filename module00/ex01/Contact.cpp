/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:55:26 by dzuiev            #+#    #+#             */
/*   Updated: 2024/07/15 18:26:11 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {};
Contact::~Contact() {};

std::string	Contact::_getInput(std::string prompt) const {
	std::string input = "";
	while (1) {
		std::cout << prompt << std::flush;
		std::getline(std::cin, input);
		if (std::cin.good() && !input.empty()) {
			break ;
		}
		else {
			std::cin.clear();
			std::cout << "Invalid input, try again." << std::endl;
		}
	}
	return (input);
}

std::string	Contact::_getFormattedSubstring(std::string input) const {
	if (input.size() > 10)
		return input.substr(0, 9) + '.';
	return input.substr(0, 10);
}

void	Contact::init(void) {
	std::cin.ignore();
	this->_firstName = _getInput("Enter your name: ");
	this->_lastName = _getInput("Enter your surname: ");
	this->_nickName = _getInput("Enter your nickname: ");
	this->_phoneNumber = _getInput("Enter your phone number :");
	this->_secretQuestion = _getInput("Enter your secret question: ");
	this->_secretAnswer = _getInput("Enter your answer on secret question: ");
	std::cout << std::endl;
}

int	Contact::noContactInBook() const {
	if (this->_firstName.empty()
		|| this->_lastName.empty()
		|| this->_nickName.empty())
		return (1);
	return (0);
}

int	Contact::displayContact(int index) const {

	if (noContactInBook())
		return 1;
	std::cout << "│" << std::setfill(' ')<< std::setw(10) << index << std::flush;
	std::cout << "│" << std::setw(10) << this->_getFormattedSubstring(this->_firstName) << std::flush;
	std::cout << "│" << std::setw(10) << this->_getFormattedSubstring(this->_lastName) << std::flush;
	std::cout << "│" << std::setw(10) << this->_getFormattedSubstring(this->_nickName) << std::flush;
	std::cout << "│" << std::endl;
	return (0);
}

void	Contact::viewContact(int index) const {
	if (noContactInBook())
		return ;
	std::cout << std::endl;
	std::cout << "======>>> CONTACT #" << index << " <<<======" << std::endl;
	std::cout << "First Name:\t" << this->_firstName << std::endl;
	std::cout << "Last Name:\t" << this->_lastName << std::endl;
	std::cout << "Nickname:\t" << this->_nickName << std::endl;
	std::cout << std::endl;
}

void	Contact::assignIndex(int i) {
	this->_index = i;
}
