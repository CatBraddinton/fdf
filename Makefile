# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdudko <kdudko@student.unit.ua>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/08 18:22:21 by kdudko            #+#    #+#              #
#    Updated: 2019/08/08 18:22:23 by kdudko           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fdf
FT := libft.a

CC := clang
FLAGS := -Wall -Wextra -Werror
MLXFLAGS := -lmlx -framework OpenGL -framework AppKit

SRC_DIR := src/
INC_DIR := inc/
LIB_DIR := libft/

SOURCES := 	src/main.c\
			src/utilits.c\
			src/validation.c\
			src/fparser.c\
			src/draw_lines.c\
			src/change_angles.c\
			src/display_image.c\
			src/inits.c\
			src/key_presses.c\
			src/draw_infomenu.c\
			src/colorize_it.c
OBJECTS := 	main.o utilits.o validation.o fparser.o draw_lines.o\
			change_angles.o display_image.o inits.o key_presses.o\
			draw_infomenu.o colorize_it.o

LIBFT := $(LIB_DIR)$(FT)
INCLUDES := $(INC_DIR)fdf.h\
			$(INC_DIR)render.h\
			$(INC_DIR)hooks.h\
			$(INC_DIR)colorize_it.h\
			$(INC_DIR)hooks.h

.PHONY: all  lib clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
	$(CC) $(FLAGS) $(MLXFLAGS) -o $(NAME) $(OBJECTS) $(LIBFT)

$(OBJECTS): $(SOURCES) $(INCLUDES)
	$(CC) $(FLAGS) -c $(SOURCES) -I $(INCLUDES)

$(LIBFT): lib

lib:
	make -C $(LIB_DIR)

clean:
	rm -f $(OBJECTS) inc/*.gch
	make fclean -C $(LIB_DIR)


fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIB_DIR)

re: fclean all
