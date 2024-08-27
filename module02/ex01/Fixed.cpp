/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:27:27 by dzuiev            #+#    #+#             */
/*   Updated: 2024/08/27 17:02:50 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* ************************************************************************** */
/*                                                                            */
/*  Default constructor:                                                      */
/*  Initializes the `_fixedPointValue` to 0.                                  */
/*  Outputs a message indicating that the default constructor was called.     */
/*                                                                            */
/* ************************************************************************** */

Fixed::Fixed() : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*  Integer constructor:                                                      */
/*  Takes an integer `value` and converts it to the fixed-point format by     */
/*  shifting it left by `_fractionalBits` positions (8 bits in this case).    */
/*  Outputs a message indicating that the integer constructor was called.     */
/*                                                                            */
/* ************************************************************************** */

Fixed::Fixed(const int value) : _fixedPointValue(value << _fractionalBits) {
    std::cout << "Int constructor called" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*  Float constructor:                                                        */
/*  Takes a floating-point `value` and converts it to the fixed-point format  */
/*  by multiplying it by `2^8` (256) and rounding the result.                 */
/*  Outputs a message indicating that the float constructor was called.       */
/*                                                                            */
/* ************************************************************************** */

Fixed::Fixed(const float value) : _fixedPointValue(static_cast<int>(roundf(value * (1 << _fractionalBits)))) {
    std::cout << "Float constructor called" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*  Copy constructor:                                                         */
/*  Initializes the current object by copying the values from another         */
/*  `Fixed` object.                                                           */
/*  Outputs a message indicating that the copy constructor was called.        */
/*                                                                            */
/* ************************************************************************** */

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

/* ************************************************************************** */
/*                                                                            */
/*  Copy assignment operator:                                                 */
/*  Assigns the values from another `Fixed` object to the current object.     */
/*  Checks for self-assignment and copies the `_fixedPointValue` using        */
/*  the `getRawBits()` method.                                                */
/*  Outputs a message indicating that the copy assignment operator was called.*/
/*  Returns a reference to the current object.                                */
/*                                                                            */
/* ************************************************************************** */

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        _fixedPointValue = other.getRawBits();
    }
    return *this;
}

/* ************************************************************************** */
/*                                                                            */
/*  Destructor:                                                               */
/*  Outputs a message indicating that the destructor was called.              */
/*                                                                            */
/* ************************************************************************** */

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*  getRawBits:                                                               */
/*  Returns the raw value of the fixed-point number (`_fixedPointValue`).     */
/*                                                                            */
/* ************************************************************************** */

int Fixed::getRawBits(void) const {
    return _fixedPointValue;
}

/* ************************************************************************** */
/*                                                                            */
/*  setRawBits:                                                               */
/*  Sets the raw value of the fixed-point number (`_fixedPointValue`) to the  */
/*  provided integer `raw`.                                                   */
/*                                                                            */
/* ************************************************************************** */

void Fixed::setRawBits(int const raw) {
    _fixedPointValue = raw;
}

/* ************************************************************************** */
/*                                                                            */
/*  toFloat:                                                                  */
/*  Converts the fixed-point value to a floating-point number by dividing it  */
/*  by `2^8` (256).                                                           */
/*  Returns the resulting float value.                                        */
/*                                                                            */
/* ************************************************************************** */

float Fixed::toFloat(void) const {
    return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits);
}

/* ************************************************************************** */
/*                                                                            */
/*  toInt:                                                                    */
/*  Converts the fixed-point value to an integer by shifting it right by      */
/*  `_fractionalBits` positions (8 bits in this case).                        */
/*  Returns the resulting integer value.                                      */
/*                                                                            */
/* ************************************************************************** */

int Fixed::toInt(void) const {
    return _fixedPointValue >> _fractionalBits;
}

