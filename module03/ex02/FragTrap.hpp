/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:45:01 by dzuiev            #+#    #+#             */
/*   Updated: 2024/09/03 11:58:11 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP

#include "ScavTrap.hpp"
#include <iostream>

class FragTrap : public  ClapTrap {
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
