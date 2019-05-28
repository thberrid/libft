# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thberrid <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/17 17:15:46 by thberrid          #+#    #+#              #
#    Updated: 2019/05/16 20:54:23 by thberrid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = /bin/sh
NAME = libft.a
FILES_C = get_next_line.c \
		  print_memory.c \
		  ft_addrswap.c \
		  ft_factorial.c \
		  ft_power.c \
		  ft_sqrt.c \
		  ft_atoi.c \
		  ft_atol.c \
		  ft_bzero.c \
		  ft_isalnum.c \
		  ft_ischarset.c \
		  ft_isalpha.c \
		  ft_isascii.c \
		  ft_isdigit.c \
		  ft_isspace.c \
		  ft_isprint.c \
		  ft_itoa.c \
		  ft_lstadd.c \
		  ft_lstgetlast.c \
		  ft_lstgetn.c \
		  ft_lstappend.c \
		  ft_lstlen.c \
		  ft_lstpush.c \
		  ft_lstpop.c \
		  ft_lstdel.c \
		  ft_lstdelone.c \
		  ft_lstiter.c \
		  ft_lstmap.c \
		  ft_lstnew.c \
		  ft_lstremove.c \
		  ft_memalloc.c \
		  ft_memccpy.c \
		  ft_memchr.c \
		  ft_memcmp.c \
		  ft_memcpy.c \
		  ft_memdel.c \
		  ft_memerase.c \
		  ft_memmove.c \
		  ft_memrealloc.c \
		  ft_memset.c \
		  ft_memswap.c \
		  ft_putchar.c \
		  ft_putchar_fd.c \
		  ft_putendl.c \
		  ft_putendl_fd.c \
		  ft_putnbr.c \
		  ft_putnbr_fd.c \
		  ft_putstr.c \
		  ft_putstr_fd.c \
		  ft_strcat.c \
		  ft_strchr.c \
		  ft_strclr.c \
		  ft_strcmp.c \
		  ft_strcpy.c \
		  ft_strdel.c \
		  ft_strdup.c \
		  ft_strequ.c \
		  ft_striter.c \
		  ft_striteri.c \
		  ft_strjoin.c \
		  ft_strlcat.c \
		  ft_strlen.c \
		  ft_strmap.c \
		  ft_strmapi.c \
		  ft_strncat.c \
		  ft_strncmp.c \
		  ft_strncpy.c \
		  ft_strnequ.c \
		  ft_strnew.c \
		  ft_strnstr.c \
		  ft_strrchr.c \
		  ft_strsplit.c \
		  ft_strstr.c \
		  ft_strsub.c \
		  ft_strtrim.c \
		  ft_tolower.c \
		  ft_toupper.c
DIR_O = obj/
DIR_H = include/
FILES_O = $(addprefix $(DIR_O), $(patsubst %.c, %.o, $(FILES_C)))
FILES_H = $(addprefix $(DIR_H), get_next_line.h libft.h)
FLAGS = -Wall -Wextra -Werror

.PHONY : clean fclean re all
.SILENT : clean fclean re all $(NAME) $(FILES_O)

all : $(NAME)

$(NAME) : $(FILES_O)
	ar rc $(NAME) $(FILES_O)
	ranlib $(NAME)
	$(info  LIBFT compilation over)

$(DIR_O)%.o : %.c $(FILES_H)
	mkdir -p $(DIR_O)
	$(info LIBFT $<)
	gcc -I ./$(DIR_H) $(FLAGS) -c -o $@ $<

clean : 
	rm -f $(FILES_O)
	$(info LIBFT .o removed)

fclean : clean
	rm -f $(NAME)
	$(info LIBFT.a removed)

re : fclean all
