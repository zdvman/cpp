/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:54:58 by dzuiev            #+#    #+#             */
/*   Updated: 2024/09/09 11:26:30 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>
#include <iostream>

class AAnimal {
	protected:
		std::string _type;

	public:
		AAnimal();
		AAnimal(std::string type);
		AAnimal(const AAnimal& other);
		virtual ~AAnimal();

		AAnimal& operator=(const AAnimal& rhs);
		std::string getType() const;
		virtual void makeSound() const = 0; // Pure virtual function, making AAnimal abstract
};

#endif
