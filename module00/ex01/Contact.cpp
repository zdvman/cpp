/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:55:26 by dzuiev            #+#    #+#             */
/*   Updated: 2024/07/04 19:54:50 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {};
Contact::~Contact() {};

std::string Contact::_getInput(std::string prompt) const {
	std::string input = "";
	while (1) {
		std::cout << prompt << std::flush;
		std::getline(std::cin, input);
		if (std::cin.good() && !input.empty())
			break ;
		else {
			std::cin.clear();
			std::cout << "Invalid input, try again." << std::endl;
		}
	}
	return (input);
}

void	Contact::init(void) {
	std::cin.ignore();
	this->_firstName = _getInput("Enter your name: ");
	this->_lastName = _getInput("Enter your surname: ");
	this->_phoneNumber = _getInput("Enter your phone number :");
	this->_secretQuestion = _getInput("Enter your secret question: ");
	this->_secretAnswer = _getInput("Enter your answer on secret question: ");
	std::cout << std::endl;
}

void	Contact::display(int index) const {
	
}
