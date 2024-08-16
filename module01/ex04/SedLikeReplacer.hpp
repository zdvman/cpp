/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SedLikeReplacer.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:33:37 by dzuiev            #+#    #+#             */
/*   Updated: 2024/08/16 17:33:14 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SEDLIKEREPLACER_HPP
#define SEDLIKEREPLACER_HPP

#include <string>
// ********************************************************************** //
// <string> library                                                       //
// Provides the std::string class for representing and manipulating       //
// sequences of characters.                                               //
// - Methods used:                                                        //
//   - c_str(): Converts a std::string to a C-style string (const char*). //
//   - find(), erase(), insert(), length(): Functions for string          //
//     manipulation.                                                      //
// ********************************************************************** //


// ********************************************************************** //
// The SedLikeReplacer class is designed to replace occurrences of a      //
// specific string (s1) with another string (s2) within the content of    //
// a file. This class manages the file operations and string replacement. //
// ********************************************************************** //
class SedLikeReplacer {
public:
	// ********************************************************************** //
	// Default constructor: Initializes an empty SedLikeReplacer object.      //
	// It doesn't take any parameters and doesn't perform any actions.        //
	// ********************************************************************** //
	SedLikeReplacer();

	// ********************************************************************** //
	// Parameterized constructor: Initializes a SedLikeReplacer object with   //
	// a filename, a search string (s1), and a replacement string (s2).       //
	// This constructor is used to set up the object with all the data needed //
	// to perform the replacement operation.                                  //
	// ********************************************************************** //
	SedLikeReplacer(const std::string& filename, const std::string& s1, const std::string& s2);

	// ********************************************************************** //
	// Copy constructor: Creates a copy of another SedLikeReplacer object.    //
	// It duplicates the filename, s1, and s2 values from the original object.//
	// ********************************************************************** //
	SedLikeReplacer(const SedLikeReplacer& other);

	// ********************************************************************** //
	// Copy assignment operator: Copies the content of one SedLikeReplacer    //
	// object to another. It ensures that the current object gets the same    //
	// filename, s1, and s2 values as the object on the right-hand side of the//
	// assignment.                                                            //
	// ********************************************************************** //
	SedLikeReplacer& operator=(const SedLikeReplacer& other);

	// ********************************************************************** //
	// Destructor: Cleans up when a SedLikeReplacer object is destroyed.      //
	// Although in this example it does nothing special, it's included        //
	// to follow the canonical form of a C++ class.                           //
	// ********************************************************************** //
	~SedLikeReplacer();

	// ********************************************************************** //
	// replaceInFile: Public method that performs the file operations and     //
	// calls the private method to replace occurrences of s1 with s2 in the   //
	// file content.                                                          //
	// ********************************************************************** //
	void replaceInFile() const;

private:
	std::string _filename;  // Holds the name of the file to be processed
	std::string _s1;        // The string to search for in the file content
	std::string _s2;        // The string to replace s1 with in the file content

	// ********************************************************************** //
	// replaceOccurrences: Private method that performs the actual replacement//
	// of all occurrences of s1 with s2 in the given string content. This     //
	// method is used by replaceInFile() to modify the content before writing //
	// it to the output file.                                                 //
	// ********************************************************************** //
	void replaceOccurrences(std::string& content, const std::string& s1, const std::string& s2) const;
};

#endif
