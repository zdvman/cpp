/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:18:43 by dzuiev            #+#    #+#             */
/*   Updated: 2024/08/13 18:26:44 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include "Weapon.hpp"


// ************************************************************************** //
// HumanA class definition                                                    //
// ************************************************************************** //
class HumanA {
private:
	std::string	_name;
	Weapon&		_weapon; // Reference to Weapon

public:
	// Constructor
	HumanA(std::string name, Weapon& weapon);
	// Destructor
	~HumanA();

	// Attack method
	void attack() const;
};


// HumanA* HumanAHorde( int N, std::string name );

#endif
