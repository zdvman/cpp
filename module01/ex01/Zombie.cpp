/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:51:03 by dzuiev            #+#    #+#             */
/*   Updated: 2024/08/13 13:26:44 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// ************************************************************************** //
// Default constructor
// ************************************************************************** //
Zombie::Zombie() : _name("Unnamed Zombie") {
	// Initialize the Zombie with a default name if no name is provided
}

// ************************************************************************** //
// Constructor to initialize the Zombie with a name
// ************************************************************************** //
Zombie::Zombie(std::string name) : _name(name) {}

// ************************************************************************** //
// Destructor to handle Zombie destruction                                    //
// ************************************************************************** //
Zombie::~Zombie() {
	// Print a message indicating that the Zombie has been destroyed
	std::cout << "Zombie " << _name << " has been destroyed." << std::endl;
}

// ************************************************************************** //
// Announce method for the Zombie to print its name and a message             //
// ************************************************************************** //
void	Zombie::announce(void) const {
	// Print the Zombie's name and a message
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
