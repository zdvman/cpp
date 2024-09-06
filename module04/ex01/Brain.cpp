/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:43:52 by dzuiev            #+#    #+#             */
/*   Updated: 2024/09/06 17:30:28 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructor called" << std::endl;
	for (int i = 0; i < 100; i++) {
		_ideas[i] = "Default idea";
	}
}

Brain::Brain(const Brain& other) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = other; 
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& rhs) {
	if (this != &rhs) {
		for (int i = 0; i < 100; i++) {
		_ideas[i] = rhs._ideas[i];
		}
	}
	return *this;
}

std::string Brain::getIdea(int index) const {
	if (index >= 0 && index <= 100) {
		return _ideas[index];
	}
	return "Invalid Index";
}

void Brain::setIdea(int index, std::string& idea) {
	if (index >= 0 && index <= 100) {
		_ideas[index] = idea;
	}
}
