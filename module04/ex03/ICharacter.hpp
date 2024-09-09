/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:41:31 by dzuiev            #+#    #+#             */
/*   Updated: 2024/09/09 17:07:51 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*   ICharacter.hpp                                                           */
/*                                                                            */
/*   This file defines the ICharacter interface. It serves as the base class  */
/*   for character types in the game. The interface declares essential        */
/*   methods for managing a character's Materia inventory, equipping,         */
/*   unequipping, and using Materia.                                          */
/*   The pure virtual functions must be implemented by any concrete class     */
/*   that inherits from this interface.                                       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*   ICharacter.hpp                                                           */
/*                                                                            */
/*   This file defines the ICharacter interface. It outlines the behavior     */
/*   for characters in the game who can equip, unequip, and use Materias.     */
/*   Any class implementing this interface must provide definitions for all   */
/*   the declared functions.                                                  */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <string>

class AMateria; // Forward declaration

class ICharacter {
public:
	virtual ~ICharacter() {}                                      // Virtual destructor to ensure proper cleanup
	virtual std::string const & getName() const = 0;              // Returns the character's name
	virtual void equip(AMateria* m) = 0;                          // Equip a Materia in the character's inventory
	virtual void unequip(int idx) = 0;                            // Unequip Materia from the inventory slot
	virtual void use(int idx, ICharacter& target) = 0;            // Use Materia on a target character
};

#endif
