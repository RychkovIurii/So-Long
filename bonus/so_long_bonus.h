/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 23:14:20 by irychkov          #+#    #+#             */
/*   Updated: 2024/06/14 16:27:28 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <MLX42/MLX42.h>
# include "get_next_line_bonus.h"
# include "libft.h"
# include <fcntl.h>

# define SCREEN_W 3200
# define SCREEN_H 1800
# define TILE_SIZE 100
# define MIN_SCALE 0.2

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_game
{
	mlx_t		*mlx;
	mlx_image_t	*player;
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*collectible;
	mlx_image_t	*exit_img;
	mlx_image_t	*enemy;
	mlx_image_t	*enemy1;
	mlx_image_t	*enemy2;
	t_position	position;
	int			fd;
	int			player_x;
	int			player_y;
	int			current_score;
	char		**map;
	size_t		map_width;
	size_t		map_height;
	int			tilesize;
	int			steps;
	int			gameover;
	int			exits;
	int			players;
	int			collectibles;
	int			enemies;
}	t_game;

void		b_load_images(t_game *game);
void		b_my_keyhook(mlx_key_data_t keydata, void *param);
void		b_get_map_height(t_game *game, const char *filename);
void		b_load_map(t_game *game, const char *filename);
void		b_parse_map(t_game *game);
void		b_ft_validate_walls(t_game *game);
int			b_validate_path(t_game *game, t_position position);
void		b_ft_check_chars(t_game *game);
int			b_ft_validate_file_ext(char *filename);
void		b_show_error(t_game *game, char *message);
void		b_cleanup_game(t_game *game);
void		b_map_handler(t_game *game, char *filename);
void		anim_blackhole(t_game *game);

#endif
