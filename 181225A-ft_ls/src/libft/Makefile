############################## COMPILE VAR #####################################

CC			=	gcc
CFLAGS		=	-O -Wall -Wextra -Werror
#CFLAGS		=	-g
HDIR		=	includes
SRCDIR		=	src
HFLAGS		=	-I $(HDIR)
NAME		=	libft.a

############################## SOURCES #########################################

BINTDIR			=	bint
FT_GETOPTDIR	=	ft_getopt
FT_PRINTFDIR	=	ft_printf

SRCC			=	dir_heap_collector.c\
					ft_atoi.c\
					ft_atoi_forward.c\
					ft_bzero.c\
					ft_intlen.c\
					ft_isalnum.c\
					ft_isalpha.c\
					ft_isascii.c\
					ft_isdigit.c\
					ft_isprint.c\
					ft_itoa.c\
					ft_lst_at.c\
					ft_lst_discard.c\
					ft_lst_find.c\
					ft_lst_foreach.c\
					ft_lst_foreach_if.c\
					ft_lst_last.c\
					ft_lst_merge.c\
					ft_lst_move_front.c\
					ft_lst_move_to_back.c\
					ft_lst_move_to_front.c\
					ft_lst_push_back.c\
					ft_lst_push_front.c\
					ft_lst_push_params.c\
					ft_lst_quicksort.c\
					ft_lst_remove_if.c\
					ft_lst_reverse.c\
					ft_lst_size.c\
					ft_lst_sort.c\
					ft_lstadd.c\
					ft_lstdel.c\
					ft_lstdelone.c\
					ft_lstiter.c\
					ft_lstmap.c\
					ft_lstnew.c\
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
					ft_secmalloc.c\
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
					ft_strsplit.c\
					ft_strstr.c\
					ft_strsub.c\
					ft_strtrim.c\
					ft_swap_p.c\
					ft_tolower.c\
					ft_toupper.c\
					get_next_line.c\
					heap_collector.c\

BINTC			=	bint_mathconsts.c\
					divide_bint.c\
					dragon4.c\
					log_and_ceil.c\
					multiply_bint.c\
					op_bint.c\
					pow_bint.c\
					shiftleft_bint.c\
					utility_bint.c\

FT_GETOPTC		=	ft_getopt.c\
					get_next_option_argument.c\
					get_short_option.c\
					getopt_errors.c\
					getopt_long_errors.c\
					init_getopt.c\
					permute_order.c\
					process_long_option.c\

FT_PRINTFC		=	basic_conversions.c\
					convert.c\
					efg_conversions.c\
					fetch.c\
					float_formats.c\
					format_data.c\
					format_data_utils.c\
					ft_bufprintf.c\
					ft_printf.c\
					ft_printf_utils.c\
					get_conv.c\
					get_flags.c\
					itoa.c\
					itoa_cast.c\
					itoa_signed.c\
					itoa_unsigned.c\
					parser.c\
					t_pbuf.c\
					t_pdata.c\
					t_pdata_stralloc.c\
					tab_conversion.c\
					uni_conversions.c\

ODIR			=	obj
OBJ				=	$(patsubst %.c,%.o,$(BINTC))\
					$(patsubst %.c,%.o,$(FT_GETOPTC))\
					$(patsubst %.c,%.o,$(FT_PRINTFC))\
					$(patsubst %.c,%.o,$(SRCC))\

vpath			%.o	$(ODIR)
vpath			%.h	$(HDIR)
vpath			%.c	$(SRCDIR)/$(BINTDIR)
vpath			%.c	$(SRCDIR)/$(FT_GETOPTDIR)
vpath			%.c	$(SRCDIR)/$(FT_PRINTFDIR)
vpath			%.c	$(SRCDIR)

############################## BUILD ###########################################

all: $(NAME)

$(NAME): $(ODIR) $(OBJ)
	ar rc $@ $(patsubst %.o,$(ODIR)/%.o,$(OBJ))
	ranlib $@

divide_bint.o: bint.h
dragon4.o: dragon4.h bint.h log_and_ceil.h
log_and_ceil.o: bint_mathconsts.h
multiply_bint.o: bint.h
op_bint.o: bint.h
pow_bint.o: bint.h bint_mathconsts.h
shiftleft_bint.o: bint.h
utility_bint.o: bint.h
dir_heap_collector.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_atoi.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_bzero.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_getopt.o: get_next_option_argument.h ft_getopt.h get_short_option.h
get_next_option_argument.o: permute_order.h ft_getopt.h process_long_option.h\
	libft.h get_next_line.h ft_printf.h t_pbuf.h
get_short_option.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h\
	getopt_errors.h
getopt_errors.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
getopt_long_errors.o: getopt_errors.h ft_getopt.h libft.h get_next_line.h\
	ft_printf.h t_pbuf.h
init_getopt.o: ft_getopt.h
permute_order.o: ft_getopt.h
process_long_option.o: libft.h get_next_line.h ft_getopt.h ft_printf.h\
	t_pbuf.h getopt_errors.h
