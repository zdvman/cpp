/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:39:29 by dzuiev            #+#    #+#             */
/*   Updated: 2024/09/03 17:21:15 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
	// Creating DiamondTrap object using the constructor
	DiamondTrap diamondBot("DiamondBot");

	// Demonstrating the copy constructor
	DiamondTrap diamondBotClone(diamondBot);

	// Demonstrating the assignment operator
	DiamondTrap assignedBot("AssignedBot");
	assignedBot = diamondBot;

	// Demonstrating the attack method (inherited from ScavTrap)
	diamondBot.attack("Target1");

	// Demonstrating specific DiamondTrap behavior
	diamondBot.whoAmI(); // Shows both the DiamondTrap name and ClapTrap name

	// Demonstrating the unique capabilities of DiamondTrap
	diamondBotClone.whoAmI(); // Shows the copied object name and its ClapTrap name

	// Polymorphic behavior test (although DiamondTrap doesn't demonstrate polymorphism directly, 
	// we'll show how the base class methods can still be used correctly)
	ClapTrap* polymorphicTrap = new DiamondTrap("PolymorphicBot");
	polymorphicTrap->attack("Target2");

	// Clean up
	delete polymorphicTrap;

	// Demonstrating destruction (shows proper destruction chaining)
	return 0;
}
