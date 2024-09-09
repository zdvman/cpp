/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:07:56 by dzuiev            #+#    #+#             */
/*   Updated: 2024/09/09 17:00:01 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*   main.cpp                                                                 */
/*                                                                            */
/*   This is the main entry point of the program. It demonstrates the usage   */
/*   of the classes that implement the Materia system (MateriaSource,         */
/*   Character, Ice, and Cure). The main function simulates a scenario where  */
/*   a character "me" learns Ice and Cure Materias, equips them, and uses     */
/*   them on another character "bob".                                         */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main() {
	// Create a MateriaSource object to store learned Materia types.
	IMateriaSource* src = new MateriaSource();

	// Learn the "ice" and "cure" Materia. They are stored in the MateriaSource.
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	// Create a new character named "me".
	ICharacter* me = new Character("me");
	
	// Create temporary AMateria pointer to hold Materia when creating it from MateriaSource.
	AMateria* tmp;

	// Create an "ice" Materia from the MateriaSource and equip it to "me".
	tmp = src->createMateria("ice");
	me->equip(tmp);

	// Create a "cure" Materia from the MateriaSource and equip it to "me".
	tmp = src->createMateria("cure");
	me->equip(tmp);

	// Create a second character named "bob".
	ICharacter* bob = new Character("bob");

	// Use the Materia in "me"'s first inventory slot (ice) on "bob".
	me->use(0, *bob);  // Output: "* shoots an ice bolt at bob *"

	// Use the Materia in "me"'s second inventory slot (cure) on "bob".
	me->use(1, *bob);  // Output: "* heals bob's wounds *"

	// Clean up memory by deleting the dynamically allocated objects.
	delete bob;
	delete me;
	delete src;

	return 0;
}
