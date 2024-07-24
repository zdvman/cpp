/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:33:45 by dzuiev            #+#    #+#             */
/*   Updated: 2024/07/24 14:53:40 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <limits>      // Standard library for limits of integral types
#include "Contact.hpp" // Include the Contact class definition

// ************************************************************************** //
//                                                                            //
// Class: PhoneBook                                                           //
//                                                                            //
// Description:                                                               //
//     This class represents a phone book that can store up to 8 contacts.    //
//     It provides methods to add, display, and search contacts, as well as   //
//     display a welcome message.                                             //
//                                                                            //
// ************************************************************************** //
class PhoneBook {
	private:
		Contact	_contacts[8]; // Array to store up to 8 contacts

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
		int		_readInput(void) const;

	public:

// ************************************************************************** //
//                                                                            //
// Constructor: PhoneBook                                                     //
//                                                                            //
// Description:                                                               //
//     Initializes a new instance of the PhoneBook class.                     //
//                                                                            //
// ************************************************************************** //
		PhoneBook();

// ************************************************************************** //
//                                                                            //
// Destructor: ~PhoneBook                                                     //
//                                                                            //
// Description:                                                               //
//     Cleans up the instance of the PhoneBook class.                         //
//                                                                            //
// ************************************************************************** //
		~PhoneBook();

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
		int		paddingSize(int width, std::string str) const;

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
    int displayBook(void) const;

// ************************************************************************** //
//                                                                            //
// Method: addContact                                                         //
//                                                                            //
// Description:                                                               //
//     Adds a new contact to the phone book.                                  //
//                                                                            //
// ************************************************************************** //
    void addContact(void);

// ************************************************************************** //
//                                                                            //
// Method: searchContact                                                      //
//                                                                            //
// Description:                                                               //
//     Searches for a contact by index and displays the contact's details.    //
//                                                                            //
// ************************************************************************** //
    void searchContact(void) const;

// ************************************************************************** //
//                                                                            //
// Method: welcomeMessage                                                     //
//                                                                            //
// Description:                                                               //
//     Displays a welcome message with instructions on how to use the phone   //
//     book.                                                                  //
//                                                                            //
// ************************************************************************** //
    void welcomeMessage(void) const;

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
    void drawLine(int typeOfLine, int width, std::string str) const;
};

#endif // PHONEBOOK_HPP
