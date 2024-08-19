/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:45:06 by dzuiev            #+#    #+#             */
/*   Updated: 2024/08/19 16:04:39 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl {
public:
    Harl();                                      // Default constructor
    ~Harl();                                     // Destructor
    void complain(std::string level);            // Public method to handle complaints based on level

private:
    std::string _levels[4];

    void debug();                                // Private method for DEBUG level complaint
    void info();                                 // Private method for INFO level complaint
    void warning();                              // Private method for WARNING level complaint
    void error();                                // Private method for ERROR level complaint

    typedef void (Harl::*HarlMemFn)();           // Typedef for pointer to member functions
    void callLevel(HarlMemFn func);              // Helper method to call the appropriate level method
};

#endif // HARL_HPP
