/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:19:40 by dzuiev            #+#    #+#             */
/*   Updated: 2024/08/13 18:31:54 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

// ************************************************************************** //
// Default constructor
// ************************************************************************** //
HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon) {}

// ************************************************************************** //
// Destructor implementation
// ************************************************************************** //
HumanA::~HumanA() {}

void HumanA::attack() const {
	std::cout << this->_name << " attacks with their " << _weapon.getType() << std::endl;
}
