/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:40:10 by dzuiev            #+#    #+#             */
/*   Updated: 2024/09/03 16:48:06 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

/* ************************************************************************** */
/*                                                                            */
/* ScavTrap Class:                                                            */
/*                                                                            */
/* ScavTrap is derived from ClapTrap using virtual inheritance.               */
/*                                                                            */
/* Virtual Inheritance:                                                       */
/* - Virtual inheritance ensures that ScavTrap and FragTrap, when used        */
/*   together in a multiple inheritance scenario (like in DiamondTrap),       */
/*   share a single instance of ClapTrap as their base class.                 */
/* - This prevents the ambiguity that would otherwise arise if ScavTrap       */
/*   and FragTrap each had their own separate instance of ClapTrap.           */
/*                                                                            */
/* Usage in ScavTrap:                                                         */
/* - ScavTrap inherits from ClapTrap and sets specific attributes related     */
/*   to energy points.                                                        */
/*                                                                            */
/* ************************************************************************** */
class ScavTrap : virtual public ClapTrap {
	public:
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& other);
		~ScavTrap();

		// Override to return "ScavTrap"
		std::string getClassName() const;
		ScavTrap& operator=(const ScavTrap& rhs);
		void guardGate();
};

#endif
