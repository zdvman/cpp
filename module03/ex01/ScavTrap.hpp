/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 12:51:18 by dzuiev            #+#    #+#             */
/*   Updated: 2024/09/03 15:49:42 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include "ClapTrap.hpp"

/* ************************************************************************** */
/*                                                                            */
/* Class: ScavTrap                                                            */
/*                                                                            */
/* Description:                                                               */
/*     A derived class from `ClapTrap` with enhanced attributes (more hit     */
/*     points, energy points, and attack damage). Adds a unique method for    */
/*     gatekeeping.                                                           */
/*                                                                            */
/* Inheritance:                                                               */
/*     Inherits from `ClapTrap` and overrides some of its behavior.           */
/*                                                                            */
/* ************************************************************************** */

class ScavTrap : public ClapTrap {
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
