/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 15:52:05 by dzuiev            #+#    #+#             */
/*   Updated: 2024/08/23 17:26:05 by dzuiev           ###   ########.fr       */
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
//                                                                            //
// Description:                                                               //
//     Initializes a new instance of the Fixed class with a value of 0.       //
//                                                                            //
// ************************************************************************** //
		Fixed ();

// ************************************************************************** //
//                                                                            //
// Copy Constructor: Fixed                                                    //
//                                                                            //
// Description:                                                               //
//     Creates a copy of an existing Fixed instance.                          //
//                                                                            //
// ************************************************************************** //
		Fixed (const Fixed& other);

// ************************************************************************** //
//                                                                            //
// Copy Assignment Operator: operator=                                        //
//                                                                            //
// Description:                                                               //
//     Assigns the value from another Fixed instance to this one.             //
//     Checks for self-assignment and copies the internal fixed-point value.  //
//                                                                            //
// ************************************************************************** //
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
//                                                                            //
// Description:                                                               //
//     Returns the raw integer value of the fixed-point number.               //
//                                                                            //
// ************************************************************************** //
		int getRawBits(void) const;

// ************************************************************************** //
//                                                                            //
// Function: setRawBits                                                       //
//                                                                            //
// Description:                                                               //
//     Sets the raw integer value of the fixed-point number.                  //
//                                                                            //
// ************************************************************************** //
		void setRawBits(int const raw);

	private:

		int _fixedPointValue; // Stores the fixed-point number value
		static const int _fractionalBits = 8; // Number of bits used for the fractional part (8 for Q8.8)

};

#endif
