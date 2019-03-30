# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/16 01:25:13 by yforeau           #+#    #+#              #
#    Updated: 2018/12/20 17:45:07 by yforeau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

############################## COMPILE VAR #####################################

CC			=	gcc
DIR			?=	181214A-ft_printfv3_cleaned
CFLAGS		=	-g -I ../$(DIR)/includes/
NAME		=	test

############################## SOURCES #########################################

LIBPRINTF	=	../$(DIR)/libftprintf.a
SRCS		=	main.c

############################## BUILD ###########################################

all: $(NAME)

$(NAME): $(SRCS) $(LIBPRINTF)
	$(CC) $^ $(CFLAGS) -o $@

$(LIBPRINTF):
	make -C ../$(DIR)/

############################## CLEANUP #########################################

clean:
	make -C ../$(DIR)/ clean

fclean: clean
	make -C ../$(DIR)/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
