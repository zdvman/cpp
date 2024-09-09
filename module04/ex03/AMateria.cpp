/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:29:16 by dzuiev            #+#    #+#             */
/*   Updated: 2024/09/09 17:09:33 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*   AMateria.cpp                                                             */
/*                                                                            */
/*   This file implements the core methods for the AMateria class, including  */
/*   constructors, destructor, copy/assignment operators, and essential       */
/*   member functions. The purpose of these methods is to manage the          */
/*   lifecycle of AMateria objects, ensuring proper initialization, copying,  */
/*   assignment, and destruction. The virtual function `use` is designed to   */
/*   be overridden by derived classes like Ice or Cure.                       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/* ************************************************************************** */
/*   Constructors, Destructor, and Assignment Operator                        */
/*                                                                            */
/*   - AMateria::AMateria() : Initializes the _type attribute to a default    */
/*     value ("default type").                                                */
/*   - AMateria::AMateria(const std::string&) : Parameterized constructor     */
/*     that initializes the _type attribute to the given string.              */
/*   - AMateria::AMateria(const AMateria&) : Copy constructor that copies     */
/*     the _type attribute from another instance of AMateria.                 */
/*   - AMateria::~AMateria() : Destructor that cleans up the AMateria object. */
/*   - AMateria& AMateria::operator=(const AMateria&) : Assignment operator   */
/*     ensures proper copying of the _type attribute and prevents self-       */
/*     assignment.                                                            */
/*                                                                            */
/* ************************************************************************** */
AMateria::AMateria() : _type("default type") {
	// std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(const std::string& type) : _type(type) {
	// std::cout << "AMateria parameterized constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other) : _type(other._type) {
	// std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria::~AMateria() {
	// std::cout << "AMateria destructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& rhs) {
	if (this != &rhs) {
		_type = rhs._type;
	}
	// std::cout << "AMateria copy assignment operator called" << std::endl;
	return *this;
}

/* ************************************************************************** */
/*   Member Functions                                                         */
/*                                                                            */
/*   - getType() : Returns the _type attribute of the AMateria instance.      */
/*   - use() : A virtual function that does nothing in the base class but     */
/*     serves as an interface for derived classes (e.g., Ice, Cure) to        */
/*     implement their specific behavior when used.                           */
/*                                                                            */
/* ************************************************************************** */
const std::string& AMateria::getType() const {
	return this->_type;
}

void AMateria::use(ICharacter& target) {
	(void) target;  // Prevents unused variable warning.
}
