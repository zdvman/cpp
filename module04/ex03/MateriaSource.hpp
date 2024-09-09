/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:06:38 by dzuiev            #+#    #+#             */
/*   Updated: 2024/09/09 16:57:44 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*   MateriaSource.hpp                                                        */
/*                                                                            */
/*   This file defines the MateriaSource class, which implements the          */
/*   IMateriaSource interface. This class can store up to 4 Materia objects,  */
/*   learn new Materia, and create copies of Materia based on their type.     */
/*   The MateriaSource class uses deep copying to manage its Materia objects. */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
private:
	AMateria* _materias[4];               // Array to store up to 4 Materias

public:
	// Constructors, Destructor, and Assignment Operator
	MateriaSource();                                    // Default constructor
	MateriaSource(const MateriaSource& other);          // Copy constructor
	MateriaSource& operator=(const MateriaSource& other); // Copy assignment operator
	~MateriaSource();                                   // Destructor

	// Member Functions
	void learnMateria(AMateria* m);                     // Store a Materia in the array
	AMateria* createMateria(std::string const & type);  // Create a Materia based on its type
};

#endif
