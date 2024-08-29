/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 15:52:05 by dzuiev            #+#    #+#             */
/*   Updated: 2024/08/29 10:57:46 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
	public:

// ************************************************************************** //
//                                                                            //
// Constructor: Fixed                                                         //
// Overloaded Constructor: Fixed(int)                                         //
// Overloaded Constructor: Fixed(float)                                       //
//                                                                            //
// Description:                                                               //
//     Initializes a new instance of the Fixed class.                         //
//     - Default constructor initializes with a value of 0.                   //
//     - Integer constructor converts an integer to fixed-point format.       //
//     - Float constructor converts a float to fixed-point format.            //
//                                                                            //
// ************************************************************************** //
		Fixed ();
		Fixed (const int value);
		Fixed (const float value);

// ************************************************************************** //
//                                                                            //
// Copy Constructor: Fixed                                                    //
// Copy Assignment Operator: operator=                                        //
//                                                                            //
// Description:                                                               //
//     - Copy constructor creates a copy of an existing Fixed instance.       //
//     - Copy assignment operator assigns the value from another Fixed        //
//       instance to this one, ensuring no self-assignment.                   //
//                                                                            //
// ************************************************************************** //
		Fixed (const Fixed& other);
		Fixed& operator=(const Fixed& other);

// ************************************************************************** //
//                                                                            //
// Destructor: ~Fixed                                                         //
//                                                                            //
// Description:                                                               //
//     Destroys the instance of the Fixed class, performing any necessary     //
//     cleanup.                                                               //
//                                                                            //
// ************************************************************************** //
		~Fixed ();

// ************************************************************************** //
//                                                                            //
// Function: getRawBits                                                       //
// Function: setRawBits                                                       //
//                                                                            //
// Description:                                                               //
//     - `getRawBits` returns the raw integer value of the fixed-point number.//
//     - `setRawBits` sets the raw integer value of the fixed-point number.   //
//                                                                            //
// ************************************************************************** //
		int getRawBits(void) const;
		void setRawBits(int const raw);

	private:

		int _fixedPointValue; // Stores the fixed-point number value
		static const int _fractionalBits = 8; // Number of bits used for the fractional part (8 for Q8.8)

};

#endif
