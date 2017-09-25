#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/19 21:03:39 by vinvimo           #+#    #+#              #
#    Updated: 2017/09/19 22:59:59 by vinvimo          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME=vinvimo.filler

CC=gcc

CFLAGS=-Wall -Wextra -Werror

HDDIRS=-I /filler.h

SRCS=get_next_line.c filler.c initialize.c create_tab.c ft_intnew.c \
get_data.c put_coor.c compensate.c check.c tmp_distance.c distance.c algo.c \
ft_print.c

OBJ=$(SRCS:.c=.o)

$(NAME): filler.h
	@make -C libft/
	$(CC) $(CFLAGS) $(SRCS) libft/libft.a -o $(NAME) $(HDDIRS)

all: $(NAME)

clean:
	@make clean -C libft/
	rm -rf $(OBJ)

fclean: clean
	@make fclean -C libft/
	@rm -rf $(NAME) a.out

re: fclean all

.PHONY: clean
