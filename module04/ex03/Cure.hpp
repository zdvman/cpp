/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:03:22 by dzuiev            #+#    #+#             */
/*   Updated: 2024/09/09 16:52:04 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*   Cure.hpp                                                                 */
/*                                                                            */
/*   This header file defines the Cure class, which is a concrete class        */
/*   inheriting from the AMateria class. Cure represents a specific type       */
/*   of Materia ("cure") and has behavior such as cloning itself and being     */
/*   used in interactions with characters.                                    */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
public:
	// Constructors, Destructor, and Assignment Operator
	Cure();                                 // Default constructor
	Cure(const Cure& other);                // Copy constructor
	Cure& operator=(const Cure& other);     // Copy assignment operator
	~Cure();                                // Destructor

	// Member Functions
	AMateria* clone() const;                // Returns a new Cure instance
	void use(ICharacter& target);           // Defines behavior when used on a target
};

#endif
