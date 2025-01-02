SRC_DIR = src
OBJ_DIR = obj

MLX_DIR = includes/minilibx-linux/
MLX = $(MLX_DIR)/libmlx_Linux.a

LIBFT_DIR = includes/libft/
LIBFT = $(LIBFT_DIR)/libft.a

# MATH = math
# RENDER = render
NAME = minirt
MAKE = make
# -L flag indicates which directories need to be searched for libraries (.a files)
# -I flad adds a directory that needs to be searched for Header files (.h files)
FLAGS = -Wall -Wextra -Werror -g -I./includes -L./includes/libft
CC = cc
HEADER = minirt.h

# ------------------------------------------------------------------- #
# ------------------------------ Files ------------------------------ #
# ------------------------------------------------------------------- #

# VPATHS =	src/				\
			# src/math/ 		\
			# src/render/
 
SRC = main.c
# SRC	=	$(addsuffix .c, $(SRC_DIR))

# Convert source files to object files in the obj directory
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

# ------------------------------------------------------------------- #
# ------------------------------ Rules ------------------------------ #
# ------------------------------------------------------------------- #
# vpath %.c $(VPATHS)

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(FLAGS) $(LIBFT)

$(OBJ_DIR)/%.o: %.c
	$(CC) -g -Wall -Wextra -Werror -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

clone:
	git clone https://github.com/42Paris/minilibx-linux.git

clean:
	rm -rf $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MLX_DIR) clean

re: fclean all

.PHONY: all clean fclean re clone
