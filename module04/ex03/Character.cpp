/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:05:57 by dzuiev            #+#    #+#             */
/*   Updated: 2024/09/09 17:08:46 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*   Character.cpp                                                            */
/*                                                                            */
/*   This file implements the Character class, which manages the character's  */
/*   inventory of Materias. The class handles equipping, unequipping, and     */
/*   using Materias, along with ensuring deep copying when characters are     */
/*   copied or assigned. Memory management is handled to avoid leaks.         */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/* ************************************************************************** */
/*   Constructors, Destructor, and Assignment Operator                        */
/*                                                                            */
/*   - Character() : Initializes the character with a name and an empty       */
/*     inventory of Materias (NULL in all slots).                             */
/*   - Character(const Character&) : Copy constructor that deep copies        */
/*     the inventory from another character.                                  */
/*   - operator=() : Assignment operator that deep copies the inventory       */
/*     from another character and handles memory management properly.         */
/*   - ~Character() : Destructor that deletes all Materia in the inventory.   */
/*                                                                            */
/* ************************************************************************** */
Character::Character(std::string const & name) : _name(name) {
	for (int i = 0; i < 4; i++) {
		_inventory[i] = NULL; // Initialize the inventory to empty slots
	}
}

Character::Character(const Character& other) : _name(other._name) {
	for (int i = 0; i < 4; i++) {
		if (other._inventory[i]) {
			_inventory[i] = other._inventory[i]->clone(); // Deep copy the Materia
		} else {
			_inventory[i] = NULL; // Empty slot
		}
	}
}

Character& Character::operator=(const Character& other) {
	if (this != &other) {
		_name = other._name; // Copy the name
		for (int i = 0; i < 4; i++) {
			if (_inventory[i]) {
				delete _inventory[i]; // Clean up existing Materia
			}
			if (other._inventory[i]) {
				_inventory[i] = other._inventory[i]->clone(); // Deep copy the Materia
			} else {
				_inventory[i] = NULL; // Empty slot
			}
		}
	}
	return *this;
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		if (_inventory[i]) {
			delete _inventory[i]; // Clean up Materia from the inventory
		}
	}
}

/* ************************************************************************** */
/*   getName()                                                                */
/*                                                                            */
/*   - Returns the name of the character.                                     */
/*                                                                            */
/* ************************************************************************** */
std::string const & Character::getName() const {
	return _name;
}

/* ************************************************************************** */
/*   equip()                                                                  */
/*                                                                            */
/*   - Equips a Materia in the first available slot of the character's        */
/*     inventory. If the inventory is full, the Materia is not equipped.      */
/*                                                                            */
/* ************************************************************************** */
void Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (!_inventory[i]) { // Find the first empty slot
			_inventory[i] = m; // Equip the Materia
			break;
		}
	}
}

/* ************************************************************************** */
/*   unequip()                                                                */
/*                                                                            */
/*   - Unequips a Materia from the inventory slot without deleting it. The    */
/*     slot is simply marked as empty (set to NULL).                          */
/*                                                                            */
/* ************************************************************************** */
void Character::unequip(int idx) {
	if (idx >= 0 && idx < 4) {
		_inventory[idx] = NULL;  // Don't delete, just unequip the Materia
	}
}

/* ************************************************************************** */
/*   use()                                                                    */
/*                                                                            */
/*   - Uses the Materia at the specified inventory slot on the target         */
/*     character. If no Materia is present in the slot, nothing happens.      */
/*                                                                            */
/* ************************************************************************** */
void Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < 4 && _inventory[idx]) {
		_inventory[idx]->use(target); // Use the Materia on the target
	}
}
