# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/24 20:47:53 by vaferrei          #+#    #+#              #
#    Updated: 2022/02/20 01:33:45 by idavoli-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c \
	ft_printf_puts.c \
	ft_resolve_dec.c \
	ft_resolve_str.c \
	ft_resolve_ptr.c \
	ft_resolve_chr.c \
	ft_resolve_hex.c \
	ft_resolve_uns.c \
	ft_resolve_flg.c \
	ft_printf_utils.c

OBJS = ${SRCS:.c=.o}

CC = clang

CFLAGS = -Wall -Wextra -Werror

${NAME}: ${OBJS}
	@ar -rcs ${NAME} ${OBJS}

all: ${NAME}

re: fclean all

bonus: all

test_run : test
	@./a.out
	@make fclean

clean:
	@rm -f ${OBJS}
	@rm -f ${BOBJS}

fclean: clean
	@rm -f ${NAME}
	@rm a.out

.PHONY: all, bonus, clean, fclean, re
