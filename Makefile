# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/28 19:24:02 by vbrazas           #+#    #+#              #
#    Updated: 2018/01/06 15:44:45 by vbrazas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
SRC		=	help.c \
			ft_printf.c \
			src/put_s.c \
			src/put_di.c
			# print_fl.c

OBJ		=	$(SRC:.c=.o)
CFLAGS	=	
# CFLAGS	=	-Wall -Wextra -Werror


all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $^
	ranlib $(NAME)

%.o: %.c
	gcc $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
