CC = gcc

FLAGS = -Wall -Wextra -Werror -g

SRC =	ft_ls.c \
	list_management1.c \
	list_management2.c \
	print_long.c \
	print_lld.c \
	handle_args.c \
	utils.c \
	utils2.c \
	utils3.c \

OBJ	= $(SRC:.c=.o)

LIB 	= libft/libft.a

NAME = ft_ls

all:		$(NAME)

$(NAME):	$(OBJ)
	$(MAKE) -C ./libft
	$(CC) -o $(NAME) $(FLAGS) $(OBJ) $(LIB)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
