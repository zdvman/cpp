/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:27:07 by dzuiev            #+#    #+#             */
/*   Updated: 2024/08/29 13:59:26 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// ClapTrap() {}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attacDamage(0) {}

ClapTrap::ClapTrap(const ClapTrap& other) {
	*this = other;
}
ClapTrap::~ClapTrap() {

}
ClapTrap& ClapTrap::operator=(const ClapTrap& rhs) {
	if (this != &rhs) {
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attacDamage = rhs._attacDamage;
	}
	return *this;
}
void ClapTrap::attack(const std::string& target) {
	std::cout << "ClapTrap "<< _name
		<< " attacks " << target
		<< ", causing " << _attacDamage
		<< " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {

}

void ClapTrap::beRepaired(unsigned int amount) {

}
