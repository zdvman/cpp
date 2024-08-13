/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:46:49 by dzuiev            #+#    #+#             */
/*   Updated: 2024/08/13 13:57:55 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main() {
	// 1. Create a string variable and initialize it with the value "HI THIS IS BRAIN".
	std::string str = "HI THIS IS BRAIN";

	// 2. Create a pointer to the string.
	std::string* stringPTR = &str;

	// 3. Create a reference to the string.
	// A reference named stringREF is created.
	// It is another name for the str string.
	// Unlike pointers, references are automatically dereferenced.
	std::string& stringREF = str;

	// 4. Output the memory address of the string variable.
	std::cout << "Memory address of the string variable: " << &str << std::endl;

	// 5. Output the memory address held by stringPTR.
	std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;

	// 6. Output the memory address held by stringREF.
	std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;

	// 7. Output the value of the string variable.
	std::cout << "Value of the string variable: " << str << std::endl;

	// 8. Output the value pointed to by stringPTR.
	std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;

	// 9. Output the value pointed to by stringREF.
	std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;

	return 0;
}
