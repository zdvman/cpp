/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:26:40 by dzuiev            #+#    #+#             */
/*   Updated: 2024/08/29 10:49:03 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

/* ************************************************************************** */
/*                                                                            */
/* Let's delve into how the shift operators (`<<`, `>>`) work, how they are   */
/* used in your code, and how the `<<` operator is overloaded for outputting  */
/* to `std::ostream`.                                                         */
/*                                                                            */
/* 1. Shift Operators `<<` and `>>`                                           */
/*                                                                            */
/* - **`<<`** — Left Shift Operator: Shifts the bits of a number to the left  */
/*   by the specified number of positions.                                    */
/* - **`>>`** — Right Shift Operator: Shifts the bits of a number to the      */
/*   right by the specified number of positions.                              */
/*                                                                            */
/* Bit shifting is used to multiply or divide by powers of two. For example:  */
/* - `x << 1` is equivalent to multiplying `x` by 2.                          */
/* - `x >> 1` is equivalent to dividing `x` by 2.                             */
/*                                                                            */
/* 2. Examples of Left and Right Shifts                                       */
/*                                                                            */
/* Let's assume we have an 8-bit number `x = 5`, which in binary looks like   */
/* `00000101`:                                                                */
/*                                                                            */
/* - `x << 1` shifts all the bits to the left by 1 position: `00001010`,      */
/*   which is `10` in decimal.                                                */
/* - `x >> 1` shifts all the bits to the right by 1 position: `00000010`,     */
/*   which is `2` in decimal.                                                 */
/*                                                                            */
/* 3. How This Is Used in Your Code                                           */
/*                                                                            */
/* 3.1. Initialization of `_fixedPointValue` for an Integer                   */
/*                                                                            */
/* ```cpp                                                                     */
/* _fixedPointValue = value << _fractionalBits;                               */
/* ```                                                                        */
/*                                                                            */
/* - Here, `value` is an integer, and `_fractionalBits` is the number of bits */
/*   allocated for the fractional part. Let's assume `_fractionalBits = 8`.   */
/*                                                                            */
/* - This code multiplies `value` by `2^8 = 256`. Shifting bits to the left   */
/*   by 8 positions allows storing the value in a fixed-point format Q8.8,    */
/*   where the integer part occupies the upper 8 bits, and the fractional     */
/*   part occupies the lower 8 bits.                                          */
/*                                                                            */
/* **Example:**                                                               */
/*                                                                            */
/* If `value = 10`:                                                           */
/*                                                                            */
/* - In binary, `value = 00000000 00001010` (16 bits).                        */
/* - After the left shift, `value << 8 = 00001010 00000000`.                  */
/* - In decimal, this is `2560`.                                              */
/*                                                                            */
/* Thus, the number 10 in Q8.8 format is represented as `2560`, where the     */
/* upper 8 bits represent the integer part `10`, and the lower 8 bits         */
/* represent `0` for the fractional part.                                     */
/*                                                                            */
/* 3.2. Initialization of `_fixedPointValue` for a Floating-Point Number      */
/*                                                                            */
/* ```cpp                                                                     */
/* _fixedPointValue = static_cast<int>(roundf(value * (1 << _fractionalBits))); */
/* ```                                                                        */
/*                                                                            */
/* - Here, `value` is a floating-point number, and `1 << _fractionalBits`     */
/*   shifts 1 to the left by `_fractionalBits` (in this case, 8), which is    */
/*   equivalent to multiplying by 256.                                        */
/*                                                                            */
/* - The code multiplies `value` by 256 to shift the fractional part into the */
/*   fixed-point representation, rounds the result, and converts it to an     */
/*   integer.                                                                 */
/*                                                                            */
/* **Example:**                                                               */
/*                                                                            */
/* If `value = 42.42`:                                                        */
/*                                                                            */
/* - Multiply `42.42 * 256 = 10883.52`.                                       */
/* - `roundf(10883.52)` rounds this value to `10884`.                         */
/* - `static_cast<int>(10884)` converts it to an integer.                     */
/*                                                                            */
/* Thus, the number `42.42` in Q8.8 format is represented as `10884`.         */
/*                                                                            */
/* 3.3. Converting `_fixedPointValue` Back to `float`                         */
/*                                                                            */
/* ```cpp                                                                     */
/* return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits);      */
/* ```                                                                        */
/*                                                                            */
/* - This code converts the fixed-point number back to `float` by dividing it */
/*   by 256.                                                                  */
/*                                                                            */
/* **Example:**                                                               */
/*                                                                            */
/* If `_fixedPointValue = 10884`:                                             */
/*                                                                            */
/* - `_fixedPointValue / 256 = 42.421875`.                                    */
/* - `static_cast<float>(42.421875)` returns the value in `float`.            */
/*                                                                            */
/* 3.4. Converting `_fixedPointValue` Back to `int`                           */
/*                                                                            */
/* ```cpp                                                                     */
/* return _fixedPointValue >> _fractionalBits;                                */
/* ```                                                                        */
/*                                                                            */
/* - Here, the bits are shifted right by 8 positions, which is equivalent to  */
/*   dividing by 256 and allows returning only the integer part of the number. */
/*                                                                            */
/* **Example:**                                                               */
/*                                                                            */
/* If `_fixedPointValue = 10884`:                                             */
/*                                                                            */
/* - `_fixedPointValue >> 8 = 42`, which is the integer part of the number.   */
/*                                                                            */
/* 4. Overloading the `<<` Operator                                           */
/*                                                                            */
/* ```cpp                                                                     */
/* std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {           */
/*     os << fixed.toFloat();                                                 */
/*     return os;                                                             */
/* }                                                                          */
/* ```                                                                        */
/*                                                                            */
/* - This overload allows `Fixed` objects to be output to a `std::ostream`,   */
/*   such as `std::cout`.                                                     */
/*                                                                            */
/* - `os` is the output stream (e.g., `std::cout`).                           */
/* - `fixed.toFloat()` converts the `Fixed` object to a floating-point number, */
/*   which is then output to the stream.                                      */
/*                                                                            */
/* **Example:**                                                               */
/*                                                                            */
/* If you have a `Fixed` object with `_fixedPointValue = 10884`, then         */
/* `std::cout << fixed;` will output `42.421875`.                             */
/*                                                                            */
/* Conclusion                                                                 */
/* - Shift operators `<<` and `>>` are used to convert numbers between        */
/*   formats, shifting bits left or right, which is equivalent to multiplying */
/*   or dividing by powers of two.                                            */
/*                                                                            */
/* - In your code, shifts are used to convert integers and floating-point     */
/*   numbers to and from the fixed-point format.                              */
/*                                                                            */
/* - Overloading the `<<` operator allows `Fixed` objects to be output in a   */
/*   standard output stream (e.g., `std::cout`) as floating-point numbers.    */
/*                                                                            */
/* ************************************************************************** */

