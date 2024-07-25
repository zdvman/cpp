/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:52:58 by dzuiev            #+#    #+#             */
/*   Updated: 2024/07/25 16:39:53 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// ************************************************************************** //
// Create a new Zombie on the heap and return a pointer to it                 //
// ************************************************************************** //
Zombie* newZombie(std::string name) {
	// Allocate memory for a new Zombie object on the heap
	// and return a pointer to it
	return new Zombie(name); 
}
