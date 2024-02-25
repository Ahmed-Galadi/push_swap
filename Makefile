# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/24 22:25:32 by agaladi           #+#    #+#              #
#    Updated: 2024/02/25 02:09:25 by agaladi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
SRCS = ft_split.c utils.c
CFLAGS = -Wall -Wextra -Werror -c
DEPS = push_swap.h
LIB = push_swap.a
OUT = push_swap
OBJS = $(SRCS:.c=.o)

all: $(OUT)

$(OUT): $(LIB)
	cc main.c $(LIB) -o $(OUT)

$(LIB): $(OBJS)
	ar -rc $(LIB) $(OBJS)

%.o: %c $(DEPS)
	$(CC) $(CFLAGS) $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -rf $(LIB)

re: fclean all

recom: re
	rm -rf $(OBJS) $(LIB)
	
	
	
