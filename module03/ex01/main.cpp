/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 12:50:43 by dzuiev            #+#    #+#             */
/*   Updated: 2024/08/30 15:26:40 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

/* ************************************************************************** */
/*                                                                            */
/* Function: main                                                             */
/*                                                                            */
/* Description:                                                               */
/*     This function demonstrates the creation, copying, assignment, and      */
/*     destruction of `ClapTrap` and `ScavTrap` objects. It also shows the    */
/*     polymorphic behavior through virtual functions and the use of          */
/*     inheritance.                                                           */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	// Creating ClapTrap objects
	ClapTrap basicBot("BasicBot");

	// Demonstrating copy constructor
	ClapTrap basicBotClone(basicBot);

	// Demonstrating assignment operator
	ClapTrap assignedBot("AssignedBot");
	assignedBot = basicBot;

	// Demonstrating ScavTrap creation (shows construction chaining)
	ScavTrap defenderBot("DefenderBot");

	// Demonstrating ScavTrap copy constructor
	ScavTrap defenderBotClone(defenderBot);

	// Use defenderBotClone to show it's distinct from defenderBot
	defenderBotClone.attack("Intruder2");

	// Demonstrating ScavTrap assignment operator
	ScavTrap assignedDefender("AssignedDefender");
	assignedDefender = defenderBot;

	// Demonstrating polymorphic behavior
	ClapTrap* polymorphicBot = new ScavTrap("PolymorphicBot");

	polymorphicBot->attack("Intruder1"); // Calls ScavTrap's attack due to virtual function

	// Demonstrating specific ScavTrap behavior
	defenderBot.guardGate();

	// Cleanup
	delete polymorphicBot; // Shows proper destruction chaining

	return 0;
}
