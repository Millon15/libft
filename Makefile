# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/28 19:24:02 by vbrazas           #+#    #+#              #
#    Updated: 2018/07/21 19:23:53 by vbrazas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

LIB			=	libft/
LIB_N		=	libft.a

SRC_D		=	src/
SRC			=	$(SRC_D)ft_printf.c \
				$(SRC_D)parseconvstr.c \
				$(SRC_D)fill_fl_struct.c \
				$(SRC_D)get_argument.c \
				$(SRC_D)indent_and_print_integer.c \
				$(SRC_D)indent_and_print_char.c \
				$(SRC_D)indent_and_print_string.c \
				$(SRC_D)indent_and_print_wide_string.c \
				$(SRC_D)print_the_bit.c

OBJ_D		=	obj/
OBJ			=	$(addprefix $(OBJ_D), $(SRC:.c=.o))

INCLUDE		=	-I includes/
CFLAGS		=	-Wall -Wextra -Werror
C			=	clang

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB)
	cp $(LIB)$(LIB_N) $(NAME)
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
	$(C) -o unittest.out $(INCLUDE) $(NAME) unittest.c
	./unittest.out
	rm -f unittest.out

.PHONY: all clean fclean re test shortfclean shortre
