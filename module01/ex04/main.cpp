/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:00:51 by dzuiev            #+#    #+#             */
/*   Updated: 2024/08/16 15:27:39 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ************************************************************************** //
//                                                                            //
// Project: SedLikeReplacer                                                   //
//                                                                            //
// Description:                                                               //
// SedLikeReplacer is a C++ program designed to mimic the basic functionality //
// of the Unix/Linux command-line tool `sed`. The name "sed" stands for       //
// "stream editor," a tool widely used for parsing and transforming text      //
// using simple commands. SedLikeReplacer focuses on one of the most common   //
// features of `sed`: replacing occurrences of a specific string within a     //
// text file with another string.                                             //
//                                                                            //
// The program reads the content of an input file, replaces all occurrences   //
// of a target string (s1) with a replacement string (s2), and writes the     //
// modified content to a new file with the ".replace" extension. This         //
// implementation mimics the command `sed 's/s1/s2/g' inputfile > outputfile`,//
// but is done in C++ without using the `sed` utility or the `replace`        //
// function from the C++ Standard Library.                                    //
//                                                                            //
// Key Features:                                                              //
// - Handles large text files by reading the entire content into memory and   //
//   performing the replacements in one pass.                                 //
// - Creates an output file with the same content as the input file, but with //
//   all specified replacements made.                                         //
// - Ensures that the input string (s1) is not empty before performing        //
//   replacements, as an empty string would lead to undefined behavior.       //
//                                                                            //
// Why "Sed is for losers"?                                                   //
// The project is humorously named "Sed is for losers" to emphasize that the  //
// task is to manually implement a feature that could easily be achieved      //
// using `sed`, thereby encouraging a deeper understanding of string and file //
// manipulation in C++. This project is a learning exercise, pushing the      //
// boundaries of basic text processing without relying on high-level          //
// utilities.                                                                 //
//                                                                            //
// ************************************************************************** //

#include "SedLikeReplacer.hpp"
#include <iostream>

// ************************************************************************* //
// The main function is the entry point of the program. It handles           //
// command-line arguments, initializes a SedLikeReplacer object, and         //
// triggers the replacement operation.                                       //
// ************************************************************************* //
int main(int argc, char* argv[]) {
	// ********************************************************************** //
	// Check that the program receives exactly three arguments: the filename, //
	// the search string (s1), and the replacement string (s2). If the number //
	// of arguments is incorrect, display usage instructions and exit.        //
	// ********************************************************************** //
	if (argc != 4) {
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	// ********************************************************************** //
	// Extract the command-line arguments into std::string variables.         //
	// filename: The name of the file to process.                             //
	// s1: The string to be replaced.                                         //
	// s2: The string to replace s1.                                          //
	// ********************************************************************** //
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	// ********************************************************************** //
	// Ensure that the search string (s1) is not empty. If it is, display an  //
	// error message and exit the program.                                    //
	// ********************************************************************** //
	if (s1.empty()) {
		std::cerr << "Error: The search string (s1) cannot be empty." << std::endl;
		return 1;
	}

	// ********************************************************************** //
	// Create a SedLikeReplacer object with the provided filename, s1, and s2. //
	// Then, call the replaceInFile method to perform the replacement operation.//
	// ********************************************************************** //
	SedLikeReplacer replacer(filename, s1, s2);
	replacer.replaceInFile();

	return 0;  // Return 0 to indicate successful execution
}
