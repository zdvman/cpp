/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:06:17 by dzuiev            #+#    #+#             */
/*   Updated: 2024/09/09 16:57:05 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*   IMateriaSource.hpp                                                       */
/*                                                                            */
/*   This file defines the IMateriaSource interface, which represents the     */
/*   blueprint for any class that can store and create Materia objects.       */
/*   This interface has two pure virtual functions:                           */
/*   - learnMateria(): Allows the class to store a Materia object.            */
/*   - createMateria(): Creates a Materia based on a given type.              */
/*   Any class that inherits from IMateriaSource must implement these         */
/*   functions.                                                               */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include "AMateria.hpp"

class IMateriaSource {
public:
	virtual ~IMateriaSource() {}                                           // Virtual destructor
	virtual void learnMateria(AMateria* m) = 0;                           // Stores a Materia in the source
	virtual AMateria* createMateria(std::string const & type) = 0;         // Creates a Materia of a given type
};

#endif
