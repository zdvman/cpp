/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:09:44 by dzuiev            #+#    #+#             */
/*   Updated: 2024/08/29 10:42:03 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* ************************************************************************** */
/*                                                                            */
/*  Constructors and Destructor:                                              */
/*  - Default constructor initializes the `_fixedPointValue` to 0.            */
/*  - Integer constructor converts an integer to a fixed-point format.        */
/*  - Float constructor converts a float to a fixed-point format.             */
/*  - Copy constructor initializes the current object with another `Fixed`.   */
/*  - Destructor does not need to do anything special.                        */
/*                                                                            */
/* ************************************************************************** */
Fixed::Fixed() : _fixedPointValue(0) {}

Fixed::Fixed(const int value) : _fixedPointValue(value << _fractionalBits) {}

Fixed::Fixed(const float value) : _fixedPointValue(static_cast<int>(roundf(value * (1 << _fractionalBits)))) {}

Fixed::Fixed(const Fixed& other) {
	*this = other;
}

Fixed::~Fixed() {}

/* ************************************************************************** */
/*                                                                            */
/*  Copy Assignment Operator:                                                 */
/*  - Assigns values from another `Fixed` object to the current object.       */
/*  - Checks for self-assignment and copies the `_fixedPointValue`.           */
/*  - Returns a reference to the current object.                              */
/*                                                                            */
/* ************************************************************************** */
Fixed& Fixed::operator=(const Fixed& rhs) {
	if (this != &rhs) {
		_fixedPointValue = rhs.getRawBits();
	}
	return *this;
}

/* ************************************************************************** */
/*                                                                            */
/*  Getter and Setter:                                                        */
/*  - `getRawBits` returns the raw fixed-point value.                         */
/*  - `setRawBits` sets the raw fixed-point value.                            */
/*                                                                            */
/* ************************************************************************** */
int Fixed::getRawBits(void) const {
	return _fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
	_fixedPointValue = raw;
}

/* ************************************************************************** */
/*                                                                            */
/*  Conversion Functions:                                                     */
/*  - `toFloat` converts the fixed-point value to a float.                    */
/*  - `toInt` converts the fixed-point value to an integer.                   */
/*                                                                            */
/* ************************************************************************** */
float Fixed::toFloat(void) const {
	return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
	return _fixedPointValue >> _fractionalBits;
}

/* ************************************************************************** */
/*                                                                            */
/*  Overloaded `<<` Operator:                                                 */
/*  - Outputs the `Fixed` object as a float by calling `toFloat()`.           */
/*  - Returns the `std::ostream` object to allow chaining.                    */
/*                                                                            */
/* ************************************************************************** */
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}

/* ************************************************************************** */
/*                                                                            */
/*  Comparison Operators:                                                     */
/*  - Overloads for >, <, >=, <=, ==, and !=.                                 */
/*  - Allows comparison between `Fixed` objects based on their raw values.    */
/*                                                                            */
/* ************************************************************************** */
bool Fixed::operator>(const Fixed& rhs) const {
	return this->_fixedPointValue > rhs._fixedPointValue;
}

bool Fixed::operator<(const Fixed& rhs) const {
	return this->_fixedPointValue < rhs._fixedPointValue;
}

bool Fixed::operator>=(const Fixed& rhs) const {
	return this->_fixedPointValue >= rhs._fixedPointValue;
}

bool Fixed::operator<=(const Fixed& rhs) const {
	return this->_fixedPointValue <= rhs._fixedPointValue;
}

bool Fixed::operator==(const Fixed& rhs) const {
	return this->_fixedPointValue == rhs._fixedPointValue;
}

bool Fixed::operator!=(const Fixed& rhs) const {
	return this->_fixedPointValue != rhs._fixedPointValue;
}

/* ************************************************************************** */
/*                                                                            */
/*  Arithmetic Operators:                                                     */
/*  - Overloads for +, -, *, and /.                                           */
/*  - Allows arithmetic operations between `Fixed` objects.                   */
/*  - Returns a new `Fixed` object containing the result of the operation.    */
/*                                                                            */
/* ************************************************************************** */
Fixed Fixed::operator+(const Fixed& rhs) const {
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(const Fixed& rhs) const {
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(const Fixed& rhs) const {
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed& rhs) const {
	return Fixed(this->toFloat() / rhs.toFloat());
}

/* ************************************************************************** */
/*                                                                            */
/*  Increment and Decrement Operators:                                        */
/*  - Supports both prefix and postfix increment (++), and decrement (--).    */
/*  - Prefix operators modify and return the object itself.                   */
/*  - Postfix operators return a temporary copy before modifying the object.  */
/*                                                                            */
/* ************************************************************************** */
Fixed& Fixed::operator++(void) { // prefix
	++this->_fixedPointValue;
	return *this;
}

Fixed Fixed::operator++(int) { // postfix
	Fixed tmp(*this);
	tmp._fixedPointValue = this->_fixedPointValue++;
	return tmp;
}

Fixed& Fixed::operator--(void) { // prefix
	--this->_fixedPointValue;
	return *this;
}

Fixed Fixed::operator--(int) { // postfix
	Fixed tmp(*this);
	tmp._fixedPointValue = this->_fixedPointValue--;
	return tmp;
}

/* ************************************************************************** */
/*                                                                            */
/*  Min and Max Functions:                                                    */
/*  - Static functions that return the smaller or larger of two `Fixed`       */
/*    objects.                                                                */
/*  - Overloaded for non-const and const references.                          */
/*                                                                            */
/* ************************************************************************** */
Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a > b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b) ? a : b;
}
