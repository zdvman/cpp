/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:07:25 by dzuiev            #+#    #+#             */
/*   Updated: 2024/09/09 16:58:39 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*   MateriaSource.cpp                                                        */
/*                                                                            */
/*   This file implements the MateriaSource class, which manages the storage  */
/*   and creation of Materia objects. The class can store up to 4 Materia     */
/*   objects, learn new Materia, and create copies of learned Materia by type.*/
/*   The class also handles deep copying of Materia objects when creating or  */
/*   assigning instances.                                                     */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

/* ************************************************************************** */
/*   Constructors, Destructor, and Assignment Operator                        */
/*                                                                            */
/*   - MateriaSource() : Initializes the inventory to NULL pointers.          */
/*   - MateriaSource(const MateriaSource&) : Copy constructor that deep       */
/*     copies the Materia inventory from another MateriaSource.               */
/*   - operator=() : Assignment operator that deep copies the Materia         */
/*     inventory from another MateriaSource and manages memory correctly.     */
/*   - ~MateriaSource() : Destructor that cleans up all Materia in the        */
/*     inventory.                                                             */
/*                                                                            */
/* ************************************************************************** */
MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++) {
		_materias[i] = NULL;  // Initialize all Materia slots to NULL
	}
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	for (int i = 0; i < 4; i++) {
		if (other._materias[i]) {
			_materias[i] = other._materias[i]->clone();  // Deep copy the Materia
		} else {
			_materias[i] = NULL;  // Empty slot
		}
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	if (this != &other) {
		for (int i = 0; i < 4; i++) {
			if (_materias[i]) {
				delete _materias[i];  // Delete existing Materia
			}
			if (other._materias[i]) {
				_materias[i] = other._materias[i]->clone();  // Deep copy the Materia
			} else {
				_materias[i] = NULL;  // Empty slot
			}
		}
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (_materias[i]) {
			delete _materias[i];  // Clean up all Materia in the inventory
		}
	}
}

/* ************************************************************************** */
/*   learnMateria()                                                           */
/*                                                                            */
/*   - Stores the given Materia in the first available slot in the inventory. */
/*     If the inventory is full (i.e., all slots are occupied), it does       */
/*     nothing.                                                               */
/*                                                                            */
/* ************************************************************************** */
void MateriaSource::learnMateria(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (!_materias[i]) {  // Find the first empty slot
			_materias[i] = m;  // Store the Materia
			break;
		}
	}
}

/* ************************************************************************** */
/*   createMateria()                                                          */
/*                                                                            */
/*   - Creates and returns a copy of the Materia based on the given type.     */
/*     If no Materia of the given type has been learned, it returns NULL.     */
/*                                                                            */
/* ************************************************************************** */
AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (_materias[i] && _materias[i]->getType() == type) {
			return _materias[i]->clone();  // Return a copy of the Materia
		}
	}
	return NULL;  // No Materia of the given type found
}
