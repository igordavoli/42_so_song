.PHONY: all clean fclean re

CC = gcc

CFLAGS = -g3 -Wall -Wextra -Werror

MLX_FLAGS = -lXext -lX11

GNL = libs/gnl/get_next_line.a
LIBFT = libs/libft/libft.a
MLX = libs/mlx/libmlx.a

NAME = so_long.out
SRC_DIR = src
OBJ_DIR = objects
HEADER = $(SRC_DIR)/so_long.h

NAME_BONUS = so_long_bonus.out
SRC_DIR_BONUS = src_bonus
OBJ_DIR_BONUS = objects_bonus

SRC_FILES = so_long.c \
utils/ft_move_hero.c \
ft_get_sprites.c \
ft_key_handler.c \
ft_close.c \
ft_close_message.c \
utils/ft_load_map.c \
utils/check_map_utils.c \
utils/ft_check_map.c \
ft_get_map.c \
ft_put_map.c \
ft_check_args.c

SRC_FILES_BONUS = so_long_bonus.c \
ft_get_sprites_bonus.c \
ft_key_handler.c \
ft_close_bonus.c \
ft_close_message.c \
ft_get_map.c \
ft_put_map.c \
ft_check_args.c \
ft_put_sprite.c \
utils_bonus/ft_check_map_chars_bonus.c \
utils_bonus/ft_check_map_items_bonus.c \
utils_bonus/ft_move_hero_bonus.c \
utils_bonus/ft_load_map.c \
utils_bonus/ft_check_map_utils.c \
utils_bonus/ft_check_map.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

SRC_BONUS = $(addprefix $(SRC_DIR_BONUS)/, $(SRC_FILES_BONUS))
OBJ_BONUS = $(SRC:$(SRC_DIR_BONUS)/%.c=$(OBJ_DIR_BONUS)/%.o)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ) $(HEADER)
	make -C ./libs/gnl
	make -C ./libs/libft
	make -C ./libs/mlx
	@$(CC) $(CFLAGS) $(OBJ) $(GNL) $(LIBFT) $(MLX) -o $(NAME) $(MLX_FLAGS)

clean:
	find -name '*.o' -delete
	rm -rf objects*

fclean:
	make  clean
	find -name '*.out' -delete

re:
	@make fclean && make all

install:
	apt install x11-apps
	apt install libxext-dev
	apt install libbsd-dev

play: all
	./$(NAME) maps/map.ber

val: all
	make re
	valgrind --track-origins=yes --leak-check=full -s ./$(NAME) maps/map.ber

reb:
	@make fclean && make $(NAME_BONUS)

$(OBJ_DIR):
	mkdir objects
	mkdir objects/utils

$(NAME_BONUS): $(OBJ_DIR_BONUS) $(OBJ_BONUS)
	make -C ./libs/gnl
	make -C ./libs/libft
	make -C ./libs/mlx
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(GNL) $(LIBFT) $(MLX) -o $(NAME_BONUS) $(MLX_FLAGS)

bonus: $(NAME_BONUS)

playb: $(NAME_BONUS)
	./$(NAME_BONUS) maps/map_bonus.ber

valb: $(NAME_BONUS)
	make reb
	valgrind --track-origins=yes --leak-check=full -s ./$(NAME_BONUS) maps/map_bonus.ber


$(OBJ_DIR_BONUS):
	mkdir objects_bonus
	mkdir objects_bonus/utils_bonus
