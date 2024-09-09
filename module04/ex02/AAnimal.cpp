/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:04:17 by dzuiev            #+#    #+#             */
/*   Updated: 2024/09/09 13:27:50 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("default AAnimal") {
	std::cout << "AAnimal default costructor called" << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type) {
	std::cout << "AAnimal costructor with type = \"" << type <<"\" value called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : _type(other._type) {
	std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& rhs) {
	if (this != &rhs) {
		_type = rhs._type;
	}
	return *this;
}

std::string AAnimal::getType() const {
	return this->_type;
}

// void AAnimal::makeSound() const {
// 	std::cout << "Generic AAnimal Sound" << std::endl;  // Default sound for AAnimal
// }
