/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:50:30 by dzuiev            #+#    #+#             */
/*   Updated: 2024/08/22 12:30:27 by dzuiev           ###   ########.fr       */
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
	Zombie(); // Default constructor
	Zombie(std::string name); // Constructor with name initialization
	~Zombie(); // Destructor

	void announce(void) const; // Method for the Zombie to announce itself

	void setName(std::string name);// Setter for _name
};

Zombie* zombieHorde( int N, std::string name );

#endif
