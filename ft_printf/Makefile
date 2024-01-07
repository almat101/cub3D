# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amatta <amatta@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/26 16:44:16 by amatta            #+#    #+#              #
#    Updated: 2023/04/26 16:58:39 by amatta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c write_char.c write_hexa.c write_nbr.c write_pointer.c write_str.c write_unsigned.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: clean all

.PHONY: all, clean, fclean, re
