/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:43:47 by dzuiev            #+#    #+#             */
/*   Updated: 2024/09/09 13:31:03 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog"), _brain(new Brain()) {
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : AAnimal(other), _brain(new Brain(*other._brain)) {
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog() {
	delete _brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs) {
	if (this != &rhs) {
		AAnimal::operator=(rhs);
		delete _brain;
		_brain = new Brain(*rhs._brain);
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Woof Woof" << std::endl;
}

Brain* Dog::getBrain() const {
	return _brain;
}
