/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 15:51:03 by dzuiev            #+#    #+#             */
/*   Updated: 2024/08/23 17:14:28 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// ************************************************************************** //
//                                                                            //
// Constructor: Fixed                                                         //
//                                                                            //
// Description:                                                               //
//     Initializes a new instance of the Fixed class with a value of 0.       //
//                                                                            //
// ************************************************************************** //
Fixed::Fixed() : _fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
};

// ************************************************************************** //
//                                                                            //
// Copy Constructor: Fixed                                                    //
//                                                                            //
// Description:                                                               //
//     Creates a copy of an existing Fixed instance by copying the raw value. //
//                                                                            //
// ************************************************************************** //
Fixed::Fixed (const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

// ************************************************************************** //
//                                                                            //
// Copy Assignment Operator: operator=                                        //
//                                                                            //
// Description:                                                               //
//     Assigns the value from another Fixed instance to this one.             //
//     Checks for self-assignment to avoid unnecessary operations.            //
//                                                                            //
// ************************************************************************** //
Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) { // avoid self operator assignment
		this->_fixedPointValue = other.getRawBits(); // Copy the raw value
	}

	return *this;
}

// ************************************************************************** //
//                                                                            //
// Destructor: ~Fixed                                                         //
//                                                                            //
// Description:                                                               //
//     Destroys the instance of the Fixed class, performing any necessary     //
//     cleanup.                                                               //
//                                                                            //
// ************************************************************************** //
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
};

// ************************************************************************** //
//                                                                            //
// Function: getRawBits                                                       //
//                                                                            //
// Description:                                                               //
//     Returns the raw integer value stored in the fixed-point variable.      //
//                                                                            //
// ************************************************************************** //
int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointValue;
}

// ************************************************************************** //
//                                                                            //
// Function: setRawBits                                                       //
//                                                                            //
// Description:                                                               //
//     Sets the raw integer value of the fixed-point variable to the given    //
//     input.                                                                 //
//                                                                            //
// ************************************************************************** //
void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointValue = raw;
}
