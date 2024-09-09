/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:54:58 by dzuiev            #+#    #+#             */
/*   Updated: 2024/09/09 11:26:30 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal {
	protected:
		std::string _type;

	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal& other);
		virtual ~Animal();

		Animal& operator=(const Animal& rhs);
		std::string getType() const;
		virtual void makeSound() const; // Virtual function, making Animal abstract
};

#endif
