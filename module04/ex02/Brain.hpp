/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:36:48 by dzuiev            #+#    #+#             */
/*   Updated: 2024/09/09 11:52:17 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain {
	private:
		std::string _ideas[100];

	public:
		Brain();
		Brain(const Brain& other);
		~Brain();

		Brain& operator=(const Brain& rhs);
		std::string getIdea(int index) const;
		void setIdea(int index, std::string& idea);
};

#endif
