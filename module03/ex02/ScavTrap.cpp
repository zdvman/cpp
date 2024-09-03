/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:40:02 by dzuiev            #+#    #+#             */
/*   Updated: 2024/09/03 14:49:24 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/* ************************************************************************** */
/*                                                                            */
/* Constructor: ScavTrap                                                      */
/*                                                                            */
/* Description:                                                               */
/*     Constructs a `ScavTrap` object, initializing it with specific values.  */
/*     Demonstrates construction chaining by first calling the base class     */
/*     (`ClapTrap`) constructor.                                              */
/*                                                                            */
/* ************************************************************************** */
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	_hitPoints = 100; 
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "[Derived Class] " << getClassName()
		<< " object with the name \"" << _name << "\" has been constructed." << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/* Copy Constructor: ScavTrap                                                 */
/*                                                                            */
/* Description:                                                               */
/*     Copies an existing `ScavTrap` object, initializing this object with    */
/*     the same attributes. Demonstrates construction chaining by calling the */
/*     base class (`ClapTrap`) copy constructor.                              */
/*                                                                            */
/* ************************************************************************** */
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	// Message now clarifies that this object is a copy, and shows the original object's name.
	std::cout << "[Derived Class] " << getClassName() << " \"" 
			<< _name << "\" created as a copy of the original \"" << other._name << "\"." << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/* Destructor: ~ScavTrap                                                      */
/*                                                                            */
/* Description:                                                               */
/*     Destructs the `ScavTrap` object. Shows proper destruction chaining     */
/*     by calling the base class (`ClapTrap`) destructor after the derived    */
/*     class destructor.                                                      */
/*                                                                            */
/* ************************************************************************** */
ScavTrap::~ScavTrap() {
	std::cout << "[Derived Class] " << getClassName()
		<< " object with the name \"" << _name << "\" has been destructed." << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/* Copy Assignment Operator: operator=                                        */
/*                                                                            */
/* Description:                                                               */
/*     Assigns the attributes of another `ScavTrap` to this object, ensuring  */
/*     that this object does not assign itself (self-assignment check).       */
/*     Calls the base class's assignment operator to handle base class        */
/*     attributes.                                                            */
/*                                                                            */
/* ************************************************************************** */
ScavTrap& ScavTrap::operator=(const ScavTrap& rhs) {
	if (this != &rhs) {
		// Chaining: Call the base class's assignment operator
		std::cout << "[Derived Class] " << getClassName() << " LHS object is about to call base class assignment operator." << std::endl;
		ClapTrap::operator=(rhs);  // This calls the base class assignment operator on *this
	}
	return *this;
}

/* ************************************************************************** */
/*                                                                            */
/* Method: getClassName                                                       */
/*                                                                            */
/* Description:                                                               */
/*     Returns the class name "ScavTrap". Overrides the base class method.    */
/*                                                                            */
/* ************************************************************************** */
std::string ScavTrap::getClassName() const {
	return "ScavTrap";
}

/* ************************************************************************** */
/*                                                                            */
/* Method: guardGate                                                          */
/*                                                                            */
/* Description:                                                               */
/*     ScavTrap-specific method that puts the object into Gatekeeper mode,    */
/*     printing a message to indicate the change.                             */
/*                                                                            */
/* ************************************************************************** */
void ScavTrap::guardGate() {
	if (_energyPoints > 0) {
		std::cout << "[Derived Class] " << getClassName() << " \"" << _name << "\" is now in Gate Keeper mode." << std::endl;
	} else {
		std::cout << "[Derived Class] " << getClassName() << " \"" << _name << "\" has no energy and cannot enter Gate Keeper mode!" << std::endl;
	}
}
