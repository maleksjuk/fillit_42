# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/14 20:51:10 by obanshee          #+#    #+#              #
#    Updated: 2019/10/31 18:03:40 by obanshee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = start

SRC = fillit.c fillit_input.c fillit_transform.c fillit_optimal.c \
	get_next_line.c fillit_map.c re_fillit.c
	#fillit_solve.c

OBJ = fillit.o fillit_input.o fillit_transform.o fillit_optimal.o \
	get_next_line.o fillit_map.o re_fillit.o
	#fillit_solve.o

all: $(NAME)

$(SRC):
	@gcc -Wall -Wextra -Werror -g -c $(SRC) -I fillit.h

$(NAME): $(OBJ)
	gcc -Wall -Wextra -Werror $(OBJ) -g -o $(NAME) -L libft -lft

$(OBJ): $(SRC)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
