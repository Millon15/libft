
SRC	:=			ft_strlen.c \
				ft_bzero.c \
				ft_memccpy.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memset.c \
				ft_strcpy.c \
				ft_strdup.c \
				ft_strncpy.c \
				ft_strstr.c \
				ft_strnstr.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strcat.c \
				ft_strcmp.c \
				ft_strncmp.c \
				ft_atoi.c \
				ft_strcat.c \
				ft_strncat.c \
				ft_strlcat.c \
				ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_memalloc.c \
				ft_memdel.c \
				ft_strnew.c \
				ft_strdel.c \
				ft_strclr.c \
				ft_striter.c \
				ft_striteri.c \
				ft_strmap.c \
				ft_strmapi.c \
				ft_strequ.c \
				ft_strnequ.c \
				ft_strsub.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_strsplit.c \
				ft_itoa.c \
				ft_itoa_base.c \
				ft_putchar.c \
				ft_putstr.c \
				ft_putendl.c \
				ft_putnbr.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_lstnew.c \
				ft_lstdelone.c \
				ft_lstdel.c \
				ft_lstadd.c \
				ft_lstiter.c \
				ft_lstmap.c \
				ft_swap.c \
				ft_range.c \
				ft_foreach.c \
				ft_pow.c \
				ft_root.c \
				ft_fcd.c \
				ft_iswhitespace.c \
				ft_atoi_base.c \
				ft_atou_base.c \
				ft_utoa_base.c \
				ft_strnjoin.c \
				ft_putnstr.c \
				ft_putnstr_fd.c \
				ft_putnendl.c \
				ft_putnendl_fd.c \
				get_next_line.c \
				ft_module.c \
				checkintstr.c \
				ft_islowercase.c \
				ft_isuppercase.c \
				ft_itoc.c \
				ft_freestrjoin.c \
				ft_tdafree.c \
				ft_bfree.c


PRINTFSRCS	:=	ft_printf.c \
				parseconvstr.c \
				fill_fl_struct.c \
				get_argument.c \
				indent_and_print_integer.c \
				indent_and_print_char.c \
				indent_and_print_string.c \
				indent_and_print_wide_string.c \
				print_the_bit.c

NAME :=			libft.a

OBJ_PATH :=		.obj/
PRINTF_PATH :=	ft_printf/
PRINTF_SPATH :=	ft_printf/src/

CC :=			clang
CFLAGS :=		-Wall -Werror -Wextra -O3
IFLAGS :=		-I $(PRINTF_PATH)includes/ -I .

SRCS +=			$(SRC)
SRCS +=			$(addprefix $(PRINTF_SPATH), $(PRINTFSRCS))
OBJS :=			$(addprefix $(OBJ_PATH), $(SRCS:%.c=%.o))


all: $(NAME)

$(NAME):		$(OBJ_PATH) $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)$(PRINTF_SPATH)
$(OBJ_PATH)%.o:	%.c
	$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ_PATH)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
