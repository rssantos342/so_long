# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ride-sou <ride-sou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/14 15:06:43 by ride-sou          #+#    #+#              #
#    Updated: 2023/06/22 18:40:07 by ride-sou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = src/so_long.c src/sl_aux.c src/sl_create_map.c src/sl_clean_exit.c \
		src/sl_check_map.c src/sl_graphics.c src/sl_moves.c

OBJS = ${SRC:.c=.o}

RM = rm -f
CFLAGS = -Wall -Wextra -Werror
MAKE = make -C
LIBFT = -L libft -lft
MLX	= -L mlx -lmlx -Ilmlx -lXext -lX11 -lm 

all:	${NAME}

$(NAME): ${OBJS}
		${MAKE} libft
		${MAKE} mlx
		cc ${CFLAGS} ${OBJS} ${LIBFT} ${MLX} -o ${NAME}

clean:
		${MAKE} libft clean
		${MAKE} mlx clean
		${RM} ${OBJS}

fclean: clean
		${MAKE} libft fclean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re

.SILENT: