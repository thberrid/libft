# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thberrid <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/30 07:56:16 by thberrid          #+#    #+#              #
#    Updated: 2019/05/30 09:32:38 by thberrid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = /bin/sh
.SUFFIXES:
.SUFFIXES: .c .o

export CC 		= gcc
export CFLAGS 	= -Wall -Wextra -Werror

LDFLAGS 		= -L ./libft/
LDLIB			= -lft
CPPFLAGS 		= -I ./include -I ./libft/include

VPATH 			= ./src
OBJDIR 			= obj

NAME 			= test
SRCS 			= test.c
OBJS_NAME		= $(SRCS:.c=.o)
OBJS 			= $(addprefix $(OBJDIR)/, $(OBJS_NAME))

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS) libft
	$(CC) $(LDFLAGS) $(LDLIB) -o $@ $(OBJS)

.PHONY: libft
libft:
	cd $@ && $(MAKE)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(OBJDIR): 
	mkdir $@

.PHONY: clean
clean:
	$(RM) $(OBJS)
	cd libft && $(MAKE) clean

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)
	cd libft && $(MAKE) fclean

.PHONY: re
re: fclean all
