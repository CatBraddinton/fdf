NAME := fdf
FT := libft.a

CC := clang
FLAGS := -Wall -Wextra -Werror -fsanitize=address -g
MLXFLAGS := -lmlx -framework OpenGL -framework AppKit

SRC_DIR := src/
INC_DIR := inc/
OBJ_DIR := obj/
LIB_DIR := libft/

SOURCES := 	src/main.c\
			src/utilits.c\
			src/validation.c\
			src/fparser.c\
			src/render.c\
			src/draw_lines.c\
			src/get_color.c\
			src/transform.c\
			src/draw_straight_line.c\
			src/display_image.c\

OBJECTS := 	main.o utilits.o validation.o fparser.o render.o draw_lines.o\
			get_color.o transform.o draw_straight_line.o display_image.o

LIBFT := $(LIB_DIR)$(FT)
INCLUDES := $(INC_DIR)fdf.h


.PHONY: all  lib clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
	$(CC) $(FLAGS) $(MLXFLAGS) -o $(NAME) $(OBJECTS) $(LIBFT)

$(OBJECTS): $(SOURCES) $(INCLUDES)
	$(CC) $(FLAGS) -c $(SOURCES) -I $(INC_DIR)

$(LIBFT): lib

lib:
	make -C $(LIB_DIR)

clean:
	rm -f $(OBJECTS)
	make fclean -C $(LIB_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIB_DIR)

re: fclean all
