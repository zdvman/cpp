/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 13:08:09 by dzuiev            #+#    #+#             */
/*   Updated: 2024/09/09 11:17:01 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : _type(other._type) {}

WrongAnimal::~WrongAnimal() {}


WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs) {
	if (this != &rhs) {
		_type = rhs._type;
	}
	return *this;
}

std::string WrongAnimal::getType() const {
	return this->_type;
}

void WrongAnimal::makeSound() const {
	std::cout << "Generic WrongAnimal Sound" << std::endl;  // Default sound for WrongAnimal
}
