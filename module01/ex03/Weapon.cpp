/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:16:49 by dzuiev            #+#    #+#             */
/*   Updated: 2024/08/13 18:22:07 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

// Constructor implementation
Weapon::Weapon(std::string type) : _type(type) {}

// Destructor implementation
Weapon::~Weapon() {}

// Getter implementation
const std::string& Weapon::getType() const {
	return _type;
}

// Setter implementation
void Weapon::setType(const std::string& newType) {
	_type = newType;
}
