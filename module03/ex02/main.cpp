/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:39:29 by dzuiev            #+#    #+#             */
/*   Updated: 2024/09/03 15:24:41 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
	// Creating FragTrap objects
	FragTrap basicBot("BasicBot");

	// Demonstrating copy constructor
	FragTrap basicBotClone(basicBot);

	// Demonstrating assignment operator
	FragTrap assignedBot("AssignedBot");
	FragTrap toCopyBot("toCopy");
	assignedBot = toCopyBot;

	// Use basicBotClone to show it's distinct from basicBot
	basicBotClone.attack("Intruder1");

	// Demonstrating specific FragTrap behavior
	assignedBot.highFivesGuys();

	// Simulate low energy scenario by manually reducing energy points
	FragTrap lowEnergyBot("LowEnergyBot");
	for (int i = 0; i < 100; ++i) {
		lowEnergyBot.attack("Target"); // Reduce energy to 0
	}
	lowEnergyBot.highFivesGuys(); // This should show the no-energy message

	// Cleanup: Destruction chaining will be shown here
	// No need for polymorphic demonstration, as `attack` is not overridden

	// Demonstrate taking damage and repairing
	basicBotClone.takeDamage(30);
	basicBotClone.beRepaired(30);

	return 0;
}
