/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:01:11 by dzuiev            #+#    #+#             */
/*   Updated: 2024/09/09 15:03:18 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
	std::cout << "Ice Materia created" << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other) {}

Ice& Ice::operator=(const Ice& rhs) {
	if (this != &rhs) {
		AMateria::operator=(rhs); // Call base class assignment
	}
	return *this;
}

Ice::~Ice() {
	std::cout << "Ice Materia destroyed" << std::endl;
}

AMateria* Ice::clone() const {
	return new Ice(*this); // Return new instance
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
