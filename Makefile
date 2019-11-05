# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/14 20:51:10 by obanshee          #+#    #+#              #
#    Updated: 2019/11/05 21:22:48 by obanshee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = fillit_main.c fillit_input.c fillit_transform.c fillit_optimal.c \
	get_next_line.c fillit_map.c re_fillit.c fillit_tetra.c \
	ft_strlen.c ft_strclr.c ft_strequ.c ft_putendl.c ft_strdup.c \
	ft_strchr.c ft_strjoin.c ft_strnew.c ft_strsub.c

OBJ = $(SRC:.c=.o)

all:$(NAME) 

$(NAME): $(OBJ)
	gcc -Wall -Wextra -Werror $(OBJ) -o $(NAME)

%.o: %.c
	@gcc -Wall -Wextra -Werror -g -c $(SRC) -I includes/

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
