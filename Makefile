# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: arommers <arommers@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/11/08 14:41:53 by arommers      #+#    #+#                  #
#    Updated: 2022/11/16 10:32:43 by arommers      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

PROJECT = Printf
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
LIBFT = ./Libft/libft.a
HEAD = ./Include/ft_printf.h
INCLUDE = -I./Include
SRC = ft_printf.c							\
		./Sources/ft_print_hex.c			\
		./Sources/ft_print_ptr.c			\
		./Sources/ft_print_unsigned.c		\
		./Sources/ft_print_various.c		\

OBJ = $(SRC:.c=.o)

GREEN	= \x1b[32m
YELLOW	= \x1b[33m
RESET	= \x1b[0m
BLUE	= \x1b[34m

all: $(NAME)

$(NAME): $(LIBFT) start $(OBJ) $(HEAD)
	@echo "Compiled with $(BLUE)$(CFLAGS)$(RESET)"
	@cp $(LIBFT) $(NAME)
	@ar -rcs $@ $(OBJ) $(HEAD)
	@echo "$(YELLOW)-------------------------------------------\n     $(NAME) = NOW READY FOR USE!\n-------------------------------------------$(RESET)"

$(LIBFT):
	@$(MAKE) -C ./Libft
	

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $^  
	@echo "Compilation Done $(YELLOW) $^ $(RESET)"

start:
	@echo "$(YELLOW)------------------------------\n	Starting $(PROJECT)\n------------------------------$(RESET)"

clean:
	@$(MAKE) clean -C ./Libft
	@rm -f $(OBJ)
	@echo "Cleaning Done $(GREEN) $@ $(PROJECT) $(RESET)"

fclean: clean
	@$(MAKE) fclean -C ./Libft
	@rm -f $(NAME)
	@echo "Cleaning Done $(GREEN) $@ $(PROJECT) $(RESET)"

re: fclean all

.PHONY: all clean fclean re