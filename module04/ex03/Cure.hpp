/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:03:22 by dzuiev            #+#    #+#             */
/*   Updated: 2024/09/09 15:03:31 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
public:
	Cure();
	Cure(const Cure& other);
	Cure& operator=(const Cure& other);
	~Cure();

	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif
