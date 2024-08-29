/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:59:39 by dzuiev            #+#    #+#             */
/*   Updated: 2024/08/29 11:24:03 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/* ************************************************************************** */
/*                                                                            */
/*  BSP: Binary Space Partitioning                                            */
/*                                                                            */
/*  Explanation:                                                              */
/*  - **Binary**: Refers to the fact that space is divided into two parts     */
/*    at each step.                                                           */
/*  - **Space**: Refers to the geometric space that is being divided,         */
/*    which could be a 2D plane, 3D volume, etc.                              */
/*  - **Partitioning**: Refers to the process of dividing the space into      */
/*    distinct regions.                                                       */
/*                                                                            */
/*  **Binary Space Partitioning (BSP)** is a method used in computer          */
/*  graphics, computational geometry, and game development to efficiently     */
/*  manage and render complex scenes by recursively dividing a space into     */
/*  convex sets using hyperplanes. In 2D, these divisions are often lines,    */
/*  and in 3D, they are planes.                                               */
/*                                                                            */
/*  In the context of this project, BSP is used to determine whether a point  */
/*  lies inside a triangle by partitioning the space and examining the        */
/*  relative positions of points.                                             */
/*                                                                            */
/* ************************************************************************** */
/*                                                                            */
/* Input: A = (0, 0), B = (10, 30), C = (20, 0), P(10, 15)                    */
/* Output: Inside                                                             */
/* Explanation:                                                               */
/*               B(10,30)                                                     */
/*                 / \                                                        */
/*                /   \                                                       */
/*               /     \                                                      */
/*              /   P   \      P'                                             */
/*             /         \                                                    */
/*      A(0,0) ----------- C(20,0)                                            */
/*                                                                            */
/* Input: A = (0, 0), B = (10, 30), C = (20, 0), P(30, 15)                    */
/* Output: Outside                                                            */
/* Explanation:                                                               */
/*               B(10,30)                                                     */
/*                 / \                                                        */
/*                /   \                                                       */
/*               /     \                                                      */
/*              /       \      P                                              */
/*             /         \                                                    */
/*      A(0,0) ----------- C(20,0)                                            */
/*                                                                            */
/* Solution:                                                                  */
/* Let the coordinates of the three corners be (x1, y1), (x2, y2) and         */
/* (x3, y3). The coordinates of the given point P are (x, y).                 */
/*                                                                            */
/* 1. Calculate the area of the given triangle, i.e., the area of triangle    */
/*    ABC.                                                                    */
/*    Area A = [ x1(y2 – y3) + x2(y3 – y1) + x3(y1-y2) ] / 2                  */
/*                                                                            */
/* 2. Calculate the area of the triangle PAB. Let this area be A1.            */
/*    Use the same formula to compute the area.                               */
/*                                                                            */
/* 3. Calculate the area of the triangle PBC. Let this area be A2.            */
/*                                                                            */
/* 4. Calculate the area of the triangle PAC. Let this area be A3.            */
/*                                                                            */
/* 5. If P lies inside the triangle, then A1 + A2 + A3 must be equal to A.    */
/*    This means that the sum of the areas of triangles PAB, PBC, and PAC     */
/*    is equal to the area of triangle ABC.                                   */
/*                                                                            */
/* ************************************************************************** */

// Custom abs function implementation
static Fixed abs(const Fixed& value) {
    return (value < 0) ? value * -1 : value;
}

// Function to calculate the area of a triangle given its vertices
static Fixed calculateArea(const Point& p1, const Point& p2, const Point& p3) {
    return abs(
        (p1.getX() * (p2.getY() - p3.getY())) +
        (p2.getX() * (p3.getY() - p1.getY())) +
        (p3.getX() * (p1.getY() - p2.getY()))
    ) / Fixed(2);
}

// BSP function to determine if a point is inside the triangle
bool bsp( Point const a, Point const b, Point const c, Point const point) {
    Fixed areaABC = calculateArea(a, b, c); // Area of triangle ABC
    Fixed areaPAB = calculateArea(point, a, b); // Area of triangle PAB
    Fixed areaPBC = calculateArea(point, b, c); // Area of triangle PBC
    Fixed areaPCA = calculateArea(point, c, a); // Area of triangle PCA

    // Check if the sum of the areas of the triangles PAB, PBC, and PCA equals the area of ABC
    return (areaABC == (areaPAB + areaPBC + areaPCA));
}

