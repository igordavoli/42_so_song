.PHONY: all clean fclean re

GNL = libs/gnl/get_next_line.a
LIBFT = libs/libft/libft.a
MLX = libs/mlx/libmlx.a

NAME = so_long.out

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -lXext -lX11

SRC = src/so_long.c \
src/ft_get_sprites.c \
src/ft_key_handler.c \
src/ft_close.c \
src/ft_close_error.c \
src/utils/ft_load_map.c \
src/utils/ft_check_map.c \
src/ft_get_map.c \
src/ft_put_map.c \
src/ft_check_args.c

OBJ = $(SRC:.c=.o)

# OBJ_B = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libs/gnl
	make -C ./libs/libft
	make -C ./libs/mlx
	@$(CC) $(CFLAGS) -fsanitize=address $(OBJ) $(GNL) $(LIBFT) $(MLX) -o $(NAME) $(MLX_FLAGS)

play: all
	./$(NAME) maps/map.ber
	make fclean

clean:
	find -name '*.o' -delete

fclean:
	find -name '*.[oa]' -delete
	find -name $(NAME) -delete

re:
	@make fclean && make all
