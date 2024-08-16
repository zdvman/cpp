/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SedLikeReplacer.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:33:57 by dzuiev            #+#    #+#             */
/*   Updated: 2024/08/16 17:31:59 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedLikeReplacer.hpp"

// ********************************************************************** //
// <iostream> library                                                      //
// Provides functionality for standard input/output stream operations.     //
// - std::cin: Standard input stream (usually the keyboard).               //
// - std::cout: Standard output stream (usually the console).              //
// - std::cerr: Standard error stream for outputting error messages.       //
// - std::endl: Inserts a newline character and flushes the output stream. //
// ********************************************************************** //
#include <iostream>

// ********************************************************************** //
// <fstream> library                                                       //
// Provides classes for file input/output operations in C++.               //
// - std::ifstream: Class for reading from files (input file stream).       //
// - std::ofstream: Class for writing to files (output file stream).        //
// - Methods used:                                                         //
//   - open(): Opens a file.                                                //
//   - close(): Closes a file.                                              //
//   - is_open(): Checks if the file is successfully opened.                //
//   - peek(): Returns the next character in the file without extracting it.//
// ********************************************************************** //
#include <fstream>

// ********************************************************************** //
// <sstream> library                                                       //
// Provides string stream classes that allow strings to be treated as      //
// streams for input and output operations.                                //
// - std::stringstream: Allows reading from and writing to strings using   //
//   stream operators.                                                     //
// - Useful for converting between strings and other data types.           //
// ********************************************************************** //
#include <sstream>
#include <sys/stat.h> // For checking file existence and permissions

// ********************************************************************** //
// Default constructor: This constructor doesn't initialize any values,   //
// leaving the SedLikeReplacer object in an empty or "unconfigured" state.//
// ********************************************************************** //
SedLikeReplacer::SedLikeReplacer() {}

// ********************************************************************** //
// Parameterized constructor: Initializes the object with a filename,     //
// search string (s1), and replacement string (s2). These values are      //
// stored in the object's private member variables for later use.         //
// ********************************************************************** //
SedLikeReplacer::SedLikeReplacer(const std::string& filename, const std::string& s1, const std::string& s2)
	: _filename(filename), _s1(s1), _s2(s2) {}

// ********************************************************************** //
// Copy constructor: Creates a new SedLikeReplacer object as a copy of    //
// another SedLikeReplacer object. All private member variables (_filename,//
// _s1, _s2) are copied from the other object.                            //
// ********************************************************************** //
SedLikeReplacer::SedLikeReplacer(const SedLikeReplacer& other)
	: _filename(other._filename), _s1(other._s1), _s2(other._s2) {}

// ********************************************************************** //
// Copy assignment operator: Allows one SedLikeReplacer object to be      //
// assigned the values of another. This operator checks if the object     //
// being assigned to is not the same as the one being copied from (to     //
// avoid self-assignment), then copies the private member variables       //
// (_filename, _s1, _s2) from the other object.                           //
// ********************************************************************** //
SedLikeReplacer& SedLikeReplacer::operator=(const SedLikeReplacer& other) {
	if (this != &other) {
		_filename = other._filename;
		_s1 = other._s1;
		_s2 = other._s2;
	}
	return *this;
}

// ********************************************************************** //
// Destructor: The destructor is automatically called when an object      //
// goes out of scope or is deleted. In this class, it does not perform    //
// any specific actions since there's no dynamic memory to clean up, but  //
// it's defined here to adhere to the canonical form.                     //
// ********************************************************************** //
SedLikeReplacer::~SedLikeReplacer() {}

// ********************************************************************** //
// replaceOccurrences: This method scans through the provided content     //
// string, looking for occurrences of s1. Whenever s1 is found, it is     //
// replaced with s2. The method continues until all occurrences of s1     //
// are replaced.                                                          //
// ********************************************************************** //
void SedLikeReplacer::replaceOccurrences(std::string& content, const std::string& s1, const std::string& s2) const {
	size_t pos = 0;
	// ********************************************************************** //
	// Loop to find each occurrence of s1 in content.                         //
	// std::string::find returns the position of the first occurrence of s1,  //
	// starting from pos. If no occurrence is found, std::string::npos is     //
	// returned, which terminates the loop.                                   //
	// ********************************************************************** //
	while ((pos = content.find(s1, pos)) != std::string::npos) {
		content.erase(pos, s1.length());  // Remove s1 from the content
		content.insert(pos, s2);          // Insert s2 at the same position
		pos += s2.length();               // Move pos past the newly inserted s2
	}
}

// ********************************************************************** //
// replaceInFile: This method performs the overall task of reading the    //
// content from the file, replacing occurrences of s1 with s2, and        //
// writing the modified content to a new file with the extension ".replace".//
// ********************************************************************** //
void SedLikeReplacer::replaceInFile() const {

	// ********************************************************************** //
	// Check if the search string s1 is empty.                                //
	// ********************************************************************** //
	if (_s1.empty()) {
		std::cerr << "Error: The search string cannot be empty." << std::endl;
		return;
	}

	// ********************************************************************** //
	// Check if s1 and s2 are identical.                                      //
	// ********************************************************************** //
	if (_s1 == _s2) {
		std::cerr << "Warning: The search string and replacement string are identical. No replacements will be made." << std::endl;
	}
	
	// ********************************************************************** //
	// The .c_str() method is used to convert std::string to const char*,     //
	// which is required by the std::ifstream constructor in C++98.           //
	// ********************************************************************** //
	std::ifstream inputFile(_filename.c_str());
	if (!inputFile) {
		std::cerr << "Error: Could not open the file " << _filename << std::endl;
		return;
	}

	// ********************************************************************** //
	// Check if the input file is empty by peeking at the first character.     //
	// std::ifstream::peek() looks at the next character in the stream without //
	// extracting it. If the next character is EOF (end-of-file), the function //
	// returns std::ifstream::traits_type::eof(), indicating that the file is  //
	// empty or we've reached the end of the file.                             //
	// ********************************************************************** //
	if (inputFile.peek() == std::ifstream::traits_type::eof()) {
		std::cerr << "Warning: The input file " << _filename << " is empty. No operations will be performed." << std::endl;
		return;
	}


	// ********************************************************************** //
	// The .c_str() method is also used for std::ofstream to convert the      //
	// std::string to const char*, which is required by the constructor in    //
	// C++98.                                                                 //
	// ********************************************************************** //
	std::string outputFilename = _filename + ".replace";
	std::ofstream outputFile(outputFilename.c_str());
	if (!outputFile) {
		std::cerr << "Error: Could not create the file " << outputFilename << std::endl;
		return;
	}

	// ********************************************************************** //
	// Read the entire content of the input file into a std::string.          //
	// std::stringstream buffer is used to read the file content into memory, //
	// which is then converted to a std::string called content.               //
	// ********************************************************************** //
	std::stringstream buffer;
	buffer << inputFile.rdbuf();
	std::string content = buffer.str();

	// ********************************************************************** //
	// Perform the string replacement using replaceOccurrences method.        //
	// This modifies the content string, replacing all occurrences of s1 with //
	// s2.                                                                    //
	// ********************************************************************** //
	replaceOccurrences(content, _s1, _s2);

	// ********************************************************************** //
	// Write the modified content to the output file.                         //
	// This writes the modified content (with all replacements made) to the   //
	// new file.                                                              //
	// ********************************************************************** //
	outputFile << content;

	// ********************************************************************** //
	// Notify the user that the replacement is complete and the output has    //
	// been written to the specified file.                                    //
	// ********************************************************************** //
	std::cout << "Replacement complete. Output written to " << outputFilename << std::endl;
}
