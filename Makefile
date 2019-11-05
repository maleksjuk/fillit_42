# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/14 20:51:10 by obanshee          #+#    #+#              #
#    Updated: 2019/11/05 18:31:14 by obanshee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = fillit_main.c fillit_input.c fillit_transform.c fillit_optimal.c \
	get_next_line.c fillit_map.c re_fillit.c fillit_tetra.c

OBJ = fillit_main.o fillit_input.o fillit_transform.o fillit_optimal.o \
	get_next_line.o fillit_map.o re_fillit.o fillit_tetra.o

NAME_lib = libft.a

SRC_lib_help = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
	ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
	ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
	ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	ft_isprint.c ft_toupper.c ft_tolower.c \
	ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c \
	ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
	ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c \
	ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

SRC_lib = $(SRC_lib_help:%.c=libft/%.c)

OBJ_lib = $(SRC_lib:.c=.o)

all: $(NAME_lib) $(NAME)

$(SRC_lib):
	@gcc -Wall -Wextra -Werror -c $(SRC) -I libft.h

$(NAME_lib): $(OBJ_lib)
	@ar rc libft/$(NAME_lib) $(OBJ_lib)
	@ranlib libft/$(NAME_lib)

$(OBJ_lib): $(SRC_lib)

$(SRC):
	@gcc -Wall -Wextra -Werror -g -c $(SRC) -I fillit.h

$(NAME): $(OBJ)
	gcc -Wall -Wextra -Werror $(OBJ) -o $(NAME) -L libft -lft

$(OBJ): $(SRC)

clean: lib_clean
	@rm -f $(OBJ)

lib_clean:
	@rm -f $(OBJ_lib)

fclean: clean lib_fclean
	@rm -f $(NAME)

lib_fclean:
	@rm -f libft/$(NAME_lib)

re: fclean all
