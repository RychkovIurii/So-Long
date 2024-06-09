# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/28 11:25:45 by irychkov          #+#    #+#              #
#    Updated: 2024/05/30 14:45:04 by irychkov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRCS = main.c
OBJS = $(SRCS:.c=.o)
MLX_DIR = ./MLX42
MLX_HEADER = -I $(MLX_DIR)/include
HEADERS = -I. $(MLX_HEADER)
LIBMLX = $(MLX_DIR)/build/libmlx42.a
LIBGLFW = /Users/irychkov/.brew/Cellar/glfw/3.4/lib/libglfw.3.dylib
OSFLAGS = -framework Cocoa -framework OpenGL -framework IOKit
CFLAGS = -Wall -Wextra -Werror 
CC = cc

all:	libmlx $(NAME)

libmlx:
	@cmake $(MLX_DIR) -B $(MLX_DIR)/build && make -C $(MLX_DIR)/build -j4

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)
	@echo "Compiling: $<"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBMLX) $(LIBGLFW) $(OSFLAGS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(MLX_DIR)/build

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re libmlx
