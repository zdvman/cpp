/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:07:25 by dzuiev            #+#    #+#             */
/*   Updated: 2024/09/09 15:10:46 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++) {
		_materias[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	for (int i = 0; i < 4; i++) {
		if (other._materias[i]) {
			_materias[i] = other._materias[i]->clone();
		} else {
			_materias[i] = NULL;
		}
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	if (this != &other) {
		for (int i = 0; i < 4; i++) {
			if (_materias[i]) {
				delete _materias[i];
			}
			if (other._materias[i]) {
				_materias[i] = other._materias[i]->clone();
			} else {
				_materias[i] = NULL;
			}
		}
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (_materias[i]) {
			delete _materias[i];
		}
	}
}

void MateriaSource::learnMateria(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (!_materias[i]) {
			_materias[i] = m;
			break;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (_materias[i] && _materias[i]->getType() == type) {
			return _materias[i]->clone();
		}
	}
	return NULL;
}
