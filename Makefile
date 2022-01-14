.PHONY: all clean fclean re

NAME = so_long.out

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -lmlx -lXext -lX11

# SRC =


# OBJ = $(SRC:.c=.o)

# OBJ_B = $(SRC:.c=.o)

all: $(NAME)

$(NAME): main.c
	@$(CC) main.c -o $(NAME) $(MLX_FLAGS)

play: all
	./$(NAME)

clean:
	@rm -rf *.o

fclean:
	@rm -rf *.o $(NAME) *.out

re:
	@make fclean && make all
#
