/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:33:45 by dzuiev            #+#    #+#             */
/*   Updated: 2024/07/09 17:01:16 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <cctype>
#include "Contact.hpp"

class PhoneBook {
	private:
		Contact	_contacts[8];

		int		_readInput(void) const;

	public:
		PhoneBook();
		~PhoneBook();

		void	addContact(void);
		void	displayContacts(void) const;
		void	searchContact(void) const;
		void	welcomeMessage(void) const;
		int		paddingSize(int width, std::string str) const;
};

#endif // PHONEBOOK_HPP
