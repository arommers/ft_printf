# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: arommers <arommers@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/11/08 14:41:53 by arommers      #+#    #+#                  #
#    Updated: 2022/11/14 11:38:12 by arommers      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
LIBFT = ./Libft/libft.a
INCLUDE = -I./Include
SRC = ft_printf.c ft_write.c ft_format_spec.c
OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) all -C ./Libft
	cp libft/libft.a $(NAME)
	$(CC) $(CFLAGS) $(INCLUDE) $(SRC)
	ar -rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	$(MAKE) clean -C ./Libft
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C ./Libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re