ft_isalnum.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_isalpha.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_isascii.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_isdigit.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_isprint.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_itoa.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_lst_at.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_lst_discard.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_lst_find.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_lst_foreach.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_lst_foreach_if.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_lst_last.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_lst_merge.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_lst_move_front.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_lst_move_to_back.o: libft.h get_next_line.h ft_getopt.h ft_printf.h\
	t_pbuf.h
ft_lst_move_to_front.o: libft.h get_next_line.h ft_getopt.h ft_printf.h\
	t_pbuf.h
ft_lst_push_back.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_lst_push_front.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_lst_push_params.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_lst_quicksort.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_lst_remove_if.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_lst_reverse.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_lst_size.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_lst_sort.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_lstadd.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_lstdel.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_lstdelone.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_lstiter.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_lstmap.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_lstnew.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_memalloc.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_memccpy.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_memchr.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_memcmp.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_memcpy.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_memdel.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_memmove.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_memset.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_print_words_tables.o: libft.h get_next_line.h ft_getopt.h ft_printf.h\
	t_pbuf.h
ft_print_words_tables_fd.o: libft.h get_next_line.h ft_getopt.h ft_printf.h\
	t_pbuf.h
basic_conversions.o: fetch.h t_farg.h libft.h get_next_line.h ft_getopt.h\
	ft_printf.h t_pbuf.h itoa_unsigned.h t_pdata.h t_params.h
convert.o: conversions.h t_farg.h t_pdata.h t_params.h format_data.h t_pbuf.h\
	libft.h get_next_line.h ft_getopt.h ft_printf.h
efg_conversions.o: fetch.h t_farg.h t_params.h log_and_ceil.h float_formats.h\
	t_pdata.h dragon4.h
fetch.o: fetch.h t_farg.h t_params.h
float_formats.o: ft_printf_utils.h t_pdata.h dragon4.h t_params.h
format_data.o: format_data_utils.h t_pdata.h t_params.h format_data.h t_pbuf.h\
	libft.h get_next_line.h ft_getopt.h ft_printf.h
format_data_utils.o: format_data.h t_params.h t_pdata.h t_pbuf.h libft.h\
	get_next_line.h ft_getopt.h ft_printf.h
ft_bufprintf.o: t_pbuf.h parser.h t_farg.h t_pdata.h t_params.h libft.h\
	get_next_line.h ft_getopt.h ft_printf.h
ft_printf.o: parser.h t_farg.h t_pbuf.h t_pdata.h t_params.h libft.h\
	get_next_line.h ft_getopt.h ft_printf.h
get_conv.o: get_flags.h t_farg.h t_params.h libft.h get_next_line.h\
	ft_getopt.h ft_printf.h t_pbuf.h
get_flags.o: t_params.h fetch.h t_farg.h libft.h get_next_line.h ft_getopt.h\
	ft_printf.h t_pbuf.h
itoa.o: fetch.h t_farg.h itoa_signed.h t_pdata.h itoa_unsigned.h t_params.h
itoa_cast.o: itoa.h t_farg.h t_params.h t_pdata.h
itoa_signed.o: itoa_signed.h t_pdata.h
itoa_unsigned.o: itoa_unsigned.h t_pdata.h t_params.h
parser.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h get_conv.h\
	t_farg.h t_params.h convert.h t_pdata.h
t_pbuf.o: t_pbuf.h libft.h get_next_line.h ft_getopt.h ft_printf.h
t_pdata.o: t_pdata.h libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
t_pdata_stralloc.o: t_pdata.h libft.h get_next_line.h ft_getopt.h ft_printf.h\
	t_pbuf.h
tab_conversion.o: get_conv.h t_farg.h t_params.h parser.h t_pbuf.h t_pdata.h\
	fetch.h libft.h get_next_line.h ft_getopt.h ft_printf.h
uni_conversions.o: fetch.h t_farg.h t_pdata.h t_params.h
ft_putchar.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_putchar_fd.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_putendl.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_putendl_fd.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_putnbr.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_putnbr_fd.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_putstr.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_putstr_fd.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_secmalloc.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_split_whitespaces.o: libft.h get_next_line.h ft_getopt.h ft_printf.h\
	t_pbuf.h
ft_stradd.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_strcat.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_strchr.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_strclr.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_strcmp.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_strcpy.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_strcut.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_strdel.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_strdup.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_strequ.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_striter.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_striteri.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_strjoin.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_strlcat.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_strlen.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_strmap.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_strmapi.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_strncat.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_strncmp.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_strncpy.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_strndup.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_strnequ.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_strnew.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_strnstr.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_strrchr.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_strsplit.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_strstr.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_strsub.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_strtrim.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_tolower.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
ft_toupper.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
get_next_line.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
heap_collector.o: libft.h get_next_line.h ft_getopt.h ft_printf.h t_pbuf.h
%.o: %.c
	$(CC) -c $(CFLAGS) $< $(HFLAGS) -o $(ODIR)/$@

$(ODIR):
	mkdir -p $@

############################## CLEANUP #########################################

clean:
	rm -rf $(ODIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
