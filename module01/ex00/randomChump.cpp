/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:53:09 by dzuiev            #+#    #+#             */
/*   Updated: 2024/07/25 16:38:13 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <sstream> // For stringstream
#include "Zombie.hpp"

// ************************************************************************** //
// Create a temporary Zombie with the given name and call its announce method //
// ************************************************************************** //
void randomChump(std::string name) {
	// Create a Zombie object on the stack
	Zombie zombi(name);
	// Call the announce method of the Zombie object
	zombi.announce();
}

// ************************************************************************** //
// Generate a random name for a Zombie                                        //
// ************************************************************************** //
std::string generateRandomName(void) {
	int min = 1;
	int max = 10;

	// Seed the random number generator with the current time
	srand(static_cast<unsigned int>(time(0)));

	// Generate a random number between min and max
	int randomNumber = min + rand() % (max - min + 1);

	// Convert the random number to a string
	std::stringstream ss;
	ss << randomNumber;

	// Return a string "randomZombie" concatenated with the random number
	return "randomZombie" + ss.str();
}
