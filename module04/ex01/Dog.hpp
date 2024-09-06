/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:39:22 by dzuiev            #+#    #+#             */
/*   Updated: 2024/09/06 17:15:55 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>
#include <iostream>

class Dog : public Animal {
		private:
			Brain* _brain;

	public:
		Dog();
		Dog(const Dog& other);
		~Dog();

		Dog& operator=(const Dog& rhs);
		void makeSound() const; // Overrides the base class virtual function
		Brain* getBrain() const;
};

#endif
