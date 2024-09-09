/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:05:34 by dzuiev            #+#    #+#             */
/*   Updated: 2024/09/09 17:08:15 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*   Character.hpp                                                            */
/*                                                                            */
/*   This file defines the Character class, which implements the ICharacter   */
/*   interface. A Character has an inventory of up to 4 Materias and can      */
/*   equip, unequip, and use them. The class includes proper memory           */
/*   management to ensure deep copying of the Materia inventory and           */
/*   preventing memory leaks.                                                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter {
private:
	std::string _name;              // Character's name
	AMateria* _inventory[4];        // Array to store up to 4 Materias

public:
	// Constructors, Destructor, and Assignment Operator
	Character(std::string const & name);              // Constructor with a name parameter
	Character(const Character& other);                // Copy constructor
	Character& operator=(const Character& other);     // Copy assignment operator
	~Character();                                     // Destructor

	// Member Functions
	std::string const & getName() const;              // Returns the character's name
	void equip(AMateria* m);                          // Equip a Materia in the inventory
	void unequip(int idx);                            // Unequip Materia from the inventory
	void use(int idx, ICharacter& target);            // Use Materia on the target character
};

#endif
