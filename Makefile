# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: arommers <arommers@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/11/08 14:41:53 by arommers      #+#    #+#                  #
#    Updated: 2022/11/15 14:51:48 by arommers      ########   odam.nl          #
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
	@echo "Compiled with $(GREEN)$(CFLAGS)$(RESET)"
	@cp $(LIBFT) $(NAME)
	@ar -rcs $@ $(OBJ) $(HEAD)
	@echo "$(BLUE)-------------------------------------------------------------$(NAME) = NOW READY FOR USE!$(RESET)"

$(LIBFT):
	@$(MAKE) -C ./Libft
	

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $^  
	@echo "$(YELLOW) $^ $(RESET)	Compiling"

start:
	@echo "$(YELLOW)---------------------\nStarting $(PROJECT)\n-------------------$(RESET)"

clean:
	@$(MAKE) clean -C ./Libft
	@rm -f $(OBJ)
	@echo "$(YELLOW) $@ $(PROJECT) $(RESET) done."

fclean: clean
	@$(MAKE) fclean -C ./Libft
	@rm -f $(NAME)
	@echo "$(YELLOW) $@ $(PROJECT) $(RESET) done."

re: fclean all

.PHONY: all clean fclean re