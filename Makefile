# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/24 22:25:32 by agaladi           #+#    #+#              #
#    Updated: 2024/06/06 05:29:10 by agaladi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
SRCS = ft_split.c utils.c is_valid.c ft_atoi.c error_handler.c \
		fill_stack.c actions.c list_utils.c bring_to_top.c sort_all.c \
		sort_int_tab.c sort_stack.c main.c
CFLAGS = -g
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
	rm -rf $(LIB) $(OUT)

re: fclean all
recom: re
	rm -rf $(OBJS) $(LIB)
