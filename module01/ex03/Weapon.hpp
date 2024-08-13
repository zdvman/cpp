/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:13:23 by dzuiev            #+#    #+#             */
/*   Updated: 2024/08/13 18:22:37 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

// ************************************************************************** //
// Weapon class definition                                                    //
// ************************************************************************** //
class Weapon {
private:
	std::string _type; // Type of the Weapon

public:
	Weapon(); // Default constructor
	Weapon(std::string type); // Constructor with name initialization
	~Weapon(); // Destructor

	// Getter for weapon type
	const std::string& getType() const;

	// Setter for weapon type
	void setType(const std::string& type);
};

#endif
