/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:52:39 by dzuiev            #+#    #+#             */
/*   Updated: 2024/07/25 16:39:10 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

// ************************************************************************** //
// Zombie class definition                                                    //
// ************************************************************************** //
class Zombie {
private:
	std::string _name; // Name of the Zombie

public:
	// Constructor to initialize the Zombie with a name
	Zombie(std::string name);
	// Destructor to handle Zombie destruction
	~Zombie();
	// Method for the Zombie to announce itself
	void announce(void);
};

// Function to create a new Zombie on the heap and return a pointer to it
Zombie* newZombie(std::string name);
// Function to create a temporary Zombie with the given name and call its announce method
void randomChump(std::string name);
// Function to generate a random name for a Zombie
std::string generateRandomName(void);

#endif
