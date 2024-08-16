/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:52:02 by dzuiev            #+#    #+#             */
/*   Updated: 2024/08/16 14:53:44 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main (void) {
	std::string name;

	std::cout << "Creating zombie on the stack." << std::endl;
	std::cout << "Input Zombie's name: " << std::flush;
	std::cin >> name;

	// ********************************************************************** //
	// Create a Zombie object on the stack                                    //
	// Declare a Zombie object on the stack                                   //
	// using the name provided by the user                                    //
	// ********************************************************************** //
	Zombie zombieOnTheStack(name); 

	std::cout << "Creating zombie on the heap." << std::endl;
	std::cout << "Input Zombie's name: " << std::flush;
	std::cin >> name;

	// ********************************************************************** //
	// Create a Zombie object on the heap                                     //
	// Create a Zombie object on the heap using the name provided by the user //
	// Call the announce method of the Zombie object                          //
	// Delete the Zombie object from the heap to free memory                  //
	// ********************************************************************** //
	Zombie* zombieOnTheHeap = newZombie(name); 
	zombieOnTheHeap->announce(); 
	delete zombieOnTheHeap; 

	// ********************************************************************** //
	// Generate and print a random name                                       //
	// Call generateRandomName to get a random name                           //
	// ********************************************************************** //
	name = generateRandomName(); 
	std::cout << "Calling randomChump()." << std::endl;

	// ********************************************************************** //
	// Call randomChump() to create a temporary Zombie                        //
	// and call its announce method                                           //
	// ********************************************************************** //
	randomChump(name);

	return 0;
}
