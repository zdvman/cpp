/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:46:15 by dzuiev            #+#    #+#             */
/*   Updated: 2024/08/13 13:43:52 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// ************************************************************************** //
// Function to create a horde of N Zombies
// ************************************************************************** //
Zombie* zombieHorde(int N, std::string name) {
	if (N <= 0) {
		return NULL; // Return nullptr if the number of zombies is invalid
	}

	// Allocate memory for N Zombie objects
	Zombie* horde = new Zombie[N];
	
	// Initialize each Zombie in the horde with the provided name
	for (int i = 0; i < N; i++) {
		horde[i] = Zombie(name);
	}

	return horde; // Return a pointer to the first Zombie in the horde
}
