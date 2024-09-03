# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/30 12:48:24 by dzuiev            #+#    #+#              #
#    Updated: 2024/09/03 10:39:53 by dzuiev           ###   ########.fr        #
#                                                                              #
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
NAME = FragTrap

DEBUG = -g
CXX_STANDARD = -std=c++98

# **************************************************************************** #
# Initialize OPTS to an empty string
OPTS =

# Conditionally add DEBUG to OPTS
ifdef DEBUG
    OPTS += $(DEBUG)
endif

# Conditionally add CXX_STANDARD to OPTS
ifdef CXX_STANDARD
    OPTS += $(CXX_STANDARD)
endif
# **************************************************************************** #
RM = rm -rf

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror $(OPTS)
INCLUDES = -I.

SRC_DIR = .
OBJ_DIR = .obj
# **************************************************************************** #

# **************************************************************************** #
# Source and Object files
FILES = main ClapTrap ScavTrap FragTrap
SRC = $(addprefix $(SRC_DIR)/, $(FILES:=.cpp))
OBJ = $(addprefix $(OBJ_DIR)/, $(FILES:=.o))
# **************************************************************************** #

# **************************************************************************** #
all: $(NAME)

# Linking the executable
$(NAME): $(OBJ)
	@$(CXX) $(OBJ) -o $@
	@echo "$(GREEN)$(NAME) compiled$(RESET)"

# -o $@ - output file name $(NAME), $@ = $(NAME)
# **************************************************************************** #

# **************************************************************************** #
# Rules for compiling source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# -c $< -o $@ - compile source file $< into object file $@,
# $< = source file, $@ = object file
# **************************************************************************** #

# **************************************************************************** #
# Cleaning up
clean:
	@ if [ -d $(OBJ_DIR) ]; then \
		$(RM) $(OBJ_DIR); \
		echo "$(YELLOW)$(NAME) object files removed$(RESET)"; \
	fi

# Full cleaning
fclean: clean
	@ if [ -f $(NAME) ]; then \
		$(RM) $(NAME); \
		echo "$(RED)$(NAME) removed$(RESET)"; \
	fi
# rm -rf - remove the directory with all its content
# -r - remove directories and their contents recursively
# -f - ignore nonexistent files and arguments, never prompt

# Rebuild everything
re: fclean all

# **************************************************************************** #
# Phony targets
.PHONY: all clean fclean re

# .PHONY is a directive to indicate that the following targets are not actual files
# **************************************************************************** #
