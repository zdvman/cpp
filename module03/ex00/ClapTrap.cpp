/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:27:07 by dzuiev            #+#    #+#             */
/*   Updated: 2024/08/30 12:18:08 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructor
ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attacDamage(0) {
	std::cout << "ClapTrap " << _name << " constructed." << std::endl;
}

// Copy Constructor
ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attacDamage(other._attacDamage) {
	std::cout << "ClapTrap " << _name << " copied from " << other._name << "." << std::endl;
}

// Destructor
ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << " destructed." << std::endl;
}

// Copy Assignment Operator
ClapTrap& ClapTrap::operator=(const ClapTrap& rhs) {
	std::cout << "ClapTrap " << _name << " assigned from " << rhs._name << "." << std::endl;
	if (this != &rhs) {
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attacDamage = rhs._attacDamage;
	}
	return *this;
}

// Attack Method
void ClapTrap::attack(const std::string& target) {
	if (_hitPoints <= 0) {
		std::cout << "ClapTrap " << _name << " is dead and cannot attack!" << std::endl;
	} else if (_energyPoints <= 0) {
		std::cout << "ClapTrap " << _name << " has no energy and cannot attack!" << std::endl;
	} else {
		std::cout << "ClapTrap " << _name
				<< " attacks " << target
				<< ", causing " << _attacDamage
				<< " points of damage!" << std::endl;
		_energyPoints--;
	}
}

// Take Damage Method
void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints > 0) {
		if (amount >= _hitPoints) {
			_hitPoints = 0;
			std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage and is now dead!" << std::endl;
		} else {
			_hitPoints -= amount;
			std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage, remaining hit points: " << _hitPoints << "." << std::endl;
		}
	} else {
		std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
	}
}

// Be Repaired Method
void ClapTrap::beRepaired(unsigned int amount) {
	if (_energyPoints > 0 && _hitPoints > 0) {
		_hitPoints += amount;
		_energyPoints--;
		std::cout << "ClapTrap " << _name << " repairs itself, restoring " 
				<< amount << " hit points! Remaining energy points: " 
				<< _energyPoints << std::endl;
	} else if (_hitPoints <= 0) {
		std::cout << "ClapTrap " << _name << " cannot repair itself because it's out of hit points!" << std::endl;
	} else {
		std::cout << "ClapTrap " << _name << " cannot repair itself because it's out of energy points!" << std::endl;
	}
}
