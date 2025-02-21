# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joamonte <joamonte@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/27 14:30:34 by ndo-vale          #+#    #+#              #
#    Updated: 2024/09/17 16:33:28 by joamonte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= miniRT
CC			= cc
CFLAGS		= -Wall -Werror -Wextra -g
IFLAGS		= -I./ 
LFLAGS		= -lm -lXext -lX11 -O3
RM			= rm -rf

PREP_DIRS	= prep
SRC_DIR		= src/
OBJ_DIR		= obj/

SRCS		= $(addprefix $(SRC_DIR), main.c clean_exit.c color.c plane.c \
					lst_utils.c ray.c sphere.c intersection.c light.c world.c \
					cylinder.c cylinder_caps.c lstadd_xs_sorted.c camera.c \
					get_target_rotation.c parser.c parse_obj.c parse_utils.c validations.c \
					irl_transform.c parse_comps.c)

OBJS		= $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a
LIBFTMATRIX_DIR = libftmatrix
LIBFTMATRIX	= $(LIBFTMATRIX_DIR)/libftmatrix.a
MLX_DIR = ./mlx_linux
MLX = $(MLX_DIR)/libmlx.a
LIBS = $(LIBFT) $(LIBFTMATRIX), $(MLX)

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p obj

$(LIBFT):
	@echo "Compiling LIBFT..."
	make -s -C $(LIBFT_DIR)

$(LIBFTMATRIX):
	@echo "Compiling LIBFTMATRIX..."
	make -s -C $(LIBFTMATRIX_DIR)

$(MLX):
	@echo "compiling MLX..."
	make -s -C $(MLX_DIR)

$(NAME): $(OBJS) $(LIBFT) $(LIBFTMATRIX) $(MLX)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(IFLAGS) $(LIBFT) $(LIBFTMATRIX) $(MLX) $(LFLAGS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	make -s clean -C $(LIBFT_DIR)
	make -s clean -C $(LIBFTMATRIX_DIR)
	make clean -C $(MLX_DIR)
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(LIBFT)
	$(RM) $(LIBFTMATRIX)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re