/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:03:39 by dzuiev            #+#    #+#             */
/*   Updated: 2024/09/09 17:06:11 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*   Cure.cpp                                                                 */
/*                                                                            */
/*   This file implements the Cure class, which represents a type of Materia. */
/*   Cure Materia can be cloned and has a unique use case, where it heals     */
/*   the wounds of a character target.                                        */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

/* ************************************************************************** */
/*   Constructors, Destructor, and Assignment Operator                        */
/*                                                                            */
/*   - Cure() : Initializes the Materia type to "cure" and logs the creation. */
/*   - Cure(const Cure&) : Copy constructor that duplicates another Cure obj. */
/*   - operator=() : Ensures deep copy of the Cure object during assignment.  */
/*   - ~Cure() : Destructor that logs when a Cure object is destroyed.        */
/*                                                                            */
/* ************************************************************************** */
Cure::Cure() : AMateria("cure") {
	// std::cout << "Cure Materia created" << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other) {
	// std::cout << "Cure Materia copy constructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& other) {
	if (this != &other) {
		AMateria::operator=(other); // Call base class assignment operator
	}
	return *this;
}

Cure::~Cure() {
	// std::cout << "Cure Materia destroyed" << std::endl;
}

/* ************************************************************************** */
/*   clone()                                                                  */
/*                                                                            */
/*   - This method creates and returns a new Cure object, ensuring that the   */
/*     new object is a deep copy of the current instance. This is useful for  */
/*     copying Materia objects during gameplay.                               */
/*                                                                            */
/* ************************************************************************** */
AMateria* Cure::clone() const {
	return new Cure(*this); // Create a deep copy of the Cure instance
}

/* ************************************************************************** */
/*   use()                                                                    */
/*                                                                            */
/*   - This method defines what happens when the Cure Materia is used on a    */
/*     character target. In this case, it heals the wounds of the target.     */
/*                                                                            */
/* ************************************************************************** */
void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
