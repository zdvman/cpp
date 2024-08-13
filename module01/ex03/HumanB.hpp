/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:17:26 by dzuiev            #+#    #+#             */
/*   Updated: 2024/08/13 18:37:08 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>

// ************************************************************************** //
// HumanB class definition                                                    //
// ************************************************************************** //


class HumanB {
private:
	std::string	_name;
	Weapon*		_weapon; // Pointer to Weapon

public:
	// Constructor
	HumanB(std::string name);
	// Destructor
	~HumanB();

	// Setter for weapon
	void setWeapon(Weapon& weapon);

	// Attack method
	void attack() const;
};

#endif
