/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 15:50:45 by dzuiev            #+#    #+#             */
/*   Updated: 2024/08/23 17:25:19 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

// ************************************************************************** //
//                                                                            //
// Function: main                                                             //
//                                                                            //
// Description:                                                               //
//     Entry point of the program. Demonstrates the creation and manipulation //
//     of objects of the Fixed class, including the use of constructors,      //
//     copy assignment operator, and member functions.                        //
//                                                                            //
// ************************************************************************** //

int main( void ) {

// ************************************************************************** //
//                                                                            //
// Variable: a                                                                //
//                                                                            //
// Description:                                                               //
//     Creates an object 'a' of the Fixed class using the default constructor.//
//     The default constructor initializes the internal fixed-point value to 0//
//     A message "Default constructor called" will be printed to the console. //
//                                                                            //
// ************************************************************************** //
	Fixed a;

// ************************************************************************** //
//                                                                            //
// Variable: b                                                                //
//                                                                            //
// Description:                                                               //
//     Creates an object 'b' of the Fixed class by copying the object 'a'.    //
//     The copy constructor is invoked here, which copies the internal        //
//     fixed-point value from 'a' to 'b'.                                     //
//     A message "Copy constructor called" will be printed to the console.    //
//                                                                            //
// ************************************************************************** //
	Fixed b( a );

// ************************************************************************** //
//                                                                            //
// Variable: c                                                                //
//                                                                            //
// Description:                                                               //
//     Creates an object 'c' of the Fixed class using the default constructor.//
//     Similar to 'a', this also initializes the internal fixed-point value   //
//     to 0.                                                                  //
//     A message "Default constructor called" will be printed to the console. //
//                                                                            //
// ************************************************************************** //
	Fixed c;

// ************************************************************************** //
//                                                                            //
// Operation: c = b                                                           //
//                                                                            //
// Description:                                                               //
//     Assigns the value of the object 'b' to the object 'c' using the copy   //
//     assignment operator. This operation copies the internal fixed-point    //
//     value from 'b' to 'c'.                                                 //
//     A message "Copy assignment operator called" will be printed to the     //
//     console, indicating that the assignment has occurred.                  //
//                                                                            //
// ************************************************************************** //
	c = b;

// ************************************************************************** //
//                                                                            //
// Operation: std::cout << a.getRawBits() << std::endl;                       //
//                                                                            //
// Description:                                                               //
//     Calls the 'getRawBits()' member function on the object 'a' to retrieve //
//     the internal fixed-point value. This value is then printed to the      //
//     console followed by a newline.                                         //
//     A message "getRawBits member function called" will be printed to the   //
//     console, followed by the value 0 (since 'a' was initialized with 0).   //
//                                                                            //
// ************************************************************************** //
	std::cout << a.getRawBits() << std::endl;

// ************************************************************************** //
//                                                                            //
// Operation: std::cout << b.getRawBits() << std::endl;                       //
//                                                                            //
// Description:                                                               //
//     Calls the 'getRawBits()' member function on the object 'b' to retrieve //
//     the internal fixed-point value. This value is then printed to the      //
//     console followed by a newline.                                         //
//     A message "getRawBits member function called" will be printed to the   //
//     console, followed by the value 0 (since 'b' is a copy of 'a', which    //
//     was initialized with 0).                                               //
//                                                                            //
// ************************************************************************** //
	std::cout << b.getRawBits() << std::endl;

// ************************************************************************** //
//                                                                            //
// Operation: std::cout << c.getRawBits() << std::endl;                       //
//                                                                            //
// Description:                                                               //
//     Calls the 'getRawBits()' member function on the object 'c' to retrieve //
//     the internal fixed-point value. This value is then printed to the      //
//     console followed by a newline.                                         //
//     A message "getRawBits member function called" will be printed to the   //
//     console, followed by the value 0 (since 'c' is a copy of 'b', which    //
//     is a copy of 'a', initialized with 0).                                 //
//                                                                            //
// ************************************************************************** //
	std::cout << c.getRawBits() << std::endl;

	return 0;
}
