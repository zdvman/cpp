/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:19:26 by dzuiev            #+#    #+#             */
/*   Updated: 2024/09/06 17:15:11 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>
#include <iostream>

class Cat : public Animal {
	private:
		Brain* _brain;

	public:
		Cat();
		Cat(const Cat& other);
		~Cat();

		Cat& operator=(const Cat& rhs);
		void makeSound() const; // Overrides the base class virtual function
		Brain* getBrain() const;
};

#endif
