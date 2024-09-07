/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:55:39 by dzuiev            #+#    #+#             */
/*   Updated: 2024/09/07 13:36:19 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name"),  // Initialize the ClapTrap part with a modified name
	FragTrap(name),                  // Initialize the FragTrap part
	ScavTrap(name),                  // Initialize the ScavTrap part
	_name(name)                      // Initialize DiamondTrap's own name
{
	_hitPoints = FragTrap::_hitPoints;          // Inherited from FragTrap
	_energyPoints = ScavTrap::_energyPoints;    // Inherited from ScavTrap
	_attackDamage = FragTrap::_attackDamage;    // Inherited from FragTrap
	std::cout << "[Hybrid Class] " << getClassName()
		<< " object with the name \"" << _name << "\" has been constructed." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: ClapTrap(other),   // Initialize the ClapTrap part of DiamondTrap using the ClapTrap copy constructor
	FragTrap(other),   // Initialize the FragTrap part of DiamondTrap using the FragTrap copy constructor
	ScavTrap(other),   // Initialize the ScavTrap part of DiamondTrap using the ScavTrap copy constructor
	_name(other._name) // Initialize the _name attribute specific to DiamondTrap using the value from the 'other' object
{
	// Message now clarifies that this object is a copy, and shows the original object's name.
	std::cout << "[Hybrid Class] " << getClassName() << " \"" 
			<< _name << "\" created as a copy of the original \"" << other._name << "\"." << std::endl;
}

DiamondTrap::~DiamondTrap() {
std::cout << "[Hybrid Class] " << getClassName()
		<< " object with the name \"" << _name << "\" has been destructed." << std::endl;
}

// Override to return "FragTrap"
std::string DiamondTrap::getClassName() const {
	return "DiamondTrap";
}

void DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs) {
	if (this != &rhs) {
		// Indicate that the LHS object is about to call the base class assignment operators
		std::cout << "[Hybrid Class] " << getClassName() 
			<< " LHS object is about to call base class assignment operators for ClapTrap, ScavTrap, and FragTrap." 
			<< std::endl;

		// Chaining: Call the base class's assignment operators
		ClapTrap::operator=(rhs);  // Call base class assignment operator for ClapTrap
		ScavTrap::operator=(rhs);  // Call base class assignment operator for ScavTrap
		FragTrap::operator=(rhs);  // Call base class assignment operator for FragTrap

		// Assign the unique attributes of DiamondTrap
		_name = rhs._name;
	}
	return *this;
}

void	DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap name: " << _name << ", ClapTrap name: " 
			<< ClapTrap::_name << std::endl;
}
