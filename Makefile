# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/24 22:25:32 by agaladi           #+#    #+#              #
#    Updated: 2024/03/03 16:14:05 by agaladi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
SRCS = ft_split.c utils.c is_valid.c ft_atoi.c error_handler.c
CFLAGS = -Wall -Wextra -Werror
DEPS = push_swap.h
LIB = push_swap.a
OUT = push_swap
OBJS = $(SRCS:.c=.o)

all: $(OUT)

$(OUT): $(LIB) $(DEPS)
	$(CC) $(CFLAGS) main.c $(LIB) -o $(OUT)

$(LIB): $(OBJS)
	ar -rc $(LIB) $(OBJS)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -rf $(LIB)

re: fclean all

recom: re
	rm -rf $(OBJS) $(LIB)