/* ************************************************************************** */
/*                                                                            */
/*   The `sign` Function: Determining Point Position Relative to a Line       */
/*                                                                            */
/* ************************************************************************** */
/*                                                                            */
/* The `sign` function calculates a value that indicates whether a point lies */
/* on one side or the other of a line formed by two other points. This is     */
/* achieved using a determinant-based method, similar to how the area of a    */
/* triangle is computed.                                                      */
/*                                                                            */
/* ### Explanation:                                                           */
/*                                                                            */
/* Given three points:                                                        */
/* - p1(x1, y1): The point for which we want to determine the position.       */
/* - p2(x2, y2): The first point that forms the line.                         */
/* - p3(x3, y3): The second point that forms the line.                        */
/*                                                                            */
/* The sign function is calculated as:                                        */
/*                                                                            */
/*    Sign = (x1 - x3) * (y2 - y3) - (x2 - x3) * (y1 - y3)                    */
/*                                                                            */
/* This formula is essentially the cross product of vectors:                  */
/*                                                                            */
/*    Vector AB = (x2 - x3, y2 - y3)                                          */
/*    Vector AP = (x1 - x3, y1 - y3)                                          */
/*                                                                            */
/* The cross product (AB × AP) gives us a scalar value indicating the relative*/
/* orientation of point P with respect to line AB.                            */
/*                                                                            */
/* ### Visualization:                                                         */
/*                                                                            */
/* Consider the points A(2, 2), B(6, 6), and P(4, 4) forming a line segment   */
/* and a test point. The vectors can be visualized as follows:                */
/*                                                                            */
/*            B(6,6)                                                          */
/*              *                                                             */
/*             /|                                                             */
/*            / |                                                             */
/*           /  |                                                             */
/*      AP  /   |                                                             */
/*         /    |                                                             */
/*        /     |                                                             */
/*       *------*                                                             */
/*      A(2,2)  P(4,4)                                                        */
/*                                                                            */
/* - Vector AB: From A(2, 2) to B(6, 6)                                       */
/* - Vector AP: From A(2, 2) to P(4, 4)                                       */
/*                                                                            */
/* The sign of the cross product of these vectors will tell us where P lies   */
/* relative to line AB.                                                       */
/*                                                                            */
/* ### Interpretation of the Result:                                          */
/*                                                                            */
/* 1. **Positive Result**:                                                    */
/*    - The point P lies on one side of the line formed by A and B.           */
/*                                                                            */
/* 2. **Negative Result**:                                                    */
/*    - The point P lies on the opposite side of the line formed by A and B.  */
/*                                                                            */
/* 3. **Zero Result**:                                                        */
/*    - The point P lies exactly on the line formed by A and B.               */
/*                                                                            */
/* ### Example 1: Point Inside the Triangle                                   */
/*                                                                            */
/* Consider the triangle formed by points A(2, 2), B(6, 6), C(8, 2), and a    */
/* point P(4, 4).                                                             */
/*                                                                            */
/* For the line AB (A(2, 2) to B(6, 6)), the `sign` function would yield a    */
/* positive value, indicating that P(4, 4) lies on one side of AB.            */
/*                                                                            */
/* ### Example 2: Point Outside the Triangle                                  */
/*                                                                            */
/* Consider the same triangle A(2, 2), B(6, 6), C(8, 2), and a point P(10, 4).*/
/*                                                                            */
/* For the line AB (A(2, 2) to B(6, 6)), the `sign` function would yield a    */
/* negative value, indicating that P(10, 4) lies on the opposite side of AB.  */
/*                                                                            */
/* This determinant-based method effectively helps in determining the relative*/
/* position of a point to the line, which is crucial in the BSP algorithm to  */
/* decide if a point lies inside a triangle.                                  */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*  Helper function to calculate the sign of the area of a triangle.          */
/*  The sign function determines whether a point lies on one side or the      */
/*  other of a line formed by two other points.                               */
/*  The result is a Fixed-point number that indicates the relative position   */
/*  of the point with respect to the line.                                    */
/*                                                                            */
/* ************************************************************************** */
/*
static Fixed sign(const Point& p1, const Point& p2, const Point& p3) {
    return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) - 
        (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
}
*/

/* ************************************************************************** */
/*                                                                            */
/*  BSP (Binary Space Partitioning) function to determine if a point lies     */
/*  inside a triangle formed by three other points.                           */
/*                                                                            */
/*  The function works by calculating the sign of the area for each of the    */
/*  sub-triangles formed by the point and the edges of the triangle. If all   */
/*  signs are consistent (all positive or all negative), the point is inside  */
/*  the triangle. If the signs are mixed, the point is outside the triangle.  */
/*                                                                            */
/*  Returns `true` if the point lies inside the triangle, otherwise `false`.  */
/*                                                                            */
/* ************************************************************************** */
/*
bool	bsp( Point const a, Point const b, Point const c, Point const point) {
    Fixed d1, d2, d3;
    bool has_neg, has_pos;

    d1 = sign(point, a, b);
    d2 = sign(point, b, c);
    d3 = sign(point, c, a);

    has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(has_neg && has_pos);
}
*/
