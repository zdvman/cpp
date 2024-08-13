/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:49:32 by dzuiev            #+#    #+#             */
/*   Updated: 2024/08/13 13:41:59 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	int N = 5;
	std::string name = "ZombieHorde";

	// Create a Zombie using the default constructor
	Zombie defaultZombie;
	defaultZombie.announce();

	// Create a Zombie using the constructor with a name
	Zombie namedZombie("Frank");
	namedZombie.announce();

	// Create a horde of Zombies
	Zombie* horde = zombieHorde(N, name);

	// Ensure the horde was created successfully
	if (horde != NULL) {
		// Call announce for each Zombie in the horde
		for (int i = 0; i < N; i++) {
			horde[i].announce();
		}
	}

	// Delete the horde to free the allocated memory
	delete[] horde;

	return 0;
}
