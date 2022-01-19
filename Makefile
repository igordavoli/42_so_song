.PHONY: all clean fclean re

GNL = libs/gnl/get_next_line.a
LIBFT = libs/libft/libft.a

NAME = so_long.out

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -lmlx -lXext -lX11

SRC = src/ft_new_sprite.c \
 src/ft_key_handler.c \
 src/ft_close.c

OBJ = $(SRC:.c=.o)

# OBJ_B = $(SRC:.c=.o)

all: $(NAME)


$(NAME): main.c $(OBJ)
	make -C ./libs/gnl
	make -C ./libs/libft
	@$(CC) $(CFLAGS) main.c $(OBJ) $(GNL) $(LIBFT) -o $(NAME) $(MLX_FLAGS)

play: all
	./$(NAME)
	make clean

clean:
	find -name '*.o' -delete

fclean:
	find -name '*.[oa]' -delete
	find -name $(NAME) -delete

re:
	@make fclean && make all
