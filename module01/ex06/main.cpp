/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:45:31 by dzuiev            #+#    #+#             */
/*   Updated: 2024/08/19 16:10:13 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv) {

	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " <log level>" << std::endl;
		return 1;
	}

	// Test the Harl class with different complaint levels
	Harl harl;
	std::string level = argv[1];
	harl.complain(level);
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.filter(level);

	return 0;
}
