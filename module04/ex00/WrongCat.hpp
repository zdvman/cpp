/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:03:39 by dzuiev            #+#    #+#             */
/*   Updated: 2024/09/10 16:21:37 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include "WrongAnimal.hpp"
#include <string>
#include <iostream>

class WrongCat : public WrongAnimal {
	public:
		WrongCat();
		WrongCat(const WrongCat& other);
		~WrongCat();

		WrongCat& operator=(const WrongCat& rhs);
		void makeSound() const;
		
};

#endif
