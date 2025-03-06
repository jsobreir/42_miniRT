OBJ_DIR = obj

MLX_DIR = includes/minilibx-linux
MLX = $(MLX_DIR)/libmlx_Linux.a

LIBFT_DIR = includes/libft
LIBFT = $(LIBFT_DIR)/libft.a

NAME = minirt
MAKE = make
# -L flag indicates which directories need to be searched for libraries (.a files)
# -I flad adds a directory that needs to be searched for Header files (.h files)
FLAGS = -g -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -I$(MLX_DIR) -lXext -lX11 -lm -lz -I./includes -L$(LIBFT_DIR) -lft -fsanitize=address
CC = cc

# ------------------------------------------------------------------- #
# ------------------------------ Files ------------------------------ #
# ------------------------------------------------------------------- #

SRC_DIR = main
WINDOWS = hooks free init
MATHS = maths maths1 maths2 matrix matrix_transform matrix2 matrix3
UTILS = utils split
RENDER = render render2 colors colors2
INTERSECTIONS = intersections intersections2 intersections_list cylinder
CAMERA = camera
PARSER = parse_file fill_data_structs fill_objects

VPATHS =	src/windows/		\
			src/parser/		\
			src/maths/		\
			src/utils/		\
			src/render/		\
			src/intersections/	\
			src/camera/	\

SRC	=	$(addsuffix .c, $(SRC_DIR)) \
		$(addsuffix .c, $(WINDOWS)) \
		$(addsuffix .c, $(PARSER)) \
		$(addsuffix .c, $(MATHS)) \
		$(addsuffix .c, $(UTILS)) \
		$(addsuffix .c, $(RENDER)) \
		$(addsuffix .c, $(INTERSECTIONS)) \
		$(addsuffix .c, $(CAMERA)) \

# Convert source files to object files in the obj directory
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

# ------------------------------------------------------------------- #
# ------------------------------ Rules ------------------------------ #
# ------------------------------------------------------------------- #
vpath %.c $(VPATHS)

all: $(OBJ_DIR) $(LIBFT_A)  $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ) $(OBJ_DIR) $(LIBFT) $(MLX)
	$(CC) $(OBJ) -o $(NAME) $(FLAGS) $(LIBFT)

$(OBJ_DIR)/%.o: %.c
	$(CC) -Wall -Wextra -Werror -g -c -I$(MLX_DIR) -I./includes $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

clone:
	git clone https://github.com/42Paris/minilibx-linux.git

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MLX_DIR) fclean

re: fclean all

.PHONY: all clean fclean re clone
