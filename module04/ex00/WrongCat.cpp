/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:08:42 by dzuiev            #+#    #+#             */
/*   Updated: 2024/09/09 11:18:46 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {}

WrongCat::WrongCat(std::string type) : WrongAnimal(type) {}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {}

WrongCat::~WrongCat() {}


WrongCat& WrongCat::operator=(const WrongCat& rhs) {
	if (this != &rhs) {
		WrongAnimal::operator=(rhs);
	}
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << "Wrong Meow" << std::endl;
}
