/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 23:14:20 by irychkov          #+#    #+#             */
/*   Updated: 2024/06/10 00:12:20 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <MLX42/MLX42.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

#define IDLE_FRAME_COUNT 6
#define RUN_FRAME_COUNT 10
#define COLLECTIBLE_FRAME_COUNT 4
#define FRAME_WIDTH 32
#define FRAME_HEIGHT 32

typedef struct	s_sprite {
	mlx_image_t	**frames;
	int	frame_count;
	int	width;
	int	height;
	int	current_frame;
} t_sprite;

typedef struct	s_game {
	mlx_t		*mlx;
	t_sprite	player_idle;
	t_sprite	player_run;
	t_sprite	wall;
	t_sprite	floor;
	t_sprite	collectible;
	t_sprite	exit;
	int			player_x;
	int			player_y;
	char		**map;
	int			map_width;
	int			map_height;
	int			steps;
	int			is_running;
} t_game;

void	init_game(t_game *game);
void	load_map(t_game *game, const char *filename);
void	render_game(t_game *game);
void	handle_input(t_game *game, int key);
//bool is_path_valid(t_game *game);
void	load_sprite_frames(t_game *game, t_sprite *sprite, const char *file_path, int frame_count);

#endif
