/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:51:06 by dzuiev            #+#    #+#             */
/*   Updated: 2024/08/29 10:37:08 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main() {
	// Define the vertices of the triangle
	Point A(0, 0);
	Point B(10, 30);
	Point C(20, 0);

	// Test case 1: Point inside the triangle
	Point P1(10, 15);
	std::cout << "Test 1: Point (10, 15) is " 
			<< (bsp(A, B, C, P1) ? "inside" : "outside") 
			<< " the triangle." << std::endl;

	// Test case 2: Point outside the triangle
	Point P2(30, 15);
	std::cout << "Test 2: Point (30, 15) is " 
			<< (bsp(A, B, C, P2) ? "inside" : "outside") 
			<< " the triangle." << std::endl;

	// Test case 3: Point on the edge of the triangle
	Point P3(10, 30);
	std::cout << "Test 3: Point (10, 30) is " 
			<< (bsp(A, B, C, P3) ? "inside" : "outside") 
			<< " the triangle." << std::endl;

	// Test case 4: Point on the vertex of the triangle
	Point P4(0, 0);
	std::cout << "Test 4: Point (0, 0) is " 
			<< (bsp(A, B, C, P4) ? "inside" : "outside") 
			<< " the triangle." << std::endl;

	// Test case 5: Another point inside the triangle
	Point P5(15, 10);
	std::cout << "Test 5: Point (15, 10) is " 
			<< (bsp(A, B, C, P5) ? "inside" : "outside") 
			<< " the triangle." << std::endl;

	// Test case 6: Point exactly at the centroid of the triangle
	Point P6(10, 10);
	std::cout << "Test 6: Point (10, 10) is " 
			<< (bsp(A, B, C, P6) ? "inside" : "outside") 
			<< " the triangle." << std::endl;

	return 0;
}
