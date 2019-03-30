############################## COMPILE VAR #####################################

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
#CFLAGS		=	-g
HDIR		=	includes
HFLAGS		=	-I $(HDIR)
NAME		=	libftprintf.a

############################## SOURCES #########################################

SRCDIR			=	src

BINTDIR			=	bint
FT_PRINTFDIR	=	ft_printf
LIBFTDIR		=	libft

BINTC			=	bint_mathconsts.c\
					divide_bint.c\
					dragon4.c\
					log_and_ceil.c\
					multiply_bint.c\
					op_bint.c\
					pow_bint.c\
					shiftleft_bint.c\
					utility_bint.c\

FT_PRINTFC		=	basic_conversions.c\
					convert.c\
					efg_conversions.c\
					fetch.c\
					float_formats.c\
					format_data.c\
					format_int_data.c\
					ft_printf.c\
					get_conv.c\
					get_flags.c\
					itoa.c\
					itoa_cast.c\
					itoa_signed.c\
					itoa_unsigned.c\
					parser.c\
					t_pdata.c\
					tab_conversion.c\
					uni_conversions.c\
					utils.c\

LIBFTC			=	ft_atoi_forward.c\
					ft_memchr.c\
					ft_memcpy.c\
					ft_memset.c\
					ft_strchr.c\
					ft_strlen.c\

ODIR			=	obj
OBJ				=	$(patsubst %.c,%.o,$(BINTC))\
					$(patsubst %.c,%.o,$(FT_PRINTFC))\
					$(patsubst %.c,%.o,$(LIBFTC))\

vpath			%.o	$(ODIR)
vpath			%.h	$(HDIR)
vpath			%.c	$(SRCDIR)/$(BINTDIR)
vpath			%.c	$(SRCDIR)/$(FT_PRINTFDIR)
vpath			%.c	$(SRCDIR)/$(LIBFTDIR)

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
basic_conversions.o: fetch.h t_farg.h libft.h itoa_unsigned.h t_pdata.h\
	t_params.h
convert.o: conversions.h t_farg.h t_pdata.h t_params.h format_data.h libft.h
efg_conversions.o: fetch.h t_farg.h t_params.h log_and_ceil.h float_formats.h\
	t_pdata.h dragon4.h
fetch.o: fetch.h t_farg.h t_params.h
float_formats.o: utils.h t_pdata.h dragon4.h t_params.h
format_data.o: format_data.h t_params.h t_pdata.h format_int_data.h libft.h
format_int_data.o: format_int_data.h t_pdata.h t_params.h format_data.h\
	libft.h
ft_printf.o: ft_printf.h parser.h t_farg.h t_pdata.h t_params.h libft.h
get_conv.o: get_flags.h t_farg.h t_params.h libft.h
get_flags.o: t_params.h fetch.h t_farg.h libft.h
itoa.o: fetch.h t_farg.h itoa_signed.h t_pdata.h itoa_unsigned.h t_params.h
itoa_cast.o: itoa.h t_farg.h t_params.h t_pdata.h
itoa_signed.o: itoa_signed.h t_pdata.h
itoa_unsigned.o: itoa_unsigned.h t_pdata.h t_params.h
parser.o: libft.h get_conv.h t_farg.h t_params.h convert.h t_pdata.h
t_pdata.o: t_pdata.h libft.h
tab_conversion.o: get_conv.h t_farg.h t_params.h parser.h t_pdata.h fetch.h\
	libft.h
uni_conversions.o: fetch.h t_farg.h t_pdata.h t_params.h
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