class Fixed {
public:
/* ************************************************************************** */
/*                                                                            */
/*  Constructors and Destructor:                                              */
/*  - Default constructor: Initializes a `Fixed` object with a default        */
/*    fixed-point value of 0.                                                 */
/*  - Integer constructor: Converts the given integer `value` to a            */
/*    fixed-point representation by shifting it left by `_fractionalBits`.    */
/*  - Float constructor: Converts the given floating-point `value` to a       */
/*    fixed-point representation by multiplying it by `2^_fractionalBits`     */
/*    and rounding the result.                                                */
/*  - Copy constructor: Initializes a new `Fixed` object by copying the       */
/*    value from another `Fixed` object.                                      */
/*  - Destructor: Cleans up resources used by the `Fixed` object.             */
/*                                                                            */
/* ************************************************************************** */
	Fixed(void);
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed& other);
	~Fixed();

/* ************************************************************************** */
/*                                                                            */
/*  Copy Assignment Operator:                                                 */
/*  - Assigns the value from another `Fixed` object to the current object.    */
/*  - The current object's fixed-point value is updated to match the `other`  */
/*    object.                                                                 */
/*                                                                            */
/* ************************************************************************** */
	Fixed& operator=(const Fixed& other);

/* ************************************************************************** */
/*                                                                            */
/*  Getters and Setters:                                                      */
/*  - `getRawBits`: Returns the raw fixed-point value stored in the object.   */
/*  - `setRawBits`: Sets the raw fixed-point value of the object to the       */
/*    provided integer `raw`.                                                 */
/*                                                                            */
/* ************************************************************************** */
	int getRawBits(void) const;
	void setRawBits(int const raw);

/* ************************************************************************** */
/*                                                                            */
/*  Conversion Functions:                                                     */
/*  - `toFloat`: Converts the fixed-point value to a floating-point number.   */
/*  - `toInt`: Converts the fixed-point value to an integer.                  */
/*                                                                            */
/* ************************************************************************** */
	float toFloat(void) const;
	int toInt(void) const;

private:
/* ************************************************************************** */
/*                                                                            */
/*  Internal Representation:                                                  */
/*  - `_fixedPointValue`: Stores the actual fixed-point number as an integer. */
/*  - `_fractionalBits`: Number of bits used for the fractional part of the   */
/*    fixed-point value (8 for Q8.8 format).                                  */
/*                                                                            */
/* ************************************************************************** */
	int _fixedPointValue;
	static const int _fractionalBits = 8;
};

/* ************************************************************************** */
/*                                                                            */
/*  Overloaded `<<` Operator:                                                  */
/*  - Allows `Fixed` objects to be output to streams like `std::cout`.         */
/*  - Converts the `Fixed` object to a float before outputting.                */
/*                                                                            */
/* ************************************************************************** */
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
