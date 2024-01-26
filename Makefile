# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: izperez <izperez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 14:42:47 by izperez           #+#    #+#              #
#    Updated: 2024/01/26 13:07:09 by izperez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CFLAGS = -Wall -Werror -Wextra -framework OpenGL -framework AppKit #-g3 -fsanitize=address

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

MLX_DIR = minilibx/
MLX = $(MLX_DIR)libmlx.a

SRCS = so_long.c map.c map_errors.c map_errors_aux.c map_flood_fill.c

HDRS = so_long.h

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(SRCS) $(HDRS)
	gcc $(CFLAGS) $(SRCS) $(LIBFT) $(MLX) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR) all clean

$(MLX):
	make -C $(MLX_DIR) all

clean:
	make -C $(LIBFT_DIR) fclean
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re $(LIBFT) $(MLX)