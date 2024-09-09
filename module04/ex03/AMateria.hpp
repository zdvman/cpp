/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:20:20 by dzuiev            #+#    #+#             */
/*   Updated: 2024/09/09 16:46:23 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*   AMateria.hpp                                                             */
/*                                                                            */
/*   This header file defines the AMateria class, which represents the        */
/*   concept of a "Materia" in the program. The class is abstract, meaning    */
/*   it contains pure virtual methods (like clone()) that must be             */
/*   implemented by any derived class (e.g., Ice, Cure). The class includes   */
/*   essential constructors, a destructor, an assignment operator, and        */
/*   functions to handle Materia-specific behavior such as usage (`use()`)    */
/*   and retrieving the type (`getType()`).                                   */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>
#include "ICharacter.hpp"  // Forward declaration of ICharacter

class AMateria {
protected:
	std::string _type;  // Represents the type of the Materia (e.g., "ice", "cure")

public:
	// Constructors, Destructor, and Assignment Operator
	AMateria();                                   // Default constructor
	AMateria(const std::string& type);            // Parameterized constructor
	AMateria(const AMateria& other);              // Copy constructor
	virtual ~AMateria();                          // Destructor
	AMateria& operator=(const AMateria& rhs);     // Assignment operator

	// Member Functions
	const std::string& getType() const;           // Returns the materia type
	virtual AMateria* clone() const = 0;          // Pure virtual function, to be overridden by derived classes
	virtual void use(ICharacter& target);         // Virtual function, to be overridden by derived classes
};

#endif
