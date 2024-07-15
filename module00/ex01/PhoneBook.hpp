/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:33:45 by dzuiev            #+#    #+#             */
/*   Updated: 2024/07/15 19:31:22 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <limits>
#include "Contact.hpp"

class PhoneBook {
	private:
		Contact	_contacts[8];

		int		_readInput(void) const;

	public:
		PhoneBook();
		~PhoneBook();

		int		paddingSize(int width, std::string str) const;
		int		displayBook(void) const;
		void	addContact(void);
		void	searchContact(void) const;
		void	welcomeMessage(void) const;
		void	drawLine(int typeOfLine, int width, std::string str) const;
};

#endif // PHONEBOOK_HPP
