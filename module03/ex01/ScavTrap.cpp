/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 12:51:37 by dzuiev            #+#    #+#             */
/*   Updated: 2024/08/30 15:04:53 by dzuiev           ###   ########.fr       */
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
	std::cout << getClassName() << " " << _name << " constructed." << std::endl;
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
	std::cout << getClassName() << " " << _name << " copied from " << other._name << "." << std::endl;
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
	std::cout << getClassName() << " " << _name << " destructed." << std::endl;
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
		// Call the base class's assignment operator to handle base class members
		ClapTrap::operator=(rhs);
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
	 std::cout << getClassName() << " " << _name << " is now in Gate keeper mode." << std::endl;
}
