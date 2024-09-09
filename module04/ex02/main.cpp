/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:09:15 by dzuiev            #+#    #+#             */
/*   Updated: 2024/09/09 13:55:48 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
	// AAnimal x = AAnimal();
	// AAnimal* y = new AAnimal();
	// x.makeSound();
	// *y = x;
	// delete y;

	Cat* originalCat = new Cat();
	Cat* copiedCat = new Cat(*originalCat);  // Deep copy

	// Test that they have different brains (deep copy):
	std::cout << "Original Cat Brain Address: " << originalCat->getBrain() << std::endl;
	std::cout << "Copied Cat Brain Address: " << copiedCat->getBrain() << std::endl;

	delete originalCat;
	delete copiedCat;

	const Cat* a = new Cat();
	const Cat* b = new Cat(*a);  // Deep copy instead of shallow copy
	Cat* c = new Cat();

	*c = *b;


	// Testing deep copy
	std::cout << "Original Cat Brain Address: " << a->getBrain() << std::endl;
	std::cout << "Copied Cat Brain Address: " << b->getBrain() << std::endl;
	std::cout << "Assigned Cat Brain Address: " << c->getBrain() << std::endl;

	const AAnimal* animals[4];

	for (int i = 0; i < 4; i++) {
		if (i < 2) {
			animals[i] = new Dog();
		} else {
			animals[i] = new Cat();
		}
	}

	for (int i = 0; i < 4; i++) {
		animals[i]->getType(), animals[i]->makeSound();
		delete animals[i];
	}

	delete a;
	delete b;
	delete c;
	
	return 0;
}
