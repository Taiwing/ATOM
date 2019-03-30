############################## COMPILE VAR #####################################

CC			=	gcc
CFLAGS		=	-O -Wall -Wextra -Werror
#CFLAGS		=	-g
HDIR		=	includes
SRCDIR		=	src
SUB1D		=	libft
HFLAGS		=	-I $(HDIR) -I $(SRCDIR)/$(SUB1D)/$(HDIR)
LIBS		=	$(SRCDIR)/$(SUB1D)/libft.a
NAME		=	ft_ls

############################## SOURCES #########################################

CONFIGDIR		=	config
LISTSDIR		=	lists
PRINTDIR		=	print
SORTDIR			=	sort

SRCC			=	main.c\

CONFIGC			=	ls_option_parser.c\
					ls_options_1.c\
					ls_options_2.c\
					ls_options_3.c\
					ls_options_4.c\
					lsconfig.c\
					set_opt.c\

LISTSC			=	ft_ls_errors.c\
					g_acl_perms.c\
					get_acl.c\
					get_acl_data.c\
					get_arg_data.c\
					get_args.c\
					get_args_d.c\
					get_file_data.c\
					get_long_data.c\
					get_xattr.c\
					get_xattracl.c\
					list_dirs.c\
					list_dirs_r.c\
					list_files.c\

PRINTC			=	get_mode_time.c\
					ls_print_dir.c\
					ls_print_file_columns.c\
					ls_print_file_long.c\
					ls_print_file_long_g.c\
					ls_print_file_long_go.c\
					ls_print_file_long_o.c\
					ls_print_file_one.c\
					ls_print_xa.c\

SORTC			=	cmp_access.c\
					cmp_ascii.c\
					cmp_creation.c\
					cmp_modif.c\
					cmp_size.c\
					ls_sort.c\

ODIR			=	obj
OBJ				=	$(patsubst %.c,%.o,$(CONFIGC))\
					$(patsubst %.c,%.o,$(LISTSC))\
					$(patsubst %.c,%.o,$(PRINTC))\
					$(patsubst %.c,%.o,$(SORTC))\
					$(patsubst %.c,%.o,$(SRCC))\

vpath			%.o	$(ODIR)
vpath			%.h	$(HDIR)
vpath			%.h	$(SRCDIR)/$(SUB1D)/$(HDIR)
vpath			%.c	$(SRCDIR)/$(CONFIGDIR)
vpath			%.c	$(SRCDIR)/$(LISTSDIR)
vpath			%.c	$(SRCDIR)/$(PRINTDIR)
vpath			%.c	$(SRCDIR)/$(SORTDIR)
vpath			%.c	$(SRCDIR)

############################## BUILD ###########################################

all: $(NAME)

$(NAME): libft.a $(ODIR) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(patsubst %.o,$(ODIR)/%.o,$(OBJ)) $(LIBS)

libft.a:
	make -C $(SRCDIR)/$(SUB1D)

ls_option_parser.o: ls_options.h lsconfig.h lsfdata.h libft.h ft_getopt.h\
	list_files.h list_dirs.h list_dirs_r.h get_args.h get_args_d.h ls_sort.h\
	get_file_data.h get_arg_data.h ls_print.h get_mode_time.h get_xa.h
ls_options_1.o: lsconfig.h lsfdata.h libft.h
ls_options_2.o: lsconfig.h lsfdata.h libft.h
ls_options_3.o: ls_options.h lsconfig.h lsfdata.h libft.h
ls_options_4.o: ls_options.h lsconfig.h lsfdata.h libft.h
lsconfig.o: lsconfig.h lsfdata.h libft.h list_dirs.h list_dirs_r.h\
	list_files.h ls_sort.h ls_print.h get_file_data.h get_arg_data.h
set_opt.o: ls_options.h lsconfig.h lsfdata.h libft.h
ft_ls_errors.o: lsconfig.h lsfdata.h libft.h
g_acl_perms.o: g_acl_perms.h
get_acl.o: get_acl.h lsconfig.h lsfdata.h libft.h
get_acl_data.o: get_acl.h lsconfig.h lsfdata.h libft.h g_acl_perms.h
get_arg_data.o: get_long_data.h lsconfig.h lsfdata.h libft.h ft_ls_errors.h
get_args.o: list_dirs.h lsconfig.h lsfdata.h libft.h ls_sort.h ft_ls_errors.h
get_args_d.o: list_dirs.h lsconfig.h lsfdata.h libft.h ls_sort.h\
	ft_ls_errors.h
get_file_data.o: get_long_data.h lsconfig.h lsfdata.h libft.h ft_ls_errors.h
get_long_data.o: lsconfig.h lsfdata.h libft.h
get_xattr.o: ft_ls_errors.h lsconfig.h lsfdata.h libft.h
get_xattracl.o: get_acl.h lsconfig.h lsfdata.h libft.h get_xattr.h
list_dirs.o: lsconfig.h lsfdata.h libft.h list_files.h ls_sort.h ls_print.h\
	ft_ls_errors.h
list_dirs_r.o: lsconfig.h lsfdata.h libft.h list_files.h ls_sort.h ls_print.h\
	ft_ls_errors.h list_dirs.h
list_files.o: lsconfig.h lsfdata.h libft.h
main.o: ls_option_parser.h lsconfig.h lsfdata.h libft.h get_args.h
get_mode_time.o: lsfdata.h libft.h
ls_print_dir.o: lsconfig.h lsfdata.h libft.h
ls_print_file_columns.o: lsconfig.h lsfdata.h libft.h
ls_print_file_long.o: get_mode_time.h lsconfig.h lsfdata.h libft.h\
	ls_print_xa.h
ls_print_file_long_g.o: get_mode_time.h lsconfig.h lsfdata.h libft.h\
	ls_print_xa.h
ls_print_file_long_go.o: get_mode_time.h lsconfig.h lsfdata.h libft.h\
	ls_print_xa.h
ls_print_file_long_o.o: get_mode_time.h lsconfig.h lsfdata.h libft.h\
	ls_print_xa.h
ls_print_file_one.o: lsconfig.h lsfdata.h libft.h
ls_print_xa.o: lsconfig.h lsfdata.h libft.h
cmp_access.o: lsfdata.h libft.h
cmp_ascii.o: lsfdata.h libft.h
cmp_creation.o: lsfdata.h libft.h
cmp_modif.o: lsfdata.h libft.h
cmp_size.o: lsfdata.h libft.h
ls_sort.o: lsconfig.h lsfdata.h libft.h
%.o: %.c
	$(CC) -c $(CFLAGS) $< $(HFLAGS) -o $(ODIR)/$@

$(ODIR):
	mkdir -p $@

############################## CLEANUP #########################################

clean:
	rm -rf $(ODIR)
	make -C $(SRCDIR)/$(SUB1D) fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
