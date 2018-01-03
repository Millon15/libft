# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/28 19:24:02 by vbrazas           #+#    #+#              #
#    Updated: 2018/01/03 19:21:22 by vbrazas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_printf
SRC		=	main.c \
			help.c \
			src/put_s.c \
			src/put_d.c \
			src/put_u.c \
			src/put_o.c \
			src/put_x.c \
			src/put_big_x.c \
			
OBJ		=	$(SRC:.c=.o)
CFLAGS	=	
# CFLAGS	=	-Wall -Wextra -Werror


all: $(NAME)

$(NAME): $(OBJ)
	gcc $(CFLAGS) -o $(NAME) $^

%.o: %.c
	gcc $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
