# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dberehov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/08 11:31:38 by dberehov          #+#    #+#              #
#    Updated: 2023/08/08 11:31:40 by dberehov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = cc
FLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -lXext -lX11 -lm -lbsd
MAKEFLAG = --no-print-directory

# Colours
BGRED 	= \033[0;41m
BGREEN 	= \033[0;42m
BGYELL 	= \033[0;43m
BGBLUE 	= \033[0;44m
BGPURP 	= \033[0;45m
BGCYAN 	= \033[0;46m
NC 		= \033[0m

# Executable name
NAME = so_long

# Required Libraries
LIBFT = libft/libft.a
MLX = minilibx-linux/libmlx.a

# Project files
SOURCES = main.c sources/error.c sources/map_handling.c sources/map_build.c \
			sources/display.c sources/movement.c sources/map_check.c        \
			sources/map_utils.c
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT) $(MLX)
	@printf "$(BGCYAN) Compiling so_long... $(NC)\n"
	$(CC) $(OBJECTS) $(LIBFT) -L minilibx-linux $(MLX_FLAGS) $(MLX) -o $(NAME)
	@printf "$(BGREEN) Compilation finished!! $(NC)\n"

$(OBJECTS_DIR): sources/%.c get_next_line/%.c
	@printf "$(BGBLUE) Creating .o files... $(NC)\n"
	mkdir -p $(@D)
	$(CC) -I includes $(FLAGS) -c $< -o $@

$(LIBFT):
	@printf "$(BGCYAN) Compiling Libft... $(NC)\n"
	@$(MAKE) $(MAKEFLAG) -C libft/

$(MLX):
	@printf "$(BGCYAN) Compiling MiniLibX... $(NC)\n"
	@$(MAKE) $(MAKEFLAG) -sC minilibx-linux/

clean:
	@printf "$(BGYELL) Deleting created objects... $(NC)\n"
	rm -f $(OBJECTS)
	@make --no-print-directory clean -C libft

fclean: clean
	@printf "$(BGYELL) Deleting executables... $(NC)\n"
	rm -f $(NAME)
	rm -f $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
