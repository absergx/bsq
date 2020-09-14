# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: memilio <memilio@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/22 12:32:44 by tbaela            #+#    #+#              #
#    Updated: 2020/02/26 11:11:14 by memilio          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
SRC1 = *.c
SRC2 = ./fncs/*.c

all:
	gcc -Wall -Wextra -Werror $(SRC1) $(SRC2) -o $(NAME) 
clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
