/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:36:07 by dzuiev            #+#    #+#             */
/*   Updated: 2024/08/29 16:37:18 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
	ClapTrap ct1("Clappy");

	ct1.attack("Target Dummy");
	ct1.takeDamage(5);
	ct1.beRepaired(3);

	ClapTrap ct2(ct1);
	ct2.attack("Another Dummy");

	ClapTrap ct3("Trappy");
	ct3 = ct1;
	ct3.takeDamage(15);
	ct3.beRepaired(10);

	return 0;
}
