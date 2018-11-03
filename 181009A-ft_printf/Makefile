CC=gcc
CFLAGS= -g -c -Wall -Wextra -Werror
HFLAGS= -I include/
NAME=libftprintf.a
SRC=src/ft_printf.c\
src/utils/parser.c\
src/utils/ft_strrev.c\
src/utils/ft_atoi_forward.c\
src/utils/fstr.c\
src/utils/fetch.c\
src/get_conv/get_type_cast.c\
src/get_conv/get_flags.c\
src/get_conv/get_conv.c\
src/convert/s_conversion.c\
src/convert/ls_conversion.c\
src/convert/lc_conversion.c\
src/convert/ft_itoa_cast.c\
src/convert/format_str.c\
src/convert/convert.c\
src/convert/c_conversion.c\
src/convert/ft_itoa_base_signed/ft_itoa_ssize_t.c\
src/convert/ft_itoa_base_signed/ft_itoa_shint.c\
src/convert/ft_itoa_base_signed/ft_itoa_llint.c\
src/convert/ft_itoa_base_signed/ft_itoa_lint.c\
src/convert/ft_itoa_base_signed/ft_itoa_intmax_t.c\
src/convert/ft_itoa_base_signed/ft_itoa_int.c\
src/convert/ft_itoa_base_signed/ft_itoa_char.c\
src/convert/ft_itoa_base_signed/ft_itoa_base_ushint.c\
src/convert/ft_itoa_base_signed/ft_itoa_base_ullint.c\
src/convert/ft_itoa_base_signed/ft_itoa_base_ulint.c\
src/convert/ft_itoa_base_signed/ft_itoa_base_uintmax_t.c\
src/convert/ft_itoa_base_signed/ft_itoa_base_uint.c\
src/convert/ft_itoa_base_signed/ft_itoa_base_uchar.c\
src/convert/ft_itoa_base_signed/ft_itoa_base_size_t.c\
src/libft/ft_bzero.c\
src/libft/ft_isalnum.c\
src/libft/ft_isalpha.c\
src/libft/ft_isascii.c\
src/libft/ft_isdigit.c\
src/libft/ft_isprint.c\
src/libft/ft_itoa.c\
src/libft/ft_lst_at.c\
src/libft/ft_lst_find.c\
src/libft/ft_lst_foreach.c\
src/libft/ft_lst_foreach_if.c\
src/libft/ft_lst_last.c\
src/libft/ft_lst_merge.c\
src/libft/ft_lst_move_front.c\
src/libft/ft_lst_push_back.c\
src/libft/ft_lst_push_front.c\
src/libft/ft_lst_push_params.c\
src/libft/ft_lst_remove_if.c\
src/libft/ft_lst_reverse.c\
src/libft/ft_lst_size.c\
src/libft/ft_lst_sort.c\
src/libft/ft_lstadd.c\
src/libft/ft_lstdel.c\
src/libft/ft_lstdelone.c\
src/libft/ft_lstiter.c\
src/libft/ft_lstmap.c\
src/libft/ft_lstnew.c\
src/libft/ft_memalloc.c\
src/libft/ft_memccpy.c\
src/libft/ft_memchr.c\
src/libft/ft_memcmp.c\
src/libft/ft_memcpy.c\
src/libft/ft_memdel.c\
src/libft/ft_memmove.c\
src/libft/ft_memset.c\
src/libft/ft_putchar.c\
src/libft/ft_putchar_fd.c\
src/libft/ft_putendl.c\
src/libft/ft_putendl_fd.c\
src/libft/ft_putnbr.c\
src/libft/ft_putnbr_fd.c\
src/libft/ft_putstr.c\
src/libft/ft_putstr_fd.c\
src/libft/ft_stradd.c\
src/libft/ft_strcat.c\
src/libft/ft_strchr.c\
src/libft/ft_strclr.c\
src/libft/ft_strcmp.c\
src/libft/ft_strcpy.c\
src/libft/ft_strcut.c\
src/libft/ft_strdel.c\
src/libft/ft_strdup.c\
src/libft/ft_strequ.c\
src/libft/ft_striter.c\
src/libft/ft_striteri.c\
src/libft/ft_strjoin.c\
src/libft/ft_strlcat.c\
src/libft/ft_strlen.c\
src/libft/ft_strmap.c\
src/libft/ft_strmapi.c\
src/libft/ft_strncat.c\
src/libft/ft_strncmp.c\
src/libft/ft_strncpy.c\
src/libft/ft_strnequ.c\
src/libft/ft_strnew.c\
src/libft/ft_strnstr.c\
src/libft/ft_strrchr.c\
src/libft/ft_strsplit.c\
src/libft/ft_strstr.c\
src/libft/ft_strsub.c\
src/libft/ft_strtrim.c\
src/libft/ft_tolower.c\
src/libft/ft_toupper.c\

OBJ=$(SRC:.c=.o)

all: $(NAME)

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

.PHONY: all clean fclean re
