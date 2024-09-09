/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:01:11 by dzuiev            #+#    #+#             */
/*   Updated: 2024/09/09 17:05:51 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*   Ice.cpp                                                                  */
/*                                                                            */
/*   This file implements the Ice class, which represents a type of Materia.  */
/*   Ice Materia can be cloned and has a unique use case, where it shoots     */
/*   an ice bolt at a target.                                                 */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

/* ************************************************************************** */
/*   Constructors, Destructor, and Assignment Operator                        */
/*                                                                            */
/*   - Ice() : Initializes the Materia type to "ice" and logs the creation.   */
/*   - Ice(const Ice&) : Copy constructor that duplicates another Ice object. */
/*   - operator=() : Ensures deep copy of the Ice object during assignment.   */
/*   - ~Ice() : Destructor that logs when an Ice object is destroyed.         */
/*                                                                            */
/* ************************************************************************** */
Ice::Ice() : AMateria("ice") {
	// std::cout << "Ice Materia created" << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other) {
	// std::cout << "Ice Materia copy constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& rhs) {
	if (this != &rhs) {
		AMateria::operator=(rhs); // Call base class assignment operator
	}
	return *this;
}

Ice::~Ice() {
	// std::cout << "Ice Materia destroyed" << std::endl;
}

/* ************************************************************************** */
/*   clone()                                                                  */
/*                                                                            */
/*   - This method creates and returns a new Ice object, ensuring that the    */
/*     new object is a deep copy of the current instance. This is useful for  */
/*     copying Materia objects during gameplay.                               */
/*                                                                            */
/* ************************************************************************** */
AMateria* Ice::clone() const {
	return new Ice(*this); // Create a deep copy of the Ice instance
}

/* ************************************************************************** */
/*   use()                                                                    */
/*                                                                            */
/*   - This method defines what happens when the Ice Materia is used on a     */
/*     character target. In this case, it shoots an ice bolt at the target.   */
/*                                                                            */
/* ************************************************************************** */
void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
