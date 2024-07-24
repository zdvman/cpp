/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:31:54 by dzuiev            #+#    #+#             */
/*   Updated: 2024/07/24 14:42:39 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>     // Standard library for input and output streams
#include <cctype>       // Standard library for character classification and conversion

// ************************************************************************** //
//                                                                            //
// Function: main                                                             //
//                                                                            //
// Description:                                                               //
//     Entry point of the program. It converts command-line arguments to      //
//     uppercase and prints them. If no arguments are provided, it prints a   //
//     default message.                                                       //
//                                                                            //
// Parameters:                                                                //
//     int argc - Number of command-line arguments                            //
//     char **argv - Array of pointers to command-line arguments              //
//                                                                            //
// Return Value:                                                              //
//     int - Returns 0 to indicate successful execution                       //
//                                                                            //
// ************************************************************************** //

int main(int argc, char **argv)
{
	// Check if there are no command-line arguments provided
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *"; // Print default message
	else {
		// Loop through each command-line argument starting from the second argument
		for (int i = 1; i < argc; ++i) {
			// Loop through each character of the current argument
			for (int j = 0; argv[i][j] != '\0'; ++j) {
				// Convert the character to uppercase and print it
				std::cout << static_cast<char>(std::toupper(argv[i][j]));
			}
		}
	}
	std::cout << std::endl; // Print a newline character at the end
	return (0); // Return 0 to indicate successful execution
}
