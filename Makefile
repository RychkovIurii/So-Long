# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/28 11:25:45 by irychkov          #+#    #+#              #
#    Updated: 2024/06/14 16:23:07 by irychkov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAMEBONUS = so_long_bonus
SRCS = main.c ft_utils.c graphics.c control.c map_loading.c map_parsing.c \
					path_validation.c map_validation.c map_validation2.c
BONUS_DIR = ./bonus/
BONUS_SRCS = main_bonus.c ft_utils_bonus.c graphics_bonus.c control_bonus.c \
			 map_loading_bonus.c map_parsing_bonus.c path_validation_bonus.c \
			 map_validation_bonus.c map_validation2_bonus.c
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(addprefix $(BONUS_DIR), $(BONUS_SRCS:.c=.o))
MLX_DIR = ./MLX42
MLX_HEADER = -I $(MLX_DIR)/include
HEADERS = -I. $(MLX_HEADER) -I$(LIBFT_DIR)
LIBMLX = $(MLX_DIR)/build/libmlx42.a
#LIBGLFW = /Users/irychkov/.brew/Cellar/glfw/3.4/lib/libglfw.3.dylib
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
#OSFLAGS = $(LIBGLFW) -framework Cocoa -framework OpenGL -framework IOKit
OSFLAGS = -ldl -lglfw -pthread -lm
CFLAGS = -Wall -Wextra -Werror
CC = cc

all: $(LIBFT) $(LIBMLX) $(NAME)

bonus: $(LIBFT) $(LIBMLX) $(NAMEBONUS)

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
	@$(CC) $(OBJS) $(LIBMLX) $(LIBFT) $(OSFLAGS) -o $(NAME)

$(NAMEBONUS): $(BONUS_OBJS)
	@$(CC) $(BONUS_OBJS) $(LIBMLX) $(LIBFT) $(OSFLAGS) -o $(NAMEBONUS)

clean:
	@rm -rf $(OBJS) $(BONUS_OBJS)
	@rm -rf $(MLX_DIR)/build
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME) $(NAMEBONUS)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re libmlx libft bonus
