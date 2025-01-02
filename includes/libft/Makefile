PRINTF_DIR = printf
PRINTF = $(PRINTF_DIR)/printf.a

SRC	 =	ft_isalnum.c ft_isprint.c ft_memcmp.c  ft_putchar_fd.c ft_split.c 	\
	ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c 			\
	ft_itoa.c ft_memcpy.c  ft_putendl_fd.c ft_strchr.c  ft_strlcpy.c 		\
	ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c 			 		\
	ft_memmove.c ft_putnbr_fd.c  ft_strdup.c  ft_strlen.c  ft_strrchr.c 	\
	ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c  		\
	ft_putstr_fd.c  ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_striteri.c	\
	get_next_line/get_next_line_bonus.c get_next_line/get_next_line_utils_bonus.c
OBJ = $(SRC:.c=.o)

BONUS = ft_lstnew.c	ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	ft_lstclear.c ft_lstdelone.c ft_lstadd_back.c ft_lstiter.c \
	ft_lstmap.c 
BONUS_OBJ = $(BONUS:.c=.o)
NAME = libft.a
FLAGS = -Wall -Wextra -Werror
CC = cc
HEADER = libft.h

all: $(NAME)

# Need to link both the objects and the printf objects to the libft.a archive
$(NAME): $(PRINTF) $(OBJ)
	ar rcs $(NAME) $(OBJ)
	ar rcs $(NAME) $(PRINTF_DIR)/*.o

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

main: all
	$(CC) $(FLAGS) -L. $(NAME)

clean:
	rm -rf $(OBJ) $(BONUS_OBJ)
	rm -rf *.o
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME) a.out
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

bonus: $(OBJ) $(BONUS_OBJ)
	ar rcs $(NAME) $(OBJ) $(BONUS_OBJ)

.PHONY:			all clean fclean re bonus