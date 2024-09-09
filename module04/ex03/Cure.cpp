/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:03:39 by dzuiev            #+#    #+#             */
/*   Updated: 2024/09/09 15:04:03 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
	std::cout << "Cure Materia created" << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other) {}

Cure& Cure::operator=(const Cure& other) {
	if (this != &other) {
		AMateria::operator=(other); // Call base class assignment
	}
	return *this;
}

Cure::~Cure() {
	std::cout << "Cure Materia destroyed" << std::endl;
}

AMateria* Cure::clone() const {
	return new Cure(*this); // Return new instance
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
