NAME = libft.so

CFLAGS = -Wall -Wextra -Werror -fPIC

OBJ = ft_putchar.o\
ft_strlen.o\
ft_atoi.o\
ft_putnbr_base.o\
ft_pow.o\
ft_swap.o\
ft_putstr.o\
ft_strcmp.o\
ft_strcat.o\
ft_strcpy.o\
ft_split.o\
ft_print_words_tables.o\
ft_split_whitespaces.o\
ft_strdup.o\
ft_join.o\
ft_convert_base.o\
ft_strstr.o\
ft_putnbr.o\
ft_strcapitalize.o\
ft_str_is_numeric.o\
ft_strupcase.o\
ft_str_is_alpha.o\
ft_str_is_uppercase.o\
ft_str_is_lowercase.o\
ft_strlowcase.o\
ft_any.o\
ft_count_if.o\
ft_abs.o\
ft_sort_wordtab.o\
ft_advanced_sort_wordtab.o\
ft_strrev.o\
ft_itoa.o\
ft_print_bits.o\
ft_create_elem.o\
ft_list_merge.o\
ft_list_size.o\
ft_list_at.o\
ft_list_push_back.o\
ft_list_sort.o\
ft_list_clear.o\
ft_list_push_front.o\
ft_sorted_list_insert.o\
ft_list_find.o\
ft_list_push_params.o\
ft_sorted_list_merge.o\
ft_list_foreach.o\
ft_list_remove_if.o\
ft_list_foreach_if.o\
ft_list_reverse.o\
ft_list_last.o\
ft_list_reverse_fun.o

%.o: %c
	gcc $(CFLAGS) $@ $<

$(NAME): $(OBJ)
	gcc -shared -fPIC -Wl,-soname,$(NAME) -o $(NAME) -lc $(OBJ)

.PHONY: clean

clean:
	rm -f $(OBJ)
