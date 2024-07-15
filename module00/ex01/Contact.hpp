/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:06:28 by dzuiev            #+#    #+#             */
/*   Updated: 2024/07/15 21:46:28 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact {
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phoneNumber;
		std::string	_secretQuestion;
		std::string	_secretAnswer;
		int			_index;

		std::string	_getFormattedSubstring(std::string input, size_t size) const;
		std::string	_getInput(std::string prompt) const;

	public:
		Contact ();
		~Contact();
		
		int		noContactInBook(void) const;
		int		displayContact(int index) const;
		int		paddingSize(int width, std::string str) const;
		void	init(void);
		void	viewContact(int index) const;
		void	assignIndex(int i);
};

#endif // CONTACT_HPP
