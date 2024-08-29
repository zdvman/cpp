/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:52:27 by dzuiev            #+#    #+#             */
/*   Updated: 2024/08/29 15:53:33 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

/* ************************************************************************** */
/*                                                                            */
/* The `Fixed` class represents a fixed-point number, where a fixed number of */
/* fractional bits are used. This allows for a trade-off between performance  */
/* and precision. The class provides a variety of constructors, operators,    */
/* and utility functions for working with fixed-point numbers.                */
/*                                                                            */
/* ************************************************************************** */
class Fixed {
public:
/* ************************************************************************** */
/*                                                                            */
/* Constructors and Destructor:                                               */
/* - Default constructor initializes the fixed-point value to 0.              */
/* - Integer and float constructors convert their input to a fixed-point      */
/*   representation.                                                          */
/* - Copy constructor initializes a new Fixed object with the same value as   */
/*   another Fixed object.                                                    */
/* - Destructor cleans up resources, though none are dynamically allocated in */
/*   this class.                                                              */
/*                                                                            */
/* ************************************************************************** */
	Fixed(void);
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed& other);
	~Fixed();

/* ************************************************************************** */
/*                                                                            */
/* Copy Assignment Operator:                                                  */
/* - Allows assignment of one Fixed object to another. Copies the internal    */
/*   fixed-point value from the right-hand side (rhs) object to the left-hand */
/*   side object.                                                             */
/*                                                                            */
/* ************************************************************************** */
	Fixed& operator=(const Fixed& rhs);

/* ************************************************************************** */
/*                                                                            */
/* Getter and Setter for the Raw Fixed-Point Value:                           */
/* - `getRawBits` returns the internal fixed-point value.                     */
/* - `setRawBits` sets the internal fixed-point value to the provided integer.*/
/*                                                                            */
/* ************************************************************************** */
	int getRawBits(void) const;
	void setRawBits(int const raw);

/* ************************************************************************** */
/*                                                                            */
/* Conversion Functions:                                                      */
/* - `toFloat` converts the fixed-point value to a floating-point number.     */
/* - `toInt` converts the fixed-point value to an integer.                    */
/*                                                                            */
/* ************************************************************************** */
	float toFloat(void) const;
	int toInt(void) const;

/* ************************************************************************** */
/*                                                                            */
/* Comparison Operators:                                                      */
/* - Overloaded operators for comparing two Fixed objects.                    */
/* - Operators include greater than (>), less than (<), greater than or equal */
/*   to (>=), less than or equal to (<=), equal to (==), and not equal to     */
/*   (!=).                                                                    */
/*                                                                            */
/* ************************************************************************** */
	bool operator>(const Fixed& other) const;
	bool operator<(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator==(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;

/* ************************************************************************** */
/*                                                                            */
/* Arithmetic Operators:                                                      */
/* - Overloaded operators for performing arithmetic on Fixed objects.         */
/* - Supported operations are addition (+), subtraction (-), multiplication   */
/*   (*), and division (/).                                                   */
/*                                                                            */
/* ************************************************************************** */
	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;
	Fixed operator*(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;

/* ************************************************************************** */
/*                                                                            */
/*  Prefix vs. Postfix Increment/Decrement Operators in C++                   */
/*                                                                            */
/*  - **Prefix (`++a`, `--a`)**:                                              */
/*    - The operation is performed first, and then the result is returned.    */
/*    - Does not take any parameters.                                         */
/*                                                                            */
/*  - **Postfix (`a++`, `a--`)**:                                             */
/*    - The current value is returned first, and then the operation is        */
/*      performed.                                                            */
/*    - Takes an `int` parameter to distinguish it from the prefix version.   */
/*    - The `int` parameter is not used in the function body; it is a         */
/*      placeholder to differentiate between the two overloads.               */
/*                                                                            */
/* ************************************************************************** */
	Fixed& operator++(void); // prefix increment
	Fixed operator++(int);   // postfix increment
	Fixed& operator--(void); // prefix decrement
	Fixed operator--(int);   // postfix decrement

/* ************************************************************************** */
/*                                                                            */
/* Min and Max Functions:                                                     */
/* - Static member functions to return the smaller or larger of two Fixed     */
/*   objects. Overloaded versions are provided for non-const and const        */
/*   references.                                                              */
/*                                                                            */
/* ************************************************************************** */
	static Fixed& min(Fixed& a, Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);

	static const Fixed& min(const Fixed& a, const Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);

private:
/* ************************************************************************** */
/*                                                                            */
/* Internal Representation:                                                   */
/* - `_fixedPointValue` stores the actual fixed-point number as an integer.   */
/* - `_fractionalBits` is the number of bits used to represent the fractional */
/*   part of the fixed-point number.                                          */
/*                                                                            */
/* ************************************************************************** */
	int _fixedPointValue;
	static const int _fractionalBits = 8; // Number of bits used for the fractional part (8 for Q8.8)
};

/* ************************************************************************** */
/*                                                                            */
/* Output Stream Operator Overload:                                            */
/* - Overloads the `<<` operator to allow Fixed objects to be sent to output   */
/*   streams like `std::cout`. Converts the Fixed object to a float for        */
/*   display.                                                                  */
/*                                                                            */
/* ************************************************************************** */
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
