# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/28 19:24:02 by vbrazas           #+#    #+#              #
#    Updated: 2018/06/07 23:14:27 by vbrazas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

LIB			=	libft/
LIB_N		=	libft.a

SRC_D		=	src/
SRC			=	$(SRC_D)ft_printf.c \
				$(SRC_D)obtainconvstr.c \
				$(SRC_D)get_argument.c \
				$(SRC_D)indent_argument.c \
				$(SRC_D)indent_digit.c

OBJ_D		=	obj/
OBJ			=	$(addprefix $(OBJ_D), $(SRC:.c=.o))

WORKSPACE	=	$(shell pwd)/
INCLUDE		=	-I $(WORKSPACE)includes/ -I $(WORKSPACE)$(LIB)
CFLAGS		=	#`-Wall -Wextra -Werror
C			=	clang

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB)
	mv $(LIB)$(LIB_N) $(NAME)
	ar -r $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ): | $(OBJ_D)

$(OBJ_D):
	mkdir -p $(OBJ_D)$(SRC_D)

$(OBJ_D)%.o: %.c
	$(C) $(CFLAGS) $(INCLUDE) -o $@ -c $<

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)
	rm -rf $(OBJ_D)

re: fclean all

shortfclean:
	rm -rf $(OBJ_D)
	rm -f $(NAME)

shortre: shortfclean all

test: shortre
	rm -f unitest.out
	$(C) -o unitest.out $(INCLUDE) $(NAME) unitest.c
	./unitest.out

.PHONY: all clean fclean re test shortfclean shortre
