/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:20:20 by dzuiev            #+#    #+#             */
/*   Updated: 2024/09/09 14:49:57 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>
#include "ICharacter.hpp"  // Forward declare ICharacter

class AMateria {
	protected:
		std::string _type;

	public:
		// Default constructor (optional if needed)
		AMateria();
		AMateria(const std::string& type);
		AMateria(const AMateria& other);
		virtual ~AMateria();

		AMateria& operator=(const AMateria& rhs);
		const std::string& getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
