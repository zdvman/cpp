/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:51:06 by dzuiev            #+#    #+#             */
/*   Updated: 2024/08/28 18:57:36 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main() {
	// Example 1: Point inside the triangle
	Point A(0, 0);
	Point B(10, 30);
	Point C(20, 0);
	Point P_inside(10, 15);

	if (bsp(A, B, C, P_inside)) {
		std::cout << "Example 1: The point (10, 15) is inside the triangle." << std::endl;
	} else {
		std::cout << "Example 1: The point (10, 15) is outside the triangle." << std::endl;
	}

	// Example 2: Point outside the triangle
	Point P_outside(30, 15);

	if (bsp(A, B, C, P_outside)) {
		std::cout << "Example 2: The point (30, 15) is inside the triangle." << std::endl;
	} else {
		std::cout << "Example 2: The point (30, 15) is outside the triangle." << std::endl;
	}

	// Example 3: Point on the edge of the triangle
	Point P_on_edge(10, 30);

	if (bsp(A, B, C, P_on_edge)) {
		std::cout << "Example 3: The point (10, 30) is inside the triangle." << std::endl;
	} else {
		std::cout << "Example 3: The point (10, 30) is outside the triangle." << std::endl;
	}

	// Example 4: Point at the vertex of the triangle
	Point P_at_vertex(20, 0);

	if (bsp(A, B, C, P_at_vertex)) {
		std::cout << "Example 4: The point (20, 0) is inside the triangle." << std::endl;
	} else {
		std::cout << "Example 4: The point (20, 0) is outside the triangle." << std::endl;
	}

	return 0;
}
