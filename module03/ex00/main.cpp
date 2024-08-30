/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:36:07 by dzuiev            #+#    #+#             */
/*   Updated: 2024/08/30 12:44:33 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <sstream>
#include <string>

static std::string intToString(int num) {
	std::stringstream ss;
	ss << num;
	return ss.str();
}

int main() {
	// Demonstrate the constructor with a name parameter
	ClapTrap robot1("Robot1");
	ClapTrap robot4("Robot4");

	// Demonstrate the copy constructor
	ClapTrap robot2(robot1);
	ClapTrap robot5(robot4);

	// Demonstrate the copy assignment operator
	ClapTrap robot3("Robot3");
	robot3 = robot1;

	ClapTrap robot6("Robot6");
	robot6 = robot4;

	// Demonstrate various actions
	robot1.attack("Target1");
	robot2.attack("Target2");
	robot3.attack("Target3");
	robot4.attack("Target4");
	robot5.attack("Target5");
	robot6.attack("Target6");

	// Demonstrate taking damage and repairs
	robot1.takeDamage(5);  // Robot1 takes 5 damage
	robot1.takeDamage(5);  // Robot1 takes another 5 damage, should be at 0 HP

	robot2.takeDamage(3);  // Robot2 takes 3 damage
	robot2.takeDamage(7);  // Robot2 takes 7 damage, should be at 0 HP

	robot3.takeDamage(9);  // Robot3 takes 9 damage
	robot3.beRepaired(5);  // Robot3 repairs 5 HP

	robot4.takeDamage(4);  // Robot4 takes 4 damage
	robot4.beRepaired(6);  // Robot4 repairs 6 HP

	robot5.attack("Target5");  // Robot5 attacks, normal
	robot5.takeDamage(11);     // Robot5 takes more damage than it has, should be 0 HP

	robot6.attack("Target6");  // Robot6 attacks, normal
	robot6.beRepaired(10);     // Robot6 repairs 10 HP, costs 1 EP

	// Attempt actions with robots that have no energy or are dead
	robot1.attack("Target7");  // Should say Robot1 is dead and cannot attack
	robot2.beRepaired(3);      // Should say Robot2 is dead and cannot repair
	robot5.attack("Target8");  // Should say Robot5 is dead and cannot attack

	// Drain robot3's energy to test behavior with 0 energy

	std::string index;
	
	for (int i = 0; i < 10; ++i) {
		robot3.attack("Target" + intToString(i + 9));
	}
	robot3.attack("FinalTarget"); // Should say Robot3 has no energy and cannot attack

	return 0;
}
