# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/14 20:51:10 by obanshee          #+#    #+#              #
#    Updated: 2019/11/05 17:12:25 by obanshee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = fillit_main.c fillit_input.c fillit_transform.c fillit_optimal.c \
	get_next_line.c fillit_map.c re_fillit.c fillit_tetra.c

OBJ = fillit_main.o fillit_input.o fillit_transform.o fillit_optimal.o \
	get_next_line.o fillit_map.o re_fillit.o fillit_tetra.o

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
