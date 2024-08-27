/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:09:44 by dzuiev            #+#    #+#             */
/*   Updated: 2024/08/27 18:30:09 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* ************************************************************************** */
/*                                                                            */
/*  Default constructor:                                                      */
/*  Initializes the `_fixedPointValue` to 0.                                  */
/*  Outputs a message indicating that the default constructor was called.     */
/*                                                                            */
/* ************************************************************************** */

Fixed::Fixed() : _fixedPointValue(0) {}

/* ************************************************************************** */
/*                                                                            */
/*  Integer constructor:                                                      */
/*  Takes an integer `value` and converts it to the fixed-point format by     */
/*  shifting it left by `_fractionalBits` positions (8 bits in this case).    */
/*  Outputs a message indicating that the integer constructor was called.     */
/*                                                                            */
/* ************************************************************************** */

Fixed::Fixed(const int value) : _fixedPointValue(value << _fractionalBits) {}

/* ************************************************************************** */
/*                                                                            */
/*  Float constructor:                                                        */
/*  Takes a floating-point `value` and converts it to the fixed-point format  */
/*  by multiplying it by `2^8` (256) and rounding the result.                 */
/*  Outputs a message indicating that the float constructor was called.       */
/*                                                                            */
/* ************************************************************************** */

Fixed::Fixed(const float value) : _fixedPointValue(static_cast<int>(roundf(value * (1 << _fractionalBits)))) {}

/* ************************************************************************** */
/*                                                                            */
/*  Copy constructor:                                                         */
/*  Initializes the current object by copying the values from another         */
/*  `Fixed` object.                                                           */
/*  Outputs a message indicating that the copy constructor was called.        */
/*                                                                            */
/* ************************************************************************** */

Fixed::Fixed(const Fixed& other) {
    *this = other;
}

/* ************************************************************************** */
/*                                                                            */
/*  Copy assignment operator:                                                 */
/*  Assigns the values from another `Fixed` object to the current object.     */
/*  Checks for self-assignment and copies the `_fixedPointValue` using        */
/*  the `getRawBits()` method.                                                */
/*  Outputs a message indicating that the copy assignment operator was called.*/
/*  Returns a reference to the current object.                                */
/*                                                                            */
/* ************************************************************************** */

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) {
        _fixedPointValue = other.getRawBits();
    }
    return *this;
}

/* ************************************************************************** */
/*                                                                            */
/*  Destructor:                                                               */
/*  Outputs a message indicating that the destructor was called.              */
/*                                                                            */
/* ************************************************************************** */

Fixed::~Fixed() {}

/* ************************************************************************** */
/*                                                                            */
/*  getRawBits:                                                               */
/*  Returns the raw value of the fixed-point number (`_fixedPointValue`).     */
/*                                                                            */
/* ************************************************************************** */

int Fixed::getRawBits(void) const {
    return _fixedPointValue;
}

/* ************************************************************************** */
/*                                                                            */
/*  setRawBits:                                                               */
/*  Sets the raw value of the fixed-point number (`_fixedPointValue`) to the  */
/*  provided integer `raw`.                                                   */
/*                                                                            */
/* ************************************************************************** */

void Fixed::setRawBits(int const raw) {
    _fixedPointValue = raw;
}

/* ************************************************************************** */
/*                                                                            */
/*  toFloat:                                                                  */
/*  Converts the fixed-point value to a floating-point number by dividing it  */
/*  by `2^8` (256).                                                           */
/*  Returns the resulting float value.                                        */
/*                                                                            */
/* ************************************************************************** */

float Fixed::toFloat(void) const {
    return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits);
}

/* ************************************************************************** */
/*                                                                            */
/*  toInt:                                                                    */
/*  Converts the fixed-point value to an integer by shifting it right by      */
/*  `_fractionalBits` positions (8 bits in this case).                        */
/*  Returns the resulting integer value.                                      */
/*                                                                            */
/* ************************************************************************** */

int Fixed::toInt(void) const {
    return _fixedPointValue >> _fractionalBits;
}

/* ************************************************************************** */
/*                                                                            */
/*  Overloaded `<<` operator:                                                 */
/*  Outputs the `Fixed` object as a floating-point number by calling the      */
/*  `toFloat()` method.                                                       */
/*  Returns the `std::ostream` object to allow chaining of output operations. */
/*                                                                            */
/* ************************************************************************** */

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}


// In the context of this code, rhs stands for "right-hand side."
// comparison operators 
bool Fixed::operator>(const Fixed& rhs) const {
	return this->_fixedPointValue > rhs._fixedPointValue;
};

bool Fixed::operator<(const Fixed& rhs) const {
	return this->_fixedPointValue < rhs._fixedPointValue;
};

bool Fixed::operator>=(const Fixed& rhs) const {
	return this->_fixedPointValue >= rhs._fixedPointValue;
};

bool Fixed::operator<=(const Fixed& rhs) const {
	return this->_fixedPointValue <= rhs._fixedPointValue;
};

bool Fixed::operator==(const Fixed& rhs) const {
	return this->_fixedPointValue == rhs._fixedPointValue;
};

bool Fixed::operator!=(const Fixed& rhs) const {
	return this->_fixedPointValue != rhs._fixedPointValue;
};

// arithmetic operators
Fixed Fixed::operator+(const Fixed& rhs) const {
	return Fixed(this->toFloat() + rhs.toFloat());
};

Fixed Fixed::operator-(const Fixed& rhs) const {
	return Fixed(this->toFloat() - rhs.toFloat());
};

Fixed Fixed::operator*(const Fixed& rhs) const {
	return Fixed(this->toFloat() * rhs.toFloat());
};

Fixed Fixed::operator/(const Fixed& rhs) const {
	return Fixed(this->toFloat() / rhs.toFloat());
};

// increment/decrement (pre-increment and post-increment,
// pre-decrement and post-decrement) operators
Fixed& Fixed::operator++(void) { //prefix
	++this->_fixedPointValue;
	return *this;
};

Fixed Fixed::operator++(int) { //postfix
	Fixed tmp(*this);
	tmp._fixedPointValue = this->_fixedPointValue++;
	return tmp;
};

Fixed& Fixed::operator--(void) { //prefix
	--this->_fixedPointValue;
	return *this;
};

Fixed Fixed::operator--(int) { //prefix
	Fixed tmp(*this);
	tmp._fixedPointValue = this->_fixedPointValue--;
	return tmp;
};

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a < b) ? a : b;
};

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a > b) ? a : b;
};

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b) ? a : b;
};

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b) ? a : b;
};
