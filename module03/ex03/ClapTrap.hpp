/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:39:20 by dzuiev            #+#    #+#             */
/*   Updated: 2024/09/03 15:48:45 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <iostream> // For std::string and std::cout

/* ************************************************************************** */
/*                                                                            */
/* Class: ClapTrap                                                            */
/*                                                                            */
/* Description:                                                               */
/*     Represents a basic robot with hit points, energy points, and attack    */
/*     damage. Provides functionality to attack, take damage, and repair.     */
/*     This class serves as a base class for more specialized robots.         */
/*                                                                            */
/* Inheritance:                                                               */
/*     The `ScavTrap` class inherits from `ClapTrap` to extend its behavior.  */
/*                                                                            */
/* Polymorphism:                                                              */
/*     The `getClassName` method is virtual, allowing derived classes to      */
/*     override it and provide their own class name.                          */
/*                                                                            */
/* ************************************************************************** */

class ClapTrap {
	protected:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;

	public:
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& other);

		// Virtual Destructor to ensure proper destruction chaining
		virtual ~ClapTrap();

		ClapTrap& operator=(const ClapTrap& rhs);

		// Virtual method for polymorphic behavior
		virtual std::string getClassName() const;

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif
