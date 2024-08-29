/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:53:14 by dzuiev            #+#    #+#             */
/*   Updated: 2024/08/29 16:03:25 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {

	private:
/* ************************************************************************** */
/*                                                                            */
/* The x and y coordinates of the point, represented as Fixed-point numbers.  */
/* Since these are marked as `const`, they can only be initialized once       */
/* during the construction of the object and cannot be changed afterwards.    */
/*                                                                            */
/* ************************************************************************** */
		const Fixed _x;
		const Fixed _y;

/* ************************************************************************** */
/*                                                                            */
/* The copy assignment operator is declared private and not defined.          */
/* This prevents the assignment of one Point object to another, which would   */
/* otherwise require changing the const member variables _x and _y.           */
/* In C++98, this is a common way to disable the assignment operator.         */
/* Any attempt to use it will result in a compilation error due to it         */
/* being private.                                                             */
/*                                                                            */
/* ************************************************************************** */
		// Point& operator=(const Point& rhs);

	public:
/* ************************************************************************** */
/*                                                                            */
/* Default constructor that initializes the point to (0, 0).                  */
/*                                                                            */
/* ************************************************************************** */
		Point();

/* ************************************************************************** */
/*                                                                            */
/* Constructor that initializes the point with given x and y coordinates.     */
/* Takes two floating-point numbers as parameters.                            */
/*                                                                            */
/* ************************************************************************** */
		Point(const float x, const float y);

/* ************************************************************************** */
/*                                                                            */
/* Copy constructor that initializes the point with the same values as        */
/* another Point object.                                                      */
/*                                                                            */
/* ************************************************************************** */
		Point(const Point& other);

/* ************************************************************************** */
/*                                                                            */
/* Destructor for the Point class.                                            */
/* Cleans up any resources used by the Point object.                          */
/*                                                                            */
/* ************************************************************************** */
		~Point();

		Point& operator=(const Point& rhs);


/* ************************************************************************** */
/*                                                                            */
/* Getter method to access the x coordinate of the Point.                     */
/*                                                                            */
/* ************************************************************************** */
		Fixed getX() const;

/* ************************************************************************** */
/*                                                                            */
/* Getter method to access the y coordinate of the Point.                     */
/*                                                                            */
/* ************************************************************************** */
		Fixed getY() const;
};

/* ************************************************************************** */
/*                                                                            */
/* Function to determine if a point lies inside a triangle formed by three    */
/* other points.                                                              */
/*                                                                            */
/* ************************************************************************** */
bool	bsp( Point const a, Point const b, Point const c, Point const point);

#endif
