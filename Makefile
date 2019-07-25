NAME = fdf

CC = clang
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

INC_DIR = inc/
INCS := $(addprefix $(INC_DIR), fdf.h)

SRC_DIR = src/
SRCS := $(addprefix $(SRC_DIR), main.c structs_inits.c validation.c)

OBJ := main.o structs_inits.o validation.o

LIB_DIR := libft
LIBFT := $(LIB_DIR)/libft.a

.PHONY: all dev
dev: $(NAME)

all: $(NAME) clean

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(MLXFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

$(OBJ): $(SRCS) $(INCS)
	$(CC) $(CFLAGS) -c $(SRCS) -I $(INCS)

$(LIBFT):
	cd $(LIB_DIR) && $(MAKE)
	

.PHONY: clean
clean:
	rm -f $(OBJ)
	cd $(LIB_DIR) && $(MAKE) clean

.PHONY: fclean
fclean: clean
	rm $(NAME) $(LIBFT)
	cd $(LIB_DIR) && $(MAKE) fclean

.PHONY: re
re: fclean all