/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:21:58 by dzuiev            #+#    #+#             */
/*   Updated: 2024/07/15 19:32:48 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void) {
	PhoneBook	book;
	std::string	input = "";

	book.welcomeMessage();
	while (input.compare("EXIT")) {
		if (!input.compare("ADD")) {
			book.addContact();
		}
		else if (!input.compare("SEARCH")) {
			if (!book.displayBook()) {
				book.searchContact();
			}
		}
		std::cout << "> " << std::flush;
		std::cin >> input;
	}
	return (0);
}
