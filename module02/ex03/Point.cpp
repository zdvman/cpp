/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:53:42 by dzuiev            #+#    #+#             */
/*   Updated: 2024/08/29 16:20:04 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/* ************************************************************************** */
/*                                                                            */
/* Default constructor that initializes the point to (0, 0).                  */
/* This constructor uses an initializer list to set the x and y coordinates   */
/* to 0. The `Fixed` class is used to represent these coordinates.            */
/*                                                                            */
/* ************************************************************************** */
Point::Point() : _x(0), _y(0) {}

/* ************************************************************************** */
/*                                                                            */
/* Constructor that initializes the point with given x and y coordinates.     */
/* Takes two floating-point numbers as parameters and converts them to        */
/* `Fixed` objects using the `Fixed` constructor.                             */
/*                                                                            */
/* ************************************************************************** */
Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y)) {}

/* ************************************************************************** */
/*                                                                            */
/* Copy constructor that initializes the point with the same values as        */
/* another `Point` object. The x and y coordinates of the new point are       */
/* initialized using the values from the `other` Point object.                */
/*                                                                            */
/* ************************************************************************** */
Point::Point(const Point& other) : _x(other._x), _y(other._y) {}

/* ************************************************************************** */
/*                                                                            */
/* Copy Assignment Operator: operator=                                        */
/*                                                                            */
/* Description:                                                               */
/*     This operator assigns the values from another `Point` instance to      */
/*     this one. Since the `_x` and `_y` members are declared as `const`,     */
/*     they cannot be modified directly after being initialized. However,     */
/*     the `const_cast` is used here to cast away the `const` qualifier,      */
/*     allowing these members to be assigned new values.                      */
/*                                                                            */
/*     This implementation is generally incorrect because it violates the     */
/*     immutability of `const` members. The `const` keyword is intended to    */
/*     guarantee that the value of a member cannot change after it is         */
/*     initialized, ensuring that objects remain in a consistent state.       */
/*     By using `const_cast`, this guarantee is broken, which can lead to     */
/*     unexpected behavior and bugs.                                          */
/*                                                                            */
/*     In typical C++ practice, you would avoid using `const_cast` in this    */
/*     way. Instead, you would either redesign the class to avoid `const`     */
/*     members where assignment is needed or delete the assignment operator.  */
/*     However, to satisfy the requirements of the subject in a C++98         */
/*     environment, this method is used.                                      */
/*                                                                            */
/*     Despite its correctness issues, this implementation is provided to     */
/*     comply with the exercise's demands.                                    */
/*                                                                            */
/* Parameters:                                                                */
/*     - rhs: The `Point` object to be copied from.                           */
/*                                                                            */
/* Return:                                                                    */
/*     Returns a reference to the current object after assignment.            */
/*                                                                            */
/* ************************************************************************** */
Point& Point::operator=(const Point& rhs) {
	// Check for self-assignment
	if (this != &rhs) {
		// Use const_cast to modify the const members
		const_cast<Fixed&>(_x) = rhs._x;
		const_cast<Fixed&>(_y) = rhs._y;
	}
	return *this;
}

/* ************************************************************************** */
/*                                                                            */
/* Destructor for the Point class.                                            */
/* Since the class does not manage dynamic memory, the destructor does        */
/* not need to perform any special actions. It is defined for completeness.   */
/*                                                                            */
/* ************************************************************************** */
Point::~Point() {}

/* ************************************************************************** */
/*                                                                            */
/* Getter method to access the x coordinate of the Point.                     */
/* Returns a `Fixed` object representing the x coordinate. The method is      */
/* marked as `const` because it does not modify any member variables.         */
/*                                                                            */
/* ************************************************************************** */
Fixed Point::getX() const {
	return this->_x;
}

/* ************************************************************************** */
/*                                                                            */
/* Getter method to access the y coordinate of the Point.                     */
/* Returns a `Fixed` object representing the y coordinate. The method is      */
/* marked as `const` because it does not modify any member variables.         */
/*                                                                            */
/* ************************************************************************** */
Fixed Point::getY() const {
	return this->_y;
}
