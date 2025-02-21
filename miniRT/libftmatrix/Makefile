# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndo-vale <ndo-vale@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/31 09:49:03 by ndo-vale          #+#    #+#              #
#    Updated: 2024/09/02 09:48:12 by ndo-vale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -g -Wall -Werror -Wextra -c -O3
NAME	= libftmatrix.a
SRCS	= matrixcmp.c tuplecmp.c get_from_matrix2.c get_from_matrix3.c get_from_matrix4.c \
			matrix_factory.c matrix4_operations.c transform_matrices1.c transform_matrices2.c \
			tup4_types.c tuple_factory.c tuple_operations1.c tuple_operations2.c \
			print_tuple.c print_matrix.c
OBJS	= $(SRCS:.c=.o)

.o:.c
	$(CC) $(CFLAGS) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf libftmatrix.a

re: fclean
	$(MAKE) all