/* ************************************************************************** */
/*                                                                            */
/*  Overloaded `<<` operator:                                                 */
/*  Outputs the `Fixed` object as a floating-point number by calling the      */
/*  `toFloat()` method.                                                       */
/*  Returns the `std::ostream` object to allow chaining of output operations. */
/*                                                                            */
/* ************************************************************************** */

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}

/* ************************************************************************** */
/*                                                                            */
/*                        Summary of Operator Overloading in C++              */
/*                                                                            */
/* Operator overloading allows you to define custom behavior for operators    */
/* (e.g., `+`, `-`, `==`, `<<`, etc.) when they are used with objects of      */
/* your custom classes. This provides a more intuitive interface for users    */
/* of your classes and allows objects to be manipulated in a natural way.     */
/* Below are key points and considerations when overloading operators:        */
/*                                                                            */
/* 1. Member Function vs. Non-Member Function                                 */
/*                                                                            */
/* - **Member Function**:                                                     */
/*   - Use when the left-hand operand must be an instance of the class.       */
/*   - Typically used for unary operators (e.g., `++`, `--`, `-`), assignment */
/*     operators (`=`), and compound assignment operators (`+=`, `-=`).       */
/*   - Provides direct access to the class's private members without needing  */
/*     `friend`.                                                              */
/*                                                                            */
/* - **Non-Member (Free) Function**:                                          */
/*   - Use when the left-hand operand can be of a different type or when both */
/*     operands need to support implicit conversions.                         */
/*   - Commonly used for binary operators (`+`, `-`, `==`, `<<`, etc.).       */
/*   - Keeps the class interface clean by accessing class data through public */
/*     methods or making the function `friend` if necessary.                  */
/*                                                                            */
/* 2. Commonly Overloaded Operators                                           */
/*                                                                            */
/* - **Arithmetic Operators**: (`+`, `-`, `*`, `/`)                           */
/*   - Typically non-member functions.                                        */
/*   - Enable arithmetic operations between objects of your class.            */
/*                                                                            */
/* - **Comparison Operators**: (`==`, `!=`, `<`, `>`, `<=`, `>=`)             */
/*   - Can be either member or non-member functions, often non-member for     */
/*     symmetry.                                                              */
/*   - Allow objects of your class to be compared in a natural way.           */
/*                                                                            */
/* - **Stream Operators**: (`<<`, `>>`)                                       */
/*   - Must be non-member functions, usually `friend` to access private data. */
/*   - Enable easy input/output of objects to streams like `std::cout`.       */
/*                                                                            */
/* - **Assignment Operators**: (`=`, `+=`, `-=`)                              */
/*   - Must be member functions.                                              */
/*   - Modify the state of the left-hand operand.                             */
/*                                                                            */
/* 3. Best Practices                                                          */
/*                                                                            */
/* - **Use Member Functions**: When the operator modifies the object or is    */
/*   unary. Examples include `=` (assignment), `+=`, `-=`.                    */
/*                                                                            */
/* - **Use Non-Member Functions**: When the operator does not modify the      */
/*   object or when you want to allow implicit conversions. Examples include  */
/*   `+`, `-`, `==`, `<<`.                                                    */
/*                                                                            */
/* - **Preserve Symmetry**: For comparison operators (`==`, `<`, etc.),       */
/*   consider non-member functions to ensure symmetry and allow implicit      */
/*   conversions for both operands.                                           */
/*                                                                            */
/* - **Maintain Encapsulation**: Prefer non-member functions or use `friend`  */
/*   only when necessary to keep private members inaccessible from outside.   */
/*                                                                            */
/* - **Respect Operator Semantics**: Ensure that your overloaded operators    */
/*   behave in a way that is consistent with their typical use. For example,  */
/*   `==` should return `true` if and only if the objects are equivalent.     */
/*                                                                            */
/* Operator overloading is a powerful feature in C++ that, when used          */
/* judiciously, can make your classes easier to use and more intuitive.       */
/* However, it's important to carefully consider whether overloading a        */
/* particular operator adds clarity and value to your code.                   */
/*                                                                            */
/* ************************************************************************** */
