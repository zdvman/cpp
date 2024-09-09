/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:43:52 by dzuiev            #+#    #+#             */
/*   Updated: 2024/09/09 11:51:48 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	for (int i = 0; i < 100; i++) {
		_ideas[i] = "Default idea";
	}
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain& other) {
	for (int i = 0; i < 100; i++) {
		_ideas[i] = other._ideas[i];
	}
	std::cout << "Brain copy constructor called" << std::endl;
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
