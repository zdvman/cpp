/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:04:17 by dzuiev            #+#    #+#             */
/*   Updated: 2024/09/09 11:15:21 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal") {}

Animal::Animal(std::string type) : _type(type) {}

Animal::Animal(const Animal& other) : _type(other._type) {}

Animal::~Animal() {}

Animal& Animal::operator=(const Animal& rhs) {
	if (this != &rhs) {
		_type = rhs._type;
	}
	return *this;
}

std::string Animal::getType() const {
	return this->_type;
}

void Animal::makeSound() const {
	std::cout << "Generic Animal Sound" << std::endl;  // Default sound for Animal
}
