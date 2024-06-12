# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/28 11:25:45 by irychkov          #+#    #+#              #
#    Updated: 2024/06/12 13:18:56 by irychkov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRCS = main.c graphics.c control.c map_loading.c map_parsing.c path_validation.c map_validation.c map_validation2.c get_next_line_bonus.c get_next_line_utils_bonus.c
OBJS = $(SRCS:.c=.o)
MLX_DIR = ./MLX42
MLX_HEADER = -I $(MLX_DIR)/include
HEADERS = -I. $(MLX_HEADER) -I$(LIBFT_DIR)
LIBMLX = $(MLX_DIR)/build/libmlx42.a
LIBGLFW = /Users/irychkov/.brew/Cellar/glfw/3.4/lib/libglfw.3.dylib
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
OSFLAGS = -framework Cocoa -framework OpenGL -framework IOKit
CFLAGS = -Wall -Wextra -Werror 
CC = cc

all: $(LIBFT) $(LIBMLX) $(NAME)

$(LIBMLX): $(MLX_DIR)/CMakeLists.txt
	@if [ ! -d "$(MLX_DIR)/build" ]; then \
		cmake $(MLX_DIR) -B $(MLX_DIR)/build; \
	fi
	@make -C $(MLX_DIR)/build -j4

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)
	@echo "Compiling: $<"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBMLX) $(LIBGLFW) $(LIBFT) $(OSFLAGS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(MLX_DIR)/build
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re libmlx libft
