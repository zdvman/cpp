/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:06:28 by dzuiev            #+#    #+#             */
/*   Updated: 2024/07/09 17:14:59 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact {
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickName;
		std::string _phoneNumber;
		std::string _secretQuestion;
		std::string _secretAnswer;
		int			_index;

		std::string _getFormattedSubstring(std::string input) const;
		std::string _getInput(std::string prompt) const;

	public:
		Contact ();
		~Contact();
		
		void init(void);
		void display(int index) const;
		void view(int index) const;
		void assignIndex(int i);
		
};

#endif // CONTACT_HPP
