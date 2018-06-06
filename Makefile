# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbrazas <vbrazas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/28 19:24:02 by vbrazas           #+#    #+#              #
#    Updated: 2018/06/06 06:19:31 by vbrazas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

LIB			=	libft/
LIB_N		=	libft.a

SRC_D		=	src/
SRC			=	$(SRC_D)ft_printf.c \
				$(SRC_D)obtainconvstr.c \
				$(SRC_D)get_argument.c

OBJ_D		=	obj/
OBJ			=	$(addprefix $(OBJ_D), $(SRC:.c=.o))

WORKSPACE	=	$(shell pwd)/
INCLUDE		=	-I $(WORKSPACE) -I $(WORKSPACE)$(LIB)
CFLAGS		=	-Wall -Wextra -Werror
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

test: all
	$(C) -o unitest $(INCLUDE) $(NAME) unitest.c
	./unitest

.PHONY: all clean fclean re test
