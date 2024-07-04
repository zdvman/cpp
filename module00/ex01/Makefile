# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/04 11:34:53 by dzuiev            #+#    #+#              #
#    Updated: 2024/07/04 11:36:11 by dzuiev           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# Colors for messages
GREEN=\033[0;32m
YELLOW=\033[0;33m
RED=\033[0;31m
BLUE=\033[0;34m
RESET=\033[0m
# **************************************************************************** #

# **************************************************************************** #
# Basic Configurations
NAME = megaphone # Name of the executable file

# BONUS_NAME = _bonus # Name of the executable file for bonus part
CXX = c++ # Compiler
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g # Flags for compiler
# **************************************************************************** #

# **************************************************************************** #
# Source and Object files
SRC = megaphone.cpp
OBJ = $(SRC:%.cpp=%.o) # All object files in current directory
# **************************************************************************** #

# **************************************************************************** #
all: $(NAME) # Main target

# Linking the executable
$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) -o $@ $(OBJ)
	@echo "$(GREEN)$(NAME) compiled$(RESET)"

# -o $@ - output file name $(NAME), $@ = $(NAME)
# **************************************************************************** #

# **************************************************************************** #
# Rules for compiling source files into object files
%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# -c $< -o $@ - compile source file $< into object file $@,
# $< = source file, $@ = object file
# **************************************************************************** #

# **************************************************************************** #
# Cleaning up
clean:
	@rm -rf $(OBJ)
	@echo "$(YELLOW)$(NAME) object files removed$(RESET)"

# Full cleaning
fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)$(NAME) removed$(RESET)"
# rm -rf - remove the directory with all its content
# -r - remove directories and their contents recursively
# -f - ignore nonexistent files and arguments, never prompt

# Rebuild everything
re: fclean all

# **************************************************************************** #
# Phony targets
.PHONY: all clean fclean re

# .PHONY is 
# **************************************************************************** #
