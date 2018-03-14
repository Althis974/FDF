# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlossy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/10 16:26:09 by rlossy            #+#    #+#              #
#    Updated: 2018/03/13 12:15:51 by rlossy      ###    #+. /#+    ###.fr      #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a
HEADER		=   libft.h
FILENAMES	=   ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c
FILENAMES	+=  ft_isdigit.c ft_isprint.c ft_itoa.c ft_memalloc.c ft_memccpy.c
FILENAMES	+=  ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c
FILENAMES	+=  ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c
FILENAMES	+=	ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c
FILENAMES	+=	ft_putstr_fd.c	ft_strcat.c	ft_strchr.c ft_strclr.c ft_strcmp.c
FILENAMES	+=	ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c
FILENAMES	+=	ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c
FILENAMES	+=	ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c 
FILENAMES	+=	ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c 
FILENAMES	+=	ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c
FILENAMES	+=	ft_toupper.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c
FILENAMES	+=	ft_lstiter.c ft_lstmap.c ft_str_is_alpha.c ft_str_is_numeric.c
FILENAMES	+=	ft_str_is_printable.c ft_str_is_lowercase.c
FILENAMES	+=	ft_str_is_uppercase.c ft_isblank.c ft_iscntrl.c ft_isgraph.c
FILENAMES	+=	ft_str_capitalizer.c ft_abs.c ft_print_hex.c ft_swap.c
FILENAMES	+=	ft_sort_int_tab.c ft_itoa_base.c ft_get_len.c ft_putnstr.c
FILENAMES	+=	ft_print_base_low.c ft_print_base_upp.c ft_putwchar.c
FILENAMES	+=	ft_putwstr.c ft_atoisign.c ft_itoasign.c
FILENAMES	+=	ft_get_len_sign.c ft_get_print_len.c ft_putallnbr.c
FILENAMES	+=	ft_putallnbr_allsign.c ft_putallnbr_nosign.c ft_wstrlen.c
FILENAMES	+=	ft_putnwstr.c ft_isvalid_conv.c ft_isalnocast.c
FILENAMES	+=	ft_wcharnput.c ft_wcharlen.c get_next_line.c ft_word_count.c
FILENAMES	+=	ft_tab2d_init.c

SOURCES     =   $(addprefix ./, $(FILENAMES))
OBJECTS     =   $(addprefix build/, $(FILENAMES:.c=.o))

.PHONY: all clean fclean re


all: $(NAME)


clean:
	    @echo "\033[31m"
		    rm -rf build/

fclean: clean
	    @echo "\033[31m"
		    rm -f $(NAME)

re: 
	@$(MAKE) fclean
	@$(MAKE) all

build:
	    @echo "\033[36m"
		    mkdir build/

$(NAME): $(OBJECTS)
	    @echo "\033[33m"
		    ar crs $@ $(OBJECTS)

build/%.o: ./%.c | build
	    gcc -Wall -Wextra -Werror -I $(HEADER) -c $< -o $@
