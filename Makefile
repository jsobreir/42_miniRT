OBJ_DIR = obj

MLX_DIR = includes/minilibx-linux
MLX = $(MLX_DIR)/libmlx_Linux.a

LIBFT_DIR = includes/libft
LIBFT = $(LIBFT_DIR)/libft.a

NAME = minirt
MAKE = make
# -L flag indicates which directories need to be searched for libraries (.a files)
# -I flad adds a directory that needs to be searched for Header files (.h files)
FLAGS = -Wall -Wextra -Werror -g -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -I$(MLX_DIR) -lXext -lX11 -lm -lz -I./includes -L$(LIBFT_DIR) -lft
CC = cc

# ------------------------------------------------------------------- #
# ------------------------------ Files ------------------------------ #
# ------------------------------------------------------------------- #

SRC_DIR = main
WINDOWS = hooks free init
MATHS = maths maths1
UTILS = utils
RENDER = render

VPATHS =	src/windows/		\
			src/parser/		\
			src/maths/		\
			src/utils/		\
			src/render/		\

SRC	=	$(addsuffix .c, $(SRC_DIR)) \
		$(addsuffix .c, $(WINDOWS)) \
		$(addsuffix .c, $(PARSER)) \
		$(addsuffix .c, $(MATHS)) \
		$(addsuffix .c, $(UTILS)) \
		$(addsuffix .c, $(RENDER)) \

# Convert source files to object files in the obj directory
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

# ------------------------------------------------------------------- #
# ------------------------------ Rules ------------------------------ #
# ------------------------------------------------------------------- #
vpath %.c $(VPATHS)

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(FLAGS) $(LIBFT)

$(OBJ_DIR)/%.o: %.c $(OBJ_DIR)
	$(CC) -g -Wall -Wextra -Werror -c -I$(MLX_DIR) -I./includes $< -o $@

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
