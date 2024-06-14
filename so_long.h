/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 23:14:20 by irychkov          #+#    #+#             */
/*   Updated: 2024/06/14 11:39:43 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <MLX42/MLX42.h>
# include "get_next_line_bonus.h"
# include "libft.h"
# include <fcntl.h>

# define TILE_SIZE 64

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
	t_position	position;
	int			fd;
	int			player_x;
	int			player_y;
	int			current_score;
	char		**map;
	size_t		map_width;
	size_t		map_height;
	int			steps;
	int			gameover;
	int			exits;
	int			players;
	int			collectibles;
}	t_game;

mlx_image_t	*load_image(t_game *game, mlx_t *mlx, const char *path);
void		load_images(t_game *game);
void		my_keyhook(mlx_key_data_t keydata, void *param);
void		get_map_height(t_game *game, const char *filename);
void		load_map(t_game *game, const char *filename);
void		parse_map(t_game *game);
int			ft_validate_walls(t_game *game);
int			validate_path(t_game *game, t_position position);
void		ft_check_chars(t_game *game);
int			ft_validate_file_ext(char *filename);
void		show_error(t_game *game, char *message);
void		cleanup_game(t_game *game);
void		map_handler(t_game *game, char *filename);

#endif
