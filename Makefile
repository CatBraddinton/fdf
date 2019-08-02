NAME = fdf

CC = clang
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS =

INCS := inc/fdf.h

SRCS := src/main.c src/validation.c src/general.c src/file_parser.c \
		src/render.c src/drawer.c src/mlx_exec.c src/hooks.c\
		src/transform.c


OBJ := 	main.o validation.o general.o file_parser.o render.o drawer.o \
		mlx_exec.o hooks.o transform.o

LIB_DIR := libft
LIBFT := $(LIB_DIR)/libft.a

.PHONY: all dev
dev: $(NAME)

all: $(NAME) clean

$(NAME):$(OBJ)
	$(CC) $(CFLAGS) $(MLXFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

$(OBJ):$(LIBFT) $(SRCS) $(INCS)
	$(CC) $(CFLAGS) -c $(SRCS) -I $(INCS)

$(LIBFT): lib

lib:
	make -C libft/

.PHONY: clean
clean:
	rm -f $(OBJ)
	cd $(LIB_DIR) && $(MAKE) clean

.PHONY: fclean
fclean: clean
	rm -f $(NAME)
	cd $(LIB_DIR) && $(MAKE) fclean

.PHONY: re
re: fclean all
