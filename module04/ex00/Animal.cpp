/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:04:17 by dzuiev            #+#    #+#             */
/*   Updated: 2024/09/06 12:45:58 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal") {}

Animal::Animal(std::string type) : type(type) {}

Animal::Animal(const Animal& other) {
	*this = other;
}

Animal::~Animal() {}

Animal& Animal::operator=(const Animal& rhs) {
	if (this != &rhs) {
		type = rhs.type;
	}
	return *this;
}

std::string Animal::getType() const {
	return this->type;
}

void Animal::makeSound() const {
	std::cout << "Generic Animal Sound" << std::endl;  // Default sound for Animal
}
