/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:46:15 by dzuiev            #+#    #+#             */
/*   Updated: 2024/08/22 12:39:19 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <sstream> // Include the sstream header

// ************************************************************************** //
// Function to create a horde of N Zombies
// ************************************************************************** //
Zombie*	zombieHorde(int N, std::string name) {
	if (N <= 0) {
		return NULL; // Return nullptr if the number of zombies is invalid
	}

	// Allocate memory for N Zombie objects
	Zombie* horde = new Zombie[N];
	
	// Initialize each Zombie in the horde with the provided name
	for (int i = 0; i < N; i++) {
		std::stringstream ss;
        ss << name << (i + 1); // Append the index to the name
        std::string indexedName = ss.str();
		horde[i].setName(indexedName);
	}

	return horde; // Return a pointer to the first Zombie in the horde
}
