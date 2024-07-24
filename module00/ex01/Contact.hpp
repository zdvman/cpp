/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:06:28 by dzuiev            #+#    #+#             */
/*   Updated: 2024/07/24 14:46:02 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>      // Standard library for input and output streams
#include <iomanip>       // Standard library for controlling input and output format

// ************************************************************************** //
//                                                                            //
// Class: Contact                                                             //
//                                                                            //
// Description:                                                               //
//     This class represents a contact in a phone book. It stores various     //
//     details about the contact and provides methods to manipulate and       //
//     display this information.                                              //
//                                                                            //
// ************************************************************************** //

class Contact {
private:
    std::string _firstName;         // First name of the contact
    std::string _lastName;          // Last name of the contact
    std::string _nickName;          // Nickname of the contact
    std::string _phoneNumber;       // Phone number of the contact
    std::string _secretQuestion;    // Secret question for the contact
    std::string _secretAnswer;      // Answer to the secret question
    int _index;                     // Index of the contact in the phone book

// ************************************************************************** //
//                                                                            //
// Method: _getFormattedSubstring                                             //
//                                                                            //
// Description:                                                               //
//     Returns a formatted substring of the input string with a specified     //
//     maximum size. If the string is longer than the specified size, it      //
//     truncates and appends a dot.                                           //
//                                                                            //
// Parameters:                                                                //
//     std::string input - The input string to format                         //
//     size_t size - The maximum size of the formatted substring              //
//                                                                            //
// Return Value:                                                              //
//     std::string - The formatted substring                                  //
//                                                                            //
// ************************************************************************** //
    std::string _getFormattedSubstring(std::string input, size_t size) const;

// ************************************************************************** //
//                                                                            //
// Method: _getInput                                                          //
//                                                                            //
// Description:                                                               //
//     Prompts the user for input and returns the entered string. Ensures     //
//     the input is not empty.                                                //
//                                                                            //
// Parameters:                                                                //
//     std::string prompt - The prompt message to display                     //
//                                                                            //
// Return Value:                                                              //
//     std::string - The user input                                           //
//                                                                            //
// ************************************************************************** //
    std::string _getInput(std::string prompt) const;

public:
// ************************************************************************** //
//                                                                            //
// Constructor: Contact                                                       //
//                                                                            //
// Description:                                                               //
//     Initializes a new instance of the Contact class.                       //
//                                                                            //
// ************************************************************************** //
    Contact();

// ************************************************************************** //
//                                                                            //
// Destructor: ~Contact                                                       //
//                                                                            //
// Description:                                                               //
//     Cleans up the instance of the Contact class.                           //
//                                                                            //
// ************************************************************************** //
    ~Contact();

// ************************************************************************** //
//                                                                            //
// Method: noContactInBook                                                    //
//                                                                            //
// Description:                                                               //
//     Checks if the contact book is empty by verifying if essential fields   //
//     are empty.                                                             //
//                                                                            //
// Return Value:                                                              //
//     int - Returns 1 if the contact book is empty, 0 otherwise              //
//                                                                            //
// ************************************************************************** //
    int noContactInBook(void) const;

// ************************************************************************** //
//                                                                            //
// Method: displayContact                                                     //
//                                                                            //
// Description:                                                               //
//     Displays the contact information in a formatted manner.                //
//                                                                            //
// Parameters:                                                                //
//     int index - The index of the contact                                   //
//                                                                            //
// Return Value:                                                              //
//     int - Returns 0 if successful, otherwise an error code                 //
//                                                                            //
// ************************************************************************** //
    int displayContact(int index) const;

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
    int paddingSize(int width, std::string str) const;

// ************************************************************************** //
//                                                                            //
// Method: init                                                               //
//                                                                            //
// Description:                                                               //
//     Initializes the contact with user-provided information.                //
//                                                                            //
// ************************************************************************** //
    void init(void);

// ************************************************************************** //
//                                                                            //
// Method: viewContact                                                        //
//                                                                            //
// Description:                                                               //
//     Displays detailed contact information for a specific contact.          //
//                                                                            //
// Parameters:                                                                //
//     int index - The index of the contact                                   //
//                                                                            //
// ************************************************************************** //
    void viewContact(int index) const;

// ************************************************************************** //
//                                                                            //
// Method: assignIndex                                                        //
//                                                                            //
// Description:                                                               //
//     Assigns an index to the contact.                                        //
//                                                                            //
// Parameters:                                                                //
//     int i - The index to be assigned                                       //
//                                                                            //
// ************************************************************************** //
    void assignIndex(int i);
};

#endif // CONTACT_HPP
