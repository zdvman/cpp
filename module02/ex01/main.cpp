/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:28:18 by dzuiev            #+#    #+#             */
/*   Updated: 2024/08/29 10:51:40 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
/* ************************************************************************** */
/*                                                                            */
/*  Creating Fixed objects:                                                   */
/*  - `a` is initialized using the default constructor.                       */
/*  - `b` is initialized with an integer value of 10.                         */
/*  - `c` is initialized with a floating-point value of 42.42f.               */
/*  - `d` is a copy of `b`, initialized using the copy constructor.           */
/*  - `a` is then assigned a new value by creating a temporary Fixed object   */
/*    initialized with 1234.4321f.                                            */
/*                                                                            */
/* ************************************************************************** */
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	a = Fixed( 1234.4321f );

/* ************************************************************************** */
/*                                                                            */
/*  Output the values of the Fixed objects:                                   */
/*  - The values of `a`, `b`, `c`, and `d` are output as floating-point       */
/*    numbers using the overloaded `<<` operator.                             */
/*                                                                            */
/* ************************************************************************** */
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

/* ************************************************************************** */
/*                                                                            */
/*  Output the integer representation of the Fixed objects:                   */
/*  - The values of `a`, `b`, `c`, and `d` are converted to integers using    */
/*    the `toInt()` method and output as integer values.                      */
/*                                                                            */
/* ************************************************************************** */
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

/* ************************************************************************** */
/*                                                                            */
/*  Return 0 to indicate successful execution.                                */
/*                                                                            */
/* ************************************************************************** */
	return 0;
}
