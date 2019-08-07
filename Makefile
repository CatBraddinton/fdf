NAME := fdf
FT := libft.a

CC := clang
FLAGS := -Wall -Wextra -Werror -O3
MLXFLAGS := -lmlx -framework OpenGL -framework AppKit

SRC_DIR := src/
INC_DIR := inc/
LIB_DIR := libft/

SOURCES := 	src/main.c\
			src/utilits.c\
			src/validation.c\
			src/fparser.c\
			src/draw_lines.c\
			src/get_color.c\
			src/change_angles.c\
			src/display_image.c\
			src/inits.c\
			src/key_presses.c\
			src/draw_infomenu.c
OBJECTS := 	main.o utilits.o validation.o fparser.o draw_lines.o get_color.o\
			change_angles.o display_image.o inits.o key_presses.o\
			draw_infomenu.o

LIBFT := $(LIB_DIR)$(FT)
INCLUDES := $(INC_DIR)fdf.h\
			$(INC_DIR)render.h\
			$(INC_DIR)hooks.h

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
