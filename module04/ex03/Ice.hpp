/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:00:27 by dzuiev            #+#    #+#             */
/*   Updated: 2024/09/09 15:01:04 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
public:
	Ice();
	Ice(const Ice& other);
	Ice& operator=(const Ice& other);
	~Ice();

	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif
