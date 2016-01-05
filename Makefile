# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amineau <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/23 15:32:27 by amineau           #+#    #+#              #
#    Updated: 2015/12/15 14:47:39 by amineau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fillit

CC=gcc

FLAGS=-Wall -Werror -Wextra

SRC=ft_create.c ft_move_inside.c ft_error.c ft_read.c ft_algo.c ft_lst.c \
	ft_tabf.c ft_checker.c main.c

LIB=lft

OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) -c $(SRC)
	$(CC) $(OBJ) -L. -$(LIB) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
