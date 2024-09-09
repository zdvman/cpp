/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:00:27 by dzuiev            #+#    #+#             */
/*   Updated: 2024/09/09 16:51:05 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*   Ice.hpp                                                                  */
/*                                                                            */
/*   This header file defines the Ice class, which is a concrete class        */
/*   inheriting from the AMateria class. Ice represents a specific type       */
/*   of Materia ("ice") and has behavior such as cloning itself and being     */
/*   used in interactions with characters.                                    */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
public:
	// Constructors, Destructor, and Assignment Operator
	Ice();                                  // Default constructor
	Ice(const Ice& other);                  // Copy constructor
	Ice& operator=(const Ice& other);       // Copy assignment operator
	~Ice();                                 // Destructor

	// Member Functions
	AMateria* clone() const;                // Returns a new Ice instance
	void use(ICharacter& target);           // Defines behavior when used on a target
};

#endif
