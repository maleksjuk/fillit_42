# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/14 20:51:10 by obanshee          #+#    #+#              #
#    Updated: 2019/11/06 22:34:43 by chbeast          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = fillit_main.c fillit_input.c fillit_transform.c fillit_optimal.c \
	fillit_map.c re_fillit.c fillit_tetra.c \
	ft_strlen.c ft_strnew.c ft_putendl.c ft_bzero.c

OBJ = $(SRC:.c=.o)

all:$(NAME) 

$(NAME): $(OBJ)
	@gcc -Wall -Wextra -Werror $(OBJ) -o $(NAME)

%.o: %.c
	@gcc -Wall -Wextra -Werror -ggdb3 -c $(SRC) -I includes/

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
