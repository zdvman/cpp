/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:54:17 by dzuiev            #+#    #+#             */
/*   Updated: 2024/09/03 14:50:16 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "[Derived Class] " << getClassName()
		<< " object with the name \"" << _name << "\" has been constructed." << std::endl;
}

// Copy Constructor
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	// Message now clarifies that this object is a copy, and shows the original object's name.
	std::cout << "[Derived Class] " << getClassName() << " \"" 
			<< _name << "\" created as a copy of the original \"" << other._name << "\"." << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "[Derived Class] " << getClassName()
		<< " object with the name \"" << _name << "\" has been destructed." << std::endl;
}

// Override to return "FragTrap"
std::string FragTrap::getClassName() const {
	return "FragTrap";
}

// Copy Assignment Operator in FragTrap (Derived Class)
FragTrap& FragTrap::operator=(const FragTrap& rhs) {
	if (this != &rhs) {
		// Chaining: Call the base class's assignment operator
		std::cout << "[Derived Class] " << getClassName() << " LHS object is about to call base class assignment operator." << std::endl;
		ClapTrap::operator=(rhs);  // This calls the base class assignment operator on *this
	}
	return *this;
}

void FragTrap::highFivesGuys(void) {
	if (_energyPoints > 0) {
		std::cout << "[Derived Class] " << getClassName() << " \"" << _name << "\" requests a positive high five ✋!" << std::endl;
	} else {
		std::cout << "[Derived Class] " << getClassName() << " \"" << _name << "\" has no energy and cannot request a high five!" << std::endl;
	}
}
