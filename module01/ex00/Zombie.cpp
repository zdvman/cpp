/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:52:27 by dzuiev            #+#    #+#             */
/*   Updated: 2024/07/25 16:45:35 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// ************************************************************************** //
// Constructor to initialize the Zombie with a name                           //
// ************************************************************************** //
Zombie::Zombie(std::string name) {
	// Initialize the _name member variable with the provided name
	this->_name = name;
}

// ************************************************************************** //
// Destructor to handle Zombie destruction                                    //
// ************************************************************************** //
Zombie::~Zombie() {
	// Print a message indicating that the Zombie has been destroyed
	std::cout << "Zombie " << this->_name << " has been destroyed." << std::endl;
}

// ************************************************************************** //
// Announce method for the Zombie to print its name and a message             //
// ************************************************************************** //
void Zombie::announce(void) {
	// Print the Zombie's name and a message
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
