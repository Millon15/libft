# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/28 19:24:02 by vbrazas           #+#    #+#              #
#    Updated: 2018/01/08 16:09:14 by vbrazas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
SRC		=	help.c \
			ft_printf.c \
			fill_flags.c \
			src/put_s.c \
			src/put_di.c \
			src/put_oux.c \
			print_fl.c

OBJ		=	$(SRC:.c=.o)
CFLAGS	=	
# CFLAGS	=	-Wall -Wextra -Werror


all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $^
	ranlib $(NAME)

%.o: %.c
	gcc $(CFLAGS) -o $@ -c $<

test:
	gcc $(CFLAGS) -o ft_printf.out $(NAME) main.c
	./ft_printf.out

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
