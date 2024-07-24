/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:21:58 by dzuiev            #+#    #+#             */
/*   Updated: 2024/07/24 15:37:31 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// ************************************************************************** //
//                                                                            //
// Function: main                                                             //
//                                                                            //
// Description:                                                               //
//     The main function for the PhoneBook application. It displays a welcome //
//     message, then enters a loop to process user commands for adding and    //
//     searching contacts.                                                    //
//                                                                            //
// Parameters:                                                                //
//     void                                                                   //
//                                                                            //
// Return Value:                                                              //
//     int - Returns 0 upon successful completion                             //
//                                                                            //
// ************************************************************************** //

int main(void) {
	PhoneBook book;        // Create an instance of the PhoneBook class
	std::string input = ""; // Variable to store user input

	book.welcomeMessage(); // Display the welcome message

	// Main loop to process user commands
	while (true) {
		std::cout << "> " << std::flush; // Prompt the user for input
		std::cin >> input;               // Read the user input

		// Clear the input buffer to remove the newline character left by std::cin
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		if (input == "EXIT")
			break; // Exit the loop if the user types "EXIT"

		if (input.compare("ADD") == 0) {
			book.addContact(); // Add a new contact if the user types "ADD"
		} else if (input.compare("SEARCH") == 0) {
			if (book.displayBook() == 0) {
				book.searchContact(); // Search for a contact if the user types "SEARCH"
			}
		}
	}

	return (0); // Return 0 to indicate successful completion
}
