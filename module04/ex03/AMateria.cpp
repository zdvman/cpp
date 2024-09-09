/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:29:16 by dzuiev            #+#    #+#             */
/*   Updated: 2024/09/09 15:21:33 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("default type") {
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(const std::string& type) : _type(type) {
	std::cout << "AMateria parameterized constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other) : _type(other._type) {
	std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria::~AMateria() {
	std::cout << "AMateria destructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& rhs) {
	if (this != &rhs) {
		_type = rhs._type;
	}
	std::cout << "AMateria copy assignment operator called" << std::endl;
	return *this;
}

const std::string& AMateria::getType() const { //Returns the materia type
	return this->_type;
}

// The use() function is still pure virtual, to be overridden by derived classes.
void AMateria::use(ICharacter& target) {
	(void) target;
}
