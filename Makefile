NAME = fdf

CC = clang
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

INCS := inc/fdf.h

SRCS := src/main.c src/validation.c src/errors.c

OBJ := main.o validation.o errors.o

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
