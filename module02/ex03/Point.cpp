/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:53:42 by dzuiev            #+#    #+#             */
/*   Updated: 2024/08/28 19:05:32 by dzuiev           ###   ########.fr       */
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
