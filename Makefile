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
	utils4.c \

OBJ	= $(SRC:.c=.o)

LIB 	= libft/libft.a

NAME = ft_ls

all:		$(NAME)

$(NAME):	$(OBJ)
	$(MAKE) -C ./libft
	$(CC) -o $(NAME) $(FLAGS) $(OBJ) $(LIB)

test:
	git clone https://github.com/yyang42/moulitest.git

clean:
	rm -f $(OBJ)
	$(MAKE) -C ./libft clean

fclean:	clean
	rm -f $(NAME)
	$(MAKE) -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re
