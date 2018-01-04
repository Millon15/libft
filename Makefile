# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/28 19:24:02 by vbrazas           #+#    #+#              #
#    Updated: 2018/01/04 15:53:41 by vbrazas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
SRC		=	help.c \
			ft_printf.c \
			src/put_s.c \
			src/put_d.c \
			src/put_u.c \
			src/put_o.c \
			src/put_x.c \
			src/put_big_x.c \
			print_fl.c \

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
