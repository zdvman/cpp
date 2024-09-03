/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:39:02 by dzuiev            #+#    #+#             */
/*   Updated: 2024/09/03 14:44:38 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructor
ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "[Base Class] " << getClassName()
		<< " object with the name \"" << _name << "\" has been constructed." << std::endl;
}

// Copy Constructor
ClapTrap::ClapTrap(const ClapTrap& other) :
	_name(other._name),
	_hitPoints(other._hitPoints),
	_energyPoints(other._energyPoints),
	_attackDamage(other._attackDamage) {
	// Message now clarifies that this object is a copy, and shows the original object's name.
	std::cout << "[Base Class] " << getClassName() << " \"" << _name 
			<< "\" created as a copy of the original \"" << other._name << "\"." << std::endl;
}

// Destructor
ClapTrap::~ClapTrap() {
	std::cout << "[Base Class] " << getClassName()
		<< " object with the name \"" << _name << "\" has been destructed." << std::endl;
}

// Copy Assignment Operator
ClapTrap& ClapTrap::operator=(const ClapTrap& rhs) { // right-hand side = left-hand side
	// Check for self-assignment
	if (this != &rhs) {
		// Copy the attributes from the source object to the current object
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	// Print a message indicating that the current object has been updated
	// with the values from the source object.
	std::cout << "[Base Class] Assignment method is called by an LHS object \"" << this->_name
		<< "\" of class " << getClassName() 
		<< ", and now it has the attributes of the original RHS object \"" << rhs._name << "\"." 
		<< std::endl;
	return *this;
}

/* ************************************************************************** */
/*                                                                            */
/* Virtual Method: getClassName                                               */
/*                                                                            */
/* Description:                                                               */
/*     Returns the class name. Declared virtual to allow derived classes to   */
/*     override and provide their own class name.                             */
/*                                                                            */
/* ************************************************************************** */
std::string ClapTrap::getClassName() const {
	return "ClapTrap";
}

// Attack Method
void ClapTrap::attack(const std::string& target) {
	if (_hitPoints <= 0) {
		std::cout << getClassName() << " " << _name
				<< " is dead and cannot attack!" << std::endl;
	} else if (_energyPoints <= 0) {
		std::cout << getClassName() << " " << _name
				<< " has no energy and cannot attack!" << std::endl;
	} else {
		std::cout << getClassName() << " " << _name
				<< " attacks " << target
				<< ", causing " << _attackDamage
				<< " points of damage!" << std::endl;
		_energyPoints--;
	}
}

// Take Damage Method
void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints > 0) {
		if (amount >= _hitPoints) {
			_hitPoints = 0;
			std::cout << getClassName() << " " << _name
					<< " takes " << amount
					<< " points of damage and is now dead!" << std::endl;
		} else {
			_hitPoints -= amount;
			std::cout << getClassName() << " " << _name
					<< " takes " << amount
					<< " points of damage, remaining hit points: " << _hitPoints << "." << std::endl;
		}
	} else {
		std::cout << getClassName() << " " << _name
				<< " is already dead!" << std::endl;
	}
}

// Be Repaired Method
void ClapTrap::beRepaired(unsigned int amount) {
	if (_energyPoints > 0 && _hitPoints > 0) {
		_hitPoints += amount;
		_energyPoints--;
		std::cout << getClassName() << " " << _name << " repairs itself, restoring " 
				<< amount << " hit points! Remaining energy points: " 
				<< _energyPoints << std::endl;
	} else if (_hitPoints <= 0) {
		std::cout << getClassName() << " " << _name
				<< " cannot repair itself because it's out of hit points!" << std::endl;
	} else {
		std::cout << getClassName() << " " << _name
				<< " cannot repair itself because it's out of energy points!" << std::endl;
	}
}
