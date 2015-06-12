#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/21 02:01:24 by fschuber          #+#    #+#              #
#    Updated: 2015/04/29 17:14:54 by fschuber         ###   ########.fr        #
#                                                                              #
#******************************************************************************#


NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_*.c
INCLUDES = -I includes
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@$(CC) $(INCLUDES) $(CFLAGS) -c $? $(SRC)
	@ar rc $(NAME) $? $(OBJ)
	@ranlib $(NAME)
	@echo "\033[32mBuilt library.\033[0m"

clean:
	@/bin/rm -f $(OBJ)
	@echo "\033[32mCleaned up object files.\033[0m"

fclean: clean
	@/bin/rm $(NAME)
	@echo "\033[32mCleaned up compiled files.\033[0m"

re: fclean all

.PHONY: all clean fclean re
