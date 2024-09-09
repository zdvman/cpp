/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:19:26 by dzuiev            #+#    #+#             */
/*   Updated: 2024/09/09 13:31:09 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <string>
#include <iostream>

class Cat : public AAnimal {
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
