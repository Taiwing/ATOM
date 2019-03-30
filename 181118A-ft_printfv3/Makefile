CC		=	gcc
CFLAGS	=	-O -c -Wall -Wextra -Werror
DFLAGS	=	-g -c
HFLAGS	=	-I includes/
NAME	=	libftprintf.a
SRC		=	ft_atoi.c\
			ft_atoi_forward.c\
			ft_bzero.c\
			ft_isalnum.c\
			ft_isalpha.c\
			ft_isascii.c\
			ft_isdigit.c\
			ft_isprint.c\
			ft_itoa.c\
			ft_lstadd.c\
			ft_lst_at.c\
			ft_lstdel.c\
			ft_lstdelone.c\
			ft_lst_find.c\
			ft_lst_foreach.c\
			ft_lst_foreach_if.c\
			ft_lstiter.c\
			ft_lst_last.c\
			ft_lstmap.c\
			ft_lst_merge.c\
			ft_lst_move_front.c\
			ft_lstnew.c\
			ft_lst_push_back.c\
			ft_lst_push_front.c\
			ft_lst_push_params.c\
			ft_lst_remove_if.c\
			ft_lst_reverse.c\
			ft_lst_size.c\
			ft_lst_sort.c\
			ft_memalloc.c\
			ft_memccpy.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_memcpy.c\
			ft_memdel.c\
			ft_memmove.c\
			ft_memset.c\
			ft_print_words_tables.c\
			ft_print_words_tables_fd.c\
			ft_putchar.c\
			ft_putchar_fd.c\
			ft_putendl.c\
			ft_putendl_fd.c\
			ft_putnbr.c\
			ft_putnbr_fd.c\
			ft_putstr.c\
			ft_putstr_fd.c\
			ft_split_whitespaces.c\
			ft_stradd.c\
			ft_strcat.c\
			ft_strchr.c\
			ft_strclr.c\
			ft_strcmp.c\
			ft_strcpy.c\
			ft_strcut.c\
			ft_strdel.c\
			ft_strdup.c\
			ft_strequ.c\
			ft_striter.c\
			ft_striteri.c\
			ft_strjoin.c\
			ft_strlcat.c\
			ft_strlen.c\
			ft_strmap.c\
			ft_strmapi.c\
			ft_strncat.c\
			ft_strncmp.c\
			ft_strncpy.c\
			ft_strndup.c\
			ft_strnequ.c\
			ft_strnew.c\
			ft_strnstr.c\
			ft_strrchr.c\
			ft_strrev.c\
			ft_strsplit.c\
			ft_strstr.c\
			ft_strsub.c\
			ft_strtrim.c\
			ft_tolower.c\
			ft_toupper.c\
			bint/bint_mathconsts.c\
			bint/divide_bint.c\
			bint/dragon4.c\
			bint/log_and_ceil.c\
			bint/multiply_bint.c\
			bint/op_bint.c\
			bint/pow_bint.c\
			bint/shiftleft_bint.c\
			bint/utility_bint.c\
			ft_printf/basic_conversions.c\
			ft_printf/convert.c\
			ft_printf/efg_conversions.c\
			ft_printf/fetch.c\
			ft_printf/float_formats.c\
			ft_printf/format_data.c\
			ft_printf/format_int_data.c\
			ft_printf/ft_printf.c\
			ft_printf/get_conv.c\
			ft_printf/get_flags.c\
			ft_printf/itoa.c\
			ft_printf/itoa_cast.c\
			ft_printf/itoa_signed.c\
			ft_printf/itoa_unsigned.c\
			ft_printf/parser.c\
			ft_printf/t_pdata.c\
			ft_printf/tab_conversion.c\
			ft_printf/uni_conversions.c\
			ft_printf/utils.c\

OBJ		=	$(SRC:.c=.o)

all: $(NAME)

debug:
	$(CC) $(DFLAGS) *.c ft_printf/*.c bint/*.c $(HFLAGS)
	ar rc $(NAME) *.o
	rm *.o
	ranlib $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $^
	ranlib $@

%.o: %.c
	$(CC) $(CFLAGS) $< $(HFLAGS) -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: debug all clean fclean re
