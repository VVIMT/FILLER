
NAME=vinvimo.filler

CC=gcc

CFLAGS=-Wall -Wextra -Werror

HDDIRS=-I /filler.h

SRCS=get_next_line.c filler.c initialize.c create_tab.c ft_intnew.c \
get_data.c put_coor.c compensate.c check.c tmp_distance.c algo.c

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
