/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:45:01 by dzuiev            #+#    #+#             */
/*   Updated: 2024/09/07 13:25:25 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP

#include "ScavTrap.hpp"
#include <iostream>

/* ************************************************************************** */
/*                                                                            */
/* FragTrap Class:                                                            */
/*                                                                            */
/* FragTrap is derived from ClapTrap using virtual inheritance.               */
/*                                                                            */
/* Virtual Inheritance:                                                       */
/* - Virtual inheritance ensures that FragTrap and ScavTrap, when used        */
/*   together in a multiple inheritance scenario (like in DiamondTrap),       */
/*   share a single instance of ClapTrap as their base class.                 */
/* - This prevents the ambiguity that would otherwise arise if FragTrap       */
/*   and ScavTrap each had their own separate instance of ClapTrap.           */
/*                                                                            */
/* Usage in FragTrap:                                                         */
/* - FragTrap inherits from ClapTrap and sets specific attributes related     */
/*   to hit points and attack damage.                                         */
/*                                                                            */
/* ************************************************************************** */
class FragTrap : virtual public  ClapTrap {
	public:
		FragTrap(std::string name);
		FragTrap(const FragTrap& other);
		~FragTrap();

		// Override to return "FragTrap"
		std::string getClassName() const;
		FragTrap& operator=(const FragTrap& rhs);
		void highFivesGuys(void);
};

#endif
